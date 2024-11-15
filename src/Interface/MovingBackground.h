#pragma once
#include "raylib.h"

namespace MovingBackground
{
	struct Background
	{
		Texture2D texture;
		Vector2 pos;

		/*float speed;*/
		float scale;

		//int repetitionCount;
	};
};

