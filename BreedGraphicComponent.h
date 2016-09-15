#ifndef __BREED_GRAPHIC_COMPONENT_H__
#define __BREED_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class BreedGraphicComponent : public cocos2d::Sprite
{
public:
	BreedGraphicComponent(int health, int attack, std::string& filename);
	
	int GetAttack() const;
	int GetHealth() const;

	~BreedGraphicComponent();

private:
	int m_health;
	int m_attack;
};

#endif