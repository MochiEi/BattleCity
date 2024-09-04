#include "Player.h"

void Player::init()
{
	Texture playerSprites{ U"example/image/player.png", TextureDesc::Mipped };

	for (int i = 0; i < 8; i++)
	{
		playerImage << playerSprites(64 * i, 0, 64, 64);
		playerSprites_Lv1 << playerSprites(64 * i, 0, 64, 64);
		playerSprites_Lv2 << playerSprites(64 * i, 64, 64, 64);
		playerSprites_Lv3 << playerSprites(64 * i, 128, 64, 64);
		playerSprites_Lv4 << playerSprites(64 * i, 192, 64, 64);
	}

	lv = level1;
}

void Player::update()
{
	move();
}

void Player::draw()
{
	if (playerImage.size() == 8)
		playerImage[(int)framePlayer].draw(playerPos);
}

void Player::move()
{
	
}
