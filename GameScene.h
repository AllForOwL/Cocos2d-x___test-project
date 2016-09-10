#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "Monster.h"

using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:
	// methods
	static cocos2d::Scene *createScene();
	virtual bool init();

	void GameScene::AddHeroes(cocos2d::Ref* ref);

	CREATE_FUNC(GameScene);
	
	void update(float dt);
	void DrawSprite(float interval);
	void UpdateHeroes(float dt);

//	void onKeyPressed(EventKeyboard::KeyCode, Event* event);
//	void onKeyReleased(EventKeyboard::KeyCode, Event* event);

private:
	cocos2d::PhysicsWorld* m_sceneWorld;

	void SetPhysicsWorld(cocos2d::PhysicsWorld* world)
	{
		m_sceneWorld = world;
	}
	bool OnContactBegin(cocos2d::PhysicsContact& contact);

	Monster*	m_Heroes;
	int			m_ID_HELL;
	int			m_ID_FIRE_GIRL;
	int			m_ID_WATER_MAN;
	std::string m_listSprite[9];
	int			m_count;
	bool		m_createHeroes;

	cocos2d::Sprite* m_spriteHeroes;
	cocos2d::Sprite* m_background;

	cocos2d::Layer* m_layer;
};

#endif // __GAME_SCENE_H__
