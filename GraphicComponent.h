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

	void update(Monster& heroes);
	void Draw(EventKeyboard::KeyCode& keyCode, GameScene& scene, Monster& hero);
	int  LoadSprites(EventKeyboard::KeyCode& keyCode);

	void Walk();
	void Attack();
	void Jump();
	void Fire();

	~GraphicComponent();
private:
	enum State
	{
		STATE_WALK,
		STATE_ATTACK,
		STATE_JUMP,
		STATE_FIRE
	};
	
	State				m_state;
	cocos2d::Sprite*	m_pSprite;
	int m_countSpritesInVectorHeroWalk;
	int m_countSpritesInVectorHeroAttack;
	int m_countSpritesInVectorHeroJump;
	int m_countSpritesInVectorWeaponFire;

	std::vector<std::string> m_vecSpritesHeroWalk;
	std::vector<std::string> m_vecSpritesHeroAttack;
	std::vector<std::string> m_vecSpritesHeroJump;
	std::vector<std::string> m_vecSpritesWeaponFire;
};

#endif