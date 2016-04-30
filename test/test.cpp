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
	g->add(std::make_shared<InputBox>(5, false, -1, getColorFromColorID(Green)), 2, 2, 3, "inp");
	mainScene->addGraphic(g, 0, 0, 0, "g");
	auto test = g->getGraphicByTag("test");
	mainScene->addKeyboardEvent({
		[test](char)->bool {test->setY(test->getY() - 1); return false;
	}, std::string("w")});
	mainScene->addKeyboardEvent({
		[test](char)->bool {test->setX(test->getX() - 1); return false;
	}, std::string("a") });
	mainScene->addKeyboardEvent({
		[test](char)->bool {test->setY(test->getY() + 1); return false;
	}, std::string("s") });
	mainScene->addKeyboardEvent({
		[test](char)->bool {test->setX(test->getX() + 1); return false;
	}, std::string("d") });
	while (true)
	{
		std::stringstream ss;
 		ss << "fps:" << mainScene->getFPS();
		((Textbox*)g->getGraphicByTag("fps").get())->setText(ss.str());
		mainScene->flush();
	}
}