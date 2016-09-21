#include "Monster.h"
#include "BotBulletGraphicComponent.h"
#include "PlayerInputComponent.h"
#include "GameScene.h"
#include "constants.h"
#include "GameObjectMonster.h"

BotBulletGraphicComponent::BotBulletGraphicComponent(int attack, const std::string& typeObject)
														: m_attack		(attack),
														  m_typeObject	(typeObject)
{
	auto physicBody = PhysicsBody::createBox(this->getContentSize());
	physicBody->setContactTestBitmask(true);
	physicBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);

	this->setPhysicsBody(physicBody);

	if (m_typeObject == CNT_NAME_BULLET_DEFAULT)
	{
		LoadBulletNormal();
		this->initWithFile(m_strFilename);
	}
	else if (m_typeObject == CNT_NAME_BOMB)
	{
		LoadBomb();
		this->initWithFile(m_strFilename);
	}
}

BotBulletGraphicComponent::BotBulletGraphicComponent(BotBulletGraphicComponent& bullet)
{
	auto physicBody = PhysicsBody::createBox(this->getContentSize());
	physicBody->setContactTestBitmask(true);
	physicBody->setCollisionBitmask(BULLET_COLLISION_BITMASK);
	
	this->m_attack		= bullet.GetAttack();
	this->m_typeObject	= bullet.GetTypeObject();
	this->m_position	= cocos2d::Point::ZERO;

	this->setPhysicsBody(physicBody);

	if (m_typeObject == CNT_NAME_BULLET_DEFAULT)
	{
		LoadBulletNormal();
		this->initWithFile(m_strFilename);
	}
	else if (m_typeObject == CNT_NAME_BOMB)
	{
		LoadBomb();
		this->initWithFile(m_strFilename);
	}
}

int BotBulletGraphicComponent::GetAttack() const
{
	return m_attack;
}

std::string BotBulletGraphicComponent::GetTypeObject() const
{
	return m_typeObject;
}

/*virtual*/ void BotBulletGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_objectMonster->m_stateBullet)
	{
		case GameObjectMonster::StateBullet::STATE_FIRE:
		{
			Vec2 _position = this->getPosition();															
			this->setPosition(++_position.x, _position.y);

			break;
		}
		case GameObjectMonster::StateBullet::STATE_FIRE_UP:
		{
			Vec2 _position = this->getPosition();
			Size _visibleSize = Director::getInstance()->getVisibleSize();

			if (_position.x >= _visibleSize.width / 2)
			{
				_position.y += 2;
				this->setPosition(--_position.x, _position.y);
			}
			else
			{
				_position.y -= 2;
				this->setPosition(--_position.x, _position.y);
			}

			break;
		}
		case GameObjectMonster::StateBullet::STATE_FIRE_BOMB:
		{

			break;
		}

		default:
			break;
	}
}

void BotBulletGraphicComponent::LoadBulletNormal()
{
	m_position = Point::ZERO;
	m_strFilename = "Bullet.png";
}

void BotBulletGraphicComponent::LoadBomb()
{
	m_position = Point::ZERO;
	m_strFilename = "Bomb.png";
}

BotBulletGraphicComponent::~BotBulletGraphicComponent()
{

}