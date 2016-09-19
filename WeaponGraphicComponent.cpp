#include "WeaponGraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

WeaponGraphicComponent::WeaponGraphicComponent(int attack, std::string& filename)
												: m_attack  (attack),
												  m_filename(filename)
{
	this->initWithFile(m_filename);
}

WeaponGraphicComponent::WeaponGraphicComponent(WeaponGraphicComponent& weapon)
{
	this->m_attack   = weapon.GetAttack();
	this->m_filename = weapon.GetFilename();
	
	this->initWithFile(m_filename);

	Size _visibleSize = Director::getInstance()->getVisibleSize();
	this->setScale(_visibleSize.width / this->getContentSize().width / 6,
		_visibleSize.height / this->getContentSize().height / 2);
	this->setPosition(100, 50);
}

/*virtual*/ void WeaponGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateWeapon)
	{
		case Monster::StateWeapon::WEAPON_STATE_FIRE:
		{
		
			break;
		}
		case Monster::StateWeapon::WEAPON_STATE_FIRE_UP:
		{

			break;
		}
		case Monster::StateWeapon::WEAPON_STATE_REST:
		{

			break;
		}
	default:
		break;
	}
}

int WeaponGraphicComponent::GetAttack() const
{
	return m_attack;
}

std::string WeaponGraphicComponent::GetFilename() const
{
	return m_filename;
}

WeaponGraphicComponent::~WeaponGraphicComponent()
{

}