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
	PhysicComponent();

	void Update(Monster& hero, GameScene& scene);
	bool onContactBegin(cocos2d::PhysicsContact& contact);


	~PhysicComponent();
};

#endif