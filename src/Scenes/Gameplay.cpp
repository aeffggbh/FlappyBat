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
#include "Interface/ColorManager.h"

namespace ObstacleNS = Obstacle;

using namespace ObstacleNS;

using namespace std;


namespace Gameplay
{
	ObstacleNS::Obstacle obstacle;
	ObstacleNS::Obstacle obstacle2;

	PlayerNS::Player player1;
	PlayerNS::Player player2;

	Buttons::Button pause;

	static bool gameOnGoing = true;
	static bool gameStarted = false;
	static bool isMultiplayer;

	static const int scoreAdd = 100;

	static Texture2D background;

	static bool CheckPlayerObstacleCollision(PlayerNS::Player player, ObstacleNS::Obstacle obstacle);
	static void CountScore(PlayerNS::Player& player, ObstacleNS::Obstacle& obstacle);

	void Init()
	{
		pause = Buttons::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);
		gameOnGoing = true;
		gameStarted = false;
		PlayerNS::Init(player1, Player::player1Color, KEY_SPACE, Player::player1Num, static_cast<float>(GetScreenWidth() / 4));
		PlayerNS::Init(player2, Player::player2Color, KEY_UP, Player::player2Num, static_cast<float>(GetScreenWidth() - GetScreenWidth() /4));
		
		ObstacleNS::Init(obstacle, static_cast<float>(GetScreenWidth()), 1, WHITE);
		ObstacleNS::Init(obstacle2, 0, -1, ColorManager::GetColor(ColorManager::Red));
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
			ObstacleNS::Update(obstacle2);
			
			PlayerNS::Update(player2, gameOnGoing);

			CountScore(player2, obstacle2);

		}

		if (CheckPlayerObstacleCollision(player1, obstacle) || CheckPlayerObstacleCollision(player2, obstacle2))
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
		{
			Draw(player2);
			ObstacleNS::Draw(obstacle2);
		}

		Buttons::Draw(pause, static_cast<int>(Text::FontSize::medium));
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
		ObstacleNS::ResetObstacle(obstacle2);
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

	bool CheckPlayerObstacleCollision(PlayerNS::Player player, ObstacleNS::Obstacle collisionObstacle)
	{
		float cx = player.collisionShape.center.x;
		float cy = player.collisionShape.center.y;
		float radius = player.collisionShape.radius;

		for (int i = 0; i < obstacleParts; i++)
		{
			float rx = collisionObstacle.parts[i].collisionShape.x;
			float ry = collisionObstacle.parts[i].collisionShape.y;
			float rw = collisionObstacle.parts[i].collisionShape.width;
			float rh = collisionObstacle.parts[i].collisionShape.height;

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