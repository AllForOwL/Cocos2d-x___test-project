#include "GraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

GraphicComponent::GraphicComponent()
{
	m_state = STATE_WALK;
	m_pSprite = Sprite::create("walk-0001.png");

	m_countSpritesInVectorHeroWalk		= 0;
	m_countSpritesInVectorHeroAttack	= 0;
	m_countSpritesInVectorHeroJump		= 0;
	m_countSpritesInVectorWeaponFire	= 0;

}

void GraphicComponent::update(Monster& heroes)
{


	/*std::vector<std::string> _vecSprites;
	int _sizeVector = LoadSprites(heroes.GetKeyCode(), _vecSprites);
	
	int _countSpriteInVector = heroes.GetCountSprite();
	if (_countSpriteInVector >= _sizeVector)
	{
		heroes.SetKeyCode(EventKeyboard::KeyCode::KEY_RIGHT_ARROW);
		_countSpriteInVector = 0;
	}

	Size _visibleSize = Director::getInstance()->getVisibleSize();

	heroes.m_sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(_vecSprites[_countSpriteInVector]));
	heroes.m_sprite->setScale(_visibleSize.width / heroes.m_sprite->getContentSize().width / 6,
		_visibleSize.height / heroes.m_sprite->getContentSize().height / 2);
	heroes.m_sprite->setPosition(50,
						 _visibleSize.height / 2 - 80);

	heroes.SetCountSprite(++_countSpriteInVector);

	m_countSpriteInVectorWeapon = 0;
	*/
}

void GraphicComponent::Draw(EventKeyboard::KeyCode& keyCode, GameScene& scene, Monster& hero)
{
	m_pSprite	= &sprite;
	int _sizeVector = LoadSprites(keyCode);

	Size _visibleSize = Director::getInstance()->getVisibleSize();

	switch (m_state)
	{
		case STATE_WALK:
		{
			Walk();

			break;
		}
		case STATE_ATTACK:
		{
			Attack();

			break;
		}
		case STATE_JUMP:
		{
			Jump();

			break;
		}
		case STATE_FIRE:
		{
			Fire();

			break;
		}
	}

	scene.addChild(m_pSprite);
}

void GraphicComponent::Walk()
{
	Size _size = Director::getInstance()->getVisibleSize();

	m_pSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesHeroWalk[m_countSpritesInVectorHeroWalk]));
	m_pSprite->setScale(_size.width / m_pSprite->getContentSize().width / 6,
		_size.height / m_pSprite->getContentSize().height / 2);
	m_pSprite->setPosition(50,
							_size.height / 2 - 80);
	++m_countSpritesInVectorHeroWalk;
}

void GraphicComponent::Attack()
{
	Size _size = Director::getInstance()->getVisibleSize();

	m_pSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesHeroAttack[m_countSpritesInVectorHeroAttack]));
	m_pSprite->setScale(_size.width / m_pSprite->getContentSize().width / 6,
		_size.height / m_pSprite->getContentSize().height / 2);
	m_pSprite->setPosition(50,
		_size.height / 2 - 80);

	++m_countSpritesInVectorHeroAttack;
}

void GraphicComponent::Jump()
{
	Size _size = Director::getInstance()->getVisibleSize();

	m_pSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesHeroJump[m_countSpritesInVectorHeroJump]));
	m_pSprite->setScale(_size.width / m_pSprite->getContentSize().width / 6,
		_size.height / m_pSprite->getContentSize().height / 2);
	m_pSprite->setPosition(50,
		_size.height / 2 - 80);

	++m_countSpritesInVectorHeroJump;
}

void GraphicComponent::Fire()
{
	Size _size = Director::getInstance()->getVisibleSize();

	m_pSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(m_vecSpritesWeaponFire[m_countSpritesInVectorWeaponFire]));
	m_pSprite->setScale(_size.width / m_pSprite->getContentSize().width / 6,
		_size.height / m_pSprite->getContentSize().height / 2);
	m_pSprite->setPosition(50,
		_size.height / 2 - 80);

	++m_countSpritesInVectorWeaponFire;
}

int GraphicComponent::LoadSprites(EventKeyboard::KeyCode& keyCode)
{
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			m_vecSpritesHeroWalk.push_back("walk-0001.png");
			m_vecSpritesHeroWalk.push_back("walk-0002.png");
			m_vecSpritesHeroWalk.push_back("walk-0003.png");
			m_vecSpritesHeroWalk.push_back("walk-0004.png");
			m_vecSpritesHeroWalk.push_back("walk-0005.png");
			m_vecSpritesHeroWalk.push_back("walk-0006.png");
			m_vecSpritesHeroWalk.push_back("walk-0007.png");
			m_vecSpritesHeroWalk.push_back("walk-0008.png");

			m_state = STATE_WALK;

			return m_vecSpritesHeroWalk.size();
		}
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			m_vecSpritesHeroJump.push_back("fall-0001.png");
			m_vecSpritesHeroJump.push_back("fall-0002.png");
			m_vecSpritesHeroJump.push_back("fall-0003.png");

			m_state = STATE_JUMP;

			return m_vecSpritesHeroJump.size();
		}
		case EventKeyboard::KeyCode::KEY_A:
		{
			m_vecSpritesHeroAttack.push_back("attack-0001.png");
			m_vecSpritesHeroAttack.push_back("attack-0002.png");
			m_vecSpritesHeroAttack.push_back("attack-0003.png");
			m_vecSpritesHeroAttack.push_back("attack-0004.png");

			m_state = STATE_ATTACK;

			return m_vecSpritesHeroAttack.size();
		}
		case EventKeyboard::KeyCode::KEY_F:
		{
			m_vecSpritesWeaponFire.push_back("fire-0001.png");
			m_vecSpritesWeaponFire.push_back("fire-0002.png");
			m_vecSpritesWeaponFire.push_back("fire-0003.png");
			m_vecSpritesWeaponFire.push_back("fire-0004.png");
			m_vecSpritesWeaponFire.push_back("fire-0005.png");

			m_state = STATE_FIRE;

			return m_vecSpritesWeaponFire.size();
		}
	}
}

GraphicComponent::~GraphicComponent()
{

}