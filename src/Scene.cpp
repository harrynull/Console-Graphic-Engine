#include "Scene.h"
#include "Graphic.h"
#include "Console.h"

void Scene::addGraphic(std::shared_ptr<Graphic>& graphic, int x, int y, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	_graphics[tag] = graphic;
}

void Scene::addGraphic(std::shared_ptr<Graphic>&& graphic, int x, int y, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	_graphics[tag] = std::move(graphic);
}

std::shared_ptr<Graphic> Scene::getGraphicByTag(const std::string& tag)
{
	auto iter = _graphics.find(tag);
	if (iter == _graphics.end()) return nullptr;
	return iter->second;
}

void Scene::flush()
{
	for (auto graphic : _graphics) {
		graphic.second->update();
		graphic.second->draw(buffer);
	}
	Console::clear();
	for (int y = 0; y != buffer.getH(); y++)
	{
		for (int x = 0; x != buffer.getW(); x++)
		{
			if (buffer.getPixel(x, y).r != 0)
				Console::print("*");
		}
		Console::print("\n");
	}
}
