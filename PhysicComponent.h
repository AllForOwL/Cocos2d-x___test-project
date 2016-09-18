#ifndef __PHYSIC_COMPONENT_H__
#define __PHYSIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class GameScene;
class Monster;

class PhysicComponent
{
public:
	enum StatePhysic
	{
		PHYSIC_NOTHING,
		PHYSIC_KILL_ENEMY,
		PHYSIC_KILL_HERO
	};

	PhysicComponent();

	void Update(Monster& hero, GameScene& scene);
	bool onContactBegin(cocos2d::PhysicsContact& contact);

	~PhysicComponent();

private:
	StatePhysic m_statePhysic;
};

#endif