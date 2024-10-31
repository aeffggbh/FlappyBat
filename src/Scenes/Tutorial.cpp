#include "Tutorial.h"

#include "Interface/Text.h"

namespace Tutorial
{
	static Texture2D background;

	Bton::Button returnToMenu;

	static int buttonFontSize = 40;
	static int regularFontSize = 30;
	static int titleFontSize = 70;

	static float buttonWidth = 250;
	static float buttonHeight = 70;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 12;
	static int heightMultiplier = 1;

	void Load()
	{
		background = LoadTexture("res/Backgrounds/MenuBackground.png");

		heightMultiplier = 1;

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Bton::Create("Return", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);

		Bton::Draw(returnToMenu, buttonFontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}
}