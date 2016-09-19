#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_statePhysic = PHYSIC_NOTHING;
	m_countElementInVector = 0;
	m_tagForDelete = 0;
}

void PhysicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (m_statePhysic)
	{
		case StatePhysic::PHYSIC_KILL_ENEMY:
		{
			// delete element from scene
			//scene.removeChildByTag(m_tagForDelete);
			scene.removeChildByTag(CNT_TAG_BULLET);
			 
			// set state 
			hero.m_stateEnemy	= Monster::StateEnemy::ENEMY_STATE_DEAD;
			hero.m_stateBullet	= Monster::StateBullet::BULLET_STATE_DEAD;
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