#ifndef __GAME_OBJECT_MONSTER_H__
#define __GAME_OBJECT_MONSTER_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class GameScene;
class Monster;

// interface for other graphics classes
class GameObjectMonster
{
public:
	void Update(Monster& hero);

	~GameObjectMonster();
};

#endif