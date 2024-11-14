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

		Color color;
		KeyboardKey jumpKey;
	};

	void Load(Player& player);

	void Init(Player& player, Color color, KeyboardKey jumpKey);
	void Update(Player& player, bool& gameOnGoing);
	void Draw(Player player);
	void Unload(Player& player);
	void ResetPlayer(Player& player);
	int GetRunScore(Player& player);
}
