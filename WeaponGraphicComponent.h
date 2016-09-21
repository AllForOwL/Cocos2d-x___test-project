#ifndef __WEAPON_GRAPHIC_COMPONENT_H__
#define __WEAPON_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class WeaponGraphicComponent : public GraphicComponent
{
public:
	WeaponGraphicComponent(int attack, const std::string& typeObject);
	WeaponGraphicComponent(WeaponGraphicComponent& weapon);

	virtual void Update(Monster& hero, GameScene& scene);

	int GetAttack() const;
	std::string GetTypeObject() const;

	~WeaponGraphicComponent();

public:
	int			m_attack;
	std::string m_typeObject;
	
	std::string m_strFilename;

};

#endif