#include "HellGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"

HellGraphicComponent::HellGraphicComponent()
{
}

/*virtual*/void HellGraphicComponent::Update(Monster& hero, GraphicComponent& graphic)
{
	
}

HellGraphicComponent::~HellGraphicComponent()
{

}

/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає діна з клавіатури
	Monster				- контейнер для цих компонентів
*/