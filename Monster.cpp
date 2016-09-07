#include "Monster.h"

Monster::Monster(Breed& breed) 
							:	m_heroes(breed), 
								m_health(m_heroes.GetHealth())
{
	this->create(m_heroes.GetFileName());
}

int Monster::GetAttack()
{
	return this->m_heroes.GetAttack();
}

Monster::~Monster()
{
}
