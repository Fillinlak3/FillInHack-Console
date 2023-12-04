#include "../Libs/Program_Manager.h"
#include "../Libs/Program_Config.h"
#include "../Libs/Debugger.h"
#include "FillInHack/Libs/Random_Generator.h"
#include <fstream>

#define _RUN_UPDATER

PC_Info* Program::pc_info;
Authentificator* Program::auth_session;
Scene* Program::scene;
bool Program::login_status;
std::string Program::security_key;

Program::Program(char* application_name) {
	LOG("(Program)", "Object created.");
	__generateSecurityKey();

	// Creating first instance for pc_info then for authentificator bc auth depends on pc_info.
	pc_info = new PC_Info();
	auth_session = new Authentificator();
	__loadSetup();
	pc_info->application_name = application_name;

#ifdef _DEBUG
	pc_info->terminal_directory = R"("C:\Users\SDK\source\repos\Fillinlak3\FillInHack-Console-Remaster\Runnables\")";
#elif defined _RELEASE
	pc_info->terminal_directory = "\"";
	pc_info->terminal_directory += pc_info->application_name.substr(0, pc_info->application_name.find_last_of('\\') + 1);
	pc_info->terminal_directory += "\"";
#ifdef _RUN_UPDATER
	pc_info->RunUpdater();
#endif
#endif

	this->login_status = false;
	this->scene = new Scene(Scene::Scene_Selector::Login);

	if (this->login_status == true)
		this->scene = new Scene(Scene::Scene_Selector::CommandLine);
}

Program::~Program() {
	delete pc_info;
	delete auth_session;
	delete scene;
	LOG("(Program)", "Object deleted.");
}

void Program::__loadSetup() {
	LOG("(Program)", "Loading Setup.");
	console_title("FIH - Active Session");

	// Center the console
	RECT rectWindow;
	GetWindowRect(GetConsoleWindow(), &rectWindow);
	int posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	int posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	SetWindowPos(GetConsoleWindow(), NULL, posx, posy, NULL, NULL, SWP_NOSIZE | SWP_NOZORDER);
}

void Program::__generateSecurityKey() {
	LOG("(Program)", "Generating security key.");
	std::string key = "";

	// Key syntax
	// ABCDEF-123456-GHIJKL-789123-MNOPQR-456789-STUVWXYZ
	Random random;
	for (size_t i = 0; i < 6; i++) {
		if (i % 2 == 0)
			key += __toUpperString(random.nextLetter(6));
		else
			key += random.nextNumber(6);
		key.push_back('-');
	}
	key += __toUpperString(random.nextLetter(8));

	this->security_key = key;
	LOG_SUCCESS("(Program)", "Security key generated = %s", this->security_key.c_str());
}

std::string Program::__toUpperString(std::string input) {
	for (size_t i = 0; i < input.length(); i++)
		input[i] = toupper(input[i]);
	return input;
}

void Program::GenerateSecurityKeyTempFile() {
	LOG("(Program)", "Generating security key temp file.");
	std::fstream fout((pc_info->temp_directory + "temp_key.fih").c_str(), std::ios::out | std::ios::binary);
	fout << Program::security_key;
	fout.close();
}

void Program::DeleteSecurityKeyTempFile() {
	LOG("(Program)", "Deleting security key temp file.");
	std::fstream fin((pc_info->temp_directory + "temp_key.fih").c_str(), std::ios::in | std::ios::binary);
	bool status = fin.is_open();
	fin.close();

	if (status)
		remove((pc_info->temp_directory + "temp_key.fih").c_str());
}