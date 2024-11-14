#include "MainMenu.h"

#include "raylib.h"

namespace MainMenu
{
	Buttons::Button play;
	Buttons::Button play2;
	Buttons::Button tutorial;
	Buttons::Button credits;
	Buttons::Button exit;

	static int fontSize = 40;
	static float buttonWidth = 250;
	static float buttonHeight = 40;
	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;


	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		play = Buttons::Create("1 Player", buttonCenterX, static_cast<float>(screenHeight * 3/8), buttonWidth, buttonHeight);
		play2 = Buttons::Create("2 Players", buttonCenterX, static_cast<float>(screenHeight * 4 / 8), buttonWidth, buttonHeight);
		tutorial = Buttons::Create("Tutorial", buttonCenterX, static_cast<float>(screenHeight * 5 / 8), buttonWidth, buttonHeight);
		credits = Buttons::Create("Credits", buttonCenterX, static_cast<float>(screenHeight * 6 / 8), buttonWidth, buttonHeight);
		exit = Buttons::Create("Exit", buttonCenterX, static_cast<float>(screenHeight * 7/8), buttonWidth, buttonHeight);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		int titleFontSize = fontSize * 2;
		const char* title = "Name";
		int textLength = MeasureText(title, titleFontSize);
		int textX = static_cast<int> (screenCenterX - textLength / 2);
		int textY = static_cast<int> (screenHeight / 6 - titleFontSize / 2);
		DrawText(title, textX, textY, titleFontSize, GREEN);

		//Version text
		DrawText("0.4",
			GetScreenWidth() / 20 * 18,
			GetScreenHeight() / 20 * 18,
			fontSize,
			MAGENTA);

		Buttons::Draw(play, fontSize);
		Buttons::Draw(play2, fontSize);
		Buttons::Draw(tutorial, fontSize);
		Buttons::Draw(credits, fontSize);
		Buttons::Draw(exit, fontSize);
	}

	void Unload()
	{
	}

}