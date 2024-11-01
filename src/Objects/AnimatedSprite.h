#pragma once

#include "raylib.h"

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