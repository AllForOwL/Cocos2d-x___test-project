#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "HeroGraphicComponent.h"
#include "WeaponGraphicComponent.h"
#include "PlayerBulletGraphicComponent.h"
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

	m_countLevel = 0;
	m_countSpriteInVector = 0;
	
	LoadFileBackground();

	auto edgeBody = PhysicsBody::createEdgeBox(_visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(SCENE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(_visibleSize.width / 2 + origin.x, _visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

	m_graphicComponentHero	= new HeroGraphicComponent(CNT_NAME_HERO_HELL);
	m_graphicComponentHero->setPosition(_visibleSize.width  / m_graphicComponentHero->getContentSize().width + 100,
										_visibleSize.height / m_graphicComponentHero->getContentSize().height + 100);
	m_graphicComponentHero->setScale(_visibleSize.width / m_graphicComponentHero->getContentSize().width / 6,
									 _visibleSize.height / m_graphicComponentHero->getContentSize().height / 4);
	
	this->addChild(m_graphicComponentHero);
	
	m_graphicComponentWeapon = new WeaponGraphicComponent(200, CNT_NAME_WEAPON_AK47);
	m_graphicComponentWeapon->setPosition(m_graphicComponentHero->getPosition().x, m_graphicComponentHero->getPosition().y - 20);
	m_graphicComponentWeapon->setScale(_visibleSize.width / m_graphicComponentWeapon->getContentSize().width / 10,
									   _visibleSize.height / m_graphicComponentWeapon->getContentSize().height / 10);
	
	this->addChild(m_graphicComponentWeapon);
	
	m_graphicComponentBullet	= new PlayerBulletGraphicComponent(101, CNT_NAME_BULLET_DEFAULT); 
	//m_graphicComponentBullet->setPosition(m_graphicComponentWeapon->getPosition().x + m_graphicComponentWeapon->getContentSize().width / 10 / 2,
	//										m_graphicComponentWeapon->getPosition().y);
	m_graphicComponentBullet->setScale(_visibleSize.width / m_graphicComponentBullet->getContentSize().width / 40,
										_visibleSize.height / m_graphicComponentBullet->getContentSize().height  / 40
										);

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

	this->schedule(schedule_selector(GameScene::update), CNT_TIME_UPDATE_SCENE);
	this->schedule(schedule_selector(GameScene::Spawn),  CNT_TIME_SPAWN);
	//this->scheduleUpdate();
	
	return true;
}

void GameScene::update(float dt)
{
	auto position = m_vecBackground[m_countLevel]->getPosition();
	m_vecBackground[m_countLevel]->setPosition(--position.x, position.y);

	m_hero->Update(*this);
}

void GameScene::Spawn(float dt)
{
	m_gameObjectMonster->Spawner(*this);
}

void GameScene::LoadFileBackground()
{
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("Backgrounds.plist");
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("1-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("2-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("2.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("3-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("4-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("4.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("5-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("5.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("6-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("6.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("7-night.png"));
	m_vecBackground.push_back(Sprite::createWithSpriteFrameName("7.png"));

	Size _visibleSize = Director::getInstance()->getVisibleSize();
	m_vecBackground[m_countLevel]->setPosition(_visibleSize.width / 2, _visibleSize.height / 2);
	m_widthBackground = m_vecBackground[m_countLevel]->getContentSize().width / 2;
	m_vecBackground[m_countLevel]->setName("background");

	this->addChild(m_vecBackground[m_countLevel]);
}

void GameScene::LoadLevel()
{
	m_vecBackground[m_countLevel]->removeFromParent();
	++m_countLevel;
	this->addChild(m_vecBackground[m_countLevel]);
}

GameScene::~GameScene()
{

}