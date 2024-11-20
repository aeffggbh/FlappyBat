#include "Text.h"

namespace Text
{
	static float textSpacing = 2.0f;

	static Font titleFont;
	static Font generalTextFont;
	static Font subtitleFont;

	void Load()
	{
		titleFont = LoadFont("res/Fonts/Carrington.ttf");
		SetTextureFilter(titleFont.texture, TEXTURE_FILTER_POINT);
		generalTextFont = LoadFont("res/Fonts/latin-modern-mono-regular.otf");
		SetTextureFilter(generalTextFont.texture, TEXTURE_FILTER_POINT);
		subtitleFont = LoadFont("res/Fonts/lobster.otf");
		SetTextureFilter(subtitleFont.texture, TEXTURE_FILTER_POINT);
	}

	void Unload()
	{
		UnloadFont(titleFont);
		UnloadFont(generalTextFont);
	}

	Text CreateText(string content, int fontSize, Vector2 pos, Color color)
	{
		Text newText;
		newText.content = content;
		newText.fontSize = fontSize;
		newText.pos = pos;
		newText.color = color;
		SetTextLength(newText);

		return newText;
	}

	Text CreateText(string content, int fontSize, Vector2 pos, Color color, Fonts font)
	{
		Text newText;
		newText.content = content;
		newText.fontSize = fontSize;
		newText.pos = pos;
		newText.color = color;
		newText.font = font;
		SetTextLengthEx(newText);

		return newText;
	}

	Font GetFont(Fonts font)
	{
		switch (font)
		{
		case Fonts::generalText:
		{
			return generalTextFont;
			break;
		}
		case Fonts::title:
		{
			return titleFont;
			break;
		}
		case Fonts::subtitle:
		{
			return subtitleFont;
			break;
		}
		default:
		{
			return generalTextFont;
			break;
		}
		}
	}

	void SetTextLength(Text& text)
	{
		text.width = MeasureText(text.content.c_str(), text.fontSize);
	}

	void SetTextLengthEx(Text& text)
	{
		text.width = static_cast<int>(MeasureTextEx(GetFont(text.font), text.content.c_str(), static_cast<float>(text.fontSize), textSpacing).x);
		text.height = static_cast<int>(MeasureTextEx(GetFont(text.font), text.content.c_str(), static_cast<float>(text.fontSize), textSpacing).y);
	}

	void Draw(Text text, int posX)
	{
		DrawTextEx(GetFont(text.font), text.content.c_str(), {static_cast<float>(posX), text.pos.y}, static_cast<float>(text.fontSize), textSpacing, text.color);
	}
	
	void Draw(Text text, int posX, int posY)
	{
		DrawTextEx(GetFont(text.font), text.content.c_str(), {static_cast<float>(posX), static_cast<float>(posY) }, static_cast<float>(text.fontSize), textSpacing, text.color);
	}

	void Draw(Text text)
	{
		DrawTextEx(GetFont(text.font), text.content.c_str(), { text.pos.x, text.pos.y }, static_cast<float>(text.fontSize), textSpacing, text.color);
	}

	void CenterText(Text &text)
	{
		int screenCenterX = GetScreenWidth() / 2;
		text.pos.x = static_cast<float>(screenCenterX - text.width / 2);
		//DrawText(text.content.c_str(), screenCenterX - text.width / 2, static_cast<int>(text.pos.y), text.fontSize, text.color);
	}

	void CenterText(Text& text1, Text& text2)
	{
		int screenCenterX = GetScreenWidth() / 2;
		int totalTextLength = text1.width + text2.width;

		int startX = screenCenterX - (totalTextLength / 2);

		text1.pos.x = static_cast<float>(startX);
		text2.pos.x = static_cast<float>(startX + text1.width);

	}
}

