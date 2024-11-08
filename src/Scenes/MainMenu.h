#pragma once
#include "Interface/Button.h"

namespace MainMenu
{
	void Load();
	void Draw();
	void Unload();

	extern Buttons::Button play;
	extern Buttons::Button tutorial;
	extern Buttons::Button credits;
	extern Buttons::Button exit;
}