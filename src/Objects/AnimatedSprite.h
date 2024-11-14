#pragma once

#include <iostream>

#include "raylib.h"

using namespace std;

namespace AnimatedSprite
{
	struct AnimatedSprite
	{
		Texture2D texture;
		float scale;

		int currentFrame;
		float frameRate;
		float frameTimer;
	};
	
}