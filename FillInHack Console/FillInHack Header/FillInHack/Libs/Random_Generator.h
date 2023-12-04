	// Random_Generator Header
#pragma once
#ifndef __RANDOM_GENERATOR_H
#define __RANDOM_GENERATOR_H

#ifndef _STRING_
#include <string>
#endif
#ifndef _INC_TIME
#include <time.h>
#endif
#ifndef _CHRONO_
#include <chrono>
#endif
#ifndef __FIH_EXCEPTIONS_H
#include "FIH_Exceptions.h"
#endif

class Random {
private:
	const char* Letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	const char* Numbers = "0123456789";
	const char* Characters = "`~!@#$%^&*()-_=+[{]};:\'\"\\|,<.>/?";

public:
	Random() noexcept { srand((uint32_t)time((time_t *)NULL)); }
	void resetSeed();
	int nextInt(const int _first, const int _second);
	int nextInt(const int _first);
	char* nextNumber(const size_t _num);
	char nextChar(void) noexcept;
	char* nextChar(const size_t num) noexcept;
	char* nextChar(const size_t _num, const char* delim) noexcept;
	char nextLetter(void) noexcept;
	char* nextLetter(const size_t _num) noexcept;
	bool nextBoolean(void) noexcept;
	float nextFloat(void) noexcept;
	double nextDouble(void) noexcept;

	// Array.
	template<typename _Element, size_t n>
	_Element nextArrayElement(const _Element(&_el)[n]) const noexcept;

	// Array in array.
	template<typename _Element, size_t n, size_t m>
	_Element nextArrayElement(const _Element(&_el)[n][m]) const noexcept;
};


#endif // !__RANDOM_GENERATOR_H