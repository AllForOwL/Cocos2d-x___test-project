#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "Weapon.h"

USING_NS_CC;

Scene *GameScene::createScene() 
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())	// if layer not create exit from function
	{
		return false;
	}
	
	Size visibleSize   = Director::getInstance()->getVisibleSize();
	Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();

	m_vecSpritesWalk.push_back("walk-0001.png");
	m_vecSpritesWalk.push_back("walk-0002.png");
	m_vecSpritesWalk.push_back("walk-0003.png");
	m_vecSpritesWalk.push_back("walk-0004.png");
	m_vecSpritesWalk.push_back("walk-0005.png");
	m_vecSpritesWalk.push_back("walk-0006.png");
	m_vecSpritesWalk.push_back("walk-0007.png");
	m_vecSpritesWalk.push_back("walk-0007.png");

	m_countSpriteInVector = 0;

	m_background = Sprite::create("background.png");
	m_background->setPosition(visibleSize.width / 2,
							  visibleSize.height / 2);

	this->addChild(m_background);
	
	//m_spriteHero = Sprite::create("walk-0001.png"); 
	//this->addChild(m_spriteHero);
	
	m_graphicComponent	= new HellGraphicComponent();
	m_graphicComponent->setScale(visibleSize.width / m_graphicComponent->getContentSize().width / 6,
								 visibleSize.height /  m_graphicComponent->getContentSize().height / 2);
	m_graphicComponent->setPosition(visibleSize.width / m_graphicComponent->getContentSize().width + 100,
									visibleSize.height / m_graphicComponent->getContentSize().height + 100);
									
	this->addChild(m_graphicComponent);

	//m_inputComponent	= new PlayerInputComponent();
	//m_hero				= new Monster(m_graphicComponent, m_inputComponent);

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float dt)
{
	m_graphicComponent->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVector]));
	
	if (++m_countSpriteInVector == 8)
	{
		m_countSpriteInVector = 0;
	}
}