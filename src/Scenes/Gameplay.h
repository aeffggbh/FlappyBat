#pragma once
#include "Interface/Button.h"

namespace Gameplay
{
	extern Buttons::Button pause;

	void Init();
	void Load();
	bool Update();
	void Draw();
	void Unload();

	void Reset();
	int GetRunScore();
}