#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class GameScene;
class Monster;

// interface for other graphics classes
class GraphicComponent : public cocos2d::Sprite
{
public:
	virtual void Update(Monster& hero, cocos2d::Sprite* _hero, GameScene& gameScene)	= 0;
	//virtual void setTexture(const std::string &filename)			= 0;
	virtual void LoadSprites(EventKeyboard::KeyCode keyCode) = 0;

	virtual ~GraphicComponent() {};

public:
	std::vector<std::string> m_vecSpritesWalk;
	std::vector<std::string> m_vecSpritesFall;
	std::vector<std::string> m_vecSpritesRun;
	std::vector<std::string> m_vecSpritesAttack;

	int m_countSpriteInVector;
	cocos2d::Sprite m_hero;

};

#endif