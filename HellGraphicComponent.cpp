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

/*  GraphicComponent	- ����� ����� ������� 
	PhysicsComponent	- ����� �������� �����
	InputComponent		- ������ ��� � ���������
	Monster				- ��������� ��� ��� ����������
*/