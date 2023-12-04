#include "../Libs/Colored_Console.h"

Colored_Console Console;

/// <summary>
	/// Set text color using id
	/// </summary>
	/// <param name="index"></param>
const void Colored_Console::SetColor(const int index) noexcept {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
}

/// <summary>
/// Reset text color
/// </summary>
/// <returns></returns>
const void Colored_Console::ResetColor(void) noexcept {
	/** This sets the line to normal ( reseting it ) **/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/// <summary>
/// Set Color using a colorname
/// </summary>
/// <param name="">black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white</param>
const void Colored_Console::SetColor(const Color_Palette::Color _colorname) noexcept {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (static_cast<int>(_colorname)));
}

/// <summary>
/// Set Foreground and Background color
/// </summary>
/// <param name="">black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white</param>
/// <returns></returns>
const void Colored_Console::SetColor(const Color_Palette::Color _foreground, const Color_Palette::Color _background) noexcept {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (static_cast<int>(_background) * 16 + static_cast<int>(_foreground)));
}

const int Colored_Console::GetColorIndex(const Color_Palette::Color _foreground, const Color_Palette::Color _background) noexcept {
	return (static_cast<int>(_background) * 16 + static_cast<int>(_foreground));
}

const void Colored_Console::print_in_color(const std::string text, const Color_Palette::Color _colorname) noexcept {
	SetColor(_colorname);
	std::cout << text;
	ResetColor();
}

const void Colored_Console::print_in_color(const std::string text, const Color_Palette::Color _foreground, const Color_Palette::Color _background) noexcept {
	SetColor(_foreground, _background);
	std::cout << text;
	ResetColor();
}