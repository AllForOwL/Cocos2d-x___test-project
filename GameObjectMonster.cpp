#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "WeaponGraphicComponent.h"
#include "BotBulletGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "constants.h"

GameObjectMonster::GameObjectMonster()
{

}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	if (m_vecComponentEnemy.size())
	{
		for (int i = 0; i < m_vecComponentEnemy.size(); i++)
		{
			m_vecComponentEnemy[i]->Update	(hero, scene);
			m_vecComponentWeapon[i]->Update	(hero, scene);
			m_vecComponentBullet[i]->Update	(hero, scene);
		}
	}
}

void GameObjectMonster::Spawner(GameScene& scene)
{
	if (m_vecComponentEnemy.size() > 0)
	{
		return;
	}

	Size _visibleSize = Director::getInstance()->getVisibleSize();
	
	int _randomValue = 1; // rand() % 3 + 1;

	if (_randomValue == 1)		// soldier
	{
		int _attackEnemy		= 200;
		int _attackWeapon		= 50;
		int _attackBullet		= 20;
		
		int _health				= 100;

		m_stateBullet	= GameObjectMonster::StateBullet::STATE_FIRE;

		std::string _typeObjectEnemy	= CNT_NAME_ENEMY_SOLDIER;
		std::string _typeObjectWeapon	= CNT_NAME_WEAPON_AK47;
		std::string _typeObjectBullet	= CNT_NAME_BULLET_DEFAULT;

		m_enemy		= new BreedGraphicComponent		(_attackEnemy, _health, _typeObjectEnemy);
		m_weapon	= new WeaponGraphicComponent	(_attackWeapon, _typeObjectWeapon); 
		m_bullet	= new BotBulletGraphicComponent	(_attackBullet, _typeObjectBullet);

		int _widthEnemy	 = m_enemy->getContentSize().width;
		int _heightEnemy = m_enemy->getContentSize().height;

		int _widthWeapon	= m_weapon->getContentSize().width;
		int _heightWeapon	= m_weapon->getContentSize().height;

		int _widthBullet	= m_bullet->getContentSize().width;
		int _heightBullet	= m_bullet->getContentSize().height;

		m_enemy->setScale(_visibleSize.width / _widthEnemy / 6,
						 _visibleSize.height / _heightEnemy / 4);
		m_weapon->setScale(_visibleSize.width / _widthWeapon / 6,
							_visibleSize.height / _heightWeapon / 4);
		m_bullet->setScale(_visibleSize.width / _widthBullet / 40,
							_visibleSize.height / _heightBullet / 40);

		m_enemy->setPosition	(350, 100);
		m_weapon->setPosition	(350, 80);
		m_bullet->setPosition	(300, 80);

		m_enemy->setName	(_typeObjectEnemy);
		m_weapon->setName	(_typeObjectWeapon);
		m_bullet->setName	(_typeObjectBullet);

		m_vecComponentEnemy.push_back	(m_enemy);
		m_vecComponentWeapon.push_back	(m_weapon);
		m_vecComponentBullet.push_back	(m_bullet);
	}
	else if (_randomValue == 2)	// tank
	{
		int _attackEnemy	= 300;
		int _attackBullet	= 120;
		
		int _health = 100;
		
		std::string _typeObjectEnemy	= CNT_NAME_ENEMY_TANK;
		std::string _typeObjectBullet	= CNT_NAME_BULLET_DEFAULT;

		m_enemy		= new BreedGraphicComponent(_attackEnemy, _health, _typeObjectEnemy);
		m_bullet	= new BotBulletGraphicComponent(_attackBullet, _typeObjectBullet); 

		int _widthEnemy  = m_enemy->getContentSize().width;
		int _heightEnemy = m_enemy->getContentSize().height;
		
		int _widthBullet	= m_bullet->getContentSize().width;
		int _heightBullet	= m_bullet->getContentSize().height;

		m_enemy->setScale(_visibleSize.width / _widthEnemy / 6,
							_visibleSize.height / _heightEnemy / 4);
		m_enemy->setScale(_visibleSize.width / _widthBullet / 6,
						  _visibleSize.height / _heightBullet / 4);

		m_enemy->setPosition(300, 50);
		m_bullet->setPosition(300 - _widthEnemy, 50);

		m_enemy->setName(_typeObjectEnemy);
		m_bullet->setName(_typeObjectBullet);

		m_vecComponentEnemy.push_back(m_enemy);
		m_vecComponentBullet.push_back(m_bullet);
	}
	else if (_randomValue == 3)	// turret
	{
		int _attackEnemy	= 200;
		int _attackBullet	= 80;
		
		int _health = 100;
		
		std::string _typeObjectEnemy	= CNT_NAME_ENEMY_TURRET;
		std::string _typeObjectBullet	= CNT_NAME_BULLET_DEFAULT; 

		m_enemy		= new BreedGraphicComponent(_attackEnemy, _health, _typeObjectEnemy);
		m_bullet	= new BotBulletGraphicComponent(_attackBullet, _typeObjectBullet);

		int _widthEnemy		= m_enemy->getContentSize().width;
		int _heightEnemy	= m_enemy->getContentSize().height;

		int _widthBullet	= m_bullet->getContentSize().width;
		int _heightBullet	= m_bullet->getContentSize().height;

		m_enemy->setScale(_visibleSize.width / _widthEnemy / 6,
							_visibleSize.height / _heightEnemy / 4);
		m_bullet->setScale(_visibleSize.width / _widthBullet / 6,
							_visibleSize.height / _heightBullet / 4);

		m_enemy->setPosition	(300,				100);
		m_bullet->setPosition	(300 - _widthEnemy, 50);

		m_enemy->setName	(_typeObjectEnemy);
		m_bullet->setName	(_typeObjectBullet);
		
		m_vecComponentEnemy.push_back	(m_enemy);
		m_vecComponentBullet.push_back	(m_bullet);
	}

	scene.addChild(m_vecComponentEnemy[m_vecComponentEnemy.size() - 1]);
	scene.addChild(m_vecComponentWeapon[m_vecComponentWeapon.size() - 1]);
	scene.addChild(m_vecComponentBullet[m_vecComponentBullet.size() - 1]);
}

GameObjectMonster::~GameObjectMonster()
{
	
}