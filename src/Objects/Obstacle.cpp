#include "Obstacle.h"

#include <iostream>

using namespace std;

namespace Obstacle
{

	static float screenWidth;
	static float screenHeight;

	static float obstacleWidth = 50;
	static float maxObstacleHeight;
	static float minObstacleHeight;

	static void ManageObstacle(Obstacle& obstacle);
	static void MoveObstacle(Obstacle& enemyToMove);
	static void KeepObstacleOnScreen(Obstacle& enemyToKeepOnScreen);

	void Load(Obstacle& obstacle)
	{
		screenWidth = static_cast<float>(GetScreenWidth());
		screenHeight = static_cast<float>(GetScreenHeight());

		maxObstacleHeight = screenHeight / 2;
		minObstacleHeight = obstacleWidth;

		SetObstacle(obstacle);
	}

	void Update(Obstacle& obstacle)
	{
		ManageObstacle(obstacle);
	}

	void Draw(Obstacle obstacle)
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

	void ResetObstacle(Obstacle& obstacleToReset)
	{
		SetObstacle(obstacleToReset);
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

	void ManageObstacle(Obstacle& obstacle)
	{
		MoveObstacle(obstacle);
		KeepObstacleOnScreen(obstacle);
	}

	void MoveObstacle(Obstacle& enemyToMove)
	{
		for (int i = 0; i < obstacleParts; i++)
		{
			enemyToMove.pos[i].x -= enemyToMove.speed * GetFrameTime();
			enemyToMove.collisionShapes[i].x = enemyToMove.pos[i].x;

		}
	}

	void KeepObstacleOnScreen(Obstacle& obstacleToKeepOnScreen)
	{
		if (obstacleToKeepOnScreen.pos[0].x + obstacleToKeepOnScreen.collisionShapes[0].width < 0)
		{
			ResetObstacle(obstacleToKeepOnScreen);
		}
	}

	
}
