#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "Weapon.h"

Monster::Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent, Weapon& weapon, GameScene& gameScene) 
							:	m_heroes			(breed), 
								m_health			(m_heroes.GetHealth()),
								m_filename			(m_heroes.GetFileName()),
								m_inputComponent	(inputComponent),
								m_graphicComponent	(graphicComponent),
								m_weapon			(weapon),
								m_gameScene			(gameScene)
{
	m_sprite = Sprite::create(m_filename);
	
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	this->m_sprite->setPosition(_visibleSize.width / 2,
		_visibleSize.height / 2);
	this->m_sprite->setScale(_visibleSize.width / this->m_sprite->getContentSize().width / 6,
		_visibleSize.height / m_sprite->getContentSize().height / 2);

	gameScene.addChild(this->m_sprite);
	//gameScene.addChild(m_weapon.m_sprite);
}

Breed& Monster::GetBreed()
{
	return m_heroes;
}

int Monster::GetAttack()
{
	return m_heroes.GetAttack();
}

void Monster::Update(float dt)
{
	// тут повинні обновляти свій стан усі компоненти
	//m_inputComponent.update		(*this);
	m_graphicComponent.Draw(m_inputComponent.GetActiveKey(), m_gameScene, *this);
}

Monster::~Monster()
{
}
