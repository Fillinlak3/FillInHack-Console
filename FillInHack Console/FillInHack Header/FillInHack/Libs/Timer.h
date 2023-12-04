// Timer Header
#pragma once
#ifndef __TIMER_H
#define __TIMER_H

#define _CRT_SECURE_NO_WARNINGS
#ifndef _CHRONO_
#include <chrono>
#endif
#ifndef _STRING_
#include <string>
#endif
#ifndef __FIH_EXCEPTIONS_H
#include "FIH_Exceptions.h"
#endif

enum class Literals {
	seconds,
	milliseconds
};

class Chrono {
public:
	Chrono() noexcept : _timerName(NULL), _duration(NULL) { }

public:
	Chrono& Initialize(const char* _timerName);

	void Start();
	Chrono& Stop();

	template<typename Literals unit> void PrintTime();

	static char* GetCurrentClock();

private:
	std::chrono::high_resolution_clock::time_point _start, _end;
	std::chrono::duration<double> _duration{};
	const char* _timerName;
};

template<typename Literals unit>
inline void Chrono::PrintTime() {
	if (_timerName == NULL || _duration.count() == NULL)
		throw FIH_Exceptions("Timer was not initialized. Unable to print.");

	switch (unit)
	{
	case Literals::seconds:
	{
		printf("\n[%s] took %.5g s.\n", this->_timerName, (double)this->_duration.count());
		break;
	}
	case Literals::milliseconds:
	{
		printf("\n[%s] took %.5g ms.\n", this->_timerName, (double)this->_duration.count() * 1000.0f);
		break;
	}
	default:
		break;
	}

	_duration = {};
}

#endif // !__TIMER_H