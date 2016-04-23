///Windows平台的Console相关操作的实现
#ifdef _WIN32
#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <Windows.h>
#include "Color.h"
#include "DisplayBuffer.h"
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreColor.getColorFlag(false) | backColor.getColorFlag(true));
}

void Console::setCursorPos(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
}

void Console::setCursorShow(bool show)
{
	CONSOLE_CURSOR_INFO ci{ 20,show };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}
void Console::printDisplayBuffer(const DisplayBuffer& buffer)
{
	_CHAR_INFO* cinfo = new _CHAR_INFO[buffer.getW()*buffer.getH()];
	for (int y = 0; y != buffer.getH(); y++)
	{
		for (int x = 0; x != buffer.getW(); x++)
		{
			auto pixel = buffer.getPixel(x, y);	//获得像素
			cinfo[y*buffer.getW() + x].Char.UnicodeChar = pixel.ch;
			cinfo[y*buffer.getW() + x].Attributes = pixel.getColorFlag();
		}
	}

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	WriteConsoleOutput(hOut, cinfo, { (short)buffer.getW(), (short)buffer.getH() }, { 0,0 }, &info.srWindow);
	delete[] cinfo;
}
void Console::printPixel(PixelData pixel, int x, int y)
{
	_CHAR_INFO cinfo[1];
	cinfo[0].Char.UnicodeChar = pixel.ch;
	cinfo[0].Attributes = pixel.getColorFlag();
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SMALL_RECT sr{ (short)x,(short)y,(short)x + 1,(short)y + 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), cinfo, { (short)1,(short)1 }, { 0,0 }, &sr);
}
#endif