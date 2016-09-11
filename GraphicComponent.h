#ifndef __GRAPHIC_COMPONENT_H__
#define __GRAPHIC_COMPONENT_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Monster;

// interface for other graphics classes
class GraphicComponent 
{
public:
	virtual void Update(Monster& hero, GraphicComponent& graphic);

	~GraphicComponent();
};

#endif