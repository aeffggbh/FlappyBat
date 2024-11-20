#pragma once
#include "raylib.h"

namespace ColorManager
{
	enum Colors
	{
		Green,
		DarkGreen,
		AlphaBlack,
		Purple,
		Red
	};

	void InitColors();
	Color GetColor(Colors color);
}


