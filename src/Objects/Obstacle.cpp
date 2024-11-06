#include "Obstacle.h"

#include <iostream>

using namespace std;

namespace Obstacle
{
	Obstacle obstacle;

	static float obstacleWidth = 50;
	static float totalObstacleHeight = 450;

	static float screenWidth;
	static float screenHeight;

	void Load()
	{
		screenWidth = static_cast<float>(GetScreenWidth());
		screenHeight = static_cast<float>(GetScreenHeight());

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
		float dividedObstacleHeight = static_cast<float>(rand() % static_cast <int>(totalObstacleHeight));

		for (int i = 0; i < obstacleParts; i++)
		{
			obstacleToSet.collisionShapes[i].width = obstacleWidth;
			obstacleToSet.collisionShapes[i].x = screenWidth + 5;

			if (i == 0)
			{
				obstacleToSet.collisionShapes[i].height = dividedObstacleHeight;
				obstacleToSet.collisionShapes[i].y = 0;
			}
			else
			{
				dividedObstacleHeight = totalObstacleHeight - dividedObstacleHeight;

				obstacleToSet.collisionShapes[i].height = dividedObstacleHeight;
				obstacleToSet.collisionShapes[i].y = screenHeight - obstacleToSet.collisionShapes[i].height;
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
