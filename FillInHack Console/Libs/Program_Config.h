#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define print(x) std::cout << x << '\n'
// ------------------------------------------
#include <Windows.h>

#define console_pause std::cout << '\n'; system("PAUSE")
#define console_clear system("CLS")
#define console_title(x) system("TITLE " x)
// ------------------------------------------