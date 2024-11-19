#pragma once
#include "Interface/Button.h"
#include "Objects/Player.h"

namespace Gameplay
{
	namespace PlayerNS = Player;

	extern Buttons::Button pause;
	extern PlayerNS::Player player1;
	extern PlayerNS::Player player2;

	void Init();
	void Load();
	bool Update();
	void Draw();
	void Unload();

	void Reset();
	void SetMultiplayer(bool isMultiplayer);
	bool IsMultiplayerMode();

}