#pragma once
#include "Shared.h"

class Map
{
public:

	void init();

	void update();

	void draw();

	Grid<Point> gridMap{ 25,25 };

	Rect playArea{ 64,32,832,832 };

private:

	Array<TextureRegion> frame;
	double frameNo = 2;
};

extern Map map;
