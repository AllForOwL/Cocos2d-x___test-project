#include "AK47GraphicComponent.h"

AK47GraphicComponent::AK47GraphicComponent()
{
	this->initWithFile("AK47.png");
}

/*virtual*/ void AK47GraphicComponent::Update(Monster& hero, GameScene& scene)
{
	
}

AK47GraphicComponent::~AK47GraphicComponent()
{

}