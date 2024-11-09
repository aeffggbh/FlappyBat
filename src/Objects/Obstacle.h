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


	void Init(Obstacle& obstacle);
	void Load();
	void Draw(Obstacle obstacle);
	void SetObstacle(Obstacle& obstacle);
	void Unload();
};

