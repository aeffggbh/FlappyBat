#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Objects/Enemy.h"
#include "Utils/SoundManager.h"
#include "Utils/Utils.h"


namespace PlayerNS = Player;
namespace EnemyNS = Enemy;

using namespace PlayerNS;
using namespace EnemyNS;
using namespace SoundManager;
using namespace Utils;

using namespace std;


namespace Gameplay
{
	Bton::Button pause;

	static const int fontSize = 40;

	static bool gameOnGoing = true;
	static bool gameStarted = false;

	static Texture2D background;

	//Player
	static void PlayerJump();
	static void PlayerFall();

	//Enemy
	static void MoveEnemy();
	static void KeepEnemyOnScreen();
	static void ResetEnemyPosition();

	//Collisions
	static bool CheckPlayerEnemyCollision();
	static bool CheckPlayerBorderCollision();

	void Load()
	{
		//pause = Bton::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);

		PlayerNS::Load();
		EnemyNS::Load();

		background = LoadTexture("");

		gameOnGoing = true;
		gameStarted = false;
	}

	bool Update()
	{
		//Jump
		if (IsMouseButtonPressed(0) || IsKeyReleased(KEY_SPACE))
		{
			PlayerJump();
		}

		PlayerFall();

		MoveEnemy();
		KeepEnemyOnScreen();

		if (CheckPlayerEnemyCollision() || CheckPlayerBorderCollision())
		{
			cout << "Colision" << endl;
			gameOnGoing = false;
		}


		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		PlayerNS::Draw();
		EnemyNS::Draw();

		DrawText((to_string(player.score)).c_str(),
			GetScreenWidth() / 2,
			fontSize / 2,
			fontSize,
			MAGENTA);

		Bton::Draw(pause, fontSize);
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
	void PlayerJump()
	{
		player.collisionShape.center.y -= player.jumpSpeed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void PlayerFall()
	{
		player.collisionShape.center.y += player.fallSpeed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void MoveEnemy()
	{
		enemy.pos.x -= enemy.speed * GetFrameTime();
		enemy.collisionShape.x = enemy.pos.x;
	}

	void KeepEnemyOnScreen()
	{
		if (enemy.pos.x + enemy.collisionShape.width < 0)
		{
			ResetEnemyPosition();
		}
	}

	void ResetEnemyPosition()
	{
		enemy.pos.x = GetScreenWidth() - enemy.collisionShape.width;
		enemy.pos.y = static_cast<float> (rand() % static_cast <int>(GetScreenHeight() - enemy.collisionShape.height));

		enemy.collisionShape.x = enemy.pos.x;
		enemy.collisionShape.y = enemy.pos.y;
	}

	bool CheckPlayerEnemyCollision()
	{
		float cx = player.collisionShape.center.x;
		float cy = player.collisionShape.center.y;
		float radius = player.collisionShape.radius;

		float rx = enemy.collisionShape.x;
		float ry = enemy.collisionShape.y; 
		float rw = enemy.collisionShape.width;
		float rh = enemy.collisionShape.height;

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

		return (distance <= radius);
	}

	bool CheckPlayerBorderCollision()
	{
		bool isCollision = false;
		if (player.collisionShape.center.y + player.collisionShape.radius >= GetScreenHeight() ||
			player.collisionShape.center.y - player.collisionShape.radius <= 0)
		{
			isCollision = true;
		}

		return isCollision;
		
	}


}