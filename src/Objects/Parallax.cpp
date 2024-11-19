#include "Parallax.h"

#include <iostream>
#include <vector>

#include "Interface/MovingBackground.h"

using namespace std;


namespace ParallaxBackground
{
	struct Parallax
	{
		vector<MovingBackground::Background> parallaxVector;
		int repetitions;
		float speed;
		Texture2D texture;
	};

	static Parallax backParallax;
	static Parallax middleParallax;
	static Parallax frontParallax;

	static float screenHeight;
	static float screenWidth;

	static void LoadBackground(Texture2D& background, string dir);
	static void InitParallax(Parallax& parallax, float speed);
	static void InitMovingBackground(MovingBackground::Background& background, Texture2D texture, Vector2 pos/*, float speed*/);
	static void UpdateParallax(Parallax& parallax);
	static void UpdateMovingBackground(MovingBackground::Background& background, int reps, float speed);
	static void DrawParallax(Parallax parallax);
	
	void Load()
	{
		LoadBackground(backParallax.texture, "res/Backgrounds/Gameplay_Back.png");
		LoadBackground(middleParallax.texture, "res/Backgrounds/Gameplay_Middle.png");
		LoadBackground(frontParallax.texture, "res/Backgrounds/Gameplay_Front.png");
	}

	void Init()
	{
		screenHeight = static_cast <float>(GetScreenHeight());
		screenWidth = static_cast <float>(GetScreenWidth());

		InitParallax(backParallax, 150.0f);
		InitParallax(middleParallax, 200.0f);
		InitParallax(frontParallax, 250.0f);

	}

	void Update()
	{
		UpdateParallax(backParallax);
		UpdateParallax(middleParallax);
		UpdateParallax(frontParallax);

	}

	void Draw()
	{
		DrawParallax(backParallax);
		DrawParallax(middleParallax);
		DrawParallax(frontParallax);
	}

	void Unload()
	{
		UnloadTexture(backParallax.texture);
		UnloadTexture(middleParallax.texture);
		UnloadTexture(frontParallax.texture);
	}

	void LoadBackground(Texture2D& background, string dir)
	{
		background = LoadTexture(dir.c_str());

	}

	void InitParallax(Parallax& parallax, float speed)
	{
		parallax.parallaxVector = vector<MovingBackground::Background>();
		parallax.speed = speed;


		MovingBackground::Background auxBackground;
		InitMovingBackground(auxBackground, parallax.texture, { 0, 0 });

		parallax.repetitions = static_cast<int>(static_cast<float>(GetScreenWidth()) / (static_cast<float>(parallax.texture.width) * auxBackground.scale)) + 2;
		
		for (int i = 0; i <= parallax.repetitions; i++)
		{
			auxBackground.pos.x = static_cast<float>(parallax.texture.width) * auxBackground.scale * i;
			parallax.parallaxVector.push_back(auxBackground);
		}
	}

	void InitMovingBackground(MovingBackground::Background& background, Texture2D texture, Vector2 pos/*, float speed*/)
	{
		background.scale = static_cast<float>(GetScreenHeight()) / static_cast<float>(texture.height);

		background.texture = texture;

		background.pos = pos;
	}

	void UpdateParallax(Parallax& parallax)
	{
		for (int i = 0; i < parallax.repetitions; i++)
		{
			UpdateMovingBackground(parallax.parallaxVector[i], parallax.repetitions-1, parallax.speed);
		}
	}

	void UpdateMovingBackground(MovingBackground::Background& background, int reps, float speed)
	{
		background.pos.x -= speed * GetFrameTime();

		if (background.pos.x + background.texture.width * background.scale < 0)
		{
			background.pos.x = background.texture.width * background.scale * reps;
		}
	}

	void DrawParallax(Parallax parallax)
	{
		for (int i = 0; i < parallax.repetitions; i++)
		{
			DrawTextureEx(
				parallax.parallaxVector[i].texture,
				Vector2{ parallax.parallaxVector[i].pos.x, parallax.parallaxVector[i].pos.y },
				0.0f,
				parallax.parallaxVector[i].scale,
				WHITE
			);
		}
	}
};