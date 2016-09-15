#include "GameObjectMonster.h"
#include "GameScene.h"
#include "BreedGraphicComponent.h"
#include "Monster.h"
#include "GraphicComponent.h"

GameObjectMonster::GameObjectMonster()
{
	Size _visibleSize = Director::getInstance()->getVisibleSize();
	m_monsterComponent = new BreedGraphicComponent(*CreateNewMonster());
	m_monsterComponent->setScale(_visibleSize.width / m_monsterComponent->getContentSize().width / 6,
								 _visibleSize.height / m_monsterComponent->getContentSize().height / 4);
	m_monsterComponent->setPosition(250, 100);
}

void GameObjectMonster::Update(Monster& hero, GameScene& scene)
{
	// додати умову при якій створювати нового монстра і додати на scene
	scene.addChild(m_monsterComponent);
}

BreedGraphicComponent* GameObjectMonster::CreateNewMonster()
{
	return new BreedGraphicComponent(100, 150, std::string("jump.png"));
}

GameObjectMonster::~GameObjectMonster()
{
}