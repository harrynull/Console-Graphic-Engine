#include "..\src\CGE.h"
#include <memory>
#include <conio.h>
int main()
{
	initCGE();
	auto mainScene = Scene::create();
	mainScene->addGraphic(std::make_shared<Rectangle>(30, 10, getColorFromColorID(White)), 5, 3, "1");
	mainScene->addGraphic(std::make_shared<Rectangle>(40, 3, getColorFromColorID(White)), 1, 5, "2");
	//while (true)
	//{
		mainScene->flush();
	//}
		_getch();
}