#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "constants.h"

BreedGraphicComponent::BreedGraphicComponent(int attack, int health, std::string& filename)
											: m_attack(attack),
											  m_health(health),
											  m_filename(filename)
{
	this->initWithFile(m_filename);
									
	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	//physicsBody->setDynamic(false);
	physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(true);

	this->setPhysicsBody(physicsBody);
}

BreedGraphicComponent::BreedGraphicComponent(BreedGraphicComponent& breed)
{
	this->m_attack		= breed.GetAttack();
	this->m_health		= breed.GetHealth();
	this->m_filename	= breed.GetFilename();

	this->initWithFile(this->m_filename);

	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	//physicsBody->setDynamic(false);
	physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(true);

	this->setPhysicsBody(physicsBody);
}

/*virtual*/ void BreedGraphicComponent::Update(Monster& hero, GameScene& scene)
{

}

int BreedGraphicComponent::GetAttack() const
{
	return m_attack;
}

int BreedGraphicComponent::GetHealth() const
{
	return m_health;
}

std::string BreedGraphicComponent::GetFilename() const
{
	return m_filename;
}

BreedGraphicComponent::~BreedGraphicComponent()
{

}