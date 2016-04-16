#include "Rectangle.h"
#include "DisplayBuffer.h"
void Rectangle::draw(DisplayBuffer& buffer)
{
	if (!_visibility) return;
	if (_solid) {
		for (int drawX = _x; drawX != _x + _w; drawX++) {
			for (int drawY = _y; drawY != _y + _h; drawY++) {
				buffer.setPixel(drawX, drawY, getColorFromColorID(White), _displayChar);
			}
		}
	}
	else {
		for (int drawX = _x; drawX != _x + _w; drawX++) {
			for (int drawY = _y; drawY != _y + _h; drawY++) {
				if (drawX != _x&&drawX != _x + _w - 1 && drawY != _y&&drawY != _y + _h - 1) continue;
				buffer.setPixel(drawX, drawY, getColorFromColorID(White), _displayChar);
			}
		}
	}
}