#include "Shared.h"

Debug debug;
InputMoveKey moveKey;

Player player;
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
			if (!moveKey.inputA && !moveKey.inputS && !moveKey.inputD)
			{
				moveKey.inputW = true;
				return true;
			}
		}
	}
	else
	{
		moveKey.inputW = false;
	}

	if (KeyA.pressed())
	{
		if (pushKey == A)
		{
			if (!moveKey.inputW && !moveKey.inputS && !moveKey.inputD)
			{
				moveKey.inputA = true;
				return true;
			}
		}
	}
	else
	{
		moveKey.inputA = false;
	}

	if (KeyS.pressed())
	{
		if (pushKey == S)
		{
			if (!moveKey.inputW && !moveKey.inputA && !moveKey.inputD)
			{
				moveKey.inputS = true;
				return true;
			}
		}
	}
	else
	{
		moveKey.inputS = false;
	}

	if (KeyD.pressed())
	{
		if(pushKey == D)
		{
			if (!moveKey.inputW && !moveKey.inputA && !moveKey.inputS)
			{
				moveKey.inputD = true;
				return true;
			}
		}
	}
	else
	{
		moveKey.inputD = false;
	}

	return false;
}
