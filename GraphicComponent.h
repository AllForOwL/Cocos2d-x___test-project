#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Monster;

class GraphicComponent 
{
public:
	GraphicComponent();	

	void update(Monster& heroes, GraphicComponent& graphicComponent);

	~GraphicComponent();
private:
	std::vector<std::string> m_vecSpriteRun;
	std::vector<std::string> m_vecSpriteFall;
	std::vector<std::string> m_vecSpriteDizzy;
	std::vector<std::string> m_vecSpriteWalk;
	std::vector<std::string> m_vecSpriteAttack;
	std::vector<std::string> m_vecSpriteDie;
};

#endif