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

void Monster::Update(GameScene& scene, GraphicComponent& graphic)
{
	m_inputComponent->Update(*this);
//	m_graphicComponent->Update(*this, graphic, scene);
}

Monster::~Monster()
{

}


/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ ��� � ���������
	Monster				- ��������� ��� ��� ����������
*/