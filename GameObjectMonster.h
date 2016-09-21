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
	BreedGraphicComponent* CreateNewMonster(int attack, int health, std::string& typeObject);
	void GoesAirplanes(std::string& filename);
	void GoesBoy(std::string& filename);
	void Spawner(GameScene& scene);

	~GameObjectMonster();
public:
	std::vector<GraphicComponent*>	m_monsterComponent;
	GraphicComponent*				m_monster;
	std::vector<std::string>		m_vecDieBoy;
	int								m_countInVector;
	std::vector<std::string>		m_vecSpritesAirplanesRest;
	int								m_countSpriteInVectorAirplanesRest;
	std::vector<std::string>		m_vecSpritesAirplanesAttack;
	int								m_countSpriteInVectorAirplanesAttack;
	std::vector<std::string>		m_vecSpritesAirplanesDead;
	int								m_countSpriteInVectorAirplanesDead;

	std::vector<std::string>		m_vecSpritesBoyWalk;
	int								m_countInVectorBoyWalk;
	std::vector<std::string>		m_vecSpritesBoyDeath;
	int								m_countInVectorBoyDeath;
};

#endif