#include "Credits.h"

#include "Interface/Text.h"

namespace Credits
{
	static Texture2D background;

	static int regularFontSize = 20;
	static int titleFontSize = 50;
	static int buttonFontSize = 30;

	static float buttonWidth = 250;
	static float buttonHeight = 60;

	static float screenHeight;
	static float screenCenterX;
	static float buttonCenterX;

	static int screenDivision = 20;
	static int heightMultiplyer = 1;
	static int textSeparation = 8;

	Bton::Button returnToMenu;

	//Texts
	static Text::Text developerText;
	static Text::Text spritesText;
	static Text::Text spritesUrlText;


	//Invisible button
	static Bton::Button spritesUrlButton;


	void Load()
	{
		background = LoadTexture("");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Bton::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);
		
		//Texts
		{

			developerText = Text::CreateText("Developed by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer - 10 }, GREEN);
			Text::SetTextLength(developerText);

			heightMultiplyer += 2;

			spritesText = Text::CreateText("Sprites by Caz Creates Games", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GREEN);
			Text::SetTextLength(spritesText);


			spritesUrlText = Text::CreateText("(caz-creates-games.itch.io/bat)", regularFontSize, { screenCenterX, screenHeight / screenDivision * heightMultiplyer }, GOLD);
			Text::SetTextLength(spritesUrlText);

			heightMultiplyer++;
		}



		//Invisible buttons
		{
			spritesUrlButton = Bton::Create("", spritesUrlText.pos.x, spritesUrlText.pos.y, static_cast<float>(spritesUrlText.length), static_cast<float>(regularFontSize));
		}
	}

	void Update()
	{
		if (Bton::IsButtonPressed(spritesUrlButton)) OpenURL("https://caz-creates-games.itch.io/bat");
		
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		Bton::Draw(returnToMenu, buttonFontSize);

		Text::DrawCentered(developerText);

		Text::DrawCentered(spritesText, spritesUrlText);
	}


	void Unload()
	{
		UnloadTexture(background);
	}
}