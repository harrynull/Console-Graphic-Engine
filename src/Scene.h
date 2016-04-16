#ifndef Scene_h__
#define Scene_h__
#include <memory>
#include "Settings.h"
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

private:
	Scene() = default;
};


#endif // Scene_h__
