#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "HellGraphicComponent.h"
#include "AK47GraphicComponent.h"
#include "BulletGraphicComponent.h"
#include "BreedGraphicComponent.h"
#include "BotInputComponent.h"
#include "PhysicComponent.h"

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
	
	Size _visibleSize   = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	m_countSpriteInVector = 0;
	
	m_background = Sprite::create("background.png");
	m_background->setPosition(_visibleSize.width / 2,
							  _visibleSize.height / 2);
	
	this->addChild(m_background);

	auto edgeBody = PhysicsBody::createEdgeBox(_visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(SCENE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(_visibleSize.width / 2 + origin.x, _visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

	m_graphicComponentHero	= new HellGraphicComponent();
	m_graphicComponentHero->setPosition(_visibleSize.width  / m_graphicComponentHero->getContentSize().width + 100,
										_visibleSize.height / m_graphicComponentHero->getContentSize().height + 100);
	m_graphicComponentHero->setScale(_visibleSize.width / m_graphicComponentHero->getContentSize().width / 6,
									 _visibleSize.height / m_graphicComponentHero->getContentSize().height / 2);
	
	this->addChild(m_graphicComponentHero);

	m_graphicComponentWeapon = new AK47GraphicComponent();
	m_graphicComponentWeapon->setPosition(100, 50);
	m_graphicComponentWeapon->setScale(_visibleSize.width / m_graphicComponentWeapon->getContentSize().width / 6,
									   _visibleSize.height / m_graphicComponentWeapon->getContentSize().height / 2);
	
	this->addChild(m_graphicComponentWeapon);

	m_graphicComponentBullet	= new BulletGraphicComponent();
	this->addChild(m_graphicComponentBullet);

	m_inputComponent			= new PlayerInputComponent();
	m_gameObjectMonster			= new GameObjectMonster();
	m_botInputComponent			= new BotInputComponent();
	m_physicComponent			= new PhysicComponent();
	m_hero						= new Monster(m_graphicComponentHero, m_graphicComponentWeapon, m_graphicComponentBullet, m_gameObjectMonster, m_inputComponent, m_botInputComponent, m_physicComponent);
	
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(InputComponent::onKeyPressed, m_inputComponent);
	//listener->onKeyReleased = CC_CALLBACK_2(InputComponent::onKeyReleased, inputComponent);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicComponent::onContactBegin, m_physicComponent);
	
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	this->schedule(schedule_selector(GameScene::update), 0.1);
	this->schedule(schedule_selector(GameScene::Spawn),  5);
	this->scheduleUpdate();

	/*SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy.plist");

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 visibleSize = Director::getInstance()->getVisibleSize();

	// background
	auto background = Sprite::createWithSpriteFrameName("background.png");
	background->setPosition(origin.x + visibleSize.x / 2, origin.y + visibleSize.y / 2);
	this->addChild(background);*/

	return true;
}

void GameScene::update(float dt)
{
	auto position = m_background->getPosition();
	m_background->setPosition(--position.x, position.y);

	m_hero->Update(*this);
}

void GameScene::Spawn(float dt)
{
	m_gameObjectMonster->Spawner(*this);
}

GameScene::~GameScene()
{

}