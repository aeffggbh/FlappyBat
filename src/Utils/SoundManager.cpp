#include "SoundManager.h"

namespace SoundManager
{	

	void Init()
	{
		InitAudioDevice();
	}

	void Unload()
	{
		CloseAudioDevice();
	}
}
