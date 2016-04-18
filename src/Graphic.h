#ifndef Graphic_h__
#define Graphic_h__
#include <string>
class DisplayBuffer;
/*!
 * \class Graphic
 *
 * \brief 所有图形的基类
 *
 * \author Null
 * \date 四月 2016
 */
class Graphic {
public:
	virtual ~Graphic() {}
	/**
	* @brief 绘图函数
	* @param[in] buffer 绘图缓存区，为绘图的目标
	* @note 将会在update函数之后被调用
	*/
	virtual void draw(DisplayBuffer& buffer) = 0;

	/**
	* @brief 刷新函数
	* @note 每帧调用一次，将在draw函数之前被调用
	*/
	virtual void update() = 0;

	int getX() const { return _x; }
	void setX(int val) { _x = val; }
	int getY() const { return _y; }
	void setY(int val) { _y = val; }
	std::string getTag() const { return _tag; }
	void setTag(std::string val) { _tag = val; }
	bool getVisibility() const { return _visibility; }
	void setVisibility(bool vis) { _visibility = vis; }

protected:
	std::string _tag;
	int _x, _y;
	bool _visibility = true;
};

#endif // Graphic_h__
