///Windows平台的Console相关操作的实现
#ifdef _WIN32
#include "Console.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
template<class ...Ts>
void Console::print(Ts && ...args)
{
	//printf效率较高
	printf(std::forward<Ts>(args)...);
}
void Console::resize(int w, int h)
{
	std::stringstream ss;
	ss << "mode con cols=" << w << " lines=" << h;
	system(ss.str().c_str());
}
#endif