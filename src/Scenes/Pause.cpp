#include "Pause.h"

#include "Interface/ColorManager.h"
#include "Interface/Text.h"

namespace Pause
{
	Buttons::Button returnToMenu;
	Buttons::Button continuePlaying;
	Text::Text gamePaused;

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
		gamePaused = Text::CreateText("Game Paused", static_cast<int>(Text::Padding::big),
			{ static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 6 - static_cast<int>(Text::Padding::big) / 2) },
			WHITE, Text::Fonts::subtitle);
		Text::CenterText(gamePaused);
	}

	void Draw()
	{
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Text::Draw(gamePaused);
		Buttons::Draw(returnToMenu, static_cast<int>(Text::Padding::medium));
		Buttons::Draw(continuePlaying, static_cast<int>(Text::Padding::medium));
	}
}