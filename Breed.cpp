#include "Breed.h"

Breed::Breed(int attack, int health, string filename)
{
	m_attack = attack;
	m_health = health;
	m_filename = filename;
}

Breed::Breed(Breed& breed)
{
	this->m_attack	 = breed.GetAttack();
	this->m_health	 = breed.GetHealth();
	this->m_filename = breed.GetFileName();
}

Breed::~Breed()
{
}
