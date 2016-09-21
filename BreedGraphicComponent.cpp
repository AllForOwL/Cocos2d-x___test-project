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

BreedGraphicComponent::BreedGraphicComponent(BreedGraphicComponent& breed)
{
	this->m_attack		= breed.GetAttack();
	this->m_health		= breed.GetHealth();
	this->m_typeObject	= breed.GetTypeObject();

	if (m_typeObject == CNT_NAME_ENEMY_SOLDIER)
	{
		LoadSpritesForSoldier();
		this->initWithFile(m_vecDefaultNamesAttack[m_countDefaultSpriteInAttack]);
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
	switch (hero.m_stateEnemy)
	{
			case Monster::StateEnemy::ENEMY_STATE_MOVE:
			{
				if (m_vecDefaultNamesMove.size() == 0)
				{
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;
					break;
				}

				if (++m_countDefaultSpriteInMove == m_vecDefaultNamesMove.size())
				{
					m_countDefaultSpriteInMove = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesMove[m_countDefaultSpriteInMove]));
				break;
			}
			case Monster::StateEnemy::ENEMY_STATE_ATTACK:
			{
				if (++m_countDefaultSpriteInAttack == m_vecDefaultNamesAttack.size())
				{
					m_countDefaultSpriteInAttack = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_DEATH;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesAttack[m_countDefaultSpriteInAttack]));

				break;
			}
			case Monster::StateEnemy::ENEMY_STATE_FIRE:
			{
				if (++m_countDefaultSpriteInFire == m_vecDefaultNamesFire.size())
				{
					m_countDefaultSpriteInFire = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_DEATH;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesFire[m_countDefaultSpriteInFire]));
			
				break;
			}
			case Monster::StateEnemy::ENEMY_STATE_DEATH:
			{
				if (++m_countDefaultSpriteInDeath == m_vecDefaultNamesDeath.size())
				{
					m_countDefaultSpriteInDeath = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_MOVE;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDefaultNamesDeath[m_countDefaultSpriteInDeath]));

				break;
			}
			default:
				break;
	}
	
	//this->setRotationX(0);
	//this->setRotationY(180);
}

void BreedGraphicComponent::LoadSpritesForSoldier()
{
	m_countDefaultSpriteInMove		= 0;
	m_countDefaultSpriteInAttack	= 0;
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

/*	m_countSpritesInVectorShotFrontSoldier	= 0;
	m_countSpritesInVectorShotUpSoldier		= 0;
	m_countSpritesInVectorWalkSoldier		= 0;

	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_1.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_2.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_3.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_4.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_5.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_6.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_7.png");
	m_vecSpritesNamesWalkSoldier.push_back("Soldier1_walk_8.png");

	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_1.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_2.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_3.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_4.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_5.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_6.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_7.png");
	m_vecSpritesNamesShotFrontSoldier.push_back("Soldier1_shot_front_8.png");

	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_1.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_2.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_3.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_4.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_5.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_6.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_7.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_8.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_9.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_10.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_11.png");
	m_vecSpritesNamesShotUpSoldier.push_back("Soldier1_shot_up_12.png");

	*/
	/*auto spritecache = SpriteFrameCache::getInstance();
	
	spritecache->addSpriteFramesWithFile("soldier.plist");
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_1.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_2.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_3.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_4.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_5.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_6.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_7.png"));
	m_vecSpritesWalkSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_walk_8.png"));

	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_1.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_2.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_3.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_4.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_5.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_6.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_7.png"));
	m_vecSpritesShotFrontSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_front_8.png"));

	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_1.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_2.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_3.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_4.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_5.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_6.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_7.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_8.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_9.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_10.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_11.png"));
	m_vecSpritesShotUpSoldier.push_back(Sprite::createWithSpriteFrameName("Soldier1_shot_up_12.png"));
	*/
}

void BreedGraphicComponent::LoadSpritesForTanks()
{
	m_countDefaultSpriteInMove		= 0;
	m_countDefaultSpriteInAttack	= 0;
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

	m_vecDefaultNamesAttack.push_back("American_sherman_attack_1.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_2.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_3.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_4.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_5.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_6.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_7.png");
	m_vecDefaultNamesAttack.push_back("American_sherman_attack_8.png");

	m_vecDefaultNamesDeath.push_back("American_sherman_death_1.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_2.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_3.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_4.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_5.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_6.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_7.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_8.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_9.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_10.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_11.png");
	m_vecDefaultNamesDeath.push_back("American_sherman_death_12.png");
}

void BreedGraphicComponent::LoadSpritesForTurrets()
{

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