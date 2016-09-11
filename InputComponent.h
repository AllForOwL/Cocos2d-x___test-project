#ifndef __INPUT_COMPONENT_H__
#define __INPUT_COMPONENT_H__

#include "cocos2d.h"
#include "Monster.h"

using namespace cocos2d;
using namespace std;

// intarface for other input classes
class InputComponent
{
public:
	virtual void Update(Monster& heroes) = 0;

	~InputComponent();
};

#endif