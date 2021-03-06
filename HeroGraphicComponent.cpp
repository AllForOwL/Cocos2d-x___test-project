#include "HeroGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "constants.h"
#include "WeaponGraphicComponent.h"
#include "PlayerBulletGraphicComponent.h"

HeroGraphicComponent::HeroGraphicComponent(const std::string& typeHero) : m_typeHero(typeHero)
{
	this->setTag(0);
	if (m_typeHero == CNT_NAME_HERO_HELL)
	{
		LoadSpritesForHell();
		m_attack = 120;
		m_health = 100;
	}

	m_countSpriteInVectorWalk		= 0;
	m_countSpriteInVectorAttack		= 0;
	m_countSpriteInVectorRun		= 0;

	this->initWithFile(m_vecSpritesWalk[m_countSpriteInVectorWalk]);

	auto physicBodyHero = PhysicsBody::createBox(this->getContentSize());
	physicBodyHero->setContactTestBitmask(true);
	physicBodyHero->setCollisionBitmask(HERO_COLLISION_BITMASK);

	this->setPhysicsBody(physicBodyHero);
}

void HeroGraphicComponent::LoadSpritesForHell()
{
	m_vecSpritesWalk.push_back("walk-0001.png");
	m_vecSpritesWalk.push_back("walk-0002.png");
	m_vecSpritesWalk.push_back("walk-0003.png");
	m_vecSpritesWalk.push_back("walk-0004.png");
	m_vecSpritesWalk.push_back("walk-0005.png");
	m_vecSpritesWalk.push_back("walk-0006.png");
	m_vecSpritesWalk.push_back("walk-0007.png");
	m_vecSpritesWalk.push_back("walk-0007.png");

	m_vecSpritesAttack.push_back("attack-0001.png");
	m_vecSpritesAttack.push_back("attack-0002.png");
	m_vecSpritesAttack.push_back("attack-0003.png");
	m_vecSpritesAttack.push_back("attack-0004.png");

	m_vecSpritesRun.push_back("run-0001.png");
	m_vecSpritesRun.push_back("run-0002.png");
	m_vecSpritesRun.push_back("run-0003.png");
	m_vecSpritesRun.push_back("run-0004.png");
	m_vecSpritesRun.push_back("run-0005.png");
	m_vecSpritesRun.push_back("run-0006.png");
	m_vecSpritesRun.push_back("run-0007.png");
	m_vecSpritesRun.push_back("run-0008.png");

	m_vecSpritesDie.push_back("die-0001.png");
	m_vecSpritesDie.push_back("die-0002.png");
	m_vecSpritesDie.push_back("die-0003.png");
	m_vecSpritesDie.push_back("die-0004.png");

	m_vecSpritesDizzy.push_back("dizzy-0001.png");
	m_vecSpritesDizzy.push_back("dizzy-0002.png");
	m_vecSpritesDizzy.push_back("dizzy-0003.png");
}

/*virtual*/ bool HeroGraphicComponent::Dead(int wounded)
{
	m_health -= wounded;
	if (m_health < 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*virtual*/void HeroGraphicComponent::Update(Monster& hero, GameScene& scene)
{
	switch (hero.m_stateHero)
	{
		case Monster::StateHero::HERO_STATE_WALK:
		{
			if (++m_countSpriteInVectorWalk >= m_vecSpritesWalk.size())
			{
				m_countSpriteInVectorWalk = 0;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWalk[m_countSpriteInVectorWalk]));
			break;
		}
		case Monster::StateHero::HERO_STATE_ATTACK:
		{
			if (++m_countSpriteInVectorAttack >= m_vecSpritesAttack.size())
			{
				m_countSpriteInVectorAttack = 0;
				hero.m_stateHero = Monster::StateHero::HERO_STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesAttack[m_countSpriteInVectorAttack]));
			break;
		}
		case Monster::StateHero::HERO_STATE_RUN:
		{
			if (++m_countSpriteInVectorRun >= m_vecSpritesRun.size())
			{
				m_countSpriteInVectorRun = 0;
				//hero.m_stateHero = Monster::StateHero::HERO_STATE_WALK;
			}
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesRun[m_countSpriteInVectorRun]));
			break;
		}
		case Monster::StateHero::HERO_STATE_JUMP:
		{
			this->setTexture(CCTextureCache::sharedTextureCache()->addImage("jump.png"));	
			hero.m_stateHero = Monster::StateHero::HERO_STATE_WALK;
			break;
		}
		case Monster::StateHero::HERO_STATE_WOUNDED:
		{
			if (!(this->m_health -= this->getTag()))
			{
				hero.m_stateHero = Monster::StateHero::HERO_STATE_DEATH;
			}

			this->setTag(0);

			break;
		}
		case Monster::StateHero::HERO_STATE_CHANGE_WEAPON_BULLET:
		{
			std::string nameWeapon = "AK47.png";
			WeaponGraphicComponent* _weapon = new WeaponGraphicComponent(100, nameWeapon);
			Size _visibleSize = Director::getInstance()->getVisibleSize();
			_weapon->setScale(_visibleSize.width / _weapon->getContentSize().width / 6,
							  _visibleSize.height / _weapon->getContentSize().height / 2);
			_weapon->setPosition(100, 50);
			
			hero.ChangeWeapon(*_weapon);
			scene.addChild(_weapon);

			///* here code for change bullet *///

			//std::string nameBullet = "bullet.jpg";
			//BulletGraphicComponent* b = new BulletGraphicComponent(20, nameBullet);
			//b->setPosition(Point(Point::ZERO));
			//hero.ChangeBullet(*b);
			//scene.addChild(b);

			hero.m_stateHero = Monster::StateHero::HERO_STATE_WALK;

			break;
		}
		case Monster::StateHero::HERO_STATE_DEATH:
		{
			this->removeFromParentAndCleanup(true);
			break;
		}
	}
}

/*virtual*/ int HeroGraphicComponent::GetAttack() const
{
	return m_attack;
}

/*virtual*/ int HeroGraphicComponent::GetHealth() const
{
	return m_health;
}

/*virtual*/ std::string HeroGraphicComponent::GetTypeObject() const
{
	return m_typeHero;
}

HeroGraphicComponent::~HeroGraphicComponent()
{

}

/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ ��� � ���������
	Monster				- ��������� ��� ��� ����������
*/