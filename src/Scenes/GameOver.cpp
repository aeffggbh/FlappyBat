#include "GameOver.h"

#include <iostream>
#include <string>

#include "Interface/Text.h"

using namespace std;

namespace GameOver
{
	static Texture2D background;

	Bton::Button returnToMenu;
	Bton::Button playAgain;

	static int regularFontSize = 40;
	static int titleFontSize = 70;
	static int buttonFontSize = 40;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 10;
	static int heightMultiplyer = 1;
	static int textSeparation = 8;

	void Load()
	{

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		heightMultiplyer = 1;

		background = LoadTexture("");

		returnToMenu = Bton::Create("Menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
		playAgain = Bton::Create("Play Again", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}

	void Draw()
	{
		ClearBackground(BLACK);

		DrawTexture(background, 0, 0, WHITE);

		Bton::Draw(returnToMenu, buttonFontSize);
		Bton::Draw(playAgain, buttonFontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}

	void SetScores(int maxScore, int runScore)
	{
		string bestScoreString = "Best score: " + to_string(maxScore);
		string currentScoreString = "Score: " + to_string(runScore);
	}
}