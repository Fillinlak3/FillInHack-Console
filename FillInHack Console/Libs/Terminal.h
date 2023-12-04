#pragma once

#include "Terminal_Commands.h"
#include <iostream>

class Terminal : public Terminal_Commands {
public:
	Terminal();
	~Terminal();

public:
	static void DisplayCommandLine();
	void FlushCommandLineBuffer() const;
};