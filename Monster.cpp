#include "Monster.h"
#include "InputComponent.h"

Monster::Monster(Breed& breed, InputComponent& inputComponent) 
							:	m_heroes(breed), 
								m_health(m_heroes.GetHealth()),
								m_filename(m_heroes.GetFileName()),
								m_inputComponent(inputComponent)
{
	this->initWithFile(m_filename);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	this->setScale(visibleSize.width / this->getContentSize().width / 2 / 2,
					visibleSize.height / this->getContentSize().height / 2);

	this->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 50);
}

Breed& Monster::GetBreed()
{
	return m_heroes;
}

int Monster::GetAttack()
{
	return m_heroes.GetAttack();
}

void Monster::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;

	m_inputComponent.update(*this, keyCode);

	CCLOG("key press");
}

//void Monster::Update()
//{
	// тут повинні обновляти свій стан усі компоненти
//	m_inputComponent.update(*this);
//}

Monster::~Monster()
{
}
