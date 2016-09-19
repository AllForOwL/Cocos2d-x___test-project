#include "Monster.h"
#include "InputComponent.h"
#include "GraphicComponent.h"
#include "GameScene.h"
#include "AK47GraphicComponent.h"
#include "GameObjectMonster.h"
#include "PhysicComponent.h"

Monster::Monster(
				GraphicComponent* graphicComponentHero, GraphicComponent* graphicComponentWeapon,
				GraphicComponent* graphicComponentBullet, GameObjectMonster* objectMonster, 
				InputComponent* inputComponent, InputComponent* botInputComponent,
				PhysicComponent* physicComponent
				) 
							:	m_graphicComponentHero	(graphicComponentHero),
								m_graphicComponentWeapon(graphicComponentWeapon),
								m_graphiComponentBullet (graphicComponentBullet),
								m_objectMonster			(objectMonster),
								m_inputComponent		(inputComponent),
								m_botInputComponent		(botInputComponent),
								m_physicComponent		(physicComponent)
{
	m_stateHero		= Monster::StateHero::HERO_STATE_WALK;
	m_stateWeapon	= Monster::StateWeapon::WEAPON_STATE_REST;
	m_stateEnemy	= Monster::StateEnemy::ENEMY_STATE_ATTACK;
	m_statePhysic	= Monster::StatePhysic::PHYSIC_NOTHING;
}

void Monster::Update(GameScene& scene)
{
	m_inputComponent->Update		(*this);
	m_graphicComponentHero->Update	(*this, scene);
	m_graphicComponentWeapon->Update(*this, scene);
	m_botInputComponent->Update		(*this);
	m_physicComponent->Update		(*this, scene);
	m_objectMonster->Update			(*this, scene);
	m_graphiComponentBullet->Update (*this, scene);
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