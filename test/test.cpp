#include "..\src\CGE.h"
#include <memory>
#include <conio.h>
int main()
{
	initCGE(60,20);
	auto mainScene = Scene::create();
	mainScene->addGraphic(std::make_shared<Rectangle>(1, 1, getColorFromColorID(White)), 0, 0);
	//while (true)
	//{
		mainScene->flush();
	//}
		_getch();
}