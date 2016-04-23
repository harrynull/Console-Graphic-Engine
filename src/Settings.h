#ifndef Settings_h__
#define Settings_h__

extern int resolutionW;
extern int resolutionH;
extern bool ignoreOutOfBoardDraw;

void initCheck(bool checkInited = true);
bool initCGE(int resW = 80, int resH = 25);
void setIgnoreOutOfBoardDraw(bool isIgnore);
void setCursorDisplay(bool display);
#endif // Settings_h__
