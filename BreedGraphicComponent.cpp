#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "constants.h"

BreedGraphicComponent::BreedGraphicComponent(int attack, int health, const std::string& typeObject)
											: m_attack(attack),
											  m_health(health),
											  m_typeObject(typeObject)
{
	if (m_typeObject == CNT_NAME_ENEMY_SOLDIER)
	{
		LoadSpritesForSoldier();
		//// !!!!!!!!!!!!!!!!!!!!!!! paste correct name file WARNING!!!!!!!!!!!!!!!!//////////
		this->initWithFile("Soldier_.png");
		this->setPosition(200, 50);
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

	this->initWithFile(this->m_typeObject);

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
		case Monster::StateEnemy::ENEMY_STATE_FIRE:
		{
			if (++m_countSpritesInVectorShotFrontSoldier == 8)
			{
				m_countSpritesInVectorShotFrontSoldier = 0;
			}
			
			this->removeAllChildrenWithCleanup(true);
			this->addChild(m_vecSpritesShotFrontSoldier[m_countSpritesInVectorShotFrontSoldier]);

			break;
		}
		default:
			break;
	}
}

void BreedGraphicComponent::LoadSpritesForSoldier()
{
	auto spritecache = SpriteFrameCache::getInstance();
	
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