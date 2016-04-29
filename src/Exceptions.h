#ifndef Exceptions_h__
#define Exceptions_h__
///在参数错误时抛出的异常
struct Bad_Arg {};
///在未初始化就调用时抛出的异常
struct NOT_INITED_YET {};
///在重复初始化时抛出的异常
struct HAS_INITED_ALREADY {};
///在重复独享时抛出的异常
struct FAILED_TO_MONOPOLIZE {};
///在没有bind的时候设置focus
struct NOT_BINDED_YET {};
#endif // Exceptions_h__