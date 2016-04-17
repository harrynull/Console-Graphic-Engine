///Windows平台的Console相关操作的实现
#ifdef _WIN32
#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <Windows.h>
#include "Color.h"
void Console::resize(int w, int h)
{
	std::stringstream ss;
	ss << "mode con cols=" << w << " lines=" << h;
	system(ss.str().c_str());
}
void Console::clear()
{
	system("cls");
}

void Console::setColor(Color foreColor, Color backColor) {
	int color = 0;
	if (foreColor.r > 128) color |= FOREGROUND_RED;
	if (foreColor.g > 128) color |= FOREGROUND_GREEN;
	if (foreColor.b > 128) color |= FOREGROUND_BLUE;
	if (backColor.r > 128) color |= BACKGROUND_RED;
	if (backColor.g > 128) color |= BACKGROUND_GREEN;
	if (backColor.b > 128) color |= BACKGROUND_BLUE;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#endif