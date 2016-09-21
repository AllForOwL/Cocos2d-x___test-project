#ifndef __BOT_BULLET_GRAPHIC_COMPONENT_H__
#define __BOT_BULLET_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class BotBulletGraphicComponent : public GraphicComponent
{
public:
	BotBulletGraphicComponent(int attack, const std::string& typeObject);
	BotBulletGraphicComponent(BotBulletGraphicComponent& bullet);

	virtual void Update(Monster& hero, GameScene& scene);

	void LoadBulletNormal();
	void LoadBomb();

	int GetAttack() const;
	std::string GetTypeObject() const;

	~BotBulletGraphicComponent();

public:
	cocos2d::Point	m_position;
	std::string		m_typeObject;
	int				m_attack;

	std::string		m_strFilename;
};

#endif