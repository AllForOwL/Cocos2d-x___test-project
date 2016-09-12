#include "HellGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "GameScene.h"

HellGraphicComponent::HellGraphicComponent()
{
	this->initWithFile("walk-0001.png");
}

/*virtual*/void HellGraphicComponent::Update(Monster& hero, cocos2d::Sprite* _hero, GameScene& gameScene)
{
	Size _size = Director::getInstance()->getVisibleSize();
	//GraphicComponent* _graphic = new HellGraphicComponent();
	this->LoadSprites(EventKeyboard::KeyCode::KEY_RIGHT_ARROW);
	
	cocos2d::Sprite* m_hero = _hero;
	m_hero->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVector]));
	m_hero->setScale(_size.width / m_hero->getContentSize().width / 6,
					_size.height / m_hero->getContentSize().height / 2);
	m_hero->setPosition(_size.width / m_hero->getContentSize().width + 100,
	_size.height / m_hero->getContentSize().height + 100);

	//graphic = m_hero;
	//_hero->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVector]));
	
	if (++m_countSpriteInVector == 8)
	{
		m_countSpriteInVector = 0;
	}

	_hero = m_hero;

	gameScene.addChild(_hero);
}

/*virtual*/ void HellGraphicComponent::LoadSprites(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
													m_vecSpritesWalk.push_back("walk-0001.png");
													m_vecSpritesWalk.push_back("walk-0002.png");
													m_vecSpritesWalk.push_back("walk-0003.png");
													m_vecSpritesWalk.push_back("walk-0004.png");
													m_vecSpritesWalk.push_back("walk-0005.png");
													m_vecSpritesWalk.push_back("walk-0006.png");
													m_vecSpritesWalk.push_back("walk-0007.png");
													m_vecSpritesWalk.push_back("walk-0007.png");

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