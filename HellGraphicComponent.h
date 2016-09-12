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

	virtual void Update(Monster& hero, cocos2d::Sprite* _hero, GameScene& gameScene);
	//virtual void setTexture(const std::string &filename);

	virtual void LoadSprites(EventKeyboard::KeyCode keyCode);

	~HellGraphicComponent();

public:
	cocos2d::Sprite*		 m_hero;

	std::vector<std::string> m_vecSpritesWalk;
	std::vector<std::string> m_vecSpritesFall;
	std::vector<std::string> m_vecSpritesRun;
	std::vector<std::string> m_vecSpritesAttack;

	int m_countSpriteInVector;
};

#endif