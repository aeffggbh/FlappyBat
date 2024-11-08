#include "Parallax.h"

#include "Interface/MovingBackground.h"


namespace Parallax
{
	static MovingBackground::MovingBackground gameplayBack;
	static MovingBackground::MovingBackground gameplayMiddle;
	static MovingBackground::MovingBackground gameplayFront;


	static float screenHeight;
	static float screenWidth;

	void Load()
	{
		screenHeight = static_cast <float>(GetScreenHeight());
		screenWidth = static_cast <float>(GetScreenWidth());

		gameplayBack.texture = LoadTexture("res/Backgrounds/Gameplay_Back.png");
		gameplayBack.pos = Vector2{ 0, 0 };

		gameplayBack.speed = -100.0f;
		gameplayBack.scale = screenWidth / gameplayBack.texture.height;
		gameplayBack.repetitionCount = static_cast <int>(screenWidth / gameplayBack.texture.width * gameplayBack.scale);


		gameplayMiddle.texture = LoadTexture("res/Backgrounds/Gameplay_Middle.png");
		gameplayMiddle.pos = Vector2{ 0, 0 };

		gameplayMiddle.speed = -150.0f;
		gameplayMiddle.scale = screenWidth / gameplayMiddle.texture.height;
		gameplayMiddle.repetitionCount = static_cast <int>(screenWidth / gameplayMiddle.texture.width * gameplayMiddle.scale);


		gameplayFront.texture = LoadTexture("res/Backgrounds/Gameplay_Front.png");
		gameplayFront.pos = Vector2{ 0, 0 };

		gameplayFront.speed = -250.0f;
		gameplayFront.scale = screenWidth / gameplayFront.texture.height;
		gameplayFront.repetitionCount = static_cast <int>(screenWidth / gameplayFront.texture.width * gameplayFront.scale);
	}

	void Update()
	{
		gameplayBack.pos.x += gameplayBack.speed * GetFrameTime();
		gameplayMiddle.pos.x += gameplayMiddle.speed * GetFrameTime();
		gameplayFront.pos.x += gameplayFront.speed * GetFrameTime();

		if (gameplayBack.pos.x <= -gameplayBack.texture.width * gameplayBack.scale * 2)
			gameplayBack.pos.x = 0;

		if (gameplayMiddle.pos.x <= -gameplayMiddle.texture.width * gameplayMiddle.scale * 2)
			gameplayMiddle.pos.x = 0;

		if (gameplayFront.pos.x <= -gameplayFront.texture.width * gameplayFront.scale * 2)
			gameplayFront.pos.x = 0;
	}

	void Draw()
	{
		//Back
		for (int i = 0; i < gameplayBack.repetitionCount; i++)
		{
			DrawTextureEx(
				gameplayBack.texture,
				Vector2{ gameplayBack.texture.width * static_cast <float> (i) + gameplayBack.pos.x, gameplayBack.pos.y },
				0.0f,
				gameplayBack.scale,
				WHITE
			);
		}

		//Middle
		for (int i = 0; i < gameplayMiddle.repetitionCount; i++)
		{
			DrawTextureEx(
				gameplayMiddle.texture,
				Vector2{ gameplayMiddle.texture.width * static_cast <float> (i) + gameplayMiddle.pos.x, gameplayMiddle.pos.y },
				0.0f,
				gameplayMiddle.scale,
				WHITE
			);
		}

		//Front
		for (int i = 0; i < gameplayFront.repetitionCount; i++)
		{
			DrawTextureEx(
				gameplayFront.texture,
				Vector2{ gameplayFront.texture.width * static_cast <float> (i) + gameplayFront.pos.x, gameplayFront.pos.y },
				0.0f,
				gameplayFront.scale,
				WHITE
			);
		}
	}

	void Unload()
	{
		UnloadTexture(gameplayBack.texture);
		UnloadTexture(gameplayMiddle.texture);
		UnloadTexture(gameplayFront.texture);
	}
};