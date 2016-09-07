#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Breed.h"

class Monster : public cocos2d::Sprite
{
public:
	Monster(Breed& breed);

	int GetAttack();

	~Monster();

private:
	Breed&	m_heroes;
	int		m_health;
	int		m_attack;
};

#endif