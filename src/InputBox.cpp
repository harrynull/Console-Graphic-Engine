#include "InputBox.h"
#include "DisplayBuffer.h"
#include "Console.h"

void InputBox::draw(DisplayBuffer& buffer)
{
	if (!_visibility) return;
	int xpos = _x, ypos = _y;
	for (unsigned char c : _text) {
		xpos++;
		if (c == '\n') {
			ypos++;
			continue;
		}
		buffer.setPixel(xpos, ypos, _foreColor, _backColor, c);
		if (_w != -1 && xpos > _x + _w - 1) {
			xpos = _x;
			ypos++;
		}
	}
}