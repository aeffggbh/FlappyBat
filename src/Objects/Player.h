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
		float speed;
		float jumpSpeed;
		float fallSpeed;
	};

	void Load(Player& player);
	void Draw(Player player);
	void Unload(Player& player);
}
