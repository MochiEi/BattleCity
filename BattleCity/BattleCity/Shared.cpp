#include "Shared.h"

Debug debug;
Share share;

Player player;
Enemy enemy;
Bullet bullet;
Map map;

bool pressedWASD(String pushKey)
{
	String W = U"W";
	String A = U"A";
	String S = U"S";
	String D = U"D";

	if (KeyW.pressed())
	{
		if (pushKey == W)
		{
			if (!share.inputA && !share.inputS && !share.inputD)
			{
				share.inputW = true;
				return true;
			}
		}
	}
	else
	{
		share.inputW = false;
	}

	if (KeyA.pressed())
	{
		if (pushKey == A)
		{
			if (!share.inputW && !share.inputS && !share.inputD)
			{
				share.inputA = true;
				return true;
			}
		}
	}
	else
	{
		share.inputA = false;
	}

	if (KeyS.pressed())
	{
		if (pushKey == S)
		{
			if (!share.inputW && !share.inputA && !share.inputD)
			{
				share.inputS = true;
				return true;
			}
		}
	}
	else
	{
		share.inputS = false;
	}

	if (KeyD.pressed())
	{
		if(pushKey == D)
		{
			if (!share.inputW && !share.inputA && !share.inputS)
			{
				share.inputD = true;
				return true;
			}
		}
	}
	else
	{
		share.inputD = false;
	}

	return false;
}

void collisionRecovery(Vec2& pos, Vec2& grid, int32 dir)
{
	enum Direction
	{
		up, down, left, right
	};

	if (dir == up)
	{
		pos.y += share.recoverySpeed * Scene::DeltaTime();
		grid.y += share.recoverySpeed * Scene::DeltaTime();
	}
	if (dir == down)
	{
		pos.y -= share.recoverySpeed * Scene::DeltaTime();
		grid.y -= share.recoverySpeed * Scene::DeltaTime();
	}
	if (dir == left)
	{
		pos.x += share.recoverySpeed * Scene::DeltaTime();
		grid.x += share.recoverySpeed * Scene::DeltaTime();
	}
	if (dir == right)
	{
		pos.x -= share.recoverySpeed * Scene::DeltaTime();
		grid.x -= share.recoverySpeed * Scene::DeltaTime();
	}
}
