#pragma once
#include "Interface/Button.h"

namespace MainMenu
{
	void Init();
	void Update();
	void KeepMusic();
	void Draw();
	void Unload();

	extern Buttons::Button play;
	extern Buttons::Button play2;
	extern Buttons::Button credits;
	extern Buttons::Button exit;
}