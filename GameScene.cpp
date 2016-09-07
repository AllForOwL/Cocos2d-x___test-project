#include "GameScene.h"
#include "constants.h"

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

	m_count = 0;

	m_background = Sprite::create("background.png");
	m_background->setPosition(visibleSize.width / 2,
							  visibleSize.height / 2);
	this->addChild(m_background);

	m_listSprite[0] = "run-0001.png";
	m_listSprite[1] = "run-0002.png";
	m_listSprite[2] = "run-0003.png";
	m_listSprite[3] = "run-0004.png";
	m_listSprite[4] = "run-0005.png";
	m_listSprite[5] = "run-0006.png";
	m_listSprite[6] = "run-0007.png";
	m_listSprite[7] = "run-0008.png";
	m_listSprite[8] = "jump.png";

	Breed temp_breed(150, 100, "imageCocosRed.png");
	m_Heroes = new Monster(temp_breed);

	m_spriteHeroes = Sprite::create(m_listSprite[0]);
	m_spriteHeroes->setPosition(visibleSize.width  / 2,
								visibleSize.height / 2);


	auto createHell = MenuItemFont::create("Create Hell",
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

	this->addChild(m_spriteHeroes);
	this->addChild(menu);

	this->schedule(schedule_selector(GameScene::DrawSprite), 0.1);
	this->scheduleUpdate();

	return true;
}

void GameScene::AddHeroes(cocos2d::Ref* ref)
{
	//this->removeAllChildrenWithCleanup(true);

	if (ref->_ID == m_ID_HELL)
	{
		Breed hell(150, 100, m_listSprite[0]);
		Monster* temp_Heroes	= new Monster(hell);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create(m_listSprite[0]);
	
		m_spriteHeroes->setPosition(100, 100);
		this->addChild(m_spriteHeroes);

		CCLOG("hell");
	}
	else if (ref->_ID == m_ID_FIRE_GIRL)
	{
		Breed fire_girl(100, 100, "imageCocosYellow.png");
		Monster* temp_Heroes	= new Monster(fire_girl);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create("imageCocosYellow.png");
		
		m_spriteHeroes->setPosition(100, 100);
		this->addChild(m_spriteHeroes);
	}
	else
	{
		Breed water_man(70, 100, "imageCocorRed.png");
		Monster* temp_Heroes	= new Monster(water_man);
		m_Heroes				= temp_Heroes;
		m_spriteHeroes			= Sprite::create("imageCocosYellow.png");

		m_spriteHeroes->setPosition(100, 100);
		this->addChild(m_spriteHeroes);
	}
}

void GameScene::update(float dt)
{
	auto position = m_background->getPosition();
	position.x -= 1;
	m_background->setPosition(position);
	//this->addChild(m_background);

	
//	this->addChild(m_spriteHeroes);

	CCLOG("update");
}

void GameScene::DrawSprite(float interval)
{
	if (m_count < 8)
	{
		++m_count;
	}
	else
	{
		m_count = 0;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	m_spriteHeroes->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_listSprite[m_count]));
	//mySprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("newImage.png"));
	m_spriteHeroes->setPosition(visibleSize.width / 2,
		visibleSize.height / 2);
}