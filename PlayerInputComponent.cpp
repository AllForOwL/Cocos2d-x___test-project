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


/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає діна з клавіатури
	Monster				- контейнер для цих компонентів
*/