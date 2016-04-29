#ifndef KeyboardEventManager_h__
#define KeyboardEventManager_h__
#include <functional>
#include <map>
#include <string>
#include "Event.h"

class KeyboardEventManager {
public:
	struct KeyEvent {
		KeyEvent(KeyboardEvent ke, std::string k, bool forw = false) :
			e(ke), keys(k), forward(forw) {}
		KeyboardEvent e;
		std::string keys;
		bool forward = false;
	};
	static const int MONOPOLIZE_PRIORITY = INT_MAX - 1;
	void bind(KeyEvent k, bool monopolize = false, int priority = 0);
	void listen();

private:
	std::multimap<int, KeyEvent> _events;

};

#endif // KeyboardEventManager_h__
