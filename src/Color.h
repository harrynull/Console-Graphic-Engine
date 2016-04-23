#ifndef Color_h__
#define Color_h__
inline unsigned char operator "" _uc(unsigned long long value)
{ return static_cast<unsigned char>(value); }

struct Color {
	bool operator==(const Color& other) const {
		return other.r == r&&other.g == g&&other.b == b&&other.transparent == transparent;
	}
	bool operator!=(const Color& other) const {
		return !(other == *this);
	}
	Color(unsigned char _r, unsigned char _g, unsigned char _b, bool _trans = false) :
		r(_r), g(_g), b(_b), transparent(_trans) {}
	unsigned char r, g, b;
	bool transparent;
#ifdef _WIN32
	int getColorFlag(bool isBackground){
		int colorFlag = 0;
		if (r > 128) colorFlag |= isBackground ? 0x0040 : 0x0004;
		if (g > 128) colorFlag |= isBackground ? 0x0020 : 0x0002;
		if (b > 128) colorFlag |= isBackground ? 0x0010 : 0x0001;
		return colorFlag;
	}
#endif
};

enum ColorID { Black, White, Red, Green, Blue, Transparent };

inline Color getColorFromColorID(ColorID id)
{
	switch (id) {
	case White:
		return Color{ 255_uc, 255_uc, 255_uc };
	case Red:
		return Color{ 255_uc, 0, 0 };
	case Green:
		return Color{ 0, 255_uc, 0 };
	case Blue:
		return Color{ 0, 0, 255_uc };
	case Transparent:
		return Color(0, 0, 0, true);
	case Black:
	default:
		return Color{ 0,0,0 };
	}
}
#endif // Color_h__