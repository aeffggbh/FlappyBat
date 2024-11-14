#pragma once
#include <iostream>
#include "raylib.h"

using namespace std;

namespace SoundManager
{
	enum class Song
	{
		menu,
		gameplay
	};

	enum class ButtonSfx
	{
		sfx0,
		sfx1,
		sfx2,
		sfx3,
		sfx4
	};

	enum class Sfx
	{
		shoot,
		planet
	};

	ButtonSfx GetRandomSfx();

	void Play(Song song);

	//void Play(Sfx sound);

	void Play(ButtonSfx sound);

	void Update(Song song);

	void Stop(Song song);

	/*bool IsPlaying(Sfx sfx);*/

	bool IsPlaying(ButtonSfx sfx);

	bool IsPlaying(Song song);

	void Load();

	Music GetMusic(Song song);

	/*Sound GetSound(Sfx sound);*/

	Sound GetSound(ButtonSfx sound);

	void Unload();
}