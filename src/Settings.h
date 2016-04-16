#ifndef Settings_h__
#define Settings_h__

extern int resolutionW;
extern int resolutionH;

void initCheck(bool checkInited = true);
bool initCGE(int resW = 25, int resH = 80);

///在未初始化就调用时抛出的异常
struct NOT_INITED_YET {};
///在重复初始化时抛出的异常
struct HAS_INITED_ALREADY {};
#endif // Settings_h__
