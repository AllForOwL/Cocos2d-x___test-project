#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"

Monster::Monster(Breed& breed, InputComponent& inputComponent, GraphicComponent& graphicComponent, GameScene& gameScene) 
							:	m_heroes			(breed), 
								m_health			(m_heroes.GetHealth()),
								m_filename			(m_heroes.GetFileName()),
								m_inputComponent	(inputComponent),
								m_graphicComponent	(graphicComponent),
								m_gameScene			(gameScene)
{
	m_countSprite	= 7;
	m_numberSprite	= 0;
	m_changeKeyCode = false;
	m_keyCode		= EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
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

void Monster::SetChangeKeyCode(bool stateKeyCode)
{
	m_changeKeyCode = stateKeyCode;
}

void Monster::SetNumberSprite(int numberSprite)
{
	m_numberSprite = numberSprite;
}

int Monster::GetNumberSprite()
{
	return m_numberSprite;
}

int Monster::GetCountSprite()
{
	return m_countSprite;
}

EventKeyboard::KeyCode Monster::GetKeyCode()
{
	return EventKeyboard::KeyCode::KEY_UP_ARROW;
}

void Monster::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;

//	m_inputComponent.update(*this/*, keyCode*/);

	CCLOG("key press");
	Update(m_changeKeyCode);
}

void Monster::Update(bool changeKEyCode)
{
	// тут повинні обновляти свій стан усі компоненти
	m_inputComponent.update		(*this);
	m_graphicComponent.update	(*this, m_gameScene, m_changeKeyCode);
}

Monster::~Monster()
{
}
