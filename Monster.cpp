#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "Weapon.h"

Monster::Monster(GraphicComponent* graphicComponent, InputComponent* inputComponent) 
							:	m_graphicComponent(graphicComponent),
								m_inputComponent  (inputComponent)
{
	m_state = STATE_WALK;
}

void Monster::Update()
{
	m_inputComponent->Update	(*this);
	m_graphicComponent->Update	(*this);
}

Monster::~Monster()
{

}

/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає дії з клавіатури
	Monster				- контейнер для цих компонентів
*/