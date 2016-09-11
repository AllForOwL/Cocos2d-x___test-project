#ifndef __HELL_GRAPHIC_COMPONENT_H__
#define __HELL_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class HellGraphicComponent : public GraphicComponent
{
public:
	virtual void Update(Monster& hero, GraphicComponent& graphic, GameScene& gameScene);
	virtual bool initWithFile(const std::string& filename);
	//virtual void setTexture(const std::string &filename);
	~HellGraphicComponent();

private:
};

#endif