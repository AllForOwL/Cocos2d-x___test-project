#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent()
{

}

/*virtual*/ void PlayerInputComponent::Update(Monster& hero)
{

}

/*virtual*/ void PlayerInputComponent::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

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