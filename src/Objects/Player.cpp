#include "Player.h"

#include <iostream>
#include <string>

#include "Utils/Utils.h"
#include "Utils/SoundManager.h"

using namespace std;
using namespace Utils;

namespace Player
{
	static float frameWidth;
	static float frameHeight;

	static Text::Text auxScoreText;

	static void InitSprite(Player& player);

	static void InitAnimation(Player& player);
	static void MovePlayer(Player& player);
	static void PlayPlayerAnimation(Player& player);
	static void PlayerJump(Player& player);
	static void PlayerFall(Player& player);
	static bool CheckPlayerBottomCollision(Player player);
	static bool CheckPlayerTopCollision(Player player);
	static void UpdateScoreText(Player& player);

	void Load(Player& player)
	{
		player.sprite.texture = LoadTexture("res/Sprites/bat.png");
	}

	void Init(Player& player, Color color, KeyboardKey jumpKey, int num, float startX)
	{
		player.score = 0;
		player.playerNumber = num;

		//Sprite
		InitSprite(player);

		//Define fly frames
		InitAnimation(player);

		player.initialPosX = startX;

		player.pos =
		{
			player.initialPosX,
			static_cast<float>(GetScreenHeight() / 2)
		};

		//Collision
		player.collisionShape.center = player.pos;
		player.collisionShape.radius = static_cast<float>(player.sprite.texture.height) / 4.0f;

		//Speed
		player.jumpSpeed = 400.0f;
		player.fallSpeed = 0.25f;
		player.speed = 0;

		//Distinctive values (when in multiplayer)
		player.color = color;
		player.jumpKey = jumpKey;
	}

	void Update(Player& player, bool& gameOnGoing)
	{
		UpdateScoreText(player);
		MovePlayer(player);
		PlayPlayerAnimation(player);
		PlayerFall(player);
		PlayerJump(player);

		//Collisions
		if (CheckPlayerBottomCollision(player))
		{
			gameOnGoing = false;
		}

		if (CheckPlayerTopCollision(player))
		{
			player.collisionShape.center.y = player.collisionShape.radius;
		}
	}

	void Draw(Player player)
	{
		Vector2 drawingPos =
		{
			player.pos.x - (frameWidth / 2),
			player.pos.y - (frameHeight / 2)
		};

		if (player.playerNumber == player2Num)
			player.flyAnimation[player.sprite.currentFrame].width *= -1;


		//Sprite
		DrawTextureRec(
			player.sprite.texture,
			player.flyAnimation[player.sprite.currentFrame],
			drawingPos,
			player.color
		);

		DrawScore(player);
	}

	void Unload(Player& player)
	{
		UnloadTexture(player.sprite.texture);
	}

	void ResetPlayer(Player& player)
	{
		player.score = 0;
		player.collisionShape.center.x = player.initialPosX;
		player.collisionShape.center.y = static_cast<float>(GetScreenHeight()) / 2.0f;
		player.speed = 0;
	}

	void DrawScore(Player player)
	{
		Text::Draw(player.scoreText);
	}

	void InitSprite(Player& player)
	{
		player.sprite.scale = 2.0f;

		player.sprite.texture.width *= static_cast <int> (player.sprite.scale);
		player.sprite.texture.height *= static_cast <int> (player.sprite.scale);

		frameWidth = static_cast <float> (player.sprite.texture.width / flyFrames);
		frameHeight = static_cast <float> (player.sprite.texture.height);
	}

	void InitAnimation(Player& player)
	{
		for (int i = 0; i < flyFrames; i++)
		{
			player.flyAnimation[i] = {
				frameWidth * i,
				0,
				frameWidth,
				frameHeight
			};
		}

		player.sprite.currentFrame = 0;
		player.sprite.frameTimer = 0.0f;
		player.sprite.frameRate = 0.09f;
	}

	void MovePlayer(Player& player)
	{
		player.collisionShape.center.y += player.speed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void PlayPlayerAnimation(Player& player)
	{
		player.sprite.frameTimer += GetFrameTime();
		if (player.sprite.frameTimer >= player.sprite.frameRate)
		{
			player.sprite.frameTimer = 0.0f;
			player.sprite.currentFrame++;

			if (player.sprite.currentFrame >= flyFrames)
			{
				player.sprite.currentFrame = 0;
			}
		}
	}

	void PlayerJump(Player& player)
	{
		if (IsKeyPressed(player.jumpKey))
		{
			if (!SoundManager::IsPlaying(SoundManager::Sfx::jumpSfx))
				SoundManager::Play(SoundManager::Sfx::jumpSfx);

			player.speed = -player.jumpSpeed;
		}

	}

	void PlayerFall(Player& player)
	{
		player.speed += player.fallSpeed;
	}

	bool CheckPlayerBottomCollision(Player player)
	{
		return player.collisionShape.center.y + player.collisionShape.radius >= GetScreenHeight();
	}

	bool CheckPlayerTopCollision(Player player)
	{
		return player.collisionShape.center.y - player.collisionShape.radius <= 0;
	}

	void UpdateScoreText(Player& player)
	{
		string score = "SCORE: " + to_string(player.score);

		auxScoreText = Text::CreateText(score, static_cast<int>(Text::FontSize::medium), { static_cast<float>(Text::Padding::small), static_cast<float>(GetScreenHeight()) - static_cast<float>(Text::FontSize::medium) - static_cast<float>(Text::Padding::small) }, player.color, Text::Fonts::generalText);

		if (player.playerNumber == player2Num)
			auxScoreText.pos.x = static_cast<float>(GetScreenWidth()) - static_cast<float>(MeasureText(auxScoreText.content.c_str(), auxScoreText.fontSize));

		player.scoreText = auxScoreText;

	}
}

