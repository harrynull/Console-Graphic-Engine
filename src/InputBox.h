#ifndef InputBox_h__
#define InputBox_h__
#include <string>
#include "Graphic.h"
#include "Color.h"
class DisplayBuffer;
class InputBox : public Graphic {
public:
	InputBox(int w, bool multiLines = false, int maxLength = -1, Color foreColor = getColorFromColorID(White),
		Color backgroundColor = getColorFromColorID(Transparent)) noexcept
		: _w(w), _foreColor(foreColor), _multiLines(multiLines), _maxLength(maxLength), _backColor(backgroundColor)
	{
		_focusable = true;
		if(!multiLines) _maxLength = _maxLength == -1 ? w : _maxLength;
	}
	virtual ~InputBox() {}
	virtual void draw(DisplayBuffer& buffer) override;
	virtual void update() override {};

	void setText(std::string text) { _text = text; }
	std::string getText() { return _text; }

	virtual void bind(Scene* s) override
	{
		_parentScene = s;
		_parentScene->addKeyboardEvent({
			[this](char ch)->bool {
			if (!_focus) return false;
			switch (ch) {
			case '\r':
				if (_multiLines) _text += ch;
				break;
			case '\b':
				if (_text.size() != 0) _text.erase(_text.end() - 1);
				break;
			default:
				if (ch != 0 && (_text.size() < _maxLength || _maxLength == -1)) _text += ch;
				break;
			}
			return true;
		}, std::string("")/*转发内容*/, true/*完全转发*/
		}, true/*独占*/, 0/*优先级*/);
	}

private:
	std::string _text;
	int _w;
	bool _multiLines;
	Color _foreColor;
	Color _backColor;
	int _maxLength;
};

#endif // InputBox_h__
