#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;
class GameObjectMonster;
class PhysicComponent;

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
		WEAPON_STATE_REST,
		WEAPON_STATE_DEAD
	};

	enum StateEnemy
	{
		ENEMY_STATE_ATTACK,
		ENEMY_STATE_FIRE,
		ENEMY_STATE_REST,
		ENEMY_STATE_DEAD
	};

	enum StatePhysic
	{
		PHYSIC_NOTHING,
		PHYSIC_KILL_ENEMY,
		PHYSIC_KILL_HERO
	};

	Monster::Monster(
						GraphicComponent* graphicComponentHero, GraphicComponent* graphiComponentWeapon, 
						GraphicComponent* graphicComponentBullet, GameObjectMonster* objectMonster, 
						InputComponent* inputComponent, InputComponent* botInputComponent,
						PhysicComponent* physicComponent
					);

	void Update(GameScene& scene);

	~Monster();

public:
	GraphicComponent*	m_graphicComponentHero;
	GraphicComponent*	m_graphicComponentWeapon;
	GraphicComponent*	m_graphiComponentBullet;
	GameObjectMonster*	m_objectMonster;
	InputComponent*		m_inputComponent;
	InputComponent*		m_botInputComponent;
	PhysicComponent*	m_physicComponent;
	StateHero			m_stateHero;
	StateWeapon			m_stateWeapon;
	StateEnemy			m_stateEnemy;
	StatePhysic			m_statePhysic;
};

#endif