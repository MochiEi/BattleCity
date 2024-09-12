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

	playerHitBox = { playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance * 2};
}

void Player::update()
{
	status();
	move();
	shot();
	collision();

	debug_changeLv();
}

void Player::draw()
{
	playerHitBox.draw();
	//gridHitBox.draw();

	if (playerImage.size() == 8)
		playerImage[(int)framePlayer].draw(playerPos);
}

void Player::status()
{
	playerImage.clear();

	if (lv == level1)
	{
		for (auto sprites : playerSprites_Lv1)
			playerImage << sprites;

		bulletLimit = 1;
		bulletSpeed = 600;
		bulletType = HE;
	}
	if (lv == level2)
	{
		for (auto sprites : playerSprites_Lv2)
			playerImage << sprites;

		bulletLimit = 1;
		bulletSpeed = 1000;
		bulletType = HE;
	}
	if (lv == level3)
	{
		for (auto sprites : playerSprites_Lv3)
			playerImage << sprites;

		bulletLimit = 2;
		bulletSpeed = 1000;
		bulletType = HE;
	}
	if (lv == level4)
	{
		for (auto sprites : playerSprites_Lv4)
			playerImage << sprites;

		bulletLimit = 2;
		bulletSpeed = 1000;
		bulletType = AP;
	}
}

void Player::move()
{
	//Print << gridCount;
	Print << playerHitBox;

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

	gridHitBox = { map.gridMap[gridPos.x][gridPos.y],64,64 };
}

void Player::shot()
{
	if (KeySpace.down())
	{
		if (bulletCount < bulletLimit)
		{
			bullet.isShot(bullet.player1, (int32)dir, playerPos, bulletSpeed);
			bulletCount++;
		}
	}
}

void Player::collision()
{
	playerHitBox = {  playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance  * 2};

	while (!map.playArea.contains(playerHitBox))
	{
		collisionRecovery(playerPos, gridCount, (int32)dir);

		playerHitBox = {  playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance  * 2};
	}

	for(int i = 0;i<enemy.max;i++)
	{
		while (enemy.enemyHitBox[i].intersects(playerHitBox))
		{
			collisionRecovery(playerPos, gridCount, (int32)dir);

			playerHitBox = {  playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance  * 2};
		}
	}
}

void Player::debug_changeLv()
{
	if (Key1.down())
		lv = level1;
	if (Key2.down())
		lv = level2;
	if (Key3.down())
		lv = level3;
	if (Key4.down())
		lv = level4;
}
