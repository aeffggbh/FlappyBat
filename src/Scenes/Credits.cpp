#include "Credits.h"

#include "Interface/Text.h"

namespace Credits
{
	static Texture2D background;

	static int regularFontSize = 25;
	static int titleFontSize = 70;
	static int buttonFontSize = 40;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 20;
	static int heightMultiplyer = 1;
	static int textSeparation = 8;

	Bton::Button returnToMenu;


	void Load()
	{
		background = LoadTexture("");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Bton::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);
	}

	void Update()
	{
		//Invisible buttons click check
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