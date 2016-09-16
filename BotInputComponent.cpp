#include "BotInputComponent.h"
#include "Monster.h"
#include "GameObjectMonster.h"

BotInputComponent::BotInputComponent()
{

}

/*virtual*/ void BotInputComponent::Update(Monster& heroes)
{
	if (heroes.m_objectMonster->m_monsterComponent.size() > 0)
	{
		if (heroes.m_objectMonster->m_monsterComponent[0]->getPosition().x - heroes.m_graphicComponentHero->getPosition().x > 50)
		{
			heroes.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_ATTACK;
		}
		else
		{
			heroes.m_stateEnemy = Monster::StateEnemy::ENEMY_STATE_REST;
		}

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