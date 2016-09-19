#include "BotInputComponent.h"
#include "Monster.h"
#include "GameObjectMonster.h"

BotInputComponent::BotInputComponent()
{

}

/*virtual*/ void BotInputComponent::Update(Monster& heroes)
{
	if (heroes.m_objectMonster->m_monsterComponent.size() > 0 && heroes.m_stateEnemy == Monster::StateEnemy::ENEMY_STATE_NOTHING)
	{
		heroes.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;	
	}
}

/*virtual*/ void BotInputComponent::onKeyPressed(EventKeyboard::KeyCode, Event* event)
{

}

/*virtual*/ void BotInputComponent::onKeyReleased(EventKeyboard::KeyCode, Event* event)
{

}

BotInputComponent::~BotInputComponent()
{

}