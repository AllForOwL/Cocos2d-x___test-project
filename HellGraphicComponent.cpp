#include "HellGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "GameScene.h"

HellGraphicComponent::HellGraphicComponent()
{
	m_vecSpritesWalk.push_back("walk-0001.png");
	m_vecSpritesWalk.push_back("walk-0002.png");
	m_vecSpritesWalk.push_back("walk-0003.png");
	m_vecSpritesWalk.push_back("walk-0004.png");
	m_vecSpritesWalk.push_back("walk-0005.png");
	m_vecSpritesWalk.push_back("walk-0006.png");
	m_vecSpritesWalk.push_back("walk-0007.png");
	m_vecSpritesWalk.push_back("walk-0007.png");

	m_vecSpritesAttack.push_back("attack-0001.png");
	m_vecSpritesAttack.push_back("attack-0002.png");
	m_vecSpritesAttack.push_back("attack-0003.png");
	m_vecSpritesAttack.push_back("attack-0004.png");

	m_vecSpritesRun.push_back("run-0001.png");
	m_vecSpritesRun.push_back("run-0002.png");
	m_vecSpritesRun.push_back("run-0003.png");
	m_vecSpritesRun.push_back("run-0004.png");
	m_vecSpritesRun.push_back("run-0005.png");
	m_vecSpritesRun.push_back("run-0006.png");
	m_vecSpritesRun.push_back("run-0007.png");
	m_vecSpritesRun.push_back("run-0008.png");

	m_vecSpritesDie.push_back("die-0001.png");
	m_vecSpritesDie.push_back("die-0002.png");
	m_vecSpritesDie.push_back("die-0003.png");
	m_vecSpritesDie.push_back("die-0004.png");

	m_vecSpritesDizzy.push_back("dizzy-0001.png");
	m_vecSpritesDizzy.push_back("dizzy-0002.png");
	m_vecSpritesDizzy.push_back("dizzy-0003.png");

	m_countSpriteInVector = 0;

	this->initWithFile(m_vecSpritesWalk[m_countSpriteInVector]);
}

/*virtual*/void HellGraphicComponent::Update(Monster& hero)
{
	switch (hero.m_state)
	{
		case Monster::State::STATE_WALK:
		{
			if (++m_countSpriteInVector >= 8)
			{
				m_countSpriteInVector = 0;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVector]));
			break;
		}
		case Monster::State::STATE_ATTACK:
		{
			if (++m_countSpriteInVector >= 4)
			{
				m_countSpriteInVector = 0;
				hero.m_state = Monster::State::STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesAttack[m_countSpriteInVector]));
			break;
		}
		case Monster::State::STATE_JUMP:
		{
			if (++m_countSpriteInVector >= 3)
			{
				m_countSpriteInVector = 0;
				hero.m_state = Monster::State::STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesFall[m_countSpriteInVector]));
			break;
		}
	}
}

HellGraphicComponent::~HellGraphicComponent()
{

}

/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає діна з клавіатури
	Monster				- контейнер для цих компонентів
*/