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
	static Text::Text developer2Text;

	static Text::Text spritesText;
	static Text::Text spritesUrlText;

	static Text::Text parallaxText;
	static Text::Text parallaxUrlText;


	//Invisible buttons
	static Buttons::Button spritesUrlButton;
	static Buttons::Button parallaxUrlButton;

	static void InitTexts();
	static void InitButtons();
	static void UpdateButtons();

	void Init()
	{
		screenHeight = static_cast<float>(GetScreenHeight());
		screenCenterX = static_cast<float>(GetScreenWidth() / 2);
		buttonCenterX = screenCenterX - buttonWidth / 2;
		InitTexts();
		InitButtons();
	}

	void Update()
	{
		UpdateButtons();
	}

	void Draw()
	{
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		Buttons::Draw(returnToMenu, buttonFontSize);

		Text::DrawCenteredEx(developerText);
		Text::DrawCenteredEx(developer2Text);

		Text::DrawCenteredEx(spritesText, spritesUrlText);
		Text::DrawCenteredEx(parallaxText, parallaxUrlText);
	}


	void Unload()
	{
		UnloadTexture(background);
	}

	void InitButtons()
	{
		returnToMenu = Buttons::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);

		spritesUrlButton = Buttons::Create("", spritesUrlText.pos.x, spritesUrlText.pos.y, static_cast<float>(spritesUrlText.width), static_cast<float>(regularFontSize));
		parallaxUrlButton = Buttons::Create("", parallaxUrlText.pos.x, parallaxUrlText.pos.y, static_cast<float>(parallaxUrlText.width), static_cast<float>(regularFontSize));
	}

	void InitTexts()
	{
		developerText = Text::CreateText("Original by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding - 10 }, GREEN, Text::Fonts::generalText);

		textPadding += 2;

		developer2Text = Text::CreateText("Forked by: Sofia Alvarez", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GREEN, Text::Fonts::generalText);

		textPadding += 3;


		spritesText = Text::CreateText("Sprites by Caz Creates Games", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GREEN, Text::Fonts::generalText);

		spritesUrlText = Text::CreateText("(caz-creates-games.itch.io/bat)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GOLD, Text::Fonts::generalText);


		textPadding += 2;

		parallaxText = Text::CreateText("Parallax by Ansimuz", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GREEN, Text::Fonts::generalText);

		parallaxUrlText = Text::CreateText("(https://ansimuz.itch.io/gothicvania-patreon-collection)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, GOLD, Text::Fonts::generalText);
		
		textPadding += 2;

	}

	void UpdateButtons()
	{
		if (Buttons::IsButtonPressed(spritesUrlButton)) OpenURL("https://caz-creates-games.itch.io/bat");
		if (Buttons::IsButtonPressed(parallaxUrlButton)) OpenURL("https://ansimuz.itch.io/gothicvania-patreon-collection");

	}
}