#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "constants.h"

GameObjectMonster::GameObjectMonster()
{

}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	if (m_monsterComponent.size())
	{
		for (int i = 0; i < m_monsterComponent.size(); i++)
		{
			m_monsterComponent[i]->Update(hero, scene);
		}
	}
}

void GameObjectMonster::Spawner(GameScene& scene)
{
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	int _randomValue = rand() % 3 + 1;

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

		int _width	= m_monster->getContentSize().width;
		int _height = m_monster->getContentSize().height;

		m_monster->setScale(_visibleSize.width / _width / 6,
							_visibleSize.height / _height / 4);

		m_monster->setPosition(300, 100);
		m_monster->setName(_typeObject);
		m_monsterComponent.push_back(m_monster);
	}

	scene.addChild(m_monsterComponent[m_monsterComponent.size() - 1]);
}

GameObjectMonster::~GameObjectMonster()
{
	
}