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
		this->initWithFile(m_vecSpritesNamesShotFrontSoldier[m_countSpritesInVectorShotFrontSoldier]);
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
		this->initWithFile(m_vecSpritesNamesShotFrontSoldier[m_countSpritesInVectorShotFrontSoldier]);
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
			case Monster::StateEnemy::ENEMY_STATE_ATTACK:
			{
				if (++m_countSpritesInVectorWalkSoldier == m_vecSpritesNamesWalkSoldier.size())
				{
					m_countSpritesInVectorWalkSoldier = 0;
					//hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_FIRE;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesNamesWalkSoldier[m_countSpritesInVectorWalkSoldier]));

				break;
			}
			case Monster::StateEnemy::ENEMY_STATE_FIRE:
			{
				if (++m_countSpritesInVectorShotFrontSoldier == m_vecSpritesNamesShotFrontSoldier.size())
				{
					m_countSpritesInVectorShotFrontSoldier = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesNamesShotFrontSoldier[m_countSpritesInVectorShotFrontSoldier]));
			
				break;
			}
			case Monster::StateEnemy::ENEMY_STATE_FIRE_UP:
			{
				if (++m_countSpritesInVectorShotUpSoldier == m_vecSpritesNamesShotUpSoldier.size())
				{
					m_countSpritesInVectorShotUpSoldier = 0;
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_FIRE_UP;
				}
				this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesNamesShotUpSoldier[m_countSpritesInVectorShotUpSoldier]));

				break;
			}
			default:
				break;
	}
}

void BreedGraphicComponent::LoadSpritesForSoldier()
{
	m_countSpritesInVectorShotFrontSoldier	= 0;
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