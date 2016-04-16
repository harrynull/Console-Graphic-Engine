#include "Scene.h"
#include "Graphic.h"

void Scene::addGraphic(std::shared_ptr<Graphic>& graphic, int x, int y, std::string tag)
{
	_graphics[tag] = graphic;
}

void Scene::addGraphic(std::shared_ptr<Graphic>&& graphic, int x, int y, std::string tag)
{
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
}
