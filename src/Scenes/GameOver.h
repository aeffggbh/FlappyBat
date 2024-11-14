#pragma once
#include "Interface/Button.h"

namespace GameOver
{
	extern Buttons::Button returnToMenu;
	extern Buttons::Button playAgain;

	void Init();
	void Draw();
	void Unload();

	void SetScores(int maxScore, int runScore);
}