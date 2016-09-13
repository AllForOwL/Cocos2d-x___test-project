#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent()
{
	m_keyCode = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
}

/*virtual*/ void PlayerInputComponent::Update(Monster& hero)
{
	switch (m_keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			hero.m_stateHero = Monster::StateHero::STATE_WALK;
			break;
		}
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			hero.m_stateHero = Monster::StateHero::STATE_JUMP;
			break;
		}
		case EventKeyboard::KeyCode::KEY_A:
		{
			hero.m_stateHero = Monster::StateHero::STATE_ATTACK;
			break;
		}
		case EventKeyboard::KeyCode::KEY_R:
		{
			hero.m_stateHero = Monster::StateHero::STATE_RUN;
			break;
		}
		case EventKeyboard::KeyCode::KEY_F:
		{
			hero.m_stateWeapon = Monster::StateWeapon::STATE_FIRE;
			break;
		}
	}
}

/*virtual*/ void PlayerInputComponent::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;
}

/*virtual*/ void PlayerInputComponent::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}

PlayerInputComponent::~PlayerInputComponent()
{

}

/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ ��� � ���������
	Monster				- ��������� ��� ��� ����������
*/