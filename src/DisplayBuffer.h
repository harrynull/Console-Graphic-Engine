#ifndef DisplayBuffer_h__
#define DisplayBuffer_h__
#include <memory>
#include <utility>
#include "Exceptions.h"
#include "Color.h"
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
	* @note buffer是w*h的4倍(char,r,g,b)
	* 排列方式:
	* 0 1 2
	* 3 4 5
	* 6 7 8
	*/
	DisplayBuffer(int w, int h)
		:_w(w), _h(h), _buffer(new unsigned char[w*h * 4]) {
		memset(_buffer.get(), 0, sizeof(unsigned char)*w*h * 4);
	};

	const std::pair<const unsigned char, Color> getPixel(int x, int y) const
	{
		const unsigned char* buffer = getPixelPos(x, y);
		return std::make_pair<const unsigned char, Color>(std::move(*buffer),
			Color{ *(buffer + 1),*(buffer + 2),*(buffer + 3) });
	}

	void setPixel(int x, int y, Color c, unsigned char ch)
	{
		unsigned char* buffer = getPixelPos(x, y);
		*buffer = ch;
		*(buffer + 1) = c.r;
		*(buffer + 2) = c.g;
		*(buffer + 3) = c.b;
	}
	void setPixel(int x, int y, Color c)
	{
		unsigned char* buffer = getPixelPos(x, y);
		*(buffer + 1) = c.r;
		*(buffer + 2) = c.g;
		*(buffer + 3) = c.b;
	}
	void setPixel(int x, int y, char ch)
	{
		*getPixelPos(x, y) = ch;
	}
	int getW() const { return _w; }
	int getH() const { return _h; }
private:
	unsigned char* getPixelPos(int x, int y)
	{
		if (x > _w || y > _h) throw Bad_Arg();
		return  _buffer.get() + (y*getW() + x) * 4;
	}
	const unsigned char* getPixelPos(int x, int y) const
	{
		if (x > _w || y > _h) throw Bad_Arg();
		return _buffer.get() + (y*getW() + x) * 4;
	}

	std::unique_ptr<unsigned char[]> _buffer;
	int _w, _h;
};

#endif // DisplayBuffer_h__