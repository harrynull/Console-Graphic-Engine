#ifndef Color_h__
#define Color_h__

struct Color {
	unsigned char r, g, b;
};

enum ColorID { Black, White };

inline Color getColorFromColorID(ColorID id)
{
	switch (id) {
	case White:
		return Color{ (unsigned char)255,(unsigned char)255,(unsigned char)255 };
	case Black:
	default:
		return Color{ 0,0,0 };
	}
}
#endif // Color_h__