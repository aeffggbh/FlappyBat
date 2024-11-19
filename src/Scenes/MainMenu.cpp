#include "MainMenu.h"

#include "Utils/SoundManager.h"
#include "Interface/Text.h"

#include "raylib.h"

namespace MainMenu
{
	Buttons::Button play;
	Buttons::Button play2;
	Buttons::Button credits;
	Buttons::Button exit;

	Text::Text mainTitle;

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

		play = Buttons::Create("1 Player", buttonCenterX, static_cast<float>(screenHeight * 3 / 8), buttonWidth, buttonHeight);
		play2 = Buttons::Create("2 Players", buttonCenterX, static_cast<float>(screenHeight * 4 / 8), buttonWidth, buttonHeight);
		credits = Buttons::Create("Credits", buttonCenterX, static_cast<float>(screenHeight * 5 / 8), buttonWidth, buttonHeight);
		exit = Buttons::Create("Exit", buttonCenterX, static_cast<float>(screenHeight * 6 / 8), buttonWidth, buttonHeight);

		mainTitle = Text::CreateText 
		("Flappy Bat",
			fontSize * 3,
			{ 0.0f,static_cast<float>(Text::Padding::medium)},
			GREEN,
			Text::Fonts::title);
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

		Text::DrawCenteredEx(mainTitle);

		//Version text
		DrawText("0.4",
			GetScreenWidth() / 20 * 18,
			GetScreenHeight() / 20 * 18,
			fontSize,
			MAGENTA);

		Buttons::Draw(play, fontSize);
		Buttons::Draw(play2, fontSize);
		Buttons::Draw(credits, fontSize);
		Buttons::Draw(exit, fontSize);
	}

	void Unload()
	{
	}

}