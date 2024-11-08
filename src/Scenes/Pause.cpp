#include "Pause.h"

namespace Pause
{
	Buttons::Button returnToMenu;
	Buttons::Button continuePlaying;

	static int fontSize = 40;
	static int titleFontSize = fontSize * 2;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	void Load()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Buttons::Create("Go to menu", buttonCenterX - buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
		continuePlaying = Buttons::Create("Continue", buttonCenterX + buttonWidth, static_cast<float>(screenHeight / 2), buttonWidth, buttonHeight);
	}

	void Draw()
	{
		const char* title = "Game Paused";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, RED);

		Buttons::Draw(returnToMenu, fontSize);
		Buttons::Draw(continuePlaying, fontSize);
	}
}