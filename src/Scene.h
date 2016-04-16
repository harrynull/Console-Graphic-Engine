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
	* @note 坐标系向下y+,向右x+,Graphic和Scene的原点都在左上角
	*/
	void addGraphic(std::shared_ptr<Graphic>& graphic, int x, int y, std::string tag);
	void addGraphic(std::shared_ptr<Graphic>&& graphic, int x, int y, std::string tag);

	/**
	* @brief 查找一个Graphic
	* @param[in] tag 要查找的Graphic的tag
	* @return 查找到的Graphic的shared_ptr指针，若找不到，返回null指针
	*/
	std::shared_ptr<Graphic> getGraphicByTag(const std::string& tag);

	/**
	* @brief 刷新显示
	*/
	void flush();

private:
	DisplayBuffer buffer;
	std::map<std::string, std::shared_ptr<Graphic>> _graphics;
	Scene() :buffer(resolutionW, resolutionH) {};
};


#endif // Scene_h__
