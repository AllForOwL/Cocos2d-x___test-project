#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "AK47GraphicComponent.h"

Monster::Monster(GraphicComponent* graphicComponentHero, GraphicComponent* graphicComponentWeapon,
				GraphicComponent* graphicComponentBullet, InputComponent* inputComponent) 
							:	m_graphicComponentHero	(graphicComponentHero),
								m_graphicComponentWeapon(graphicComponentWeapon),
								m_graphiComponentBullet (graphicComponentBullet),
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
	m_graphiComponentBullet->Update (*this);
}

Monster::~Monster()
{
	delete m_graphicComponentHero;
	delete m_graphicComponentWeapon;
	delete m_inputComponent;
}

/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ 䳿 � ���������
	Monster				- ��������� ��� ��� ����������
*/