#include "ColorManager.h"

namespace ColorManager
{
	static Color purple;
	static Color green;
	static Color darkGreen;
	static Color alphaBlack;
	static Color red;

	static Color GetColor(int r, int g, int b)
	{
		Color myColor;
		myColor.a = 255;
		myColor.r = static_cast<char>(r);
		myColor.g = static_cast<char>(g);
		myColor.b = static_cast<char>(b);

		return myColor;
	}

	static Color GetColor(int r, int g, int b, int a)
	{
		Color myColor;
		myColor.a = static_cast<char>(a);
		myColor.r = static_cast<char>(r);
		myColor.g = static_cast<char>(g);
		myColor.b = static_cast<char>(b);

		return myColor;
	}

	Color GetColor(Colors color)
	{
		Color myColor{};

		switch (color)
		{
		case Green:
		{
			myColor = green;
			break;
		}
		case DarkGreen:
		{
			myColor = darkGreen;
			break;
		}
		case AlphaBlack:
		{
			myColor = alphaBlack;
			break;
		}
		case Purple:
		{
			myColor = purple;
			break;
		}
		case Red:
		{
			myColor = red;
			break;
		}
		default:
		{
			myColor = red;
			break;
		}
		}

		return myColor;
	}

	void InitColors()
	{
		purple = GetColor(203, 125, 244);
		darkGreen = GetColor(13, 32, 47);
		green = GetColor(74, 139, 68);
		alphaBlack = GetColor(38, 50, 56, 200);
		red = GetColor(244, 67, 54);
	}


	void SetForeColor(Colors color)
	{
		Color myColor = GetColor(color);
	}
}