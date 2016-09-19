#include "Monster.h"
#include "BulletGraphicComponent.h"
#include "PlayerInputComponent.h"
#include "GameScene.h"
#include "constants.h"

BulletGraphicComponent::BulletGraphicComponent(std::string& filename)
												: m_filename(filename)
{
	this->initWithFile(m_filename);
	this->setTag(CNT_TAG_BULLET);

	auto physicBody = PhysicsBody::createBox(this->getContentSize());
//	physicBody->setDynamic(false);
	physicBody->setContactTestBitmask(true);
	physicBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);

	this->setPhysicsBody(physicBody);
	
	m_position = cocos2d::Point::ZERO;
}

BulletGraphicComponent::BulletGraphicComponent(BulletGraphicComponent& bullet)
{
	this->setTag(CNT_TAG_BULLET);

	auto physicBody = PhysicsBody::createBox(this->getContentSize());
	physicBody->setContactTestBitmask(true);
	physicBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);
	
	this->m_filename = bullet.GetFilename();
	this->m_position = bullet.getPosition();

	this->setPhysicsBody(physicBody);
	this->initWithFile(m_filename);
}

std::string BulletGraphicComponent::GetFilename() const
{
	return m_filename;
}

/*virtual*/ void BulletGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateBullet)
	{
		case Monster::StateBullet::BULLET_STATE_FIRE:
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
		case Monster::StateBullet::BULLET_STATE_FIRE_UP:
		{
			if (m_position == cocos2d::Point::ZERO)
			{
				m_position = hero.m_graphicComponentWeapon->getPosition();
			}
			else if (m_position < Director::getInstance()->getVisibleSize())
			{
				++m_position.x;
				m_position.y += 2;
			}
			else
			{
				m_position = Point::ZERO;
				hero.m_stateWeapon = Monster::StateWeapon::WEAPON_STATE_REST;
			}
			setPosition(m_position);

			break;
		}
		case Monster::StateBullet::BULLET_STATE_DEAD:
		{
			m_position = cocos2d::Point::ZERO;
			this->setPosition(m_position);
			this->setTag(CNT_TAG_BULLET);
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