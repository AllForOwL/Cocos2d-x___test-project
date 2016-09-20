const int CNT_NUMBER_SPRITES_WALK	= 8;
const int CNT_NUMBER_SPRITES_RUN	= 7;
const int CNT_NUMBER_SPRITES_ATTACK = 4;
const int CNT_NUMBER_SPRITES_DIE	= 4;
const int CNT_NUMBER_SPRITES_DIZZY	= 3;

const int CNT_TAG_AIRPLANE			= 0;
const int CNT_TAG_BOY				= 1;
const int CNT_TAG_TANK				= 2;
const int CNT_TAG_BULLET			= 100;

const int CNT_TIME_SPAWN			= 5;
const float CNT_TIME_UPDATE_SCENE	= 10;

const std::string CNT_NAME_HERO_HELL		= "Hell";

const std::string CNT_NAME_ENEMY_SOLDIER	= "Soldier";
const std::string CNT_NAME_ENEMY_TANK		= "Tank";
const std::string CNT_NAME_ENEMY_TURRET		= "Turret";

const std::string CNT_NAME_WEAPON_AK		= "AK-47";

const std::string CNT_NAME_BULLET_DEFAULT	= "BULLET_NORMAL";

#define HERO_COLLISION_BITMASK		0x000001
#define ENEMY_COLLISION_BITMASK		0x000002
#define BULLET_COLLISION_BITMASK	0x000003
#define SCENE_COLLISION_BITMASK		0x000004
