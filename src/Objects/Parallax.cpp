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
		gameplayBack.speed = -30.0f;
		gameplayBack.pos = Vector2{ 0, 0 };


		gameplayMiddle.texture = LoadTexture("res/Backgrounds/Gameplay_Middle.png");
		gameplayMiddle.speed = -50.0f;
		gameplayMiddle.pos = Vector2{ 0, 0 };


		gameplayFront.texture = LoadTexture("res/Backgrounds/Gameplay_Front.png");
		gameplayFront.speed = -70.0f;
		gameplayFront.pos = Vector2{ 300, 0 };
	}

	void Update()
	{
		gameplayBack.pos.x += gameplayBack.speed * GetFrameTime();
		gameplayMiddle.pos.x += gameplayMiddle.speed * GetFrameTime();
		gameplayFront.pos.x += gameplayFront.speed * GetFrameTime();

		if (gameplayBack.pos.x <= -gameplayBack.texture.width * 2)
			gameplayBack.pos.x = 0;

		if (gameplayMiddle.pos.x <= -gameplayMiddle.texture.width * 2)
			gameplayMiddle.pos.x = 0;

		if (gameplayFront.pos.x <= -gameplayFront.texture.width * 2)
			gameplayFront.pos.x = 0;
	}

	void Draw()
	{
		//Back
		DrawTextureEx(
			gameplayBack.texture,
			gameplayBack.pos,
			0.0f,
			0.0f,
			WHITE
		);

		DrawTextureEx(
			gameplayBack.texture,
			Vector2{ gameplayBack.texture.width * 2 + gameplayBack.pos.x, gameplayBack.pos.y },
			0.0f,
			0.0f,
			WHITE
		);


		//Middle
		DrawTextureEx(
			gameplayMiddle.texture,
			gameplayMiddle.pos,
			0.0f,
			0.0f,
			WHITE
		);

		DrawTextureEx(
			gameplayMiddle.texture,
			Vector2{ gameplayMiddle.texture.width * 2 + gameplayMiddle.pos.x, gameplayMiddle.pos.y },
			0.0f,
			0.0f,
			WHITE
		);


		//Front
		DrawTextureEx(
			gameplayFront.texture,
			gameplayFront.pos,
			0.0f,
			0.0f,
			WHITE
		);

		DrawTextureEx(
			gameplayFront.texture,
			Vector2{ gameplayFront.texture.width * 2 + gameplayFront.pos.x, gameplayFront.pos.y },
			0.0f,
			0.0f,
			WHITE
		);

	}

	void Unload()
	{
		UnloadTexture(gameplayBack.texture);
		UnloadTexture(gameplayMiddle.texture);
		UnloadTexture(gameplayFront.texture);
	}
};