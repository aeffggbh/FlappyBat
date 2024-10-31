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


	void Load()
	{
		//pause = Bton::Create("Pause", static_cast<float>(GetScreenWidth() - 180), 20, 160, 50);

		PlayerNS::Load();

		background = LoadTexture("");

		gameOnGoing = true;
		gameStarted = false;
	}

	bool Update()
	{
		//Jump
		if (IsMouseButtonPressed(0) || IsKeyReleased(KEY_SPACE))
		{
			cout << "Click pressed" << endl;
			cout << "Y: " << player.collisionShape.center.y << endl;
			PlayerJump();
		}

		PlayerFall();

		MoveEnemy();
		KeepEnemyOnScreen();


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
		enemy.pos.y = enemy.collisionShape.y = static_cast<float> (rand() % GetScreenHeight() - enemy.collisionShape.height);
	}


}