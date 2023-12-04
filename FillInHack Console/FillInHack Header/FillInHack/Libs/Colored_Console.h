	// Colored_Console Header
#pragma once
#ifndef __COLORED_CONSOLE_H
#define __COLORED_CONSOLE_H

#include <iostream>
#include <Windows.h>

/// <summary>
/// Create an instance object of Console class and use SetColor(colorname)
/// </summary>
namespace Color_Palette {
		// -- Macros -> Define Colors --
	#ifdef _Colored_Console_Colors_Macros_ // Define before including library
		#define BLACK FIH::Colored_Console::Colored_Console::SetColor(0)
		#define BLUE FIH::Colored_Console::Colored_Console::SetColor(1)
		#define GREEN FIH::Colored_Console::Colored_Console::SetColor(2)
		#define CYAN FIH::Colored_Console::Colored_Console::SetColor(3)
		#define RED FIH::Colored_Console::Colored_Console::SetColor(4)
		#define MAGENTA FIH::Colored_Console::Colored_Console::SetColor(5)
		#define GOLD FIH::Colored_Console::Colored_Console::SetColor(6)
		#define WHITE FIH::Colored_Console::Colored_Console::SetColor(7)
		#define GRAY FIH::Colored_Console::Colored_Console::SetColor(8)
		#define BRIGHT_BLUE FIH::Colored_Console::Colored_Console::SetColor(9)
		#define LIME FIH::Colored_Console::Colored_Console::SetColor(10)
		#define SKY_BLUE FIH::Colored_Console::Colored_Console::SetColor(11)
		#define BRIGHT_RED FIH::Colored_Console::Colored_Console::SetColor(12)
		#define BRIGHT_MAGENTA FIH::Colored_Console::Colored_Console::SetColor(13)
		#define YELLOW FIH::Colored_Console::Colored_Console::SetColor(14)
		#define BRIGHT_WHITE FIH::Colored_Console::Colored_Console::SetColor(15)
		#define RESET FIH::Colored_Console::Colored_Console::ResetColor()
	#endif // _Colored_Console_Colors_Macros_ definiton

	/// <summary>
	/// black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white
	/// </summary>
	enum class Color {
		black,
		blue,
		green,
		cyan,
		red,
		purple,
		gold,
		white,
		gray,
		indigo,
		lime,
		aqua,
		bright_red,
		magenta,
		yellow,
		bright_white,
		//reset
	};
}


/// <summary>
/// SetColor(colorname / index)
/// </summary>
class Colored_Console {
protected:
	static const int GetColorIndex(const Color_Palette::Color _foreground, const Color_Palette::Color _background = Color_Palette::Color::black) noexcept;

public:
	static const void SetColor(const int index) noexcept;
	static const void SetColor(const Color_Palette::Color _colorname) noexcept;
	static const void SetColor(const Color_Palette::Color _foreground, const Color_Palette::Color _background) noexcept;
	static const void print_in_color(const std::string text, const Color_Palette::Color _colorname) noexcept;
	static const void print_in_color(const std::string text, const Color_Palette::Color _foreground, const Color_Palette::Color _background) noexcept;

	static const void ResetColor(void) noexcept;
};
extern Colored_Console Console;


#endif // !__COLORED_CONSOLE_H