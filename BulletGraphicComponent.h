#ifndef __BULLET_GRAPHIC_COMPONENT_H__
#define __BULLET_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class BulletGraphicComponent : public GraphicComponent
{
public:
	BulletGraphicComponent();

	virtual void Update(Monster& hero);

	~BulletGraphicComponent();

private:
	cocos2d::Point m_position;
};

#endif