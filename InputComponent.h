#ifndef __INPUT_COMPONENT_H__
#define __INPUT_COMPONENT_H__

#include "cocos2d.h"
#include "Monster.h"

using namespace cocos2d;
using namespace std;

class InputComponent
{
public:
	InputComponent();

	EventKeyboard::KeyCode GetActiveKey();
	void update(Monster& heroes);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	
	~InputComponent();

private:
	int						m_countSprite;
	EventKeyboard::KeyCode	m_keyCode;
	bool					m_GoToRight;
};

#endif