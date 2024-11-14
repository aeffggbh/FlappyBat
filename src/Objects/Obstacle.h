#pragma once

#include "Objects//Sprite.h"

#include "raylib.h"

namespace Obstacle
{
	const int obstacleParts = 2;
	const int frames = 3;

	struct ObstaclePart
	{
		Rectangle collisionShape;
		Sprite::Sprite spriteParts[frames];
		Vector2 pos;
		int trunkRepetitions;
	};

	struct Obstacle
	{
		ObstaclePart parts[obstacleParts];
		float speed;
	};


	void Load();

	void Init(Obstacle& obstacle);
	void Update(Obstacle& obstacle);
	void Draw(Obstacle obstacle);
	void SetObstacle(Obstacle& obstacle);
	void Unload();
	void ResetObstacle(Obstacle& enemyToReset);
};

