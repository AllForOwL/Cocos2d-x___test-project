#include "PhysicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

PhysicComponent::PhysicComponent()
{
	m_statePhysic = PHYSIC_NOTHING;
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
			spritecache->addSpriteFramesWithFile("cross.plist");

			auto mysprite = Sprite::createWithSpriteFrameName("7.png");
			
			
			//mysprite->setContentSize(mysprite->getContentSize().width / 4, mysprite->getContentSize().height);

			//auto sprite = mysprite->getContentSize();

			//auto newspriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("13 - Copie.png");
			//auto newSprite = Sprite::createWithSpriteFrame(newspriteFrame);


			// create the animation out of the frames
			//Animation* animation = Animation::createWithSpriteFrames(newspriteFrame, 0.1f);
			//Animate* animate = Animate::create(animation);

			// run it and repeat it forever
			//mysprite->runAction(RepeatForever::create(animate));

			scene.addChild(mysprite);

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
		CCLOG("Collision");
	}

	return true;
}

PhysicComponent::~PhysicComponent()
{

}