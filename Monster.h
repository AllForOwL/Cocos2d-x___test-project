#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;
class GameObjectMonster;

class Monster
{
public:
	enum StateHero
	{
		HERO_STATE_WALK,
		HERO_STATE_ATTACK,
		HERO_STATE_RUN,
		HERO_STATE_JUMP
	};

	enum StateWeapon
	{
		WEAPON_STATE_FIRE,
		WEAPON_STATE_REST
	};

	enum StateEnemy
	{
		ENEMY_STATE_ATTACK,
		ENEMY_STATE_FIRE,
		ENEMY_STATE_REST,
		ENEMY_STATE_DEAD
	};

	Monster::Monster(GraphicComponent* graphicComponentHero, GraphicComponent* graphiComponentWeapon, 
		GraphicComponent* graphicComponentBullet, GameObjectMonster* objectMonster, InputComponent* inputComponent, InputComponent* botInputComponent);

	void Update(GameScene& scene);

	~Monster();

public:
	GraphicComponent*	m_graphicComponentHero;
	GraphicComponent*	m_graphicComponentWeapon;
	GraphicComponent*	m_graphiComponentBullet;
	GameObjectMonster*	m_objectMonster;
	InputComponent*		m_inputComponent;
	InputComponent*		m_botInputComponent;
	StateHero			m_stateHero;
	StateWeapon			m_stateWeapon;
	StateEnemy			m_stateEnemy;
};

#endif