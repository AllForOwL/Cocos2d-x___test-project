#ifndef __BREED_GRAPHIC_COMPONENT_H__
#define __BREED_GRAPHIC_COMPONENT_H__

#include "cocos2d.h"
#include "GraphicComponent.h"

using namespace std;
using namespace cocos2d;

class Monster;

class BreedGraphicComponent : public GraphicComponent
{
public:
	BreedGraphicComponent(int attack, int health, const std::string& typeObject);
	BreedGraphicComponent(BreedGraphicComponent& breed);

	virtual void Update(Monster& hero, GameScene& scene);

	void		LoadSpritesForSoldier();
	int			GetAttack()   const;
	int			GetHealth()   const;
	std::string GetTypeObject() const;

	~BreedGraphicComponent();

private:
	int m_attack;
	int m_health;
	std::string m_typeObject;
	
	std::vector<cocos2d::Sprite*> m_vecSpritesWalkSoldier;
	std::vector<cocos2d::Sprite*> m_vecSpritesShotFrontSoldier;
	std::vector<cocos2d::Sprite*> m_vecSpritesShotUpSoldier;
	
	int	m_countSpritesInVectorWalkSoldier;
	int	m_countSpritesInVectorShotFrontSoldier;
	int	m_countSpritesInVectorShotUpSoldier;
};
#endif