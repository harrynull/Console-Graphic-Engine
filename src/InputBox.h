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
		if(!multiLines) _maxLength = _maxLength == -1 ? w : _maxLength;
	}
	virtual ~InputBox() {}
	virtual void draw(DisplayBuffer& buffer) override;
	virtual void update() override;

	void setText(std::string text) { _text = text; }
	std::string getText() { return _text; }
private:
	std::string _text;
	int _w;
	bool _multiLines;
	Color _foreColor;
	Color _backColor;
	int _maxLength;
};

#endif // InputBox_h__
