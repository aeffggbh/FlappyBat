#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/Parallax.h"

namespace ObstacleNS = Obstacle;

using namespace ObstacleNS;

using namespace std;


namespace Gameplay
{
	ObstacleNS::Obstacle obstacle;

	PlayerNS::Player player1;
	PlayerNS::Player player2;

	Buttons::Button pause;

	static const int fontSize = 40;

	static bool gameOnGoing = true;
	static bool gameStarted = false;
	static bool isMultiplayer = false;;

	static Texture2D background;

	//Player
	static void MovePlayer(PlayerNS::Player& player);
	static void PlayPlayerAnimation(PlayerNS::Player& player);
	static void PlayerJump(PlayerNS::Player& player);
	static void PlayerFall(PlayerNS::Player& player);
	static void ResetPlayer(PlayerNS::Player& player);

	//Enemy
	static void ManageObstacle();
	static void MoveObstacle(ObstacleNS::Obstacle& enemyToMove);
	static void KeepObstacleOnScreen(ObstacleNS::Obstacle& enemyToKeepOnScreen);
	static void ResetObstaclePosition(ObstacleNS::Obstacle& enemyToReset);

	//Collisions
	static bool CheckPlayerObstacleCollision(PlayerNS::Player player);
	static bool CheckPlayerBottomCollision(PlayerNS::Player player);
	static bool CheckPlayerTopCollision(PlayerNS::Player player);

	void Init()
	{
		ObstacleNS::Init(obstacle);
		gameOnGoing = true;
		gameStarted = false;
	}

	void Load()
	{
		//pause = Buttons::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);

		PlayerNS::Load(player1, WHITE, KEY_SPACE);
		PlayerNS::Load(player2, RED, KEY_UP);
		ObstacleNS::Load();
		Parallax::Load();

		//background = LoadTexture("");


	}

	bool Update()
	{
		Parallax::Update();

		ManageObstacle();

		UpdatePlayer(player1);

		if (isMultiplayer)
			UpdatePlayer(player2);

		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		Parallax::Draw();

		ObstacleNS::Draw(obstacle);
		PlayerNS::Draw(player1);
		if (isMultiplayer)
			Draw(player2);

		//Buttons::Draw(pause, fontSize);
	}

	void Unload()
	{
		PlayerNS::Unload(player1);
		PlayerNS::Unload(player2);
		UnloadTexture(background);
		Parallax::Unload();
	}

	void Reset()
	{
		ResetObstaclePosition(obstacle);
		ResetPlayer(player1);
		ResetPlayer(player2);
	}

	void UpdatePlayer(PlayerNS::Player& player)
	{
		MovePlayer(player);
		PlayPlayerAnimation(player);
		PlayerFall(player);
		PlayerJump(player);

		//Collisions
		if (CheckPlayerObstacleCollision(player) || CheckPlayerBottomCollision(player))
		{
			gameOnGoing = false;
		}

		if (CheckPlayerTopCollision(player))
		{
			//Hacer esto funcion
			player.collisionShape.center.y = player.collisionShape.radius;
		}
	}

	int GetRunScore(PlayerNS::Player& player)
	{
		return player.score;
	}

	void SetMultiplayer(bool multiplayerMode)
	{
		isMultiplayer = multiplayerMode;
	}

	//Player
	void MovePlayer(PlayerNS::Player& player)
	{
		player.collisionShape.center.y += player.speed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void PlayPlayerAnimation(PlayerNS::Player& player)
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

	void PlayerJump(PlayerNS::Player& player)
	{
		if (IsKeyPressed(player.jumpKey))
			player.speed = player.jumpSpeed;

	}

	void PlayerFall(PlayerNS::Player& player)
	{
		player.speed += player.fallSpeed;
	}

	void ResetPlayer(PlayerNS::Player& player)
	{
		player.collisionShape.center.x = static_cast<float>(GetScreenWidth()) / 4.0f;
		player.collisionShape.center.y = static_cast<float>(GetScreenHeight()) / 2.0f;
		player.speed = 0;
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
	bool CheckPlayerObstacleCollision(PlayerNS::Player player)
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

	bool CheckPlayerBottomCollision(PlayerNS::Player player)
	{
		return player.collisionShape.center.y + player.collisionShape.radius >= GetScreenHeight();
	}

	bool CheckPlayerTopCollision(PlayerNS::Player player)
	{
		return player.collisionShape.center.y - player.collisionShape.radius <= 0;
	}


}