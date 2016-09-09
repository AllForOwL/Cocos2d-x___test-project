#include "InputComponent.h"

InputComponent::InputComponent()
{
	m_countSprite		= 0;
	//m_keyCodePrevious	= EventKeyboard::KeyCode::KEY_0;
	m_GoToRight			= true;

	m_vecSpriteRun.push_back("run-0001.png");
	m_vecSpriteRun.push_back("run-0002.png");
	m_vecSpriteRun.push_back("run-0003.png");
	m_vecSpriteRun.push_back("run-0004.png");
	m_vecSpriteRun.push_back("run-0005.png");
	m_vecSpriteRun.push_back("run-0006.png");
	m_vecSpriteRun.push_back("run-0007.png");
	m_vecSpriteRun.push_back("run-0008.png");

	m_vecSpriteFall.push_back("fall-0001.png");
	m_vecSpriteFall.push_back("fall-0002.png");
	m_vecSpriteFall.push_back("fall-0003.png");

	m_vecSpriteDizzy.push_back("dizzy-0001.png");
	m_vecSpriteDizzy.push_back("dizzy-0002.png");
	m_vecSpriteDizzy.push_back("dizzy-0003.png");

	m_vecSpriteWalk.push_back("walk-0001.png");
	m_vecSpriteWalk.push_back("walk-0002.png");
	m_vecSpriteWalk.push_back("walk-0003.png");
	m_vecSpriteWalk.push_back("walk-0004.png");
	m_vecSpriteWalk.push_back("walk-0005.png");
	m_vecSpriteWalk.push_back("walk-0006.png");
	m_vecSpriteWalk.push_back("walk-0007.png");
	m_vecSpriteWalk.push_back("walk-0008.png");

	m_vecSpriteAttack.push_back("attack-0001.png");
	m_vecSpriteAttack.push_back("attack-0002.png");
	m_vecSpriteAttack.push_back("attack-0003.png");
	m_vecSpriteAttack.push_back("attack-0004.png");

	m_vecSpriteDie.push_back("die-0001.png");
	m_vecSpriteDie.push_back("die-0002.png");
	m_vecSpriteDie.push_back("die-0003.png");
}

void InputComponent::update(Monster& heroes, EventKeyboard::KeyCode keyCode)
{
	if (m_keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if (m_countSprite == 2)
		{
			EventKeyboard::KeyCode tempKeyCode = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
			m_keyCode = tempKeyCode;
			heroes.setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpriteFall[m_countSprite]));
			m_countSprite = 0;
		}
		else
		{
			heroes.setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpriteFall[m_countSprite]));
		}
	}
	else
	{
		if (m_countSprite == 7)
		{
			heroes.setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpriteWalk[m_countSprite]));
			m_countSprite = 0;
		}
		else
		{
			heroes.setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpriteWalk[m_countSprite]));
		}
	}
	++m_countSprite;
}

/*void InputComponent::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	m_keyCode = keyCode;


	CCLOG("key press");
}

void InputComponent::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	// додати код для спрацювання при відпусканні клавіші
}
*/
InputComponent::~InputComponent()
{

}
