#pragma once

#include "raylib.h"

namespace Enemy
{
	struct Enemy
	{
		Rectangle collisionShape;
		Vector2 pos;
		float speed;
	};

	extern Enemy enemy;

	void Load();
	void Draw();
	void Unload();
};

