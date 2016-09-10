#include "GameScene.h"
#include "constants.h"
#include "InputComponent.h"
#include "GraphicComponent.h"

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

	m_count			= 0;
	m_createHeroes	= false;

	std::vector<std::string> m_vecSpriteRun;
	m_vecSpriteRun.push_back("walk-0001.png");

	m_background = Sprite::create("background.png");
	m_background->setPosition(visibleSize.width / 2,
							  visibleSize.height / 2);

	this->addChild(m_background);

	Breed				temp_breed(150, 100, "");
	InputComponent		inputComponent;
	GraphicComponent	graphicComponent;
	m_Heroes = new Monster(temp_breed, inputComponent, graphicComponent, *this);
	
	/*auto backOrig = Sprite::create("back_3200x2000.png");
	auto oWidth = backOrig->getContentSize().width;
	auto oHeight = backOrig->getContentSize().height;
	backOrig->setFlippedY(true);
	backOrig->setScale(vWidth / oWidth, vHeight / oHeight); // backOrig scaled to screen size
	backOrig->setPosition(vWidth / 2, vHeight / 2);
	*/
	
	/*auto createHell = MenuItemFont::create("Create Hell",
		CC_CALLBACK_1(GameScene::AddHeroes, this));
	createHell->setPosition(visibleSize.width / 2,
		visibleSize.height / 2);
	m_ID_HELL = createHell->_ID;

	auto createFireGirl = MenuItemFont::create("Create Fire-girl",
		CC_CALLBACK_1(GameScene::AddHeroes, this));
	createFireGirl->setPosition(visibleSize.width / 2,
		visibleSize.height / 2 - 30);
	m_ID_FIRE_GIRL = createFireGirl->_ID;

	auto createWaterMan = MenuItemFont::create("Create Water-Man",
		CC_CALLBACK_1(GameScene::AddHeroes, this));
	createWaterMan->setPosition(visibleSize.width / 2,
		visibleSize.height - 90);
	m_ID_WATER_MAN =  createWaterMan->_ID;

	auto menu = Menu::create(createHell, createFireGirl, createWaterMan, NULL);
	menu->setPosition(Point::ZERO);
	
	*/

	//this->addChild(m_spriteHeroes);
	//this->addChild(menu);

	// creating a keyboard event listener
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Monster::onKeyPressed, m_Heroes);
//	listener->onKeyReleased = CC_CALLBACK_2(InputComponent::onKeyReleased, inputComponent);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(GameScene::UpdateHeroes), 0.1);
	this->scheduleUpdate();
	
	return true;
}

void GameScene::AddHeroes(cocos2d::Ref* ref)
{
	/*m_createHeroes = true;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (ref->_ID == m_ID_HELL)
	{
		Breed hell(150, 100, m_listSprite[0]);
		Monster* temp_Heroes	= new Monster(hell);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create(m_listSprite[0]);

		m_spriteHeroes->setScale(visibleSize.width / m_spriteHeroes->getContentSize().width / 4,
			visibleSize.height / m_spriteHeroes->getContentSize().height / 2);
		m_spriteHeroes->setPosition(visibleSize.width / 2,
			visibleSize.height / 2);
		
		this->addChild(m_spriteHeroes);

		CCLOG("hell");
	}
	else if (ref->_ID == m_ID_FIRE_GIRL)
	{
		Breed fire_girl(100, 100, m_listSprite[0]);
		Monster* temp_Heroes	= new Monster(fire_girl);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create(m_listSprite[0]);

		m_spriteHeroes->setScale(visibleSize.width / m_spriteHeroes->getContentSize().width / 4,
			visibleSize.height / m_spriteHeroes->getContentSize().height / 2);
		m_spriteHeroes->setPosition(visibleSize.width / 2,
			visibleSize.height / 2);

		this->addChild(m_spriteHeroes);
	}
	else
	{
		Breed water_man(70, 100, m_listSprite[0]);
		Monster* temp_Heroes	= new Monster(water_man);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create(m_listSprite[0]);

		m_spriteHeroes->setScale(visibleSize.width / m_spriteHeroes->getContentSize().width / 4,
			visibleSize.height / m_spriteHeroes->getContentSize().height / 2);
		m_spriteHeroes->setPosition(visibleSize.width / 2,
			visibleSize.height / 2);

		this->addChild(m_spriteHeroes);
	}*/
}

void GameScene::update(float dt)
{
	Size _visibleSize = Director::getInstance()->getVisibleSize();

	int _x = m_background->getPosition().x;
	int _y = m_background->getPosition().y;

	if (_x - _visibleSize.width / 2 == m_background->getContentSize().width)
	{
		m_background->setPosition(_visibleSize.width / 2,
								  _visibleSize.height / 2);
	}
	else
	{
		m_background->setPosition(--_x, _y);
	}
}

void GameScene::UpdateHeroes(float dt)
{
	m_Heroes->Update(dt);
}

void GameScene::DrawSprite(float interval)
{
	//if (!m_createHeroes)
	//{
	//	return;
	//}
}