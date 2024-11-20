#include "MainMenu.h"

#include "Utils/SoundManager.h"
#include "Interface/Text.h"
#include "Interface/ColorManager.h"

#include "raylib.h"

namespace MainMenu
{
	Buttons::Button play;
	Buttons::Button play2;
	Buttons::Button credits;
	Buttons::Button exit;

	Text::Text mainTitle;

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

		play = Buttons::Create("1 Player", buttonCenterX, static_cast<float>(screenHeight * 3 / 8), buttonWidth, buttonHeight);
		play2 = Buttons::Create("2 Players", buttonCenterX, static_cast<float>(screenHeight * 4 / 8), buttonWidth, buttonHeight);
		credits = Buttons::Create("Credits", buttonCenterX, static_cast<float>(screenHeight * 5 / 8), buttonWidth, buttonHeight);
		exit = Buttons::Create("Exit", buttonCenterX, static_cast<float>(screenHeight * 6 / 8), buttonWidth, buttonHeight);

		mainTitle = Text::CreateText 
		("Flappy Bat",
			static_cast<int>(Text::FontSize::giant),
			{ 0.0f,static_cast<float>(Text::Padding::medium)},
			WHITE,
			Text::Fonts::title);
		Text::CenterText(mainTitle);
	}

	void Update()
	{
		if (!SoundManager::IsPlaying(SoundManager::Song::menu))
			SoundManager::Play(SoundManager::Song::menu);
		else
			SoundManager::Update(SoundManager::Song::menu);
	}

	void KeepMusic()
	{
		SoundManager::Update(SoundManager::Song::menu);
	}


	void Draw()
	{
		ClearBackground(BLACK);

		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), ColorManager::GetColor(ColorManager::AlphaBlack));

		Text::Draw(mainTitle);

		//Version text
		DrawText("0.4",
			GetScreenWidth() / 20 * 18,
			GetScreenHeight() / 20 * 18,
			static_cast<int>(Text::Padding::medium),
			MAGENTA);

		Buttons::Draw(play, static_cast<int>(Text::Padding::medium));
		Buttons::Draw(play2, static_cast<int>(Text::Padding::medium));
		Buttons::Draw(credits, static_cast<int>(Text::Padding::medium));
		Buttons::Draw(exit, static_cast<int>(Text::Padding::medium));
	}

	void Unload()
	{
	}

}