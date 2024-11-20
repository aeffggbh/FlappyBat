#include "Button.h"

#include "Interface/Text.h"
#include "Interface/ColorManager.h"


namespace Buttons
{
	void DrawButton(Button button, Color color, int fontSize);

	void DrawButtonEx(Button button, Color color, int fontSize);

	void Draw(Button button, int fontSize)
	{
		if (button.isSelected)
			DrawButtonEx(button, ColorManager::GetColor(ColorManager::Purple), fontSize);
		else
			DrawButtonEx(button, ColorManager::GetColor(ColorManager::DarkGreen), fontSize);
	}

	Button Create(const char* text, float recX, float recY, float recWidth, float recHeight)
	{
		Button newButton;
		newButton.text = text;
		newButton.rec.x = recX;
		newButton.rec.y = recY;
		newButton.rec.width = recWidth;
		newButton.rec.height = recHeight;
		newButton.isSelected = false;

		return newButton;
	}

	bool IsButtonSelected(Button& button)
	{
		Vector2 mousePosition = GetMousePosition();
		//Mouse hover
		if (mousePosition.x < button.rec.x + button.rec.width &&
			mousePosition.x > button.rec.x &&
			mousePosition.y > button.rec.y &&
			mousePosition.y < button.rec.y + button.rec.height)
		{
			button.isSelected = true;
			return true;
		}
		else
		{
			button.isSelected = false;
			return false;
		}
	}

	bool IsButtonPressed(Button& button)
	{
		bool pressed = false;

		if (IsMouseButtonReleased(0))
			pressed = true;

		if (IsButtonSelected(button) && pressed)
			return true;
		else
			return false;
	}

	void DrawButton(Button button, Color color, int fontSize)
	{
		int x = static_cast <int> (button.rec.x);
		int y = static_cast <int> (button.rec.y);
		int width = static_cast <int> (button.rec.width);
		int height = static_cast <int> (button.rec.height);

		DrawRectangle(x, y, width, height, color);

		int textLength = MeasureText(button.text, fontSize);
		int textX = static_cast<int> (button.rec.x + button.rec.width / 2 - textLength / 2);
		int textY = static_cast<int> (button.rec.y + button.rec.height / 2 - fontSize / 2);

		DrawText(button.text, textX, textY, fontSize, WHITE);
	}
	
	void DrawButtonEx(Button button, Color color, int fontSize)
	{
		int x = static_cast <int> (button.rec.x);
		int y = static_cast <int> (button.rec.y);
		int width = static_cast <int> (button.rec.width);
		int height = static_cast <int> (button.rec.height);

		DrawRectangle(x, y, width, height, color);

		Text::Text buttonText = Text::CreateText(button.text, fontSize, { 0,0 }, WHITE, Text::Fonts::generalText);

		int textX = static_cast<int> (button.rec.x + button.rec.width / 2 - buttonText.width / 2);
		int textY = static_cast<int> (button.rec.y + button.rec.height / 2 - buttonText.height / 2);

		Text::Draw(buttonText, textX, textY);
	}
}
