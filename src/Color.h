#ifndef Color_h__
#define Color_h__
inline unsigned char operator "" _uc(unsigned long long value)
{ return static_cast<unsigned char>(value); }

struct Color {
	unsigned char r, g, b;
};

enum ColorID { Black, White };

inline Color getColorFromColorID(ColorID id)
{
	switch (id) {
	case White:
		return Color{ 255_uc, 255_uc, 255_uc };
	case Black:
	default:
		return Color{ 0,0,0 };
	}
}
#endif // Color_h__