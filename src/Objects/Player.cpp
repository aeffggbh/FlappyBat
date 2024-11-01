#include "Player.h"

#include "cmath"

#include "Utils/Utils.h"

using namespace Utils;

namespace Player
{
	Player player;
	static Vector2 spriteCenter;

	void Load()
	{
		player.score = 0;

		//Sprite
		player.sprite.texture = LoadTexture("");
		player.sprite.scale = 1.75f;
		player.sprite.source =
		{
			0,
			0,
			static_cast<float>(player.sprite.texture.width),
			static_cast<float>(player.sprite.texture.height)
		};

		player.pos.x = static_cast<float>(GetScreenWidth()) / 10;
		player.pos.y = static_cast<float>(GetScreenHeight() / 2);

		float destinationWidth = player.sprite.texture.width * player.sprite.scale;
		float destinationHeight = player.sprite.texture.height * player.sprite.scale;

		player.sprite.destination =
		{
			player.pos.x,
			player.pos.y,
			destinationWidth,
			destinationHeight
		};

		float spriteCenterX = player.sprite.texture.width * player.sprite.scale / 2;
		float spriteCenterY = player.sprite.texture.height * player.sprite.scale / 2;
		spriteCenter = { spriteCenterX, spriteCenterY };

		//Collision
		player.collisionShape.center = player.pos;
		player.collisionShape.radius = 25;

		//Speed
		player.jumpSpeed = 500000.0f;
		player.fallSpeed = 400.0f;
		player.speed = { 0,0 };
	}

	void Draw()
	{
		//Collision
#ifdef _DEBUG
		DrawCircle(static_cast <int>(player.collisionShape.center.x), static_cast <int>(player.collisionShape.center.y), player.collisionShape.radius, BLUE);
#endif // _DEBUG

		//Sprite
		DrawTexturePro(
			player.sprite.texture,
			player.sprite.source,
			player.sprite.destination,
			spriteCenter,
			player.sprite.rotation,
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

