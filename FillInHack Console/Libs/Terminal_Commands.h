#pragma once

#include <iostream>
#include <vector>

class Terminal_Commands {
public:
	Terminal_Commands();
	~Terminal_Commands();

public:
	Terminal_Commands& SetCommand(std::string _commandLine);
	void Execute();

private:
	std::string command_input;
	std::string command_arguments;
	
};