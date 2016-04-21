#include "GraphicsGroup.h"

void GraphicsGroup::draw(DisplayBuffer & buffer)
{
	if (!_visibility) return;
	for (const auto& g : _graphics) {
		g.second->draw(buffer);
	}
}
void GraphicsGroup::add(std::shared_ptr<Graphic>& graphic, int x, int y, int layer, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	graphic->setTag(tag);
	_graphics.insert({ layer,std::move(graphic) });
}

void GraphicsGroup::add(std::shared_ptr<Graphic>&& graphic, int x, int y, int layer, std::string tag)
{
	graphic->setX(x);
	graphic->setY(y);
	_graphics.insert({ layer,std::move(graphic) });
}
