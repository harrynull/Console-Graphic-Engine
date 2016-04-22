#include "Settings.h"
#include "Console.h"
#include "Exceptions.h"
int resolutionW;
int resolutionH;
bool initialized = false;
bool ignoreOutOfBoardDraw = true;
/**
* @brief 检查初始化状态
* @param[in] checkInited 预期的初始化状态
* @note 如果checkInited==true，但是未初始化，抛出NOT_INITED_YET异常
* @note 如果checkInited==false，但是已初始化，抛出HAS_INITED_ALREADY异常
*/
void initCheck(bool checkInited)
{
	if (checkInited) {
		if (!initialized) throw NOT_INITED_YET(); //没有调用initCGE()
	}
	else {
		if (initialized) throw HAS_INITED_ALREADY(); //重复调用initCGE()
	}
}

/**
* @brief 初始化Console Graphic Engine
* @param[in] resW 分辨率宽
* @param[in] resH 分辨率高
* @return 是否初始化成功
*/
bool initCGE(int resW, int resH)
{
	initCheck(false);
	resolutionW = resW;
	resolutionH = resH;
	Console::resize(resW, resH);
	initialized = true;
	return true;
}

void setIgnoreOutOfBoardDraw(bool isIgnore) {
	ignoreOutOfBoardDraw = isIgnore;
}
