#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "HellGraphicComponent.h"
#include "WeaponGraphicComponent.h"
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
	Vec2 origin			= Director::getInstance()->getVisibleOrigin();

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

	/*auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("explosion_bullet.plist");

	Vector<cocos2d::SpriteFrame*> frame;
	frame.reserve(5);
	frame.pushBack(SpriteFrame::create("13_5.png", Rect(0, 0, 32, 33)));
	frame.pushBack(SpriteFrame::create("13_4.png", Rect(0, 0, 32, 33)));
	frame.pushBack(SpriteFrame::create("13_3.png", Rect(0, 0, 32, 33)));
	frame.pushBack(SpriteFrame::create("13_2.png", Rect(0, 0, 32, 33)));
	frame.pushBack(SpriteFrame::create("13_1.png", Rect(0, 0, 32, 33)));

	Animation* animation = Animation::createWithSpriteFrames(frame, 0.1f);
	Animate* animate = Animate::create(animation);
	*/

	//auto sprite = Sprite::create("AK47.png");
	//auto moveBy = MoveBy::create(10, Vec2(20, 0));
	//sprite->runAction(moveBy);

	//this->addChild(sprite);

	// Move sprite to position 50,10 in 2 seconds.
	//auto moveTo = MoveTo::create(2, Vec2(50, 10));
	//sprite->runAction(moveTo);

	// Move sprite 20 points to right in 2 seconds
	
	//sprite->runAction(RepeatForever::create(animate));
	//sprite->setPosition(100, 100);
	
	m_graphicComponentHero	= new HellGraphicComponent();
	m_graphicComponentHero->setPosition(_visibleSize.width  / m_graphicComponentHero->getContentSize().width + 100,
										_visibleSize.height / m_graphicComponentHero->getContentSize().height + 100);
	m_graphicComponentHero->setScale(_visibleSize.width / m_graphicComponentHero->getContentSize().width / 6,
									 _visibleSize.height / m_graphicComponentHero->getContentSize().height / 2);
	
	this->addChild(m_graphicComponentHero);
	
	std::string nameWeapon = "mi-71.png";
	m_graphicComponentWeapon = new WeaponGraphicComponent(200, nameWeapon);
	m_graphicComponentWeapon->setPosition(100, 50);
	m_graphicComponentWeapon->setScale(_visibleSize.width / m_graphicComponentWeapon->getContentSize().width / 6,
									   _visibleSize.height / m_graphicComponentWeapon->getContentSize().height / 2);
	
	this->addChild(m_graphicComponentWeapon);
	
	std::string nameBullet = "shuriken.png";
	m_graphicComponentBullet	= new BulletGraphicComponent(30, nameBullet); 
	m_graphicComponentBullet->setName("bullet");
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