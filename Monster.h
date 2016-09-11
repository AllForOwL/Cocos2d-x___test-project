#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Breed.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;
class GameScene;
class Weapon;

class Monster
{
public:
	Monster();
	Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent, Weapon& weapon, GameScene& gameScene);

	Breed&	GetBreed();
	void	Update(float dt);
	int		GetAttack();
	
	~Monster();

public:
	Breed&					m_heroes;
	InputComponent& 		m_inputComponent;
	GraphicComponent&		m_graphicComponent;
	Weapon&					m_weapon;
	GameScene&				m_gameScene;
	int						m_health;
	int						m_attack;
	string					m_filename;
	cocos2d::Sprite*		m_sprite;
};

#endif