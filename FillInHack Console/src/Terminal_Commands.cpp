#define _CRT_SECURE_NO_WARNINGS

#include "FillInHack/Libs/Colored_Console.h"
#include "../Libs/Terminal_Commands.h"
#include "../Libs/Program_Manager.h"
#include "../Libs/Program_Config.h"
#include "../Libs/Debugger.h"
// -------------------------
#include <algorithm>
#include <functional>
#include <Windows.h>
#include <string>
#include <ctime>
// -------------------------

namespace StringFormatter {
	// trim from start
	inline std::string& ltrim(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
			return !std::isspace(ch);
		}));
		return s;
	}

	// trim from end
	inline std::string& rtrim(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
		}).base(), s.end());
		return s;
	}

	// trim from both ends
	inline std::string& trim(std::string& s) {
		return ltrim(rtrim(s));
	}

	// lowercase string
	inline std::string& lowercase(std::string& s) {
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return s;
	}
}

Terminal_Commands::Terminal_Commands() {
	LOG("(Terminal_Commands)", "Object created.");
}

Terminal_Commands::~Terminal_Commands() {
	LOG("(Terminal_Commands)", "Object deleted.");
}

Terminal_Commands& Terminal_Commands::SetCommand(std::string _command) {
	command_input.clear();
	command_arguments.clear();

	// EXAMPLE SYNTAX OF COMMAND LINE USAGE:
	// help							encryptor
	// ^- command_input				^- command_arguments

	// Skip empty line
	if (_command.empty() || _command.length() == NULL)
		return *this;

	// Getting the command_input.
	StringFormatter::trim(_command);

	char* _cmd = new char[_command.length() + 1];
	strcpy(_cmd, _command.c_str());
	char* p = strtok(_cmd, " ");
	command_input = p;
	p = strtok(NULL, " ");

	// Getting the command arguments.
	command_arguments = StringFormatter::trim(_command.erase(0, command_input.length()));

	// Command input will always be converted to lowercase.
	StringFormatter::lowercase(command_input);

	return *this;
}

void Terminal_Commands::Execute() {

	// Skip empty line & avoid error message unknown command.
	if (command_input.empty() || command_input.length() == NULL)
		return;

	if (command_input == "help" || command_input == "whatis") {
		if (StringFormatter::lowercase(command_arguments) == "encryptor") {
			Program::GenerateSecurityKeyTempFile();
			system(("\"" + Program::pc_info->terminal_directory + command_arguments + ".exe " + Program::security_key + " /?" + "\"").c_str());
			Program::DeleteSecurityKeyTempFile();
			return;
		}

		system(("\"" + Program::pc_info->terminal_directory + "help.exe " + command_arguments + "\"").c_str());
	}
	else if (command_input == "clear" || command_input == "cls") {
		console_clear;
	}
	else if (command_input == "encryptor") {
		Program::GenerateSecurityKeyTempFile();
		system(("\"" + Program::pc_info->terminal_directory + command_input + ".exe " + Program::security_key + " " + command_arguments + "\"").c_str());
		Program::DeleteSecurityKeyTempFile();
	}
	else if (command_input == "exit") {
		Program::login_status = false;
	}
	else if (command_input == "userwd") {
		Program::scene = new Scene(Scene::Scene_Selector::ChangeUsername);
	}
	else if (command_input == "passwd") {
		Program::scene = new Scene(Scene::Scene_Selector::ChangePassword);
	}
	else if (command_input == "logout" || command_input == "logoff") {
		Program::login_status = false;
		Program::scene = new Scene(Scene::Scene_Selector::Login);
	}
	else if (command_input == "batch-mode") {
		Program::scene = new Scene(Scene::Scene_Selector::BatchMode);
	}
	else if (command_input == "time") {
		time_t now = time(NULL);
		std::cout << "The current time is: " << ctime(&now) << '\n';
	}
	else {
		std::cout << "[";
		Colored_Console::print_in_color("!", Color_Palette::Color::red);
		std::cout << "] Unknown command \'" << command_input << "\' - rest of line ignored.\n";
	}
}