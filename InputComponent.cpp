#include "InputComponent.h"

InputComponent::InputComponent()
{
	m_keyCode = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
}

EventKeyboard::KeyCode InputComponent::GetActiveKey()
{
	return m_keyCode;
}

void InputComponent::update(Monster& heroes)
{
	heroes.SetKeyCode(m_keyCode);
}

void InputComponent::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;

	CCLOG("key press");
}

void InputComponent::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	// додати код для спрацювання при відпусканні клавіші
}

InputComponent::~InputComponent()
{

}
