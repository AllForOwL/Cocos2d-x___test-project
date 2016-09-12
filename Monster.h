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
	enum State
	{
		STATE_WALK,
		STATE_ATTACK,
		STATE_RUN,
		STATE_JUMP
	};

	Monster::Monster(GraphicComponent* graphicComponent, InputComponent* inputComponent);

	void Update();

	~Monster();

public:
	GraphicComponent*	m_graphicComponent;
	InputComponent*		m_inputComponent;
	State				m_state;
};

#endif