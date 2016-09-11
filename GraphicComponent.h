#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class GameScene;
class Monster;

// interface for other graphics classes
class GraphicComponent  : public cocos2d::Sprite
{
public:
	virtual void Update(Monster& hero, GraphicComponent& graphic, GameScene& gameScene)	= 0;
	virtual bool initWithFile(const std::string& filename)			= 0;
	//virtual void setTexture(const std::string &filename)			= 0;
	virtual ~GraphicComponent() {};
};

#endif