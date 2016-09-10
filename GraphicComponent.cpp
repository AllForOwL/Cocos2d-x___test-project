#include "GraphicComponent.h"
#include "Monster.h"
#include "GameScene.h"

GraphicComponent::GraphicComponent()
{
}

void GraphicComponent::update(Monster& heroes)
{
	std::vector<std::string> _vecSprites;
	int _sizeVector = LoadSprites(heroes.GetKeyCode(), _vecSprites);
	
	int _countSpriteInVector = heroes.GetCountSprite();
	if (_countSpriteInVector >= _sizeVector)
	{
		heroes.SetKeyCode(EventKeyboard::KeyCode::KEY_RIGHT_ARROW);
		_countSpriteInVector = 0;
	}

	Size _visibleSize			= Director::getInstance()->getVisibleSize();

	heroes.m_sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(_vecSprites[_countSpriteInVector]));
	heroes.m_sprite->setScale(_visibleSize.width / heroes.m_sprite->getContentSize().width / 2,
		_visibleSize.height / heroes.m_sprite->getContentSize().height / 2);
	heroes.m_sprite->setPosition(_visibleSize.width / 2,
						 _visibleSize.height / 2);

	heroes.SetCountSprite(++_countSpriteInVector);
}

int GraphicComponent::LoadSprites(EventKeyboard::KeyCode keyCode, 
									std::vector<std::string>& vecSprites)
{
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			vecSprites.push_back("walk-0001.png");
			vecSprites.push_back("walk-0002.png");
			vecSprites.push_back("walk-0003.png");
			vecSprites.push_back("walk-0004.png");
			vecSprites.push_back("walk-0005.png");
			vecSprites.push_back("walk-0006.png");
			vecSprites.push_back("walk-0007.png");
			vecSprites.push_back("walk-0008.png");

			return vecSprites.size();
		}
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			vecSprites.push_back("fall-0001.png");
			vecSprites.push_back("fall-0002.png");
			vecSprites.push_back("fall-0003.png");

			return vecSprites.size();
		}
		case EventKeyboard::KeyCode::KEY_A:
		{
			vecSprites.push_back("attack-0001.png");
			vecSprites.push_back("attack-0002.png");
			vecSprites.push_back("attack-0003.png");
			vecSprites.push_back("attack-0004.png");

			return vecSprites.size();
		}
	}
}

GraphicComponent::~GraphicComponent()
{

}