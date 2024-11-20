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

	enum class Sfx
	{
		buttonSfx0,
		buttonSfx1,
		buttonSfx2,
		buttonSfx3,
		buttonSfx4,

		jumpSfx
	};

	Sfx GetRandomSfx();

	void Play(Song song);

	//void Play(Sfx sound);

	void Play(Sfx sound);

	void Update(Song song);

	void Stop(Song song);

	/*bool IsPlaying(Sfx sfx);*/

	bool IsPlaying(Sfx sfx);

	bool IsPlaying(Song song);

	void Load();

	Music GetMusic(Song song);

	/*Sound GetSound(Sfx sound);*/

	Sound GetSound(Sfx sound);

	void Unload();
}