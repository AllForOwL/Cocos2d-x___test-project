#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "HeroGraphicComponent.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_statePhysic			= STATE_NOTHING;
	m_countElementInVector	= 0;
	m_tagForDelete			= 0;
}

void PhysicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (m_statePhysic)
	{
		case StatePhysic::STATE_WOUNDED_ENEMY:
		{
			if (hero.m_objectMonster->m_vecComponentEnemy[0]->Dead(hero.m_graphiComponentHeroBullet->GetAttack()))
			{
				hero.m_objectMonster->m_vecComponentEnemy[0]->removeFromParentAndCleanup(true);
				hero.m_graphiComponentHeroBullet->removeFromParentAndCleanup(true);
				this->m_statePhysic = StatePhysic::STATE_NOTHING;
			}
			else
			{
				hero.m_graphiComponentHeroBullet->removeFromParentAndCleanup(true);
				this->m_statePhysic = StatePhysic::STATE_NOTHING;
			}
			break;
		}
		case StatePhysic::STATE_WOUNDED_HERO:
		{
			if (hero.m_graphicComponentHero->Dead(hero.m_objectMonster->m_vecComponentBullet[0]->GetAttack()))
			{
				hero.m_graphicComponentHero->removeFromParentAndCleanup(true);
				hero.m_objectMonster->m_vecComponentBullet[0]->removeFromParentAndCleanup(true);
				m_statePhysic = StatePhysic::STATE_NOTHING;
			}
			else
			{
				hero.m_objectMonster->m_vecComponentBullet[0]->removeFromParentAndCleanup(true);
				m_statePhysic = StatePhysic::STATE_NOTHING;
			}

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

	if (_a->getCollisionBitmask() == BULLET_COLLISION_BITMASK && _b->getCollisionBitmask() == HERO_COLLISION_BITMASK ||
		_a->getCollisionBitmask() == HERO_COLLISION_BITMASK && _b->getCollisionBitmask() == BULLET_COLLISION_BITMASK
		)
	{
		this->m_statePhysic = StatePhysic::STATE_WOUNDED_HERO;

		CCLOG("Collision");
	}
	else if (_a->getCollisionBitmask() == BULLET_COLLISION_BITMASK && _b->getCollisionBitmask() == ENEMY_COLLISION_BITMASK ||
			_a->getCollisionBitmask() == ENEMY_COLLISION_BITMASK && _b->getCollisionBitmask() == BULLET_COLLISION_BITMASK
			)
	{
		this->m_statePhysic = StatePhysic::STATE_WOUNDED_ENEMY;

		CCLOG("collision");
	}

	return true;
}

PhysicComponent::~PhysicComponent()
{

}