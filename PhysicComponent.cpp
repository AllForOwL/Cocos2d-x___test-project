#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_statePhysic = PHYSIC_NOTHING;
	m_vecSprites.reserve(5);
	m_countElementInVector = 0;
}

void PhysicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (m_statePhysic)
	{
		case StatePhysic::PHYSIC_KILL_ENEMY:
		{
			// load the Sprite Sheet
			auto spritecache = SpriteFrameCache::getInstance();

			// the .plist file can be generated with any of the tools mentioned below
			spritecache->addSpriteFramesWithFile("explosion_bullet.plist");

//			m_vecSprites.resize(5);

			m_vecSprites.push_back(Sprite::createWithSpriteFrameName("13_1.png"));
			m_vecSprites.push_back(Sprite::createWithSpriteFrameName("13_2.png"));
			m_vecSprites.push_back(Sprite::createWithSpriteFrameName("13_3.png"));
			m_vecSprites.push_back(Sprite::createWithSpriteFrameName("13_4.png"));
			m_vecSprites.push_back(Sprite::createWithSpriteFrameName("13_5.png"));
			
		//	for (int i = 0; i < 5; i++)
		//	{
		//		m_vecSprites[i]->setPosition(m_positionCollision.x + i, m_positionCollision.y);
		//	}

		//	scene.addChild(m_vecSprites[m_countElementInVector]);
			scene.removeChildByName("bullet");
			scene.removeChildByName("monster");

			hero.m_stateEnemy	= Monster::StateEnemy::ENEMY_STATE_DEAD;
			hero.m_stateWeapon	= Monster::StateWeapon::WEAPON_STATE_DEAD;

			if (++m_countElementInVector == 5)
			{
				m_statePhysic = PhysicComponent::StatePhysic::PHYSIC_NOTHING;
				m_countElementInVector = 0;
			}

			m_statePhysic = StatePhysic::PHYSIC_NOTHING;

			break;
		}
		case StatePhysic::PHYSIC_KILL_HERO:
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
		m_statePhysic = PHYSIC_KILL_ENEMY;
		m_positionCollision = _a->getPosition();
		CCLOG("Collision");
	}

	return true;
}

PhysicComponent::~PhysicComponent()
{

}