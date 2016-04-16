#ifndef Console_h__
#define Console_h__

/*!
 * \class Console
 *
 * \brief 平台相关的控制台API
 *
 * \author Null
 * \date 四月 2016
 */
class Console {
public:
	/**
	* @brief 输出文字到控制台
	* @param[in] args 参数(和printf相同)
	*/
	template<class... Ts>
	static void print(Ts&&... args);

	/**
	* @brief 设置控制台大小
	* @param[in] w 宽
	* @param[in] h 高
	*/
	static void resize(int w, int h);
};

#endif // Console_h__