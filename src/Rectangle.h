#ifndef Rectangle_h__
#define Rectangle_h__
#include "Graphic.h"
#include "Color.h"
class DisplayBuffer;
class Rectangle : public Graphic {
public:
	/**
	* @brief 矩形的构造函数
	* @param[in] w 宽
	* @param[in] h 高
	* @param[in] foreColor 前景色
	* @param[in] backgroundColor 背景色
	* @param[in] solid 是否是实心的
	*/
	Rectangle(int w, int h, char displayChar, Color foreColor=getColorFromColorID(White),
		Color backgroundColor = getColorFromColorID(White), bool solid = true) noexcept
		: _w(w), _h(h), _displayChar(displayChar), _foreColor(foreColor),_backColor(backgroundColor), _solid(solid) {}
	virtual ~Rectangle() {}
	virtual void draw(DisplayBuffer& buffer) override;
	virtual void update() override {};
private:
	bool _solid;
	int _w, _h;
	Color _foreColor;
	Color _backColor;
	const unsigned char _displayChar;
};

#endif // Rectangle_h__
