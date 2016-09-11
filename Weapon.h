#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class GameScene;
class GraphicComponent;
class Monster;

class Weapon : public cocos2d::Sprite
{
public:
	Weapon(int attack, std::string filename, std::string fire);

	void Update(EventKeyboard::KeyCode& keyCode, GraphicComponent& graphic, GameScene& scene);
	int GetAttack();	
	void Fire();

	~Weapon();

public:
	int			m_attack;
	std::string	m_filename;
	std::string	m_fireSheet;

	cocos2d::Sprite*	m_sprite;
	cocos2d::Sprite*	m_spriteFire;
};

#endif