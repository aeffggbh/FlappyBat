#include "GameOver.h"

#include <iostream>
#include <string>

#include "Interface/Text.h"
#include "Interface/ColorManager.h"
#include "Scenes/Gameplay.h"

using namespace std;

namespace GameOver
{
	static Text::Text gameOver;

	Buttons::Button returnToMenu;
	Buttons::Button playAgain;

	Text::Text player1ScoreText;
	Text::Text player2ScoreText;

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

	static void InitTexts();

	void Init()
	{

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		heightMultiplyer = 1;

		InitTexts();
	}

	void Draw()
	{
		ClearBackground(BLACK);

		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Text::Draw(gameOver);
		Text::Draw(player1ScoreText);
		if (Gameplay::IsMultiplayerMode())
			Text::Draw(player2ScoreText);

		Buttons::Draw(returnToMenu, buttonFontSize);
		Buttons::Draw(playAgain, buttonFontSize);
	}

	void Unload()
	{
	}

	void SaveScores(int runScore)
	{
		string currentScoreString = "Score: " + to_string(runScore);

		player1ScoreText = Text::CreateText(currentScoreString.c_str(), static_cast<int>(Text::FontSize::big), { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2 - static_cast<float>(Text::FontSize::big))}, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		Text::CenterText(player1ScoreText);
	}

	void SaveScores(int player1Score, int player2Score)
	{
		string currentScoreString = "Player 1 Score: " + to_string(player1Score);
		string currentScoreString2 = "Player 2 Score: " + to_string(player2Score);

		player1ScoreText = Text::CreateText(currentScoreString.c_str(), static_cast<int>(Text::FontSize::big), { static_cast<float>(GetScreenWidth() / 2), gameOver.pos.y + gameOver.height + static_cast<float>(Text::Padding::big)}, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		Text::CenterText(player1ScoreText);
		
		player2ScoreText = Text::CreateText(currentScoreString2.c_str(), static_cast<int>(Text::FontSize::big), { static_cast<float>(GetScreenWidth() / 2), player1ScoreText.pos.y + player1ScoreText.height + static_cast<float>(Text::Padding::medium) }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		Text::CenterText(player2ScoreText);
	
	}

	void InitTexts()
	{
		gameOver = Text::CreateText("Game Over", titleFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, WHITE, Text::Fonts::subtitle);
		Text::CenterText(gameOver);

		returnToMenu = Buttons::Create("Menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
		playAgain = Buttons::Create("Play Again", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);

	}
}