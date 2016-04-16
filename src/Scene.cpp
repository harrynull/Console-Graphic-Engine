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
			auto pixel = buffer.getPixel(x, y);	//获得像素
			if (pixel.second.r != 0) {
				Console::printChar(pixel.first);	//打印像素
			}
			else
			{
				if (y != buffer.getH() - 1 || x != buffer.getW() - 1) //最后一个不输出空格
					Console::print(" ");
			}
		}
	}
}
