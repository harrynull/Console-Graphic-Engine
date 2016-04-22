#ifndef Exceptions_h__
#define Exceptions_h__
///在参数错误时抛出的异常
struct Bad_Arg{};
///在未初始化就调用时抛出的异常
struct NOT_INITED_YET {};
///在重复初始化时抛出的异常
struct HAS_INITED_ALREADY {};
#endif // Exceptions_h__