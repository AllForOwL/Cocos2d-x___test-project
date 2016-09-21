#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_statePhysic			= PHYSIC_NOTHING;
	m_countElementInVector	= 0;
	m_tagForDelete			= 0;
}

void PhysicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (m_statePhysic)
	{
		case StatePhysic::PHYSIC_KILL_ENEMY:
		{
			// set state 
			//hero.m_objectMonster->m_stateEnemy	= GameObjectMonster::StateEnemy::ENEMY_STATE_DEATH;
			hero.m_stateBullet	= Monster::StateBullet::BULLET_STATE_REST;
			m_statePhysic		= StatePhysic::PHYSIC_NOTHING;

			break;
		}
		case StatePhysic::PHYSIC_KILL_HERO:
		{

		   break;
		}
		case StatePhysic::PHYSIC_NOTHING:
		{
			
			break;
		}
	default:
		break;
	}
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
		m_statePhysic		= PHYSIC_KILL_ENEMY;
		m_positionCollision = _a->getPosition();
		CCLOG("Collision");
	}

	return true;
}

PhysicComponent::~PhysicComponent()
{

}