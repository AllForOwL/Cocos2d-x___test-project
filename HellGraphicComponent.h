#ifndef __HELL_GRAPHIC_COMPONENT_H__
#define __HELL_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class HellGraphicComponent : public GraphicComponent
{
public:
	HellGraphicComponent();

	virtual void Update(Monster& hero, GameScene& scene);

	~HellGraphicComponent();

public:
	std::vector<std::string> m_vecSpritesWalk;
	std::vector<std::string> m_vecSpritesAttack;
	std::vector<std::string> m_vecSpritesRun;
	std::vector<std::string> m_vecSpritesFall;
	std::vector<std::string> m_vecSpritesDie;
	std::vector<std::string> m_vecSpritesDizzy;

	int m_countSpriteInVectorWalk;
	int m_countSpriteInVectorAttack;
	int m_countSpriteInVectorRun;
};

#endif