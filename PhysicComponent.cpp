#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
		
}

void PhysicComponent::Update(Monster& hero, GameScene& scene)
{

}

bool PhysicComponent::onContactBegin(cocos2d::PhysicsContact& contact)
{
	PhysicsBody* _a = contact.getShapeA()->getBody();
	PhysicsBody* _b = contact.getShapeB()->getBody();

	if (
		_a->getCollisionBitmask() == BULLET_COLLISION_BITMASK && _b->getCollisionBitmask() == ENEMY_COLLISION_BITMASK ||
		_a->getCollisionBitmask() == ENEMY_COLLISION_BITMASK  && _b->getCollisionBitmask() == BULLET_COLLISION_BITMASK
		)
	{
		CCLOG("Collision");
	}
	
	return true;
}

PhysicComponent::~PhysicComponent()
{

}