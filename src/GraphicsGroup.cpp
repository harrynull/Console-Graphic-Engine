#include "GraphicsGroup.h"
#include "DisplayBuffer.h"
void GraphicsGroup::draw(DisplayBuffer & buffer)
{
	if (!_visibility) return;
	buffer.setOffset(_x, _y);
	for (const auto& g : _graphics) {
		g.second->draw(buffer);
	}
	buffer.setOffset(0,0);
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
	graphic->setTag(tag);
	_graphics.insert({ layer,std::move(graphic) });
}

std::shared_ptr<Graphic> GraphicsGroup::getGraphicByTag(const std::string& tag)
{
	for (const auto& g : _graphics) {
		if (g.second->getTag() == tag) return g.second;
	}
	return nullptr;
}