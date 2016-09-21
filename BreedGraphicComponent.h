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

	enum ActiveEnemy
	{
		ACTIVE_SOLDIER,
		ACTIVE_TANK,
		ACTIVE_TURRET
	};

	BreedGraphicComponent(int attack, int health, const std::string& typeObject);
	BreedGraphicComponent(BreedGraphicComponent& breed);

	virtual void Update(Monster& hero, GameScene& scene);

	void		LoadSpritesForSoldier();
	void		LoadSpritesForTanks();
	void		LoadSpritesForTurrets();
	void		LoadSpritesForAirplanes();

	void		Fire();
	void		Move();
	void		Attack();
	void		Death();

	int			GetAttack()   const;
	int			GetHealth()   const;
	std::string GetTypeObject() const;

	~BreedGraphicComponent();

private:
	int m_attack;
	int m_health;
	std::string m_typeObject;
	
	std::vector<std::string> m_vecDefaultNamesMove;
	std::vector<std::string> m_vecDefaultNamesFire;
	std::vector<std::string> m_vecDefaultNamesDeath;

	int	m_countDefaultSpriteInMove;
	int m_countDefaultSpriteInFire;
	int m_countDefaultSpriteInDeath;

	ActiveEnemy	m_activeEnemy;

	/*std::vector<std::string> m_vecSpritesNamesWalkSoldier;
	std::vector<std::string> m_vecSpritesNamesShotFrontSoldier;
	std::vector<std::string> m_vecSpritesNamesShotUpSoldier;
	
	std::vector<std::string> m_vecSpritesNameMoveTanks;
	std::vector<std::string> m_vecSpritesNameAttackTanks;
	std::vector<std::string> m_vecSpritesNameDeathTanks;

	int	m_countSpritesInVectorWalkSoldier;
	int	m_countSpritesInVectorShotFrontSoldier;
	int	m_countSpritesInVectorShotUpSoldier;

	int	m_countSpritesInVectorMoveTank;
	int	m_countSpritesInVectorAttackTank;
	int	m_countSpritesInVectorDeathTank;&=*/
};
#endif