#include "Gameplay.h"

#include <iostream>
#include <string>
#include <cmath>

#include "raylib.h"

#include "Objects/Player.h"
#include "Utils/SoundManager.h"
#include "Utils/Utils.h"


namespace PlayerNS = Player;

using namespace PlayerNS;
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
	static void MovePlayer();

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
		if (IsMouseButtonPressed(0))
		{
			
		}

		MovePlayer();

		return gameOnGoing;
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		PlayerNS::Draw();

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
	void MovePlayer()
	{

	}


}