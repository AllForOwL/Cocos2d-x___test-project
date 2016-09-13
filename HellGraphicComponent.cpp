#include "HellGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "constants.h"

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

	m_countSpriteInVectorWalk		= 0;
	m_countSpriteInVectorAttack		= 0;
	m_countSpriteInVectorRun		= 0;

	this->initWithFile(m_vecSpritesWalk[m_countSpriteInVectorWalk]);
}

/*virtual*/void HellGraphicComponent::Update(Monster& hero)
{
	switch (hero.m_stateHero)
	{
		case Monster::StateHero::STATE_WALK:
		{
			if (++m_countSpriteInVectorWalk >= CNT_NUMBER_SPRITES_WALK)
			{
				m_countSpriteInVectorWalk = 0;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVectorWalk]));
			break;
		}
		case Monster::StateHero::STATE_ATTACK:
		{
			if (++m_countSpriteInVectorAttack >= CNT_NUMBER_SPRITES_ATTACK)
			{
				m_countSpriteInVectorAttack = 0;
				hero.m_stateHero = Monster::StateHero::STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesAttack[m_countSpriteInVectorAttack]));
			break;
		}
		case Monster::StateHero::STATE_RUN:
		{
			if (++m_countSpriteInVectorRun >= CNT_NUMBER_SPRITES_RUN)
			{
				m_countSpriteInVectorRun = 0;
				hero.m_stateHero = Monster::StateHero::STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesRun[m_countSpriteInVectorRun]));
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