#ifndef Event_h__
#define Event_h__
#include <functional>
struct Event {
	Event(std::function<bool()> f) :callback(f) {};
	std::function<bool()> callback;
};

#endif // Event_h__
