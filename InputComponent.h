#ifndef __INPUT_COMPONENT_H__
#define __INPUT_COMPONENT_H__

#include "cocos2d.h"
#include "Monster.h"

using namespace cocos2d;
using namespace std;

//class Monster;

class InputComponent
{
public:
	InputComponent();

	void update(Monster& heroes, EventKeyboard::KeyCode keyCode);

	//void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	//void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	
	~InputComponent();

private:
	std::vector<std::string> m_vecSpriteRun;
	std::vector<std::string> m_vecSpriteFall;
	std::vector<std::string> m_vecSpriteDizzy;
	std::vector<std::string> m_vecSpriteWalk;
	std::vector<std::string> m_vecSpriteAttack;
	std::vector<std::string> m_vecSpriteDie;

	int						m_countSprite;
	EventKeyboard::KeyCode	m_keyCode;
	bool					m_GoToRight;
};

#endif