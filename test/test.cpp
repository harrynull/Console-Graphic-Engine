#include "..\src\CGE.h"
#include "..\src\Console.h"
#include <memory>
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
	g->add(std::make_shared<InputBox>(5, false, -1, getColorFromColorID(Green)), 2, 2, 3);
	mainScene->addGraphic(g, 0, 0, 0, "g");
	mainScene->addEvent(Event([&]()->bool {
		switch (Console::getchar()) {
		case 'w':g->getGraphicByTag("test")->setY(g->getGraphicByTag("test")->getY() - 1); break;
		case 'a':g->getGraphicByTag("test")->setX(g->getGraphicByTag("test")->getX() - 1); break;
		case 's':g->getGraphicByTag("test")->setY(g->getGraphicByTag("test")->getY() + 1); break;
		case 'd':g->getGraphicByTag("test")->setX(g->getGraphicByTag("test")->getX() + 1); break;
		}
		
		return false;
	}));
	while (true)
	{
		std::stringstream ss;
 		ss << "fps:" << mainScene->getFPS();
		((Textbox*)g->getGraphicByTag("fps").get())->setText(ss.str());
		mainScene->flush();
	}
}