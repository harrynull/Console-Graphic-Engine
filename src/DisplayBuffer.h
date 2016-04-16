#ifndef DisplayBuffer_h__
#define DisplayBuffer_h__
#include <memory>
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
	* @note buffer是w*h的3倍(r,g,b)
	* 排列方式:
	* 0 1 2
	* 3 4 5
	* 6 7 8
	*/
	DisplayBuffer(int w, int h)
		:_w(w), _h(h), _buffer(new unsigned char[w*h * 3]) {
		memset(_buffer.get(), 0, sizeof(unsigned char)*w*h * 3);
	};

	const Color getPixel(int x, int y) const
	{
		if (x > _w || y > _h) throw Bad_Arg();
		unsigned char* buffer = _buffer.get();
		buffer += y*getW() * 3;
		return Color{ *buffer,*(buffer + 1),*(buffer + 2) };
	}

	void setPixel(int x, int y, Color c)
	{
		if (x > _w || y > _h) throw Bad_Arg();
		unsigned char* buffer = _buffer.get();
		buffer += y*getW() * 3;
		*buffer = c.r;
		*(buffer + 1) = c.g;
		*(buffer + 2) = c.b;
	}
	int getW() const { return _w; }
	int getH() const { return _h; }
private:
	std::unique_ptr<unsigned char[]> _buffer;
	int _w, _h;
};

#endif // DisplayBuffer_h__