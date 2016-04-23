#include "..\src\CGE.h"
#include <memory>
#include <conio.h>
#include <sstream>
int main()
{
	initCGE();
	auto mainScene = Scene::create();
	auto g = std::make_shared<GraphicsGroup>();
	g->add(std::make_shared<Rectangle>(30, 10, '.', getColorFromColorID(Red), getColorFromColorID(Green)), 8, 3, 2, "test");
	g->add(std::make_shared<Rectangle>(40, 3, '*', getColorFromColorID(Green), getColorFromColorID(Blue)), 3, 5, 1);
	g->add(std::make_shared<Rectangle>(80, 25, '#', getColorFromColorID(Blue), getColorFromColorID(Transparent), false), 0, 0, 1);
	g->add(std::make_shared<Textbox>("Test1", Textbox::FillWidth), 12, 12, 3, "fps");
	g->add(std::make_shared<Textbox>("Test000000000002", 5, getColorFromColorID(Green)), 12, 16, 3);
	mainScene->addGraphic(g, 0, 0, 0, "g");
	mainScene->addEvent(Event([&]()->bool {	
		g->getGraphicByTag("test")->setX(g->getGraphicByTag("test")->getX() + 1);
		return false;
	}));
	while (true)
	{
		std::stringstream ss;
 		ss << "fps:" << mainScene->getFPS();
		((Textbox*)g->getGraphicByTag("fps").get())->setText(ss.str());
		mainScene->flush();
	}
	_getch();
}