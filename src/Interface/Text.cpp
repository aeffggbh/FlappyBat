#include "Text.h"

namespace Text
{
	Text CreateText(string content, int fontSize, Vector2 pos, Color color)
	{
		Text newText;
		newText.content = content;
		newText.fontSize = fontSize;
		newText.pos = pos;
		newText.color = color;

		return newText;
	}

	void SetTextLength(Text& text)
	{
		text.length = MeasureText(text.content.c_str(), text.fontSize);
	}


	void Draw(Text text, int posX)
	{
		DrawText(text.content.c_str(), posX, static_cast<int>(text.pos.y), text.fontSize, text.color);
	}

	void Draw(Text text)
	{
		DrawText(text.content.c_str(), static_cast<int>(text.pos.x), static_cast<int>(text.pos.y), text.fontSize, text.color);
	}

	void DrawCentered(Text text)
	{
		int screenCenterX = GetScreenWidth() / 2;
		DrawText(text.content.c_str(), screenCenterX - text.length / 2, static_cast<int>(text.pos.y), text.fontSize, text.color);
	}


	void DrawCentered(Text text1, Text text2)
	{
		int screenCenterX = GetScreenWidth() / 2;
		int totalTextLength = text1.length + text2.length;

		int startX = screenCenterX - (totalTextLength / 2);

		Draw(text1, startX);
		Draw(text2, startX + text1.length + 5);
	}
}

