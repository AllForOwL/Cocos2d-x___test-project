#include "Monster.h"
#include "BulletGraphicComponent.h"
#include "PlayerInputComponent.h"
#include "GameScene.h"
#include "constants.h"

BulletGraphicComponent::BulletGraphicComponent()
{
	this->initWithFile("shuriken.png");
	
	auto physicBody = PhysicsBody::createBox(this->getContentSize());
//	physicBody->setDynamic(false);
	physicBody->setContactTestBitmask(true);
	physicBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);

	this->setPhysicsBody(physicBody);
	
	m_position = cocos2d::Point::ZERO;
}

/*virtual*/ void BulletGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateWeapon)
	{
		case Monster::StateWeapon::WEAPON_STATE_FIRE:
		{
			if (m_position == cocos2d::Point::ZERO)
			{
				m_position = hero.m_graphicComponentWeapon->getPosition();
			}
			else if (m_position < Director::getInstance()->getVisibleSize())
			{
				++m_position.x;
			}
			else
			{
				m_position = Point::ZERO;
				hero.m_stateWeapon = Monster::StateWeapon::WEAPON_STATE_REST;
			}
			setPosition(m_position);

			break;
		}
		case Monster::StateWeapon::WEAPON_STATE_DEAD:
		{
			m_position = cocos2d::Point::ZERO;
			this->setPosition(m_position);
			hero.m_stateWeapon = Monster::StateWeapon::WEAPON_STATE_REST;
			scene.addChild(this);

			break;
		}
	default:
		break;
	}
}

BulletGraphicComponent::~BulletGraphicComponent()
{

}