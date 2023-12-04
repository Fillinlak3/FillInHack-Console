#include "../Libs/Timer.h"

Chrono& Chrono::Initialize(const char* _timerName) {
	this->_timerName = _timerName;

	return *this;
}

void Chrono::Start() {
	this->_start = std::chrono::high_resolution_clock::now();
}

Chrono& Chrono::Stop() {
	if (_timerName == NULL || _start.time_since_epoch().count() == NULL)
		throw FIH_Exceptions("Cannot stop a not started timer.");

	this->_end = std::chrono::high_resolution_clock::now();
	this->_duration = this->_end - this->_start;

	this->_start = this->_end = {};

	return *this;
}

char* Chrono::GetCurrentClock() {
	time_t now = time(NULL);
	char* dt = ctime(&now);
	dt[strlen(dt) - 1] = 0;

	return dt;
}