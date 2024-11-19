#pragma once

#include <iostream>

#include "raylib.h"

using namespace std;

namespace Text
{
	enum class Padding
	{
		small = 20,
		medium = 40,
		big = 70,
	};

	enum class FontSize
	{
		small = 20,
		medium = 40,
		big = 70
	};

	enum class Fonts
	{
		generalText,
		title
	};

	struct Text
	{
		string content;
		int fontSize;
		int width;
		int height;
		Vector2 pos;
		Color color;
		Fonts font;
	};

	void Load();

	void Unload();

	Text CreateText(string content, int fontSize, Vector2 pos, Color color);

	Text CreateText(string content, int fontSize, Vector2 pos, Color color, Fonts font);

	Font GetFont(Fonts font);

	void SetTextLength(Text& text);

	void SetTextLengthEx(Text& text);

	void Draw(Text text, int posX);

	void Draw(Text text);

	void DrawCentered(Text text);

	void DrawCentered(Text text1, Text text2);
	void DrawEx(Text text, int posX);
	void DrawEx(Text text, int posX, int posY);
	void DrawEx(Text text);
	void DrawCenteredEx(Text text);
	void DrawCenteredEx(Text text1, Text text2);
}