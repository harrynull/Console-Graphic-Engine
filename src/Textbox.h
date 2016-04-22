#ifndef Textbox_h__
#define Textbox_h__
#include <string>
#include "Graphic.h"
#include "Color.h"
class DisplayBuffer;
class Textbox : public Graphic {
public:
	///长度不限制
	static const int FillWidth = -1;

	Textbox(std::string text, int w = FillWidth, Color foreColor = getColorFromColorID(White),
		Color backgroundColor = getColorFromColorID(Transparent)) noexcept
		: _text(text), _foreColor(foreColor), _backColor(backgroundColor), _w(w) {}
	virtual ~Textbox() {}
	virtual void draw(DisplayBuffer& buffer) override;
	virtual void update() override {};

	void setText(std::string text) { _text = text; }
	std::string getText() { return _text; }
private:
	std::string _text;
	int _w;
	Color _foreColor;
	Color _backColor;
};

#endif // Textbox_h__
