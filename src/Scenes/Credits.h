#pragma once
#include "Interface/Button.h"

namespace Credits
{
	void Load();
	void Update();
	void Draw();
	void Unload();

	extern Buttons::Button returnToMenu;
}