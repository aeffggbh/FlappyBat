#include "Game.h"

#include <iostream>

#include "raylib.h"

#include "Scenes/MainMenu.h"
#include "Scenes/Gameplay.h"
#include "Scenes/Tutorial.h"
#include "Scenes/Credits.h"
#include "Scenes/Pause.h"
#include "Scenes/GameOver.h"

#include "Interface/Button.h"
#include "Utils/SoundManager.h"

using namespace Buttons;
using namespace SoundManager;

namespace Game
{
	static const int screenWidth = 800;
	static const int screenHeight = 600;

	enum class CurrentScene
	{
		MainMenu, Gameplay, Tutorial, Credits, Pause, GameOver
	};

	static CurrentScene currentScene;

	static float gameShouldClose;
	static float gameplayOnGoing;

	static void Load();
	static void Update();
	static void Draw();
	static void Unload();

	static void ResetGame();

	void Run()
	{
		Load();
		do
		{
			Update();
			Draw();

		} while (!gameShouldClose);

		Unload();
	}


	void Load()
	{
		
		gameShouldClose = false;
		gameplayOnGoing = false;

		currentScene = CurrentScene::MainMenu;

		InitWindow(screenWidth, screenHeight, "Aliens");

		SetExitKey(0);

		SoundManager::Load();
		MainMenu::Load();
		Gameplay::Load();
		Tutorial::Load();
		Credits::Load();
		Pause::Load();
		GameOver::Load();
	}


	void Update()
	{
		gameShouldClose = WindowShouldClose();

		switch (currentScene)
		{
		case Game::CurrentScene::MainMenu:
		{
			if (IsButtonPressed(MainMenu::play))
			{
				gameplayOnGoing = true;
				currentScene = CurrentScene::Gameplay;
			}
			else if (IsButtonPressed(MainMenu::tutorial))
			{
				currentScene = CurrentScene::Tutorial;
			}
			else if (IsButtonPressed(MainMenu::credits))
			{
				currentScene = CurrentScene::Credits;
			}
			else if (IsButtonPressed(MainMenu::exit))
			{
				gameShouldClose = true;
			}

			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			gameplayOnGoing = Gameplay::Update();

			if (IsButtonPressed(Gameplay::pause) || IsKeyReleased(KEY_ESCAPE))
			{
				currentScene = CurrentScene::Pause;
			}

			if (!gameplayOnGoing)
			{
				/*runScore = Gameplay::GetRunScore();

				if (runScore > maxScore)
				{
					maxScore = runScore;
				}

				GameOver::SetScores(maxScore, runScore);
				*/
				currentScene = CurrentScene::GameOver;
			}

			break;
		}


		case Game::CurrentScene::Tutorial:
		{
			if (IsButtonPressed(Tutorial::returnToMenu) || IsKeyReleased(KEY_ESCAPE))
				currentScene = CurrentScene::MainMenu;

			break;
		}


		case Game::CurrentScene::Credits:
		{
			Credits::Update();

			if (IsButtonPressed(Credits::returnToMenu) || IsKeyReleased(KEY_ESCAPE))
				currentScene = CurrentScene::MainMenu;

			break;
		}


		case Game::CurrentScene::Pause:
		{
			if (IsButtonPressed(Pause::returnToMenu))
			{
				ResetGame();
				currentScene = CurrentScene::MainMenu;
			}
			else if (IsButtonPressed(Pause::continuePlaying) || IsKeyReleased(KEY_ESCAPE))
			{
				currentScene = CurrentScene::Gameplay;
			}
			break;
		}


		case Game::CurrentScene::GameOver:
		{
			if (IsButtonPressed(GameOver::returnToMenu))
			{
				ResetGame();
				currentScene = CurrentScene::MainMenu;
			}
			else if (IsButtonPressed(GameOver::playAgain))
			{
				ResetGame();
				currentScene = CurrentScene::Gameplay;
			}
			break;
		}


		default:
		{
			break;
		}
		}
	}


	void Draw()
	{
		BeginDrawing();

		switch (currentScene)
		{
		case Game::CurrentScene::MainMenu:
		{
			MainMenu::Draw();
			break;
		}


		case Game::CurrentScene::Gameplay:
		{
			Gameplay::Draw();
			break;
		}


		case Game::CurrentScene::Tutorial:
		{
			Tutorial::Draw();
			break;
		}


		case Game::CurrentScene::Credits:
		{
			Credits::Draw();
			break;
		}

		case Game::CurrentScene::Pause:
		{
			Pause::Draw();
			break;
		}


		case Game::CurrentScene::GameOver:
		{
			GameOver::Draw();
			break;
		}


		default:
		{
			std::cout << "Error, entro al default" << std::endl;
			break;
		}
		}

		EndDrawing();
	}


	void Unload()
	{
		Gameplay::Unload();
		Tutorial::Unload();
		Credits::Unload();
		GameOver::Unload();

		SoundManager::Unload();

		CloseWindow();
	}


	void ResetGame()
	{
		currentScene = CurrentScene::MainMenu;

		Gameplay::Load();
	}
}