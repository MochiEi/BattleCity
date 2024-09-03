#pragma once
#include <Siv3D.hpp>

struct GameData
{

};

using App = SceneManager< String, GameData >;

#include "Debug.h"
#include "Game.h"
#include "Player.h"

typedef struct
{
	double deltaTime;
}Base;

extern Base base;

void deltaTime();
