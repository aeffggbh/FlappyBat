#include "Credits.h"

#include "Interface/Text.h"
#include "Interface/ColorManager.h"

namespace Credits
{
	static int regularFontSize = 30;
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

	static Text::Text musicText;
	static Text::Text musicUrlText;

	static Text::Text sfxText;
	static Text::Text sfxUrlText;

	//Invisible buttons
	static Buttons::Button spritesUrlButton;
	static Buttons::Button parallaxUrlButton;
	static Buttons::Button musicUrlButton;
	static Buttons::Button sfxUrlButton;

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

		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Buttons::Draw(returnToMenu, buttonFontSize);

		Text::Draw(developerText);
		Text::Draw(developer2Text);

		Text::Draw(spritesText);
		Text::Draw(spritesUrlText);

		Text::Draw(parallaxText);
		Text::Draw(parallaxUrlText);

		Text::Draw(musicText);
		Text::Draw(musicUrlText);

		Text::Draw(sfxText);
		Text::Draw(sfxUrlText);
	}


	void Unload()
	{
	}

	void InitButtons()
	{
		returnToMenu = Buttons::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);

		spritesUrlButton = Buttons::Create("", spritesUrlText.pos.x, spritesUrlText.pos.y, static_cast<float>(spritesUrlText.width), static_cast<float>(regularFontSize));
		parallaxUrlButton = Buttons::Create("", parallaxUrlText.pos.x, parallaxUrlText.pos.y, static_cast<float>(parallaxUrlText.width), static_cast<float>(regularFontSize));
		musicUrlButton = Buttons::Create("", musicUrlText.pos.x, musicUrlText.pos.y, static_cast<float>(musicUrlText.width), static_cast<float>(regularFontSize));
		sfxUrlButton = Buttons::Create("", sfxUrlText.pos.x, sfxUrlText.pos.y, static_cast<float>(sfxUrlText.width), static_cast<float>(regularFontSize));
		
	}

	void InitTexts()
	{
		developerText = Text::CreateText("Original by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding - 10 }, WHITE, Text::Fonts::generalText);

		textPadding += 2;

		developer2Text = Text::CreateText("Forked by: Sofia Alvarez", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);

		textPadding += 3;

		spritesText = Text::CreateText("Bat by Caz Creates Games on Itch.io ", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		spritesUrlText = Text::CreateText("(Click here!)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);

		textPadding += 2;

		parallaxText = Text::CreateText("Gothicvania by Ansimuz on Itch.io ", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		parallaxUrlText = Text::CreateText("(Click here!)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		
		textPadding += 2;

		musicText = Text::CreateText("Music made with Suno AI ", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		musicUrlText = Text::CreateText("(Click here!)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		
		textPadding += 2;
		
		sfxText = Text::CreateText("UI Audio by Kenney ", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		sfxUrlText = Text::CreateText("(Click here!)", regularFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);
		
		textPadding += 2;

		Text::CenterText(developerText);
		Text::CenterText(developer2Text);

		Text::CenterText(spritesText, spritesUrlText);
		Text::CenterText(parallaxText, parallaxUrlText);
		Text::CenterText(musicText, musicUrlText);
		Text::CenterText(sfxText, sfxUrlText);

	}

	void UpdateButtons()
	{
		if (Buttons::IsButtonPressed(spritesUrlButton)) OpenURL("https://caz-creates-games.itch.io/bat");
		if (Buttons::IsButtonPressed(parallaxUrlButton)) OpenURL("https://ansimuz.itch.io/gothicvania-patreon-collection");
		if (Buttons::IsButtonPressed(musicUrlButton)) OpenURL("https://suno.com/");
		if (Buttons::IsButtonPressed(sfxUrlButton)) OpenURL("https://kenney.nl/assets/ui-audio");


	}
}