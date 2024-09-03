#pragma once
#include "Shared.h"

class Debug
{
public:

	void game()
	{
		gridLine();
	}

	void gridLine()
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				Rect(64 + 32 * i, 32 + 32 * j, 64, 64)
					.drawFrame(0, 1, Color(50, 50, 50));
			}
		}
	}
};

extern Debug debug;
