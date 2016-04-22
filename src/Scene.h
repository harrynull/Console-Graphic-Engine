#ifndef Scene_h__
#define Scene_h__
#include <memory>
#include <string>
#include <map>
#include "Settings.h"
#include "DisplayBuffer.h"
class Graphic;
class Scene {
public:
	
	/**
	* @brief 工厂函数
	*/
	template<class... Ts>
	static std::unique_ptr<Scene> create(Ts&&... args)
	{
		initCheck();
		return std::unique_ptr<Scene>(new Scene(std::forward<Ts>(args)...));
	}

	/**
	* @brief 添加Graphic
	* @param[in] Graphic 要加入的Graphic
	* @param[in] x 要加入的Graphic在屏幕的X位置
	* @param[in] y 要加入的Graphic在屏幕的Y位置
	* @param[in] tag 要加入的Graphic的tag(用于查找该Graphic)，注意同一个Scene中tag不能重复
	* @param[in] layer 要加入的Graphic的layer, layer大的图形可以覆盖layer小的图形, 相同layer的图形的覆盖顺序无定义
	* @note 坐标系向下y+,向右x+,Graphic和Scene的原点都在左上角
	*/
	void addGraphic(std::shared_ptr<Graphic>& graphic, int x, int y, int layer = 0, std::string tag = "");
	void addGraphic(std::shared_ptr<Graphic>&& graphic, int x, int y, int layer = 0, std::string tag = "");

	/**
	* @brief 查找一个Graphic
	* @param[in] tag 要查找的Graphic的tag
	* @return 查找到的Graphic的shared_ptr指针，若找不到，返回null指针
	*/
	std::shared_ptr<Graphic> getGraphicByTag(const std::string& tag);

	/**
	* @brief 刷新显示
	*/
	void reDraw(); ///强行重绘所有显示（可能有闪烁）
	void flush();  ///只刷新修改部分
	
	/**
	* @brief 获得当前的fps
	* @return 返回当前的fps
	*/
	double getFPS();

private:
	DisplayBuffer buffer;
	std::multimap<int, std::shared_ptr<Graphic>> _graphics;
	Scene() :buffer(resolutionW, resolutionH) {};
	double fps;
};


#endif // Scene_h__
