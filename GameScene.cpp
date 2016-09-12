#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "HellGraphicComponent.h"
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

	m_countSpriteInVector = 0;

	m_background = Sprite::create("background.png");
	m_background->setPosition(visibleSize.width / 2,
							  visibleSize.height / 2);

	this->addChild(m_background);
	
	m_graphicComponent	= new HellGraphicComponent();
	m_graphicComponent->setScale(visibleSize.width / m_graphicComponent->getContentSize().width / 6,
								 visibleSize.height /  m_graphicComponent->getContentSize().height / 2);
	m_graphicComponent->setPosition(visibleSize.width / m_graphicComponent->getContentSize().width + 100,
									visibleSize.height / m_graphicComponent->getContentSize().height + 100);
									
	this->addChild(m_graphicComponent);

	m_inputComponent	= new PlayerInputComponent();
	m_hero				= new Monster(m_graphicComponent, m_inputComponent);


	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(InputComponent::onKeyPressed, m_inputComponent);
	//listener->onKeyReleased = CC_CALLBACK_2(InputComponent::onKeyReleased, inputComponent);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	this->schedule(schedule_selector(GameScene::update), 50);
	//this->scheduleUpdate();

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float dt)
{
	auto position = m_background->getPosition();
	m_background->setPosition(--position.x, position.y);

	m_hero->Update();
}