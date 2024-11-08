#include "MainMenu.h"

#include "raylib.h"

namespace MainMenu
{
	static Texture2D background;

	Buttons::Button play;
	Buttons::Button tutorial;
	Buttons::Button credits;
	Buttons::Button exit;

	static int fontSize = 40;
	static float buttonWidth = 250;
	static float buttonHeight = 70;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	void Load()
	{
		background = LoadTexture("res/Backgrounds/MenuBackground.png");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		play = Buttons::Create("Play", buttonCenterX, static_cast<float>(screenHeight / 6 * 2), buttonWidth, buttonHeight);
		tutorial = Buttons::Create("Tutorial", buttonCenterX, static_cast<float>(screenHeight / 6 * 3), buttonWidth, buttonHeight);
		credits = Buttons::Create("Credits", buttonCenterX, static_cast<float>(screenHeight / 6 * 4), buttonWidth, buttonHeight);
		exit = Buttons::Create("Exit", buttonCenterX, static_cast<float>(screenHeight / 6 * 5), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		DrawTexture(background, 0, 0, WHITE);

		int titleFontSize = fontSize * 2;
		const char* title = "Name";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, GREEN);

		//Version text
		DrawText("0.2",
			GetScreenWidth() / 20 * 18,
			GetScreenHeight() / 20 * 18,
			fontSize,
			MAGENTA);

		Buttons::Draw(play, fontSize);
		Buttons::Draw(tutorial, fontSize);
		Buttons::Draw(credits, fontSize);
		Buttons::Draw(exit, fontSize);
	}

	void Unload()
	{
		UnloadTexture(background);
	}

}