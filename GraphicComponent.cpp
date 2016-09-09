#include "GraphicComponent.h"
#include "Monster.h"

GraphicComponent::GraphicComponent()
{
	m_vecSpriteRun.push_back("run-0001.png");
	m_vecSpriteRun.push_back("run-0002.png");
	m_vecSpriteRun.push_back("run-0003.png");
	m_vecSpriteRun.push_back("run-0004.png");
	m_vecSpriteRun.push_back("run-0005.png");
	m_vecSpriteRun.push_back("run-0006.png");
	m_vecSpriteRun.push_back("run-0007.png");
	m_vecSpriteRun.push_back("run-0008.png");

	m_vecSpriteFall.push_back("fall-0001.png");
	m_vecSpriteFall.push_back("fall-0002.png");
	m_vecSpriteFall.push_back("fall-0003.png");

	m_vecSpriteDizzy.push_back("dizzy-0001.png");
	m_vecSpriteDizzy.push_back("dizzy-0002.png");
	m_vecSpriteDizzy.push_back("dizzy-0003.png");

	m_vecSpriteWalk.push_back("walk-0001.png");
	m_vecSpriteWalk.push_back("walk-0002.png");
	m_vecSpriteWalk.push_back("walk-0003.png");
	m_vecSpriteWalk.push_back("walk-0004.png");
	m_vecSpriteWalk.push_back("walk-0005.png");
	m_vecSpriteWalk.push_back("walk-0006.png");
	m_vecSpriteWalk.push_back("walk-0007.png");
	m_vecSpriteWalk.push_back("walk-0008.png");

	m_vecSpriteAttack.push_back("attack-0001.png");
	m_vecSpriteAttack.push_back("attack-0002.png");
	m_vecSpriteAttack.push_back("attack-0003.png");
	m_vecSpriteAttack.push_back("attack-0004.png");

	m_vecSpriteDie.push_back("die-0001.png");
	m_vecSpriteDie.push_back("die-0002.png");
	m_vecSpriteDie.push_back("die-0003.png");
}

void GraphicComponent::update(Monster& heroes, GraphicComponent& graphicComponent)
{

	m_vecSpriteWalk.push_back("walk-0001.png");
	m_vecSpriteWalk.push_back("walk-0002.png");
	m_vecSpriteWalk.push_back("walk-0003.png");
	m_vecSpriteWalk.push_back("walk-0004.png");
	m_vecSpriteWalk.push_back("walk-0005.png");
	m_vecSpriteWalk.push_back("walk-0006.png");
	m_vecSpriteWalk.push_back("walk-0007.png");
	m_vecSpriteWalk.push_back("walk-0008.png");

	int  _countSprite = heroes.GetCountSprite();
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	heroes.setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpriteWalk[_countSprite]));
	heroes.setPosition(_visibleSize.width / 2,
					   _visibleSize.height / 2);

	heroes.SetCountSprite(++_countSprite);
	if (_countSprite)
	{
		heroes.SetCountSprite(0);
	}
}

GraphicComponent::~GraphicComponent()
{

}