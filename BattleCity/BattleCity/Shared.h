#pragma once
#include <Siv3D.hpp>

struct GameData
{

};

using App = SceneManager< String, GameData >;

#include "Debug.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"

 struct Share
{
	/// 移動制御 ///
	bool inputW = false;
	bool inputA = false;
	bool inputS = false;
	bool inputD = false;

	/// 衝突復帰 ///
	int32 recoverySpeed = 1;

	/// 当たり判定許容値 ///
	int32 tolerance = 1;
};

extern Share share;

bool pressedWASD(String pushKey);

void collisionRecovery(Vec2& pos, Vec2& grid, int32 dir);
