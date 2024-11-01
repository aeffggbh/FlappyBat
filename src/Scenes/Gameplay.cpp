#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Objects/Enemy.h"


namespace PlayerNS = Player;
namespace EnemyNS = Enemy;

using namespace PlayerNS;
using namespace EnemyNS;

using namespace std;


namespace Gameplay
{
	Bton::Button pause;

	static const int fontSize = 40;

	static bool gameOnGoing = true;
	static bool gameStarted = false;

	static Texture2D background;

	//Player
	static void PlayPlayerAnimation();
	static void PlayerJump();
	static void PlayerFall();

	//Enemy
	static void ManageEnemy();
	static void MoveEnemy(EnemyNS::Enemy& enemyToMove);
	static void KeepEnemyOnScreen(EnemyNS::Enemy enemyToKeepOnScreen);
	static void ResetEnemyPosition(EnemyNS::Enemy& enemyToReset);

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
		PlayPlayerAnimation();

		//Jump
		if (IsMouseButtonPressed(0) || IsKeyReleased(KEY_SPACE))
		{
			PlayerJump();
		}

		PlayerFall();

		ManageEnemy();

		if (CheckPlayerEnemyCollision() || CheckPlayerBorderCollision())
		{
			gameOnGoing = false;
		}

		//cout << enemy.pos[0].x << " " << enemy.pos[0].y << endl;
		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		PlayerNS::Draw();
		EnemyNS::Draw();

		Bton::Draw(pause, fontSize);

		DrawCircle(static_cast <int>(player.pos.x),
			static_cast <int>(player.pos.y),
			player.collisionShape.radius,
			GREEN);

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
		player.collisionShape.center.y -= player.jumpSpeed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}

	void PlayerFall()
	{
		player.collisionShape.center.y += player.fallSpeed * GetFrameTime();
		player.pos.y = player.collisionShape.center.y;
	}


	//Enemy
	void ManageEnemy()
	{
		MoveEnemy(enemy);
		KeepEnemyOnScreen(enemy);
	}

	void MoveEnemy(EnemyNS::Enemy& enemyToMove)
	{
		for (int i = 0; i < obstacleParts; i++)
		{
			enemyToMove.pos[i].x -= enemyToMove.speed * GetFrameTime();
			enemyToMove.collisionShapes[i].x = enemyToMove.pos[i].x;

		}
	}

	void KeepEnemyOnScreen(EnemyNS::Enemy enemyToKeepOnScreen)
	{
		if (enemyToKeepOnScreen.pos[0].x + enemyToKeepOnScreen.collisionShapes[0].width < 0)
		{
			ResetEnemyPosition(enemyToKeepOnScreen);
		}
	}

	void ResetEnemyPosition(EnemyNS::Enemy& enemyToReset)
	{
		EnemyNS::SetEnemy(enemyToReset);
	}


	//Collision
	bool CheckPlayerEnemyCollision()
	{
		float cx = player.collisionShape.center.x;
		float cy = player.collisionShape.center.y;
		float radius = player.collisionShape.radius;

		for (int i = 0; i < obstacleParts; i++)
		{
			float rx = enemy.collisionShapes[i].x;
			float ry = enemy.collisionShapes[i].y;
			float rw = enemy.collisionShapes[i].width;
			float rh = enemy.collisionShapes[i].height;

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
				cout << "Colision player enemy" << endl;
				return true;
			}
		}

		return false;;
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