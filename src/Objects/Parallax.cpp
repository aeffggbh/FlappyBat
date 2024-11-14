#include "Parallax.h"

#include <iostream>

#include "Interface/MovingBackground.h"

using namespace std;


namespace Parallax
{
	static MovingBackground::MovingBackground gameplayBack;
	static MovingBackground::MovingBackground gameplayMiddle;
	static MovingBackground::MovingBackground gameplayFront;

	static float screenHeight;
	static float screenWidth;

	static void LoadBackground(MovingBackground::MovingBackground& background, string dir);
	static void InitMovingBackground(MovingBackground::MovingBackground& background, float speed);
	static void UpdateMovingBackground(MovingBackground::MovingBackground& background);
	static void DrawMovingBackground(MovingBackground::MovingBackground& background);

	void Load()
	{
		LoadBackground(gameplayBack, "res/Backgrounds/Gameplay_Back.png");
		LoadBackground(gameplayMiddle, "res/Backgrounds/Gameplay_Middle.png");
		LoadBackground(gameplayFront, "res/Backgrounds/Gameplay_Front.png");
	}

	void Init()
	{
		
		screenHeight = static_cast <float>(GetScreenHeight());
		screenWidth = static_cast <float>(GetScreenWidth());

		InitMovingBackground(gameplayBack, -100.0f);
		InitMovingBackground(gameplayMiddle, -150.0f);
		InitMovingBackground(gameplayFront, -250.0f);

	}

	void Update()
	{
		UpdateMovingBackground(gameplayBack);
		UpdateMovingBackground(gameplayMiddle);
		UpdateMovingBackground(gameplayFront);

	}

	void Draw()
	{
		DrawMovingBackground(gameplayBack);
		DrawMovingBackground(gameplayMiddle);
		DrawMovingBackground(gameplayFront);
	}

	void Unload()
	{
		UnloadTexture(gameplayBack.texture);
		UnloadTexture(gameplayMiddle.texture);
		UnloadTexture(gameplayFront.texture);
	}

	void LoadBackground(MovingBackground::MovingBackground& background, string dir)
	{
		background.texture = LoadTexture(dir.c_str());
	}

	void InitMovingBackground(MovingBackground::MovingBackground& background, float speed)
	{
		background.pos = Vector2{ 0, 0 };

		background.speed = speed;
		background.scale = screenWidth / background.texture.height;
		background.repetitionCount = static_cast <int>(screenWidth / background.texture.width * background.scale);
	}

	void UpdateMovingBackground(MovingBackground::MovingBackground& background)
	{
		background.pos.x += background.speed * GetFrameTime();
		if (background.pos.x <= -background.texture.width * background.scale * 2)
			background.pos.x = 0;
	}

	void DrawMovingBackground(MovingBackground::MovingBackground& background)
	{
		for (int i = 0; i < background.repetitionCount; i++)
		{
			DrawTextureEx(
				background.texture,
				Vector2{ background.texture.width * static_cast <float> (i) + background.pos.x, background.pos.y },
				0.0f,
				background.scale,
				WHITE
			);
		}
	}
};