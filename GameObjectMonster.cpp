#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"

GameObjectMonster::GameObjectMonster()
{
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	m_monsterComponent.resize(5);
	for (int i = 0; i < 5; i++)
	{
		m_monsterComponent[i] = new BreedGraphicComponent(*CreateNewMonster());
		m_monsterComponent[i]->setScale(_visibleSize.width / m_monsterComponent[i]->getContentSize().width / 6,
			_visibleSize.height / m_monsterComponent[i]->getContentSize().height / 4);
		m_monsterComponent[i]->setPosition(250 + i * 30, 100);
	}

	m_vecDieBoy.push_back("die-0001.png");
	m_vecDieBoy.push_back("die-0002.png");
	m_vecDieBoy.push_back("die-0003.png");
	m_vecDieBoy.push_back("die-0004.png");
	m_countInVector = 0;

}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateEnemy)
	{
		case Monster::StateEnemy::ENEMY_STATE_ATTACK:
		{
			for (int i = 0; i < 5; i++)
			{
				m_monsterComponent[i]->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecDieBoy[m_countInVector]));
			}
			if (++m_countInVector == 4)
			{
				m_countInVector = 0;
			}
			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_FIRE:
		{

			break;
		}
		case Monster::StateEnemy::ENEMY_STATE_REST:
		{
			for (int i = 0; i < 5; i++)
			{
				scene.addChild(m_monsterComponent[i]);
			}
			hero.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;

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

GameObjectMonster::~GameObjectMonster()
{
}