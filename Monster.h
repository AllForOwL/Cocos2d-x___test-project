#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Breed.h"

using namespace std;
using namespace cocos2d;

class InputComponent;
class GraphicComponent;
class GameScene;

class Monster
{
public:
	Monster::Monster(GraphicComponent* graphicComponent, InputComponent* inputComponent);

	void Update(GameScene& scene, GraphicComponent& graphic);

	~Monster();

private:
	GraphicComponent*	m_graphicComponent;
	InputComponent*		m_inputComponent
};

#endif