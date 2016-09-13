#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;

class Monster
{
public:
	enum StateHero
	{
		STATE_WALK,
		STATE_ATTACK,
		STATE_RUN,
		STATE_JUMP
	};

	enum StateWeapon
	{
		STATE_FIRE,
		STATE_REST
	};

	Monster::Monster(GraphicComponent* graphicComponentHero, GraphicComponent* graphiComponentWeapon, InputComponent* inputComponent);

	void Update();

	~Monster();

public:
	GraphicComponent*	m_graphicComponentHero;
	GraphicComponent*	m_graphicComponentWeapon;
	InputComponent*		m_inputComponent;
	StateHero			m_stateHero;
	StateWeapon			m_stateWeapon;
};

#endif