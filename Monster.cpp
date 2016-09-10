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
	m_sprite = Sprite::create("walk-0001.png");
	
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	this->m_sprite->setPosition(_visibleSize.width / 2,
		_visibleSize.height / 2);
	gameScene.addChild(this->m_sprite);

	m_countSpriteInVector	= 0;
	m_changeKeyCode			= false;
	m_keyCode				= EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
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
	m_countSpriteInVector = countSprite;
}

void Monster::SetChangeKeyCode(bool stateKeyCode)
{
	m_changeKeyCode = stateKeyCode;
}

int Monster::GetCountSprite()
{
	return m_countSpriteInVector;
}

EventKeyboard::KeyCode Monster::GetKeyCode()
{
	return m_keyCode;
}

void Monster::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;
}

void Monster::Update(float dt)
{
	// тут повинні обновляти свій стан усі компоненти
	//m_inputComponent.update		(*this);
	m_graphicComponent.update	(*this);
}

Monster::~Monster()
{
}
