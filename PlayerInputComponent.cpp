#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent()
{

}

/*virtual*/ void PlayerInputComponent::Update(Monster& hero)
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