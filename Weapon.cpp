#include "Weapon.h"
#include "GraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

Weapon::Weapon(int attack, std::string filename, std::string fire) 
										: m_attack		(attack),
										  m_filename	(filename),
										  m_fireSheet	(fire)
{
	this->m_sprite			= Sprite::create(m_filename);
	this->m_spriteFire		= Sprite::create(m_fireSheet);
	Size _visibleSize		= Director::getInstance()->getVisibleSize();

	//this->m_sprite->setPosition(50,
		//						_visibleSize.height / 2 - 120);
	this->m_sprite->setScale((_visibleSize.width / this->m_sprite->getContentSize().width)  / 4,
							 (_visibleSize.height / this->m_sprite->getContentSize().height) / 5);
}

void Weapon::Update(EventKeyboard::KeyCode& keyCode, GraphicComponent& graphic, GameScene& scene)
{
	//graphic.Draw(keyCode, graphic.m_vecSpritesFire);
}

void Weapon::Fire()
{
	
}

int Weapon::GetAttack()
{
	return m_attack;
}

Weapon::~Weapon()
{
}
