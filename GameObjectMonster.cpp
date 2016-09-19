#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "constants.h"

const int CNT_COUNT_OBJECT = 10;

GameObjectMonster::GameObjectMonster()
{
	/*Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	m_monsterComponent.resize(CNT_COUNT_OBJECT);
	for (int i = 0; i < CNT_COUNT_OBJECT; i++)
	{
		m_monsterComponent[i] = new BreedGraphicComponent(*CreateNewMonster());
		m_monsterComponent[i]->setScale(_visibleSize.width / m_monsterComponent[i]->getContentSize().width / 6,
			_visibleSize.height / m_monsterComponent[i]->getContentSize().height / 4);
		m_monsterComponent[i]->setPosition(150 + i * 30, 100);
	}

	m_vecDieBoy.push_back("die-0001.png");
	m_vecDieBoy.push_back("die-0002.png");
	m_vecDieBoy.push_back("die-0003.png");
	m_vecDieBoy.push_back("die-0004.png");
	m_countInVector = 0;

	*/
	
	m_vecSpritesAirplanesRest.push_back("AEG_CIV_default.png");
	
	m_vecSpritesAirplanesAttack.push_back("AEG_CIV_attack_1.png");
	m_vecSpritesAirplanesAttack.push_back("AEG_CIV_attack_1.png");

	m_vecSpritesAirplanesDead.push_back("AEG_CIV_death_1.png");
	m_vecSpritesAirplanesDead.push_back("AEG_CIV_death_2.png");
	m_vecSpritesAirplanesDead.push_back("AEG_CIV_death_3.png");
	m_vecSpritesAirplanesDead.push_back("AEG_CIV_death_4.png");

	m_vecSpritesBoyWalk.push_back("walk-0001.png");
	m_vecSpritesBoyWalk.push_back("walk-0002.png");
	m_vecSpritesBoyWalk.push_back("walk-0003.png");
	m_vecSpritesBoyWalk.push_back("walk-0004.png");
	m_vecSpritesBoyWalk.push_back("walk-0005.png");
	m_vecSpritesBoyWalk.push_back("walk-0006.png");
	m_vecSpritesBoyWalk.push_back("walk-0007.png");
	m_vecSpritesBoyWalk.push_back("walk-0008.png");

	m_vecSpritesBoyDeath.push_back("dizzy-0001.png");
	m_vecSpritesBoyDeath.push_back("dizzy-0002.png");
	m_vecSpritesBoyDeath.push_back("dizzy-0002.png");

	m_countSpriteInVectorAirplanesRest		= 0;
	m_countSpriteInVectorAirplanesAttack	= 0;
	m_countSpriteInVectorAirplanesDead		= 0;
	m_countInVectorBoyWalk					= 0;
	m_countInVectorBoyDeath					= 0;

	std::string filename = "attack-0001.png";
	m_monster = new BreedGraphicComponent(*CreateNewMonster(100, 100, filename));
}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateEnemy)
	{
		case Monster::StateEnemy::ENEMY_STATE_ATTACK:
		{
			if (m_monsterComponent.size() == 0) return;
			
			if (m_monsterComponent[0]->getTag() == CNT_TAG_AIRPLANE)
			{
				GoesAirplanes(m_vecSpritesAirplanesAttack[m_countSpriteInVectorAirplanesAttack]);
				if (++m_countSpriteInVectorAirplanesAttack > 1)
				{
					m_countSpriteInVectorAirplanesAttack = 0;
				}
			}
			else
			{
				GoesBoy(m_vecSpritesBoyWalk[m_countInVectorBoyWalk]);
				if (++m_countInVectorBoyWalk > 7)
				{
					m_countInVectorBoyWalk = 0;
				}
			}
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_FIRE:
		{
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_REST:
		{	
			GoesAirplanes(m_vecSpritesAirplanesRest[0]);
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_DEAD:
		{
			if (m_monsterComponent[0]->getTag() == CNT_TAG_AIRPLANE)
			{
				GoesAirplanes(m_vecSpritesAirplanesDead[m_countSpriteInVectorAirplanesDead]);
				if (++m_countSpriteInVectorAirplanesDead == 4)
				{
					m_countSpriteInVectorAirplanesDead = 0;
					scene.removeChildByTag(CNT_TAG_AIRPLANE);
					m_monsterComponent.pop_back();
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_NOTHING;
				}
			}
			else
			{
				GoesBoy(m_vecSpritesBoyDeath[m_countInVectorBoyDeath]);
				if (++m_countInVectorBoyDeath == 3)
				{
					m_countInVectorBoyDeath = 0;
					scene.removeChildByTag(CNT_TAG_BOY);
					m_monsterComponent.pop_back();
					hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_NOTHING;
				}
			}			
			break;
		}
	}
}

BreedGraphicComponent* GameObjectMonster::CreateNewMonster(int attack, int health, std::string& filename)
{
	return new BreedGraphicComponent(attack, health, std::string(filename));
}

void GameObjectMonster::GoesAirplanes(std::string& filename)
{
	for (int i = 0; i < m_monsterComponent.size(); i++)
	{
		Vec2 _positionAirplane = m_monsterComponent[i]->getPosition();
		m_monsterComponent[i]->setPosition(--_positionAirplane.x, _positionAirplane.y);
		m_monsterComponent[i]->setTexture(CCTextureCache::sharedTextureCache()->addImage(filename));

	}
}

void GameObjectMonster::GoesBoy(std::string& filename)
{
	for (int i = 0; i < m_monsterComponent.size(); i++)
	{
		Vec2 _positionAirplane = m_monsterComponent[i]->getPosition();
		//m_monsterComponent[i]->setPosition(--_positionAirplane.x, _positionAirplane.y);
		m_monsterComponent[i]->setTexture(CCTextureCache::sharedTextureCache()->addImage(filename));

	}
}

void GameObjectMonster::Spawner(GameScene& scene)
{
	if (m_monsterComponent.size() > 0)
	{
		return;
	}

	Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	int _randomValue = 1; // rand() % 1 + 0;

	if (_randomValue == 0)		// airplanes
	{
		int _attack				= 200;
		int _health				= 100;
		std::string _filename	= "AEG_CIV_attack_1.png";

		m_monster = new BreedGraphicComponent(*CreateNewMonster(_attack, _health, _filename));
		//m_monster->setRotationX(180);

		int _width	= m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;

		m_monster->setScale(_visibleSize.width / _width / 10,
							_visibleSize.height / _height / 6);

		m_monster->setPosition(_visibleSize.width - 30, _visibleSize.height - _visibleSize.height / _height / 6);
		m_monster->setTag(CNT_TAG_AIRPLANE);
		m_monster->setName("airplanes");
		m_monsterComponent.push_back(m_monster);
	}
	else if (_randomValue == 1)	// boy
	{
		int _attack = 100;
		int _health = 100;
		std::string _filename = "attack-0001.png";

		m_monster = new BreedGraphicComponent(*CreateNewMonster(_attack, _health, _filename));

		int _width  = m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;
		
		m_monster->setScale(_visibleSize.width / _width / 6,
			_visibleSize.height / _height / 2);

		m_monster->setPosition(300, 50);
		m_monster->setTag(CNT_TAG_BOY);
		m_monster->setName("boy");
		m_monsterComponent.push_back(m_monster);
	}

	scene.addChild(m_monsterComponent[m_monsterComponent.size() - 1]);
}

GameObjectMonster::~GameObjectMonster()
{
	
}