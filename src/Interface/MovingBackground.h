#pragma once
#include "raylib.h"

namespace MovingBackground
{
	struct MovingBackground
	{
		Texture2D texture;
		Vector2 pos;
		float speed;
	};
};

