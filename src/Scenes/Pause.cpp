#include "Pause.h"

#include "Interface/ColorManager.h"
#include "Interface/Text.h"

namespace Pause
{
	Buttons::Button returnToMenu;
	Buttons::Button continuePlaying;
	Text::Text gamePaused;

	static int fontSize = 40;
	static int titleFontSize = fontSize * 2;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Buttons::Create("Go to menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		continuePlaying = Buttons::Create("Continue", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		gamePaused = Text::CreateText("Game Paused", titleFontSize,
			{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 6 - titleFontSize / 2) },
			WHITE, Text::Fonts::subtitle);
		Text::CenterText(gamePaused);
	}

	void Draw()
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Text::Draw(gamePaused);
		Buttons::Draw(returnToMenu, fontSize);
		Buttons::Draw(continuePlaying, fontSize);
	}
}