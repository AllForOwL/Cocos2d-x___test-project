#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "AK47GraphicComponent.h"

Monster::Monster(GraphicComponent* graphicComponentHero, GraphicComponent* graphicComponentWeapon, InputComponent* inputComponent) 
							:	m_graphicComponentHero	(graphicComponentHero),
								m_graphicComponentWeapon(graphicComponentWeapon),
								m_inputComponent		(inputComponent)
{
	m_stateHero		= STATE_WALK;
	m_stateWeapon	= STATE_REST;
}

void Monster::Update()
{
	m_inputComponent->Update		(*this);
	m_graphicComponentHero->Update	(*this);
	m_graphicComponentWeapon->Update(*this);
}

Monster::~Monster()
{
	delete m_graphicComponentHero;
	delete m_graphicComponentWeapon;
	delete m_inputComponent;
}

/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає дії з клавіатури
	Monster				- контейнер для цих компонентів
*/