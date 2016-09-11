#include "HellGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"
#include "GameScene.h"

bool HellGraphicComponent::initWithFile(const std::string& filename)
{
	if (!Sprite::init())
	{
		return false;
	}

	auto spriteTemp = Sprite::create(filename);
	spriteTemp->setPosition(50, 50);
	this->addChild(spriteTemp);

	return true;
}

/*virtual*/void HellGraphicComponent::Update(Monster& hero, GraphicComponent& graphic, GameScene& gameScene)
{
	Size _size = Director::getInstance()->getVisibleSize();
	GraphicComponent* _graphic = new HellGraphicComponent();
	_graphic->initWithFile("walk-0001.png");

	gameScene.addChild(_graphic);
}


HellGraphicComponent::~HellGraphicComponent()
{

}

/*  GraphicComponent	- тільки малює спрайти 
	PhysicsComponent	- виявлє зіткнення героя
	InputComponent		- приймає діна з клавіатури
	Monster				- контейнер для цих компонентів
*/