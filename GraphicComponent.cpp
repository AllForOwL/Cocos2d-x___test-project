#include "GraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

GraphicComponent::GraphicComponent()
{
}

void GraphicComponent::update(Monster& heroes, GameScene& gameScene, bool changeKeyCode)
{
	std::vector<std::string> m_vecSpriteRun;
	std::vector<std::string> m_vecSpriteFall;
	std::vector<std::string> m_vecSpriteDizzy;
	std::vector<std::string> m_vecSpriteWalk;
	std::vector<std::string> m_vecSpriteAttack;
	std::vector<std::string> m_vecSpriteDie;

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

	int  _numberSpriteInVector	= heroes.GetNumberSprite();
	Size _visibleSize			= Director::getInstance()->getVisibleSize();
	int	_countSprites			= heroes.GetCountSprite();

	gameScene.removeAllChildrenWithCleanup(true);

	EventKeyboard::KeyCode	_keyCode = heroes.GetKeyCode();
	cocos2d::Sprite*		_sprite;
	
	if (changeKeyCode)
	{
		heroes.SetChangeKeyCode(false);
		EventKeyboard::KeyCode _keyCode = heroes.GetKeyCode();
		switch (_keyCode)
		{
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
			{
				_sprite			= Sprite::create(m_vecSpriteFall[0]);
				heroes.SetCountSprite(3);
				break;
			}
			case EventKeyboard::KeyCode::KEY_A:
			{
				_sprite			= Sprite::create(m_vecSpriteAttack[0]);
				heroes.SetCountSprite(4);
				break;
			}
			case EventKeyboard::KeyCode::KEY_D:
			{
				_sprite			= Sprite::create(m_vecSpriteDie[0]);
				heroes.SetCountSprite(4);;
				break;
			}
			case EventKeyboard::KeyCode::KEY_R:
			{
				_sprite			= Sprite::create(m_vecSpriteRun[0]);
				heroes.SetCountSprite(8);
				break;
			}
			default:
				break;
		}
	}
	else
	{
		if (_numberSpriteInVector >= _countSprites)
		{
			heroes.SetCountSprite(7);
			_numberSpriteInVector = 0;
			heroes.SetKeyCode(EventKeyboard::KeyCode::KEY_RIGHT_ARROW);
			_keyCode = heroes.GetKeyCode();
		}
		switch (_keyCode)
		{
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			{
				_sprite	= Sprite::create(m_vecSpriteWalk[_numberSpriteInVector]);
				_countSprites = 7;
				break;
			}
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
			{
				_sprite	= Sprite::create(m_vecSpriteFall[_numberSpriteInVector]);
				break;
			}
			case EventKeyboard::KeyCode::KEY_A:
			{
				_sprite	= Sprite::create(m_vecSpriteAttack[_numberSpriteInVector]);
				break;
			}
			case EventKeyboard::KeyCode::KEY_D:
			{
				_sprite	= Sprite::create(m_vecSpriteDie[_numberSpriteInVector]);
				break;
			}
			case EventKeyboard::KeyCode::KEY_R:
			{
				_sprite	= Sprite::create(m_vecSpriteRun[_numberSpriteInVector]);
				break;
			}
			default:
				break;
		}
	}
	
	_sprite->setScale(_visibleSize.width / _sprite->getContentSize().width / 2,
					 _visibleSize.height / _sprite->getContentSize().height / 2);
	_sprite->setPosition(_visibleSize.width  / 2,
						 _visibleSize.height / 2);

	gameScene.addChild(_sprite);
	heroes.SetNumberSprite(++_numberSpriteInVector);
}

GraphicComponent::~GraphicComponent()
{

}