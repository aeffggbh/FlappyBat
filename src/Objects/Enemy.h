#pragma once

#include "raylib.h"

namespace Enemy
{
	const int obstacleParts = 2;

	struct Enemy
	{
		Rectangle collisionShapes[obstacleParts];
		Vector2 pos[obstacleParts];
		float speed;
	};

	extern Enemy enemy;

	void Load();
	void Draw();
	void SetEnemy(Enemy& enemy);
	void Unload();
};

