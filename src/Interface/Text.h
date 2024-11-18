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

	struct Text
	{
		string content;
		int fontSize;
		int length;
		Vector2 pos;
		Color color;
	};

	Text CreateText(string content, int fontSize, Vector2 pos, Color color);

	void SetTextLength(Text& text);

	void Draw(Text text, int posX);

	void Draw(Text text);

	void DrawCentered(Text text);

	void DrawCentered(Text text1, Text text2);
}