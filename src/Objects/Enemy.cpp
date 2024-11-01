#include "Enemy.h"

#include <iostream>

using namespace std;

namespace Enemy
{
	Enemy enemy;

	static float obstacleWidth = 50;
	static float totalObstacleHeight = 350;

	static float screenWidth;
	static float screenHeight;

	void Load()
	{
		screenWidth = static_cast<float>(GetScreenWidth());
		screenHeight = static_cast<float>(GetScreenHeight());

		SetEnemy(enemy);
	}

	void Draw()
	{
		for (int i = 0; i < obstacleParts; i++)
		{
			DrawRectangle(static_cast<int>(enemy.pos[i].x),
				static_cast<int>(enemy.pos[i].y),
				static_cast<int>(enemy.collisionShapes[i].width),
				static_cast<int>(enemy.collisionShapes[i].height),
				RED);
		}
	}

	void SetEnemy(Enemy& enemyToSet)
	{
		float dividedObstacleHeight = static_cast<float>(rand() % static_cast <int>(totalObstacleHeight));

		for (int i = 0; i < obstacleParts; i++)
		{
			enemyToSet.collisionShapes[i].width = obstacleWidth;
			enemyToSet.collisionShapes[i].x = screenWidth - obstacleWidth;

			if (i == 0)
			{
				enemyToSet.collisionShapes[i].height = dividedObstacleHeight;
				enemyToSet.collisionShapes[i].y = 0;
			}
			else
			{
				dividedObstacleHeight = totalObstacleHeight - dividedObstacleHeight;

				enemyToSet.collisionShapes[i].height = dividedObstacleHeight;
				enemyToSet.collisionShapes[i].y = screenHeight - enemyToSet.collisionShapes[i].height;
			}
			enemyToSet.pos[i].x = enemyToSet.collisionShapes[i].x;
			enemyToSet.pos[i].y = enemyToSet.collisionShapes[i].y;

			cout << enemyToSet.pos[i].x << " " << enemyToSet.pos[i].y << endl;
		}

		cout << endl << endl;

		enemyToSet.speed = 500;
	}

	void Unload()
	{
		//Unload texture
	}
}
