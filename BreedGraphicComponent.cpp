#include "BreedGraphicComponent.h"

BreedGraphicComponent::BreedGraphicComponent(int health, int attack, std::string& filename)
											: m_health(health),
											  m_attack(attack)	
{
	this->initWithFile(filename);
}

int BreedGraphicComponent::GetAttack() const
{
	return m_attack;
}

int BreedGraphicComponent::GetHealth() const
{
	return m_health;
}

BreedGraphicComponent::~BreedGraphicComponent()
{

}