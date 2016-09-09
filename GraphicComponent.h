#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Monster;
class GameScene;

class GraphicComponent 
{
public:
	GraphicComponent();	

	Monster& update(Monster& heroes, GameScene& gameScene);

	~GraphicComponent();
private:
};

#endif