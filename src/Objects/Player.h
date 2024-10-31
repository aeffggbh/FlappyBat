#pragma once

#include "raylib.h"

#include "Objects/Sprite.h"
#include "Objects/Circle.h"


namespace Player
{
	struct Player
	{
		int score;

		//Drawing
		Vector2 pos;
		Sprite::Sprite sprite;
		
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
