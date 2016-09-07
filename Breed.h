#ifndef __BREED_H__
#define __BREED_H__

#include <string>

using namespace std;

class Breed
{
public:
	Breed(Breed& breed);

	Breed(int attack, int health, string filename);

	int GetHealth()
	{
		return m_health;
	}

	int GetAttack()
	{
		return m_attack;
	}

	string GetFileName()
	{
		return m_filename;
	}

	~Breed();

private:
	int		m_attack;
	int		m_health;
	string m_filename;
};

#endif