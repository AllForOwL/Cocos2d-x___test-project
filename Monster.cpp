#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "Weapon.h"

Monster::Monster(GraphicComponent* graphicComponent, InputComponent* inputComponent) 
							:	m_graphicComponent(graphicComponent),
								m_inputComponent  (inputComponent)
{

}

Monster::~Monster()
{

}


/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає діна з клавіатури
	Monster				- контейнер для цих компонентів
*/