#ifndef GraphicsGroup_h__
#define GraphicsGroup_h__
#include <map>
#include <memory>
#include "Graphic.h"
class DisplayBuffer;
class GraphicsGroup : public Graphic {
public:
	GraphicsGroup() noexcept {};
	virtual ~GraphicsGroup() {}
	virtual void draw(DisplayBuffer& buffer) override;
	virtual void update() override;

	void add(std::shared_ptr<Graphic>& graphic, int x, int y, int layer = 0, std::string tag = "");
	void add(std::shared_ptr<Graphic>&& graphic, int x, int y, int layer = 0, std::string tag = "");

	/**
	* @brief 查找一个Graphic
	* @param[in] tag 要查找的Graphic的tag
	* @return 查找到的Graphic的shared_ptr指针，若找不到，返回null指针
	*/
	std::shared_ptr<Graphic> getGraphicByTag(const std::string& tag);
private:
	std::multimap<int, std::shared_ptr<Graphic>> _graphics;
};

#endif // GraphicsGroup_h__
