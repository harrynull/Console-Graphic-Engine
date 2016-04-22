#ifndef Console_h__
#define Console_h__
#include <stdio.h>
struct Color;
/*!
 * \class Console
 *
 * \brief 平台相关的控制台API
 *
 * \author Null
 * \date 四月 2016
 */
#include <Windows.h>
class Console {
public:
	/**
	* @brief 输出文字到控制台
	* @param[in] text 要输出的文字
	*/
	static void print(const char* text)
	{
		puts(text);
	}
	/**
	* @brief 打印单个字符
	* @param[in] c 要打印的字符
	*/
	static void printChar(const unsigned char c)
	{
		putchar(c);
	}

	/**
	* @brief 设置控制台大小
	* @param[in] w 宽
	* @param[in] h 高
	*/
	static void resize(int w, int h);

	/**
	* @brief 清屏
	*/
	static void clear();

	static void setColor(Color foreColor, Color backColor);
};

#endif // Console_h__