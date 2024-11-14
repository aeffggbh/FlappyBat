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

	//Enemy
	

	//Collisions
	static bool CheckPlayerObstacleCollision(PlayerNS::Player player);

	void Init()
	{
		ObstacleNS::Load(obstacle);
		gameOnGoing = true;
		gameStarted = false;
	}

	void Load()
	{
		//pause = Buttons::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);

		PlayerNS::Load(player1, WHITE, KEY_SPACE);
		PlayerNS::Load(player2, RED, KEY_UP);
		ObstacleNS::Load(obstacle);
		Parallax::Load();

	}

	bool Update()
	{
		Parallax::Update();

		ObstacleNS::Update(obstacle);

		PlayerNS::Update(player1, gameOnGoing);

		if (isMultiplayer)
			PlayerNS::Update(player2, gameOnGoing);

		if (CheckPlayerObstacleCollision(player1) || CheckPlayerObstacleCollision(player2))
			gameOnGoing = false;
		

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
		ObstacleNS::ResetObstacle(obstacle);
		PlayerNS::ResetPlayer(player1);
		PlayerNS::ResetPlayer(player2);
	}

	void SetMultiplayer(bool multiplayerMode)
	{
		isMultiplayer = multiplayerMode;
	}

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


}