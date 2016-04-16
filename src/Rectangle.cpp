#include "Rectangle.h"
#include "DisplayBuffer.h"
void Rectangle::draw(DisplayBuffer& buffer)
{
	if (!_visibility) return;
	if (_solid) {
		for (int drawX = _x; drawX != _x + _w; drawX++) {
			for (int drawY = _y; drawY != _y + _h; drawY++) {
				buffer.setPixel(drawX, drawY, getColorFromColorID(White));
			}
		}
	}
	else {

	}
}