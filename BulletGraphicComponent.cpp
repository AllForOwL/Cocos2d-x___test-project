#include "Monster.h"
#include "BulletGraphicComponent.h"
#include "PlayerInputComponent.h"

BulletGraphicComponent::BulletGraphicComponent()
{
	this->initWithFile("shuriken.png");
	
	m_position = cocos2d::Point::ZERO;
}

/*virtual*/ void BulletGraphicComponent::Update(Monster& hero)
{
	switch (hero.m_stateWeapon)
	{
		case Monster::StateWeapon::STATE_FIRE:
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
				hero.m_stateWeapon = Monster::StateWeapon::STATE_REST;
			}
			setPosition(m_position);
			break;
		}
	default:
		break;
	}
}

BulletGraphicComponent::~BulletGraphicComponent()
{

}