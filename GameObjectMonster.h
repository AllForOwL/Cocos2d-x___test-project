#ifndef __GAME_OBJECT_MONSTER_H__
#define __GAME_OBJECT_MONSTER_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class GameScene;
class BreedGraphicComponent;
class Monster;
class GraphicComponent;

// interface for other graphics classes
class GameObjectMonster
{
public:
	GameObjectMonster();

	void Update(Monster& hero, GameScene& scene);
	BreedGraphicComponent* CreateNewMonster();

	~GameObjectMonster();

private:
	GraphicComponent* m_monsterComponent;
};

#endif