#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/Parallax.h"
#include "Utils/SoundManager.h"
#include "Scenes/GameOver.h"



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
	static bool isMultiplayer;

	static const int scoreAdd = 100;

	static Texture2D background;

	static bool CheckPlayerObstacleCollision(PlayerNS::Player player);
	static void CountScore(PlayerNS::Player& player, ObstacleNS::Obstacle& obstacle);
	//static void DrawScores(PlayerNS::Player player1, PlayerNS::Player player2);

	void Init()
	{
		pause = Buttons::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);
		ObstacleNS::Init(obstacle);
		gameOnGoing = true;
		gameStarted = false;
		PlayerNS::Init(player1, Player::player1Color, KEY_SPACE, Player::player1Num);
		PlayerNS::Init(player2, Player::player2Color, KEY_UP, Player::player2Num);
		ObstacleNS::Init(obstacle);
	}

	void Load()
	{
		PlayerNS::Load(player1);
		PlayerNS::Load(player2);
		ObstacleNS::Load();
	}

	bool Update()
	{
		if (!SoundManager::IsPlaying(SoundManager::Song::gameplay))
			SoundManager::Play(SoundManager::Song::gameplay);
		else
			SoundManager::Update(SoundManager::Song::gameplay);

		ObstacleNS::Update(obstacle);

		PlayerNS::Update(player1, gameOnGoing);

		CountScore(player1, obstacle);

		if (isMultiplayer)
		{
			CountScore(player2, obstacle);
			PlayerNS::Update(player2, gameOnGoing);

		}

		if (CheckPlayerObstacleCollision(player1) || CheckPlayerObstacleCollision(player2))
			gameOnGoing = false;

	
		if (!gameOnGoing)
		{
			if (isMultiplayer)
				GameOver::SaveScores(player1.score, player2.score);
			else
				GameOver::SaveScores(player1.score);
		}

		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		ParallaxBackground::Draw();

		ObstacleNS::Draw(obstacle);
		PlayerNS::Draw(player1);
		if (isMultiplayer)
			Draw(player2);

		Buttons::Draw(pause, fontSize);
	}

	void Unload()
	{
		PlayerNS::Unload(player1);
		PlayerNS::Unload(player2);
		UnloadTexture(background);
		ParallaxBackground::Unload();
		ObstacleNS::Unload();
	}

	void Reset()
	{
		ObstacleNS::ResetObstacle(obstacle);
		PlayerNS::ResetPlayer(player1);
		PlayerNS::ResetPlayer(player2);
		gameOnGoing = true;
	}

	void SetMultiplayer(bool multiplayerMode)
	{
		isMultiplayer = multiplayerMode;
	}

	bool IsMultiplayerMode()
	{
		return isMultiplayer;
	}

	bool CheckPlayerObstacleCollision(PlayerNS::Player player)
	{
		float cx = player.collisionShape.center.x;
		float cy = player.collisionShape.center.y;
		float radius = player.collisionShape.radius;

		for (int i = 0; i < obstacleParts; i++)
		{
			float rx = obstacle.parts[i].collisionShape.x;
			float ry = obstacle.parts[i].collisionShape.y;
			float rw = obstacle.parts[i].collisionShape.width;
			float rh = obstacle.parts[i].collisionShape.height;

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

	void CountScore(PlayerNS::Player& player, ObstacleNS::Obstacle& obstacleToGetThrough)
	{
		if (static_cast<int>(player.collisionShape.center.x) == static_cast<int>(obstacleToGetThrough.parts[0].collisionShape.x + obstacleToGetThrough.parts[0].collisionShape.width / 2.0f)
			&& !obstacleToGetThrough.addedScore)
		{
			player.score += scoreAdd;
			obstacleToGetThrough.addedScore = true;
		}

		/*cout << "PLAYER X: " << player.collisionShape.center.x << endl;
		cout << "OBSTACLE X: " << obstacleToGetThrough.parts[0].collisionShape.x + obstacleToGetThrough.parts[0].collisionShape.width / 2.0f << endl;*/

	}


}