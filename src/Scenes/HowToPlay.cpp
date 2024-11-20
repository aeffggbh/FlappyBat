#include "Scenes/HowToPlay.h"
#include "Scenes/Gameplay.h"
#include "Interface/Text.h"
#include "Interface/ColorManager.h"

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
	static int fontSize2 = 25;
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

		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Text::Draw(howToPlayTitle);
		if (Gameplay::IsMultiplayerMode())
		{
			Text::Draw(instructionsPlayer1);
			Text::Draw(instructionsPlayer2);
		}
		else
			Text::Draw(instructionsSingle);

		Buttons::Draw(returnToMenu, fontSize);
		Buttons::Draw(continuePlaying, fontSize);
	}

	void InitTexts()
	{
		howToPlayTitle = Text::CreateText("HOW TO PLAY", fontSize, { screenCenterX, screenHeight / 6 }, WHITE, Text::Fonts::subtitle);

		instructionsPlayer1 = Text::CreateText("PLAYER 1: JUMP WITH THE SPACE KEY. You dodge the NORMAL obstacle!", fontSize2, { screenCenterX, screenHeight / 4 }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);

		instructionsPlayer2 = Text::CreateText("PLAYER 2: JUMP WITH THE UP KEY. You dodge the RED obstacle!", fontSize2, { screenCenterX, screenHeight / 3 }, ColorManager::GetColor(ColorManager::Red), Text::Fonts::generalText);

		instructionsSingle = Text::CreateText("JUMP WITH THE SPACE KEY!", fontSize, { screenCenterX, screenHeight / 4 }, MAGENTA, Text::Fonts::generalText);

		returnToMenu = Buttons::Create("Go to menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		continuePlaying = Buttons::Create("Continue", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);


		Text::CenterText(howToPlayTitle);
		Text::CenterText(instructionsPlayer1);
		Text::CenterText(instructionsPlayer2);
		Text::CenterText(instructionsSingle);
	}
}