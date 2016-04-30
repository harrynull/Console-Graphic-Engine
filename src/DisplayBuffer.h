#ifndef DisplayBuffer_h__
#define DisplayBuffer_h__
#include <memory>
#include <utility>
#include <tuple>
#include "Exceptions.h"
#include "Color.h"
struct PixelData {
	bool operator==(const PixelData& other) const {
		return other.ch == ch&&other.foreColor == foreColor&&other.backColor == backColor;
	}
	bool operator!=(const PixelData& other) const {
		return !(other == *this);
	}
	const unsigned char ch;
	Color foreColor, backColor;
#ifdef _WIN32
	int getColorFlag()
	{
		return foreColor.getColorFlag(false) | backColor.getColorFlag(true);
	}
#endif
};
/*!
 * \class DisplayBuffer
 *
 * \brief 绘图缓冲区
 *
 * \author Null
 * \date 四月 2016
 */
class DisplayBuffer {
public:
	/**
	* @brief DisplayBuffer的构造函数
	* @param[in] w 宽
	* @param[in] h 高
	* @note buffer是w*h的7倍(char,f_r,f_g,f_b,b_r,b_g,b_b)
	* 排列方式:
	* 0 1 2
	* 3 4 5
	* 6 7 8
	*/
	DisplayBuffer(int w, int h)
		:_w(w), _h(h), _offsetX(0), _offsetY(0), _buffer(new unsigned char[w*h * 7]) {
		clear();
	};

	DisplayBuffer clone() {
		DisplayBuffer db(_w, _h);
		memcpy(db._buffer.get(), _buffer.get(), sizeof(unsigned char)*_w*_h * 7);
		return db;
	}

	const PixelData getPixel(int x, int y) const
	{
		const unsigned char* buffer = getPixelPos(x, y);
		return PixelData{ std::move(*buffer),
			Color{ *(buffer + 1),*(buffer + 2),*(buffer + 3) }, Color{ *(buffer + 4),*(buffer + 5),*(buffer + 6) } };
	}

	void setPixel(int x, int y, Color fore, Color back, unsigned char ch)
	{
		unsigned char* buffer = getPixelPos(x, y);
		if (!buffer) return;
		*buffer = ch;
		if (!fore.transparent) {
			*(buffer + 1) = fore.r;
			*(buffer + 2) = fore.g;
			*(buffer + 3) = fore.b;
		}
		if (!back.transparent)
		{
			*(buffer + 4) = back.r;
			*(buffer + 5) = back.g;
			*(buffer + 6) = back.b;
		}
	}
	void setPixelForeColor(int x, int y, Color fore)
	{
		if (fore.transparent) return; //如果是颜色是透明的，不做任何修改
		unsigned char* buffer = getPixelPos(x, y);
		if (!buffer) return;
		*(buffer + 1) = fore.r;
		*(buffer + 2) = fore.g;
		*(buffer + 3) = fore.b;
	}
	void setPixelBackgroundColor(int x, int y, Color back)
	{
		if (back.transparent) return; //如果是颜色是透明的，不做任何修改
		unsigned char* buffer = getPixelPos(x, y);
		if (!buffer) return;
		*(buffer + 4) = back.r;
		*(buffer + 5) = back.g;
		*(buffer + 6) = back.b;
	}
	void setPixelChar(int x, int y, char ch)
	{
		*getPixelPos(x, y) = ch;
	}
	
	void clear() {
		memset(_buffer.get(), 0, sizeof(unsigned char)*_w*_h * 7);
	}

	const unsigned char* getBuffer()
	{
		return _buffer.get();
	}

	int getW() const { return _w; }
	int getH() const { return _h; }
	int getOffsetX() const { return _offsetX; }
	int getOffsetY() const { return _offsetY; }
	void setOffset(int x, int y) { _offsetX = x; _offsetY = y; }

private:
	unsigned char* getPixelPos(int x, int y)
	{
		extern bool ignoreOutOfBoardDraw;
		if (x + _offsetX >= _w || y + _offsetY >= _h || x < 0 || y < 0) {
			if (!ignoreOutOfBoardDraw) throw Bad_Arg();
			else return nullptr;
		}
		return  _buffer.get() + ((y + _offsetY)*getW() + x + _offsetX) * 7;
	}
	const unsigned char* getPixelPos(int x, int y) const
	{
		extern bool ignoreOutOfBoardDraw;
		if (x + _offsetX >= _w || y + _offsetY >= _h || x < 0 || y < 0) {
			if (!ignoreOutOfBoardDraw) throw Bad_Arg();
			else return nullptr;
		}
		return  _buffer.get() + ((y + _offsetY)*getW() + x + _offsetX) * 7;
	}

	std::unique_ptr<unsigned char[]> _buffer;
	int _w, _h;
	int _offsetX, _offsetY;
};

#endif // DisplayBuffer_h__