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

void InputBox::update()
{
	char ch = Console::getchar();
	switch (ch) {
	case '\r':
		if (_multiLines) _text += ch;
		break;
	case '\b':
		if(_text.size()!=0) _text.erase(_text.end() - 1);
		break;
	default:
		if (ch != 0 && (_text.size() < _maxLength||_maxLength == -1)) _text += ch;
		break;
	}
}
