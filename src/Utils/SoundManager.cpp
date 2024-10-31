#include "SoundManager.h"

namespace SoundManager
{	

	void Load()
	{
		InitAudioDevice();
	}

	void Unload()
	{
		CloseAudioDevice();
	}
}
