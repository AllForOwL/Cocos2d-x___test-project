#include "GraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

GraphicComponent::GraphicComponent()
{
}

Monster& GraphicComponent::update(Monster& heroes, GameScene& gameScene)
{
	std::vector<std::string> m_vecSpriteRun;
	std::vector<std::string> m_vecSpriteFall;
	std::vector<std::string> m_vecSpriteDizzy;
	std::vector<std::string> m_vecSpriteWalk;
	std::vector<std::string> m_vecSpriteAttack;
	std::vector<std::string> m_vecSpriteDie;

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

	int  _countSprite = heroes.GetCountSprite();
	Size _visibleSize = Director::getInstance()->getVisibleSize();

	gameScene.removeAllChildrenWithCleanup(true);
	auto sprite = Sprite::create(m_vecSpriteWalk[_countSprite]);
	sprite->setScale(_visibleSize.width / sprite->getContentSize().width / 2,
					 _visibleSize.height / sprite->getContentSize().height / 2);

	sprite->setPosition(_visibleSize.width  / 2,
						_visibleSize.height / 2);

	gameScene.addChild(sprite);

	heroes.SetCountSprite(++_countSprite);

	if (_countSprite == 7)
	{
		heroes.SetCountSprite(0);
	}

	return heroes;
}

GraphicComponent::~GraphicComponent()
{

}