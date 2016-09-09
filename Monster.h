#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Breed.h"

using namespace std;
using namespace cocos2d;

class InputComponent;

class Monster : public cocos2d::Sprite
{
public:
	Monster();
	Monster(Breed& breed, InputComponent& inputComponent);

	Breed& GetBreed();
	//void Update();
	int GetAttack();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
	~Monster();

private:
	Breed&					m_heroes;
	InputComponent& 		m_inputComponent;
	int						m_health;
	int						m_attack;
	string					m_filename;
	EventKeyboard::KeyCode	m_keyCode;
};

#endif