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
	void Spawner(GameScene& scene);

	~GameObjectMonster();
private:
	std::vector<GraphicComponent*>	m_monsterComponent;
	GraphicComponent*				m_monster;
	std::vector<std::string>		m_vecDieBoy;
	int								m_countInVector;
};

#endif