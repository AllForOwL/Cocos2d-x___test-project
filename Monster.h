#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Breed.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;

class Monster : public cocos2d::Sprite
{
public:
	Monster();
	Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent);

	Breed& GetBreed();
	void Run();
	int GetAttack();
	int GetCountSprite();
	void SetKeyCode(EventKeyboard::KeyCode keyCode);
	void SetCountSprite(int countSprite);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
	~Monster();

private:
	Breed&					m_heroes;
	InputComponent& 		m_inputComponent;
	GraphicComponent&		m_graphicComponent;
	int						m_health;
	int						m_attack;
	string					m_filename;
	EventKeyboard::KeyCode	m_keyCode;
	int						m_countSprite;
};

#endif