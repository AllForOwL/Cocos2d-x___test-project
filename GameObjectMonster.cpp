#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "constants.h"

const int CNT_COUNT_OBJECT = 10;

GameObjectMonster::GameObjectMonster()
{
	//std::string s = "Soldier.png";

	//m_monster = new BreedGraphicComponent(*CreateNewMonster(100, 100, s));
}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	if (m_monsterComponent.size())
	{
		m_monsterComponent[0]->Update(hero, scene);
	}

/*	switch (hero.m_stateEnemy)
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
	}*/
}

BreedGraphicComponent* GameObjectMonster::CreateNewMonster(int attack, int health, std::string& typeObject)
{
	return new BreedGraphicComponent(attack, health, std::string(typeObject));
}

void GameObjectMonster::GoesAirplanes(std::string& filename)
{
	for (int i = 0; i < m_monsterComponent.size(); i++)
	{
		Vec2 _positionAirplane = m_monsterComponent[i]->getPosition();
		m_monsterComponent[i]->setTexture(CCTextureCache::sharedTextureCache()->addImage(filename));
	}
}

void GameObjectMonster::GoesBoy(std::string& filename)
{
	for (int i = 0; i < m_monsterComponent.size(); i++)
	{
		Vec2 _positionAirplane = m_monsterComponent[i]->getPosition();
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
	
	int _randomValue  = 1; //= rand() % 3 + 1;

	if (_randomValue == 1)		// soldier
	{
		int _attack				= 200;
		int _health				= 100;
		std::string _typeObject = CNT_NAME_ENEMY_SOLDIER;

		m_monster = new BreedGraphicComponent(_attack, _health, _typeObject);
		
		int _width	= m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;

		m_monster->setScale(_visibleSize.width / m_monster->getContentSize().width / 6,
			_visibleSize.height / m_monster->getContentSize().height / 4);

		m_monster->setPosition(350, 100);
		m_monster->setName(_typeObject);
		m_monsterComponent.push_back(m_monster);
	}
	else if (_randomValue == 2)	// tank
	{
		int _attack = 300;
		int _health = 100;
		std::string _typeObject = CNT_NAME_ENEMY_TANK;

		m_monster = new BreedGraphicComponent(_attack, _health, _typeObject);

		int _width  = m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;
		
		m_monster->setScale(_visibleSize.width / _width / 6,
			_visibleSize.height / _height / 4);

		m_monster->setPosition(300, 50);
		m_monster->setName(_typeObject);
		m_monsterComponent.push_back(m_monster);
	}
	else if (_randomValue == 3)	// turret
	{
		int _attack = 200;
		int _health = 100;
		std::string _typeObject = CNT_NAME_ENEMY_TURRET;

		m_monster = new BreedGraphicComponent(_attack, _health, _typeObject);

		int _width = m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;

		m_monster->setScale(_visibleSize.width / _width / 6,
			_visibleSize.height / _height / 4);

		m_monster->setPosition(300, 50);
		m_monster->setName(_typeObject);
		m_monsterComponent.push_back(m_monster);
	}

	scene.addChild(m_monsterComponent[0]);
}

GameObjectMonster::~GameObjectMonster()
{
	
}