#include "../Libs/Scene_Builder.h"
#include "../Libs/Program_Manager.h"
#include "../Libs/Program_Config.h"
#include "../Libs/Terminal.h"
#include "../Libs/Debugger.h"
#include "FillInHack/Libs/Colored_Console.h"
// ----------------------------
#include <iostream>
#include <string>
#include <conio.h>
// ----------------------------

// Get combinations like: CTRL-C, CTRL-BREAK to prevent them from closing the program.
inline BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal.
	case CTRL_C_EVENT:
		LOG("(Scene_Builder)", "Ctrl-C event");
		std::cout << '\n';
		Terminal::DisplayCommandLine();
		return TRUE;

		// CTRL-CLOSE: when user presses the X button to close the program.
	case CTRL_CLOSE_EVENT:
		return TRUE;

		// CTRL-BREAK: quit
	case CTRL_BREAK_EVENT:
		LOG("(Scene_Builder)", "Ctrl-Break event\n");
		return FALSE;

	case CTRL_LOGOFF_EVENT:
		LOG("(Scene_Builder)", "Ctrl-Logoff event\n");
		return FALSE;

	case CTRL_SHUTDOWN_EVENT:
		LOG("(Scene_Builder)", "Ctrl-Shutdown event\n");
		return FALSE;

	default:
		return FALSE;
	}
}

// Handle the Ctrl-C event
bool Scene::__capture_CTRL_Events(bool __activate_handler) {
	if (!SetConsoleCtrlHandler(CtrlHandler, __activate_handler) && __activate_handler) {
		Program::login_status = false;
		std::cerr << "An error occured while loading the page, retry opening the console.\n";
		return false;
	}
	return true;
}

Scene::Scene() {
	LOG("(Scene_Builder)", "Object created.");
}

Scene::Scene(Scene_Selector scene_selection) {
	LOG("(Scene_Builder)", "Object created.");
	switch (scene_selection)
	{
	case Scene_Selector::Login:
		this->LoginPage();
		break;
	case Scene_Selector::Register:
		this->RegisterPage();
		break;
	case Scene_Selector::ChangeUsername:
		this->ChangeUsernamePage();
		break;
	case Scene_Selector::ChangePassword:
		this->ChangePasswordPage();
		break;
	case Scene_Selector::CommandLine:
		this->TerminalPage();
		break;
	case Scene_Selector::BatchMode:
		this->BatchMode();
		break;
	default:
		break;
	}
}

Scene::~Scene() {
	LOG("(Scene_Builder)", "Object deleted.");
}

std::string Scene::__getPassword(std::string prompt)
{
	std::string result;

	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(ih, &mode))
		throw std::runtime_error::runtime_error(
			"getpassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

	// Get the password string
	WriteConsoleA(oh, prompt.c_str(), (DWORD)prompt.length(), &count, NULL);
	char c = NULL;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL); // change input characters
			result.push_back(c);
		}
	}

	// Restore the console mode
	SetConsoleMode(ih, mode);

	return result;
}

void Scene::LoginPage() {
	LOG("(Scene_Builder)", "Init login page.");
	// Deactivate CTRL-C event to prevent bugging.
	this->__capture_CTRL_Events(false);

#ifdef _RELEASE
	console_clear;
#endif
	unsigned tries = 0;
	std::string username, password;
	std::cout << "Enter your account credentials.\n";
	std::cout << "Username: "; std::cin >> username;
	std::cin.get();
	while (Program::login_status == false && tries <= 3) {
		password = __getPassword("Password: ");
		std::cout << '\n';
		//std::cout << "Password: "; std::getline(std::cin, password);
		if (Program::auth_session->Login(username, password) == true) {
			Program::login_status = true;
			std::cout << "You have successfully logged in!\n";

			// Also update the console's title.
			system(("TITLE FIH - Logged as: " + Program::auth_session->GetUsername() + "@fillinhack").c_str());
		}
		else {
			if (++tries <= 3)
				std::cerr << "Wrong password, try again (" << tries << "/3)\n";
			else {
				std::cerr << "Wrong password, the number of tries has been exceeded.\n";
#ifdef _RELEASE
				std::cerr << "Hence, you are kicked from the consoleand the account is suspended.\n";
				for (int seconds = 5; seconds >= 1; seconds--) {
					std::cout << "The program will be closing automacally in " << seconds << " second";
					if (seconds > 1)
						std::cout << "s.";
					else
						std::cout << ".";
					Sleep(1000);
					std::cout << '\r';
				}
#endif
			}
		}
	}
}

void Scene::RegisterPage() {
	LOG("(Scene_Builder)", "Init register page.");
}

void Scene::ChangeUsernamePage() {
	LOG("(Scene_Builder)", "Init change username page.");
	std::string new_username, confirm_new_username;
	std::cout << "New username: ";
	std::getline(std::cin, new_username);
	std::cout << "Confirm new username: ";
	std::getline(std::cin, confirm_new_username);

	if (new_username != confirm_new_username) {
		std::cout << "Usernames do not match. Operation refused.\n";
	}
	else if (!Program::auth_session->ChangeUsername(new_username)) {
		std::cout << "Couldn't change the username. Try another username.\n";
	}
	else {
		// Also update the console's title.
		system(("TITLE FIH - Logged as: " + Program::auth_session->GetUsername() + "@fillinhack").c_str());
		std::cout << "Username updated succesfully!\n";
	}
}

void Scene::ChangePasswordPage() {
	LOG("(Scene_Builder)", "Init change password page.");
	std::string new_password, confirm_new_password;
	std::cout << "New password: ";
	new_password = __getPassword("Password: ");
	std::cout << '\n';
	std::cout << "Confirm new password: ";
	confirm_new_password = __getPassword("Password: ");
	std::cout << '\n';

	// Check if passwords match
	if (new_password != confirm_new_password) {
		std::cout << "Passwords do not match. Operation refused.\n";
		return;
	}

	if (!Program::auth_session->ChangePassword(new_password)) {
		std::cout << "Couldn't change the password. Try another password.\n";
		return;
	}
	else {
		std::cout << "Password updated succesfully!\n";
	}
}

void Scene::BatchMode() {
	std::cout << "Batch-Mode: [";
	Colored_Console::print_in_color("ON", Color_Palette::Color::green);
	std::cout << "]\nType exit to close this mode.\n\n";

	system("cmd");

	std::cout << "\nBatch-Mode: [";
	Colored_Console::print_in_color("OFF", Color_Palette::Color::red);
	std::cout << "]\n\n";
}

void Scene::TerminalPage() {
	LOG("(Scene_Builder)", "Init terminal page.");
	// Set the console's title to 'FIH - Logged as: user@fillinhack'
	system(("TITLE FIH - Logged as: " + Program::auth_session->GetUsername() + "@fillinhack").c_str());
	Terminal* console = new Terminal();
	std::string command;

	// Catch CTRL-C Events.
	__capture_CTRL_Events(true);

	/*
		The idea here is that the command line is displayed before running into loop to
		avoid bugging and writting it continuously. So it will be printed once before the
		loop and after user input.
	*/
	console->DisplayCommandLine();
	// If the scene is changed during the loop, it will return by itself to the CommandLine scene.
	while (Program::login_status == true) {
		command.clear();
		if (_kbhit()) {
			console->FlushCommandLineBuffer();
			std::getline(std::cin, command);
			console->SetCommand(command).Execute();

			// Avoids interspersing with Ctrl-C event.
			// Displays the command line only when user is active.
			if (!std::cin.fail() && Program::login_status)
				console->DisplayCommandLine();
		}
	}
}