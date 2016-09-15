#ifndef __BREED_GRAPHIC_COMPONENT_H__
#define __BREED_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class Monster;

class BreedGraphicComponent : public GraphicComponent
{
public:
	BreedGraphicComponent(int attack, int health, std::string& filename);
	BreedGraphicComponent(BreedGraphicComponent& breed);

	virtual void Update(Monster& hero);

	int			GetAttack()   const;
	int			GetHealth()   const;
	std::string GetFilename() const;

	~BreedGraphicComponent();

private:
	int m_attack;
	int m_health;
	std::string m_filename;

};
#endif