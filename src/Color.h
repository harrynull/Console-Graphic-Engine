#ifndef Color_h__
#define Color_h__
inline unsigned char operator "" uc(unsigned long long value)
{ return static_cast<unsigned char>(value); }

struct Color {
	unsigned char r, g, b;
};

enum ColorID { Black, White };

inline Color getColorFromColorID(ColorID id)
{
	switch (id) {
	case White:
		return Color{ 255uc, 255uc, 255uc };
	case Black:
	default:
		return Color{ 0,0,0 };
	}
}
#endif // Color_h__