#include "Utils/SoundManager.h"

namespace SoundManager
{
#pragma region DIRECTORIES
	//music
	static string menuMusicDir = "res/Audio/Music/Menu_Theme.mp3";
	static string gameplayMusicDir = "res/Audio/Music/Gameplay_Theme.mp3";

	//button sfx
	static string buttonSfx0Dir = "res/Audio/Sfx/click1.ogg";
	static string buttonSfx1Dir = "res/Audio/Sfx/click2.ogg";
	static string buttonSfx2Dir = "res/Audio/Sfx/click3.ogg";
	static string buttonSfx3Dir = "res/Audio/Sfx/click4.ogg";
	static string buttonSfx4Dir = "res/Audio/Sfx/click5.ogg";

	static string jumpSfxDir = "res/Audio/Sfx/rollover3.ogg";


#pragma endregion

	//music
	static Music menuMusic;
	static Music gameplayMusic;

	//button sfx
	static Sound buttonSfx0;
	static Sound buttonSfx1;
	static Sound buttonSfx2;
	static Sound buttonSfx3;
	static Sound buttonSfx4;

	static Sound jumpSfx;

	Sfx GetRandomSfx()
	{
		Sfx sfx = static_cast<Sfx>(GetRandomValue(static_cast<int>(Sfx::buttonSfx0), static_cast<int>(Sfx::buttonSfx4)));

		return sfx;
	}

	void Play(Song song)
	{
		PlayMusicStream(GetMusic(song));
	}

	/*void Play(Sfx sound)
	{
		PlaySound(GetSound(sound));
	}*/

	void Play(Sfx sound)
	{
		PlaySound(GetSound(sound));
	}

	void Update(Song song)
	{
		UpdateMusicStream(GetMusic(song));
	}

	void Stop(Song song)
	{
		StopMusicStream(GetMusic(song));
	}

	/*bool IsPlaying(Sfx sfx)
	{
		return IsSoundPlaying(GetSound(sfx));
	}*/

	bool IsPlaying(Sfx sfx)
	{
		return IsSoundPlaying(GetSound(sfx));
	}

	bool IsPlaying(Song song)
	{
		return IsMusicStreamPlaying(GetMusic(song));
	}

	void Load()
	{
		InitAudioDevice();

		menuMusic = LoadMusicStream(menuMusicDir.c_str());
		gameplayMusic = LoadMusicStream(gameplayMusicDir.c_str());

		buttonSfx0 = LoadSound(buttonSfx0Dir.c_str());
		buttonSfx1 = LoadSound(buttonSfx1Dir.c_str());
		buttonSfx2 = LoadSound(buttonSfx2Dir.c_str());
		buttonSfx3 = LoadSound(buttonSfx3Dir.c_str());
		buttonSfx4 = LoadSound(buttonSfx4Dir.c_str());

		jumpSfx = LoadSound(jumpSfxDir.c_str());
	}

	Music GetMusic(Song song)
	{
		switch (song)
		{
		case Song::menu:
		{
			return menuMusic;
			break;
		}
		case Song::gameplay:
		{
			return gameplayMusic;
			break;
		}
		default:
		{
			return menuMusic;
			break;
		}
		}
	}

	Sound GetSound(Sfx sound)
	{
		switch (sound)
		{
		case Sfx::buttonSfx0:
		{
			return buttonSfx0;
			break;
		}
		case Sfx::buttonSfx1:
		{
			return buttonSfx1;
			break;
		}
		case Sfx::buttonSfx2:
		{
			return buttonSfx2;
			break;
		}
		case Sfx::buttonSfx3:
		{
			return buttonSfx3;
			break;
		}
		case Sfx::jumpSfx:
		{
			return jumpSfx;
			break;
		}
		default:
		{
			return buttonSfx0;
			break;
		}
		}
	}

	void Unload()
	{
		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);

		UnloadSound(buttonSfx0);
		UnloadSound(buttonSfx1);
		UnloadSound(buttonSfx2);
		UnloadSound(buttonSfx3);
		UnloadSound(buttonSfx4);

		UnloadSound(jumpSfx);

		CloseAudioDevice();
	}
}