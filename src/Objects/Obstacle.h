#pragma once

#include "raylib.h"

namespace Obstacle
{
	const int obstacleParts = 2;

	struct Obstacle
	{
		Rectangle collisionShapes[obstacleParts];
		Vector2 pos[obstacleParts];
		float speed;
	};


	void Load(Obstacle& obstacle);
	void Update(Obstacle& obstacle);
	void Draw(Obstacle obstacle);
	void SetObstacle(Obstacle& obstacle);
	void Unload();
	void ResetObstacle(Obstacle& enemyToReset);
};

