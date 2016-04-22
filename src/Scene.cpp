#include "Scene.h"
#include "Graphic.h"
#include "Console.h"
#include "Color.h"
#include "DisplayBuffer.h"
#include <chrono>

void Scene::addGraphic(std::shared_ptr<Graphic>& graphic, int x, int y, int layer, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	graphic->setTag(tag);
	_graphics.insert({ layer,std::move(graphic) });
}

void Scene::addGraphic(std::shared_ptr<Graphic>&& graphic, int x, int y, int layer, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	graphic->setTag(tag);
	_graphics.insert({ layer,std::move(graphic) });
}

std::shared_ptr<Graphic> Scene::getGraphicByTag(const std::string& tag)
{
	for (const auto& g : _graphics) {
		if (g.second->getTag() == tag) return g.second;
	}
	return nullptr;
}

void Scene::flush()
{
	buffer.clear();
	for (auto graphic : _graphics) {
		graphic.second->update();
		graphic.second->draw(buffer);
	}
	auto timeBeforeDraw = std::chrono::system_clock::now();
	Console::clear();
	for (int y = 0; y != buffer.getH(); y++)
	{
		for (int x = 0; x != buffer.getW(); x++)
		{
			if (y != buffer.getH() - 1 || x != buffer.getW() - 1) {
				auto pixel = buffer.getPixel(x, y);	//获得像素
				Console::setColor(pixel.foreColor, pixel.backColor);
				Console::printChar(pixel.ch);	//打印像素
			}
		}
	}
	auto timeAfterDraw = std::chrono::system_clock::now();
	auto diff = (timeAfterDraw - timeBeforeDraw).count() / 1000.0 / 1000.0;
	fps = 1.0 / diff;
}

void Scene::reDraw()
{
	buffer.clear();
	for (auto graphic : _graphics) {
		graphic.second->update();
		graphic.second->draw(buffer);
	}
	auto timeBeforeDraw = std::chrono::system_clock::now();
	Console::clear();
	for (int y = 0; y != buffer.getH(); y++)
	{
		for (int x = 0; x != buffer.getW(); x++)
		{
			if (y != buffer.getH() - 1 || x != buffer.getW() - 1) {
				auto pixel = buffer.getPixel(x, y);	//获得像素
				Console::setColor(pixel.foreColor, pixel.backColor);
				Console::printChar(pixel.ch);	//打印像素
			}
		}
	}
	auto timeAfterDraw = std::chrono::system_clock::now();
	auto diff = (timeAfterDraw - timeBeforeDraw).count()/1000.0/1000.0;
	fps = 1.0 / diff;
}

double Scene::getFPS()
{
	return fps;
}
