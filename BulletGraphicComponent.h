#ifndef __BULLET_GRAPHIC_COMPONENT_H__
#define __BULLET_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class BulletGraphicComponent : public GraphicComponent
{
public:
	BulletGraphicComponent(std::string& filename);
	BulletGraphicComponent(BulletGraphicComponent& bullet);

	virtual void Update(Monster& hero, GameScene& scene);

	std::string GetFilename() const;

	~BulletGraphicComponent();

private:
	cocos2d::Point	m_position;
	std::string		m_filename;
};

#endif