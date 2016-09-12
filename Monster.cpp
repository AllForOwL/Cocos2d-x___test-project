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

/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ 䳿 � ���������
	Monster				- ��������� ��� ��� ����������
*/