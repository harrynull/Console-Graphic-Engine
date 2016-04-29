#include "KeyboardEventManager.h"
#include "Exceptions.h"
#include "Console.h"

void KeyboardEventManager::bind(KeyEvent k, bool monopolize, int priority)
{
	if (monopolize) {
		priority = MONOPOLIZE_PRIORITY;
	}
	_events.insert({ priority, k });
}

void KeyboardEventManager::listen()
{
	char ch = Console::getchar();
	if (ch == '\0') return;
	for (auto iter = _events.rbegin();iter != _events.rend();++iter) {
		if (iter->second.forward || iter->second.keys.find(ch) < iter->second.keys.size()) {
			bool monopolize = iter->second.e(ch);
			if (monopolize) break;
		}
	}
}
