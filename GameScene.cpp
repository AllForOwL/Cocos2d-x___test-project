#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "HellGraphicComponent.h"
#include "AK47GraphicComponent.h"
#include "BulletGraphicComponent.h"
#include "BreedGraphicComponent.h"

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
	Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();

	m_countSpriteInVector = 0;

	m_background = Sprite::create("background.png");
	m_background->setPosition(_visibleSize.width / 2,
							  _visibleSize.height / 2);
	this->addChild(m_background);

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

	m_graphicComponentBullet = new BulletGraphicComponent();
	this->addChild(m_graphicComponentBullet);

	m_inputComponent	= new PlayerInputComponent();
	
	m_gameObjectMonster = new GameObjectMonster();
	m_hero				= new Monster(m_graphicComponentHero, m_graphicComponentWeapon, m_graphicComponentBullet, m_gameObjectMonster, m_inputComponent);

	//m_objectMonster = new BreedGraphicComponent(100, 150, std::string("darksaber_attack0077.png"));
	//m_objectMonster->setPosition(200, 250);
	//this->addChild(m_objectMonster);

	
	m_hero->Update(*this);

	//m_gameObjectMonster->Update(*m_hero, *this);

	//auto listener = EventListenerKeyboard::create();
	//listener->onKeyPressed = CC_CALLBACK_2(InputComponent::onKeyPressed, m_inputComponent);
	//listener->onKeyReleased = CC_CALLBACK_2(InputComponent::onKeyReleased, inputComponent);
	
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	//this->schedule(schedule_selector(GameScene::update), 50);
	//this->scheduleUpdate();

	return true;
}

void GameScene::update(float dt)
{
	auto position = m_background->getPosition();
	m_background->setPosition(--position.x, position.y);

	m_hero->Update(*this);
}

GameScene::~GameScene()
{

}