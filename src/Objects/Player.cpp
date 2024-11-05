#include "Player.h"

#include "cmath"

#include "Utils/Utils.h"

using namespace Utils;

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	static float frameWidth;
	static float frameHeight;

	void Load()
	{
		player.score = 0;

		//Sprite
		player.sprite.texture = LoadTexture("res/Sprite/bat.png");
		player.sprite.scale = 3.0f;

		player.sprite.texture.width *= static_cast <int> (player.sprite.scale);
		player.sprite.texture.height *= static_cast <int> (player.sprite.scale);

		frameWidth = static_cast <float> (player.sprite.texture.width / flyFrames);
		frameHeight = static_cast <float> (player.sprite.texture.height);

		//Define fly frames
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

		//Sprite Center
		float spriteCenterX = static_cast <float>  (player.sprite.texture.width / flyFrames / 2);
		float spriteCenterY = static_cast <float> (player.sprite.texture.height / 2);
		spriteCenter = { spriteCenterX, spriteCenterY };

		player.pos =
		{
			static_cast<float>(GetScreenWidth() / 10),
			static_cast<float>(GetScreenHeight() / 2)
		};

		//Collision
		player.collisionShape.center = player.pos;
		player.collisionShape.radius = 22;

		//Speed
		player.jumpSpeed = -300.0f;
		player.fallSpeed = 0.4f;
		player.speed = 0;
	}

	void Draw()
	{
		//Collision
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.collisionShape.center.x), 
			static_cast <int>(player.collisionShape.center.y), 
			player.collisionShape.radius, 
			BLUE);
#endif // _DEBUG

		Vector2 drawingPos =
		{
			player.pos.x - (frameWidth / 2),
			player.pos.y - (frameHeight / 2)
		};

		//Sprite
			DrawTextureRec(
				player.sprite.texture,
				player.flyAnimation[player.sprite.currentFrame],
				drawingPos,
				WHITE
			);

		//Center
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.pos.x), static_cast <int>(player.pos.y), 5, YELLOW);
#endif // _DEBUG
	}

	void Unload()
	{
		UnloadTexture(player.sprite.texture);
	}
}

