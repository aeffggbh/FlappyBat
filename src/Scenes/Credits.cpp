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
	static int textPadding = 1;

	Buttons::Button returnToMenu;

	//Texts
	static Text::Text developerText;

	static Text::Text spritesText;
	static Text::Text spritesUrlText;

	static Text::Text parallaxText;
	static Text::Text parallaxUrlText;


	//Invisible buttons
	static Buttons::Button spritesUrlButton;
	static Buttons::Button parallaxUrlButton;


	void Load()
	{
		//background = LoadTexture("");

		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;

		returnToMenu = Buttons::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);

		//Texts
		{

			developerText = Text::CreateText("Developed by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding - 10 }, GREEN);
			Text::SetTextLength(developerText);

			textPadding += 2;

			spritesText = Text::CreateText("Sprites by Caz Creates Games", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GREEN);
			Text::SetTextLength(spritesText);

			spritesUrlText = Text::CreateText("(caz-creates-games.itch.io/bat)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GOLD);
			Text::SetTextLength(spritesUrlText);

			textPadding += 2;

			parallaxText = Text::CreateText("Parallax by Ansimuz", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GREEN);
			Text::SetTextLength(parallaxText);

			parallaxUrlText = Text::CreateText("(https://ansimuz.itch.io/gothicvania-patreon-collection)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GOLD);
			Text::SetTextLength(parallaxUrlText);

			textPadding += 2;


		}

		//Invisible buttons
		{
			spritesUrlButton = Buttons::Create("", spritesUrlText.pos.x, spritesUrlText.pos.y, static_cast<float>(spritesUrlText.length), static_cast<float>(regularFontSize));
			parallaxUrlButton = Buttons::Create("", parallaxUrlText.pos.x, parallaxUrlText.pos.y, static_cast<float>(parallaxUrlText.length), static_cast<float>(regularFontSize));
		}
	}

	void Update()
	{
		if (Buttons::IsButtonPressed(spritesUrlButton)) OpenURL("https://caz-creates-games.itch.io/bat");
		if (Buttons::IsButtonPressed(parallaxUrlButton)) OpenURL("https://ansimuz.itch.io/gothicvania-patreon-collection");

	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		Buttons::Draw(returnToMenu, buttonFontSize);

		Text::DrawCentered(developerText);

		Text::DrawCentered(spritesText, spritesUrlText);
		Text::DrawCentered(parallaxText, parallaxUrlText);
	}


	void Unload()
	{
		UnloadTexture(background);
	}
}