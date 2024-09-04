#pragma once
#include "Shared.h"

class Player
{
public:

	void init();

	void update();

	void draw();

private:

	void move();

	enum Level
	{
		level1, level2, level3, level4
	}lv;

	Array<TextureRegion> playerImage;
	Array<TextureRegion> playerSprites_Lv1;
	Array<TextureRegion> playerSprites_Lv2;
	Array<TextureRegion> playerSprites_Lv3;
	Array<TextureRegion> playerSprites_Lv4;
	double framePlayer;

	Vec2 playerPos{ 352, 800 };
	int32 moveSpeed = 150;
	int32 frameSpeed = 20;
};

extern Player player;
