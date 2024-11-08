#pragma once
#include "Interface/Button.h"

namespace Gameplay
{
	extern Buttons::Button pause;

	void Load();
	bool Update();
	void Draw();
	void Unload();

	int GetRunScore();
}