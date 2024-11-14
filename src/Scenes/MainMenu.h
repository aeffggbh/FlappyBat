#pragma once
#include "Interface/Button.h"

namespace MainMenu
{
	void Init();
	void Draw();
	void Unload();

	extern Buttons::Button play;
	extern Buttons::Button play2;
	extern Buttons::Button tutorial;
	extern Buttons::Button credits;
	extern Buttons::Button exit;
}