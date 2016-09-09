#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"

Monster::Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent) 
							:	m_heroes			(breed), 
								m_health			(m_heroes.GetHealth()),
								m_filename			(m_heroes.GetFileName()),
								m_inputComponent	(inputComponent),
								m_graphicComponent	(graphicComponent)
{
	this->initWithFile(m_filename);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	this->setScale(visibleSize.width / this->getContentSize().width / 2 / 2,
					visibleSize.height / this->getContentSize().height / 2);

	this->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 50);

	m_countSprite = 0;
}

Breed& Monster::GetBreed()
{
	return m_heroes;
}

int Monster::GetAttack()
{
	return m_heroes.GetAttack();
}

void Monster::SetKeyCode(EventKeyboard::KeyCode keyCode)
{
	m_keyCode = keyCode;
}

void Monster::SetCountSprite(int countSprite)
{
	m_countSprite = countSprite;
}

int Monster::GetCountSprite()
{
	return m_countSprite;
}

void Monster::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;

//	m_inputComponent.update(*this/*, keyCode*/);

	CCLOG("key press");
}

void Monster::Run()
{
	// тут повинні обновляти свій стан усі компоненти
	m_inputComponent.update(*this);
	m_graphicComponent.update(*this, m_graphicComponent);
}

Monster::~Monster()
{
}
