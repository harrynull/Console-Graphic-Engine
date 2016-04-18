#include "..\src\CGE.h"
#include <memory>
#include <conio.h>
int main()
{
	initCGE();
	auto mainScene = Scene::create();

	mainScene->addGraphic(std::make_shared<Rectangle>(30, 10, '.', getColorFromColorID(Red), getColorFromColorID(Green)), 8, 3, 2);
	mainScene->addGraphic(std::make_shared<Rectangle>(40, 3, '*', getColorFromColorID(Green), getColorFromColorID(Blue)), 3, 5, 1);
	mainScene->addGraphic(std::make_shared<Rectangle>(80 - 2, 25 - 2, '#', getColorFromColorID(Blue), getColorFromColorID(Transparent), false), 1, 1, 1);
	//while (true)
	//{
	mainScene->flush();
	//}
	_getch();
}