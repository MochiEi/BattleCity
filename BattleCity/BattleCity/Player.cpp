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

	playerHitBox = { playerPos,64,64 };
}

void Player::update()
{
	move();
	collision();
}

void Player::draw()
{
	//playerHitBox.draw();
	//gridHitBox.draw();

	if (playerImage.size() == 8)
		playerImage[(int)framePlayer].draw(playerPos);
}

void Player::move()
{
	//Print << gridCount;
	//Print << playerHitBox;

	if (pressedWASD(U"W"))
	{
		dir = up;

		playerPos.x = gridHitBox.x;
		playerPos.y -= moveSpeed * Scene::DeltaTime();

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 0 || framePlayer >= 2) framePlayer = 0;

		gridCount.x = 0;

		gridCount.y -= moveSpeed * Scene::DeltaTime();

		if (gridCount.y < -16)
		{
			gridCount.y += 32;
			gridPos.y--;
		}
	}

	if (pressedWASD(U"S"))
	{
		dir = down;

		playerPos.x = gridHitBox.x;
		playerPos.y += moveSpeed * Scene::DeltaTime();

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 2 || framePlayer >= 4) framePlayer = 2;

		gridCount.x = 0;

		gridCount.y += moveSpeed * Scene::DeltaTime();

		if (gridCount.y > 16)
		{
			gridCount.y -= 32;

			gridPos.y++;
		}
	}

	if (pressedWASD(U"A"))
	{
		dir = left;

		playerPos.y = gridHitBox.y;
		playerPos.x -= moveSpeed * Scene::DeltaTime();

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 4 || framePlayer >= 6) framePlayer = 4;

		gridCount.y = 0;

		gridCount.x -= moveSpeed * Scene::DeltaTime();

		if (gridCount.x < -16)
		{
			gridCount.x += 32;

			gridPos.x--;
		}
	}

	if (pressedWASD(U"D"))
	{
		dir = right;

		playerPos.y = gridHitBox.y;
		playerPos.x += moveSpeed * Scene::DeltaTime();

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 6 || framePlayer >= 8) framePlayer = 6;

		gridCount.y = 0;

		gridCount.x += moveSpeed * Scene::DeltaTime();

		if (gridCount.x > 16)
		{
			gridCount.x -= 32;

			gridPos.x++;
		}
	}

	playerHitBox = { playerPos,64,64 };
	gridHitBox = { map.gridMap[gridPos.x][gridPos.y],64,64 };
}

void Player::collision()
{
	while (!map.playArea.contains(playerHitBox))
	{
		if (dir == up)
		{
			playerPos.y += removeSpeed * Scene::DeltaTime();
			gridCount.y = 0;
		}
		if (dir == down)
		{
			playerPos.y -= removeSpeed * Scene::DeltaTime();
			gridCount.y = 0;
		}
		if (dir == left)
		{
			playerPos.x += removeSpeed * Scene::DeltaTime();
			gridCount.x = 0;
		}
		if (dir == right)
		{
			playerPos.x -= removeSpeed * Scene::DeltaTime();
			gridCount.x = 0;
		}
		playerHitBox = { playerPos,64,64 };
	}
}
