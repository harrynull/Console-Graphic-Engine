#include "Rectangle.h"
#include "DisplayBuffer.h"
void Rectangle::draw(DisplayBuffer& buffer)
{
	if (!_visibility) return;
	for (int drawX = _x; drawX != _x + _w; drawX++) {
		for (int drawY = _y; drawY != _y + _h; drawY++) {
			if (!_solid&&drawX != _x&&drawX != _x + _w - 1 && drawY != _y&&drawY != _y + _h - 1) continue;
			buffer.setPixel(drawX, drawY, _foreColor, _backColor, _displayChar);
		}
	}
}