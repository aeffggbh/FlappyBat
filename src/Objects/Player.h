#pragma once

#include "raylib.h"

#include "Objects/AnimatedSprite.h"
#include "Objects/Circle.h"


namespace Player
{
	const int flyFrames = 2;

	struct Player
	{
		int score;

		//Drawing
		Vector2 pos;
		AnimatedSprite::AnimatedSprite sprite;

		//Animation
		Rectangle flyAnimation[flyFrames];

		//Collision
		Circle::Circle collisionShape;

		//Speed
		Vector2 speed;
		float jumpSpeed;
		float fallSpeed;
	};

	extern Player player;

	void Load();
	void Draw();
	void Unload();
}
