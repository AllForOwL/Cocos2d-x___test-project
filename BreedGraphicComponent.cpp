#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"
#include "constants.h"

BreedGraphicComponent::BreedGraphicComponent(int attack, int health, const std::string& typeObject)
											: m_attack(attack),
											  m_health(health),
											  m_typeObject(typeObject)
{
	if (m_typeObject == CNT_NAME_ENEMY_SOLDIER)
	{
		LoadSpritesForSoldier();
		this->initWithFile(m_vecDefaultNamesMove[m_countDefaultSpriteInMove]);
		this->m_stateEnemy = StateEnemy::ENEMY_STATE_MOVE;
	}
	else if (m_typeObject == CNT_NAME_ENEMY_TANK)
	{
		LoadSpritesForTanks();
		this->initWithFile(m_vecDefaultNamesMove[m_countDefaultSpriteInMove]);
		this->m_stateEnemy = StateEnemy::ENEMY_STATE_FIRE;
	}
	else if (m_typeObject == CNT_NAME_ENEMY_TURRET)
	{
		LoadSpritesForTurrets();
		this->initWithFile(m_vecDefaultNamesFire[m_countDefaultSpriteInFire]);
		this->m_stateEnemy = StateEnemy::ENEMY_STATE_FIRE;
	}

	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(true);

	this->setPhysicsBody(physicsBody);
}

BreedGraphicComponent::BreedGraphicComponent(BreedGraphicComponent& breed)
{
	this->m_attack		= breed.GetAttack();
	this->m_health		= breed.GetHealth();
	this->m_typeObject	= breed.GetTypeObject();

	if (m_typeObject == CNT_NAME_ENEMY_SOLDIER)
	{
		LoadSpritesForSoldier();
		this->initWithFile(m_vecDefaultNamesFire[m_countDefaultSpriteInFire]);
	}
	else if (m_typeObject == CNT_NAME_ENEMY_TANK)
	{
		LoadSpritesForTanks();
		this->initWithFile(m_vecDefaultNamesMove[m_countDefaultSpriteInMove]);
	}

	auto physicsBody = PhysicsBody::createBox(this->getContentSize());
	//physicsBody->setDynamic(false);
	physicsBody->setCollisionBitmask(ENEMY_COLLISION_BITMASK);
	physicsBody->setContactTestBitmask(true);

	this->setPhysicsBody(physicsBody);
}

/*virtual*/ void BreedGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (this->m_stateEnemy)
	{
			case StateEnemy::ENEMY_STATE_FIRE:
			{
				Fire();			
				break;
			}
			case StateEnemy::ENEMY_STATE_MOVE:
			{
				Move();
				break;
			}
			case StateEnemy::ENEMY_STATE_DEATH:
			{
				Death();
				break;
			}
			default:
				break;
	}
}

void BreedGraphicComponent::Fire()
{
	if (++m_countDefaultSpriteInFire == m_vecDefaultNamesFire.size())
	{
		m_countDefaultSpriteInFire = 0;
	}
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesFire[m_countDefaultSpriteInFire]));
}

void BreedGraphicComponent::Move()
{
	if (this->GetTypeObject() == CNT_NAME_ENEMY_TURRET)
	{
		return;
	}

	if (++m_countDefaultSpriteInMove == m_vecDefaultNamesMove.size())
	{
		m_countDefaultSpriteInMove = 0;
	}
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesMove[m_countDefaultSpriteInMove]));
}

void BreedGraphicComponent::Death()
{
	if (this->GetTypeObject() != CNT_NAME_ENEMY_TANK)
	{
		return;
	}

	if (++m_countDefaultSpriteInDeath == m_vecDefaultNamesDeath.size())
	{
		m_countDefaultSpriteInDeath = 0;
	}
	this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesDeath[m_countDefaultSpriteInDeath]));
}

void BreedGraphicComponent::LoadSpritesForSoldier()
{
	m_countDefaultSpriteInMove		= 0;
	m_countDefaultSpriteInFire		= 0;
	m_countDefaultSpriteInDeath		= 0;

	m_vecDefaultNamesMove.push_back("Soldier1_walk_1.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_2.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_3.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_4.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_5.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_6.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_7.png");
	m_vecDefaultNamesMove.push_back("Soldier1_walk_8.png");

	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_1.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_2.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_3.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_4.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_5.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_6.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_7.png");
	m_vecDefaultNamesFire.push_back("Soldier1_shot_front_8.png");
}

void BreedGraphicComponent::LoadSpritesForTanks()
{
	m_countDefaultSpriteInMove		= 0;
	m_countDefaultSpriteInFire		= 0;
	m_countDefaultSpriteInDeath		= 0;

	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_1.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_2.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_3.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_4.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_5.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_6.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_7.png");
	m_vecDefaultNamesMove.push_back("American_sherman_move_forward_8.png");

	m_vecDefaultNamesFire.push_back("American_sherman_attack_1.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_2.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_3.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_4.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_5.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_6.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_7.png");
	m_vecDefaultNamesFire.push_back("American_sherman_attack_8.png");

	m_vecDefaultNamesDeath.push_back("American_sherman_death_1.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_2.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_3.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_4.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_5.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_6.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_7.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_8.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_9.png");
}

void BreedGraphicComponent::LoadSpritesForTurrets()
{
	m_countDefaultSpriteInMove		= 0;
	m_countDefaultSpriteInFire		= 0;
	m_countDefaultSpriteInDeath		= 0;

	m_vecDefaultNamesFire.push_back("turret_1_fire_1.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_2.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_3.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_4.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_5.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_6.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_7.png");
	m_vecDefaultNamesFire.push_back("turret_1_fire_8.png");
}

void BreedGraphicComponent::LoadSpritesForAirplanes()
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

std::string BreedGraphicComponent::GetTypeObject() const
{
	return m_typeObject;
}

BreedGraphicComponent::~BreedGraphicComponent()
{

}