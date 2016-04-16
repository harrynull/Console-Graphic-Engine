#include "..\src\CGE.h"
#include <memory>
int main()
{
	initCGE(60,20);
	auto mainScene = Scene::create();
	mainScene->addGraphic(std::make_shared<Rectangle>(12, 12, getColorFromColorID(White)), 5, 5);
	while (true)
	{
		
	}
}