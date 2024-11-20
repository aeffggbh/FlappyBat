#include "Credits.h"

#include "Interface/Text.h"
#include "Interface/ColorManager.h"

namespace Credits
{
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

	static Text::Text treeText;
	static Text::Text treeUrlText;

	static Text::Text titleFontText;
	static Text::Text titleFontUrlText;

	static Text::Text subtitleFontText;
	static Text::Text subtitleFontUrlText;

	static Text::Text generalFontText;
	static Text::Text generalFontUrlText;

	//Invisible buttons
	static Buttons::Button spritesUrlButton;
	static Buttons::Button parallaxUrlButton;
	static Buttons::Button musicUrlButton;
	static Buttons::Button sfxUrlButton;
	static Buttons::Button treeUrlButton;
	static Buttons::Button titleFontUrlButton;
	static Buttons::Button subtitleFontUrlButton;
	static Buttons::Button generalFontUrlButton;

	static void InitCreditText(Text::Text &text, Text::Text& urlText, string content);
	static void InitTexts();
	static void InitCreditButton(Buttons::Button& button, Text::Text url);
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

		Text::Draw(treeText);
		Text::Draw(treeUrlText);

		Text::Draw(titleFontText);
		Text::Draw(titleFontUrlText);

		Text::Draw(subtitleFontText);
		Text::Draw(subtitleFontUrlText);

		Text::Draw(generalFontText);
		Text::Draw(generalFontUrlText);

	}


	void Unload()
	{
	}

	void InitButtons()
	{
		returnToMenu = Buttons::Create("Return", buttonCenterX, screenHeight / 6 * 5, buttonWidth, buttonHeight);

		InitCreditButton(spritesUrlButton, spritesUrlText);
		InitCreditButton(parallaxUrlButton, parallaxUrlText);
		InitCreditButton(musicUrlButton, musicUrlText);
		InitCreditButton(sfxUrlButton, sfxUrlText);
		InitCreditButton(treeUrlButton, treeUrlText);
		InitCreditButton(titleFontUrlButton, titleFontUrlText);
		InitCreditButton(subtitleFontUrlButton, subtitleFontUrlText);
		InitCreditButton(generalFontUrlButton, generalFontUrlText);

	}

	void InitCreditText(Text::Text& text, Text::Text& urlText, string content)
	{
		text = Text::CreateText(content, static_cast<int>(Text::FontSize::small), { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		urlText = Text::CreateText("(Click here!)", static_cast<int>(Text::FontSize::small), { screenCenterX, screenHeight / screenDivision * textPadding }, ColorManager::GetColor(ColorManager::Purple), Text::Fonts::generalText);

		Text::CenterText(text, urlText);

		textPadding += 1;
	}

	void InitTexts()
	{
		developerText = Text::CreateText("Original by: Nicolas Leon", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding - 10 }, WHITE, Text::Fonts::generalText);

		Text::CenterText(developerText);

		textPadding += 2;

		developer2Text = Text::CreateText("Forked by: Sofia Alvarez", titleFontSize, { screenCenterX, screenHeight / screenDivision * textPadding }, WHITE, Text::Fonts::generalText);
		Text::CenterText(developer2Text);

		textPadding += 3;

		InitCreditText(spritesText, spritesUrlText, "Bat by Caz Creates Games on Itch.io ");

		InitCreditText(parallaxText, parallaxUrlText, "Gothicvania by Ansimuz on Itch.io ");

		InitCreditText(musicText, musicUrlText, "Music made with Suno AI ");
		
		InitCreditText(sfxText, sfxUrlText, "UI Audio by Kenney ");

		InitCreditText(treeText, treeUrlText, "Tree sprite by Alexa Laborero ");

		InitCreditText(titleFontText, titleFontUrlText, "Carrington font by Bright Ideas ");

		InitCreditText(subtitleFontText, subtitleFontUrlText, "Lobster font by Impallari Type ");

		InitCreditText(generalFontText, generalFontUrlText, "Latin Modern Mono Regular font by GUST e-foundry ");

	}

	void InitCreditButton(Buttons::Button &button, Text::Text url)
	{
		button = Buttons::Create("", url.pos.x, url.pos.y, static_cast<float>(url.width), static_cast<float>(Text::FontSize::small));

	}

	void UpdateButtons()
	{
		if (Buttons::IsButtonPressed(spritesUrlButton)) OpenURL("https://caz-creates-games.itch.io/bat");
		if (Buttons::IsButtonPressed(parallaxUrlButton)) OpenURL("https://ansimuz.itch.io/gothicvania-patreon-collection");
		if (Buttons::IsButtonPressed(musicUrlButton)) OpenURL("https://suno.com/");
		if (Buttons::IsButtonPressed(sfxUrlButton)) OpenURL("https://kenney.nl/assets/ui-audio");
		if (Buttons::IsButtonPressed(treeUrlButton)) OpenURL("https://xertun.itch.io/");
		if (Buttons::IsButtonPressed(titleFontUrlButton)) OpenURL("https://fontsquirrel.com/fonts/carrington");
		if (Buttons::IsButtonPressed(subtitleFontUrlButton)) OpenURL("https://www.fontsquirrel.com/fonts/lobster");
		if (Buttons::IsButtonPressed(generalFontUrlButton)) OpenURL("https://www.fontsquirrel.com/fonts/latin-modern-mono");
	}
}