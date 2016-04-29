#ifndef Event_h__
#define Event_h__
#include <functional>
using Event = std::function<void()>;
using KeyboardEvent = std::function<bool(char)>; //bool是否阻挡后续信息传递
#endif // Event_h__
