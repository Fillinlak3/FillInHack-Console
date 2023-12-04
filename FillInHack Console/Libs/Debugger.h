#pragma once

#include <iostream>

#ifdef _DEBUG
#include "FillInHack/Libs/Colored_Console.h"

#define LOG(x, ...) \
Colored_Console::SetColor(Color_Palette::Color::purple); \
std::cout << x << ' '; \
Colored_Console::SetColor(Color_Palette::Color::gray); \
printf(__VA_ARGS__); printf("\n"); \
Colored_Console::ResetColor()

#define LOG_SUCCESS(x, ...) \
Colored_Console::SetColor(Color_Palette::Color::purple); \
std::cout << x << ' '; \
Colored_Console::SetColor(Color_Palette::Color::lime); \
printf(__VA_ARGS__); printf("\n"); \
Colored_Console::ResetColor()

#define LOG_FAIL(x, ...) \
Colored_Console::SetColor(Color_Palette::Color::purple); \
std::cout << x << ' '; \
Colored_Console::SetColor(Color_Palette::Color::bright_red); \
printf(__VA_ARGS__); printf("\n"); \
Colored_Console::ResetColor()

#define LOG_WARNING(x, ...) \
Colored_Console::SetColor(Color_Palette::Color::purple); \
std::cout << x << ' '; \
Colored_Console::SetColor(Color_Palette::Color::gold); \
printf(__VA_ARGS__); printf("\n"); \
Colored_Console::ResetColor()

#elif defined _RELEASE

#define LOG(x, ...)			0
#define LOG_FAIL(x, ...)	0
#define LOG_WARNING(x, ...) 0
#define LOG_SUCCESS(x, ...) 0

#endif