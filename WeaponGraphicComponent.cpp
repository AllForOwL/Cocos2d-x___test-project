#include "WeaponGraphicComponent.h"

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
}

/*virtual*/ void WeaponGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	
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