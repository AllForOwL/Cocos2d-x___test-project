#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"


#include "Breed.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;
class GameScene;

class Monster : public cocos2d::Sprite
{
public:
	Monster();
	Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent, GameScene& gameScene);

	Breed&					GetBreed();
	void					Update(bool changeKeyCode);
	int						GetAttack();
	int						GetCountSprite();
	EventKeyboard::KeyCode	GetKeyCode();
	int						GetNumberSprite();
	void					SetKeyCode(EventKeyboard::KeyCode keyCode);
	void					SetCountSprite(int countSprite);
	void					SetChangeKeyCode(bool stateKeyCode);
	void					SetNumberSprite(int numberSprite);

	void					onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
	~Monster();

public:
	Breed&					m_heroes;
	InputComponent& 		m_inputComponent;
	GraphicComponent&		m_graphicComponent;
	GameScene&				m_gameScene;
	int						m_health;
	int						m_attack;
	string					m_filename;
	EventKeyboard::KeyCode	m_keyCode;
	int						m_countSprite;
	int						m_numberSprite;
	bool					m_changeKeyCode;
};

#endif