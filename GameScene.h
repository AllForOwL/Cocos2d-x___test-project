#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "Monster.h"
#include "GraphicComponent.h"
#include "PlayerInputComponent.h"

using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:
	// methods
	static cocos2d::Scene *createScene();
	virtual bool init();
	void update(float dt);

	CREATE_FUNC(GameScene);

private:
	cocos2d::PhysicsWorld* m_sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		m_sceneWorld = world;
	}

	cocos2d::Sprite* m_background;

	cocos2d::Sprite* m_spriteHero;
	cocos2d::Layer* m_layer;

	Monster*			m_hero;
	GraphicComponent*	m_graphicComponent;
	InputComponent*		m_inputComponent;

	std::vector<std::string> m_vecSpritesWalk;
	int m_countSpriteInVector;

};

#endif // __GAME_SCENE_H__
