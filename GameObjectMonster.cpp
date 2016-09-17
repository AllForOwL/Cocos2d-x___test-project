#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"

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
	m_monster = new BreedGraphicComponent(*CreateNewMonster());
}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateEnemy)
	{
		case Monster::StateEnemy::ENEMY_STATE_ATTACK:
		{
			/*int _x;
			int _y;
			for (int i = 0; i < CNT_COUNT_OBJECT; i++)
			{
				m_monsterComponent[i]->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDieBoy[m_countInVector]));
				_x = m_monsterComponent[i]->getPosition().x;
				_y = m_monsterComponent[i]->getPosition().y;
				m_monsterComponent[i]->setPosition(++_x,
													//_y += rand() % 10 + 1
													_y + i);
			}
			if (++m_countInVector == 4)
			{
				m_countInVector = 0;
			}
			*/
			
			if (m_monsterComponent.size() > 0)
			{
				/*int _x = m_monsterComponent[0]->getPosition().x;
				int	_y = m_monsterComponent[0]->getPosition().y;

				m_monsterComponent[0]->setPosition(_x - 5, _y);*/
			}
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_FIRE:
		{
			
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_REST:
		{
			
			/*for (int i = 0; i < CNT_COUNT_OBJECT; i++)
			{
				scene.addChild(m_monsterComponent[i]);
			}*/
						
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_DEAD:
		{
			break;
		}
	}
}

BreedGraphicComponent* GameObjectMonster::CreateNewMonster()
{
	return new BreedGraphicComponent(100, 150, std::string("jump.png"));
}

void GameObjectMonster::Spawner(GameScene& scene)
{
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	m_monster = new BreedGraphicComponent(*CreateNewMonster());
	m_monster->setScale(_visibleSize.width / m_monster->getContentSize().width / 6,
		_visibleSize.height / m_monster->getContentSize().height / 4);
	m_monster->setPosition(250 + m_monsterComponent.size(), 50);
	m_monster->setTag(m_monsterComponent.size());
	m_monsterComponent.push_back(m_monster);
	
	scene.addChild(m_monster);
}

GameObjectMonster::~GameObjectMonster()
{

}