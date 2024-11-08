#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/Parallax.h"


namespace PlayerNS = Player;
namespace ObstacleNS = Obstacle;

using namespace PlayerNS;
using namespace ObstacleNS;

using namespace std;


namespace Gameplay
{
	Buttons::Button pause;

	static const int fontSize = 40;

	static bool gameOnGoing = true;
	static bool gameStarted = false;

	static Texture2D background;

	//Player
	static void MovePlayer();
	static void PlayPlayerAnimation();
	static void PlayerJump();
	static void PlayerFall();

	//Enemy
	static void ManageObstacle();
	static void MoveObstacle(ObstacleNS::Obstacle& enemyToMove);
	static void KeepObstacleOnScreen(ObstacleNS::Obstacle& enemyToKeepOnScreen);
	static void ResetObstaclePosition(ObstacleNS::Obstacle& enemyToReset);

	//Collisions
	static bool CheckPlayerObstacleCollision();
	static bool CheckPlayerBottomCollision();
	static bool CheckPlayerTopCollision();

	void Load()
	{
		//pause = Buttons::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);

		PlayerNS::Load();
		ObstacleNS::Load();
		Parallax::Load();

		//background = LoadTexture("");

		gameOnGoing = true;
		gameStarted = false;
	}

	bool Update()
	{
		Parallax::Update();

		MovePlayer();
		PlayPlayerAnimation();
		PlayerFall();

		//Jump
		if (IsMouseButtonPressed(0) || IsKeyReleased(KEY_SPACE))
		{
			PlayerJump();
		}


		ManageObstacle();

		//Collisions
		if (CheckPlayerObstacleCollision() || CheckPlayerBottomCollision())
		{
			gameOnGoing = false;
		}

		if (CheckPlayerTopCollision())
		{
			//Hacer esto funcion
			player.speed = 0;
			player.collisionShape.center.y = player.collisionShape.radius + 1;
		}

		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		Parallax::Draw();

		PlayerNS::Draw();
		ObstacleNS::Draw();

		Buttons::Draw(pause, fontSize);
	}

	void Unload()
	{
		PlayerNS::Unload();
		UnloadTexture(background);
	}

	int GetRunScore()
	{
		return player.score;
	}


	//Player
	void MovePlayer()
	{
		player.collisionShape.center.y += player.speed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void PlayPlayerAnimation()
	{
		player.sprite.frameTimer += GetFrameTime();
		if (player.sprite.frameTimer >= player.sprite.frameRate)
		{
			player.sprite.frameTimer = 0.0f;
			player.sprite.currentFrame++;

			if (player.sprite.currentFrame >= PlayerNS::flyFrames)
			{
				player.sprite.currentFrame = 0;
			}
		}
	}

	void PlayerJump()
	{
		player.speed = player.jumpSpeed;
		
	}

	void PlayerFall()
	{
		player.speed += player.fallSpeed;
	}


	//Enemy
	void ManageObstacle()
	{
		MoveObstacle(obstacle);
		KeepObstacleOnScreen(obstacle);
	}

	void MoveObstacle(ObstacleNS::Obstacle& enemyToMove)
	{
		for (int i = 0; i < obstacleParts; i++)
		{
			enemyToMove.pos[i].x -= enemyToMove.speed * GetFrameTime();
			enemyToMove.collisionShapes[i].x = enemyToMove.pos[i].x;

		}
	}

	void KeepObstacleOnScreen(ObstacleNS::Obstacle& obstacleToKeepOnScreen)
	{
		if (obstacleToKeepOnScreen.pos[0].x + obstacleToKeepOnScreen.collisionShapes[0].width < 0)
		{
			ResetObstaclePosition(obstacleToKeepOnScreen);
		}
	}

	void ResetObstaclePosition(ObstacleNS::Obstacle& obstacleToReset)
	{
		ObstacleNS::SetObstacle(obstacleToReset);
	}


	//Collision
	bool CheckPlayerObstacleCollision()
	{
		float cx = player.collisionShape.center.x;
		float cy = player.collisionShape.center.y;
		float radius = player.collisionShape.radius;

		for (int i = 0; i < obstacleParts; i++)
		{
			float rx = obstacle.collisionShapes[i].x;
			float ry = obstacle.collisionShapes[i].y;
			float rw = obstacle.collisionShapes[i].width;
			float rh = obstacle.collisionShapes[i].height;

			float testX = cx;
			float testY = cy;

			if (cx < rx)
				testX = rx;
			else if (cx > rx + rw)
				testX = rx + rw;
			if (cy < ry)
				testY = ry;
			else if (cy > ry + rh)
				testY = ry + rh;


			float distX = cx - testX;
			float distY = cy - testY;
			float distance = std::sqrt((distX * distX) + (distY * distY));

			if (distance <= radius)
			{
				return true;
			}
		}

		return false;;
	}

	bool CheckPlayerBottomCollision()
	{
		return player.collisionShape.center.y + player.collisionShape.radius >= GetScreenHeight();
	}

	bool CheckPlayerTopCollision()
	{
		return player.collisionShape.center.y - player.collisionShape.radius <= 0;
	}


}