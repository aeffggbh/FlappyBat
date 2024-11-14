#pragma once
#include "Interface/Button.h"

namespace Credits
{
	void Init();
	void Update();
	void Draw();
	void Unload();

	extern Buttons::Button returnToMenu;
}