#ifndef __AK47_GRAPHIC_COMPONENT_H__
#define __AK47_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class AK47GraphicComponent : public GraphicComponent
{
public:
	AK47GraphicComponent();

	virtual void Update(Monster& hero);

	~AK47GraphicComponent();

public:

};

#endif