#pragma once

#include "Objects/Sprite.h"

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
		float hSpeed;
		float vSpeed;
		float originX;
		float offSetY;
		float finishX;
		bool addedScore;
		bool movesVertical;
		Color color;
	};


	void Load();

	void Init(Obstacle& obstacle, float originX, float speed, Color color);
	void Update(Obstacle& obstacle);
	void Draw(Obstacle obstacle);
	void SetObstacle(Obstacle& obstacle);
	void Unload();
	void ResetObstacle(Obstacle& enemyToReset);
};

