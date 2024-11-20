#pragma once

#include "raylib.h"

#include "Objects/AnimatedSprite.h"
#include "Objects/Circle.h"
#include "Interface/Text.h"


namespace Player
{
	const int flyFrames = 2;

	struct Player
	{
		int score;
		int playerNumber;

		Text::Text scoreText;

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

		float initialPosX;

		Color color;
		KeyboardKey jumpKey;
	};

	enum PlayerNum
	{
		player1Num = 1,
		player2Num
	};

	const Color player1Color = WHITE;
	const Color player2Color = RED;

	void Load(Player& player);

	void Init(Player& player, Color color, KeyboardKey jumpKey, int num, float startX);
	void Update(Player& player, bool& gameOnGoing);
	void Draw(Player player);
	void Unload(Player& player);
	void ResetPlayer(Player& player);
	void DrawScore(Player player);
}
