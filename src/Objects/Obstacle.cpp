#include "Obstacle.h"

#include <iostream>

using namespace std;

namespace Obstacle
{
	Obstacle obstacle;

	static float screenWidth;
	static float screenHeight;

	static float obstacleWidth = 50;
	static float maxObstacleHeight;
	static float minObstacleHeight;

	void Load()
	{
		screenWidth = static_cast<float>(GetScreenWidth());
		screenHeight = static_cast<float>(GetScreenHeight());

		maxObstacleHeight = screenHeight / 2;
		minObstacleHeight = obstacleWidth;

		SetObstacle(obstacle);
	}

	void Draw()
	{
		for (int i = 0; i < obstacleParts; i++)
		{
			DrawRectangle(static_cast<int>(obstacle.pos[i].x),
				static_cast<int>(obstacle.pos[i].y),
				static_cast<int>(obstacle.collisionShapes[i].width),
				static_cast<int>(obstacle.collisionShapes[i].height),
				RED);
		}
	}

	void SetObstacle(Obstacle& obstacleToSet)
	{
		float dividedObstacleHeight = static_cast<float>(GetRandomValue(static_cast<int>(minObstacleHeight), static_cast<int>(maxObstacleHeight)));

		float obstacleSpace = 150.0f;

		for (int i = 0; i < obstacleParts; i++)
		{
			obstacleToSet.collisionShapes[i].width = obstacleWidth;
			obstacleToSet.collisionShapes[i].x = screenWidth + obstacleWidth;

			if (i == 0)
			{
				obstacleToSet.collisionShapes[i].height = dividedObstacleHeight;
				obstacleToSet.collisionShapes[i].y = 0;
			}
			else
			{
				obstacleToSet.collisionShapes[i].y = obstacleToSet.collisionShapes[i-1].y + obstacleToSet.collisionShapes[i - 1].height + obstacleSpace;

				obstacleToSet.collisionShapes[i].height = screenHeight - obstacleToSet.collisionShapes[i].y;
			}
			obstacleToSet.pos[i].x = obstacleToSet.collisionShapes[i].x;
			obstacleToSet.pos[i].y = obstacleToSet.collisionShapes[i].y;

		}

		obstacleToSet.speed = 500;
	}

	void Unload()
	{
		//Unload texture
	}
}
