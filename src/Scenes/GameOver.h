#pragma once
#include "Interface/Button.h"

namespace GameOver
{
	extern Buttons::Button returnToMenu;
	extern Buttons::Button playAgain;

	void Init();
	void Draw();
	void Unload();

	void SaveScores(int runScore);
	void SaveScores(int player1Score, int player2Score);
}