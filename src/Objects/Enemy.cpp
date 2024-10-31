#include "Enemy.h"

#include <iostream>

namespace Enemy
{
	Enemy enemy;

	static float width = 50;
	static float height = 350;

	static float screenWidth = static_cast<float>(GetScreenWidth());
	static float screenHeight = static_cast<float>(GetScreenHeight());

	void Load()
	{
		enemy.collisionShape.width = width;
		enemy.collisionShape.height = height;
		enemy.collisionShape.x = screenWidth - width;
		enemy.collisionShape.y = static_cast<float> (rand() % static_cast<int>(screenHeight - height));

		enemy.pos.x = enemy.collisionShape.x;
		enemy.pos.y = enemy.collisionShape.y;

		enemy.speed = 500;
	}

	void Draw()
	{
		DrawRectangle(static_cast<int>(enemy.pos.x),
			static_cast<int>(enemy.pos.y),
			static_cast<int>(enemy.collisionShape.width),
			static_cast<int>(enemy.collisionShape.height),
			RED);
	}

	void Unload()
	{

	}
}
