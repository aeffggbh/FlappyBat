#include "Scenes/HowToPlay.h"
#include "Scenes/Gameplay.h"
#include "Interface/Text.h"

namespace HowToPlay
{
	Text::Text howToPlayTitle;
	//Multiplayer
	Text::Text instructionsPlayer1;
	Text::Text instructionsPlayer2;
	//Singleplayer
	Text::Text instructionsSingle;

	Buttons::Button returnToMenu;
	Buttons::Button continuePlaying;

	static int fontSize = 40;
	static int titleFontSize = fontSize * 2;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static void InitTexts();

	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		InitTexts();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		Text::DrawCentered(howToPlayTitle);
		if (Gameplay::isMultiplayerMode())
		{
			Text::DrawCentered(instructionsPlayer1);
			Text::DrawCentered(instructionsPlayer2);
		}
		else
			Text::DrawCentered(instructionsSingle);

		Buttons::Draw(returnToMenu, fontSize);
		Buttons::Draw(continuePlaying, fontSize);
	}

	void InitTexts()
	{
		howToPlayTitle = Text::CreateText("HOW TO PLAY", fontSize, { screenCenterX, screenHeight / 6 }, YELLOW);

		instructionsPlayer1 = Text::CreateText("PLAYER 1: JUMP WITH THE SPACE KEY. You are the PURPLE ONE!", fontSize / 2, { screenCenterX, screenHeight / 4 }, MAGENTA);

		instructionsPlayer2 = Text::CreateText("PLAYER 2: JUMP WITH THE UP KEY. You are the RED ONE!", fontSize / 2, { screenCenterX, screenHeight / 3 }, RED);

		instructionsSingle = Text::CreateText("JUMP WITH THE SPACE KEY!", fontSize, { screenCenterX, screenHeight / 4 }, MAGENTA);

		returnToMenu = Buttons::Create("Go to menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		continuePlaying = Buttons::Create("Continue", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);

	}
}