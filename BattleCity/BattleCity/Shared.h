#pragma once
#include <Siv3D.hpp>

struct GameData
{

};

using App = SceneManager< String, GameData >;

#include "Debug.h"
#include "Game.h"
#include "Player.h"
#include "Map.h"

 struct InputMoveKey
{
	bool inputW = false;
	bool inputA = false;
	bool inputS = false;
	bool inputD = false;
};

extern InputMoveKey moveKey;

bool pressedWASD(String pushKey);
