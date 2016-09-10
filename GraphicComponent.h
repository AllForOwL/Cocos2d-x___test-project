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

	void update(Monster& heroes, GameScene& gameScene, bool changeKeyCode);
	int LoadSprites(EventKeyboard::KeyCode keyCode, std::vector<std::string>& vecSprites);

	~GraphicComponent();
private:
};

#endif