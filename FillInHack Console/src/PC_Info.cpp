#define _CRT_SECURE_NO_WARNINGS
#include "../Libs/PC_Info.h"
#include "../Libs/Debugger.h"

#include <Windows.h>
#include <lmcons.h>
#include <fstream>
#include <sys/stat.h>

#define EXIST true
#define DOESNT_EXIST false
// ----------------------------

PC_Info::PC_Info() {
	LOG("(PC_Info)", "Object created.");
	this->__scrapData();

	// Check if AppData/Roaming/FillInHack Console folder exist.
	if (__checkAppdataDir() == DOESNT_EXIST) {
		LOG_FAIL("(PC_Info)", "FillInHack Console folder doesn't exists.");
		system(("mkdir \"" + appdata_directory + "\"").c_str());
		LOG("(PC_Info)", "FillInHack Console folder created.");
	} else LOG_WARNING("(PC_Info)", "FillInHack Console folder already exists.");

	// Check if accounts file exists
	if (this->__checkAccountsFile() == DOESNT_EXIST) {
		LOG_FAIL("(PC_Info)", "Accounts file doesn't exists.");
		this->__createAccountsFile();
		LOG("(PC_Info)", "Accounts file created.");
	} else LOG_WARNING("(PC_Info)", "Accounts file already exists.");
}

PC_Info::~PC_Info() {
	LOG("(PC_Info)", "Object deleted.");
}

void PC_Info::RunUpdater() {
	/*
		Check if the Updater ran before console program by verifying the versions file
		If TRUE, then delete the file.
		Otherwise, run the updater program.
	*/
	if (__checkVersionsOfAllPrograms() == EXIST) {
		LOG_WARNING("(PC_Info)", "Updater ran before the program, deleting versions file.");
		remove(this->versions_file.c_str());
	} else {
		LOG_WARNING("(PC_Info)", "Versions file wasn't found. Running the updater first.");
		this->updater_program_path = this->terminal_directory + R"("FillInHack Console Updater.lnk")";
		system(("\"" + this->updater_program_path + "\"").c_str());
		exit(0);
	}
}

void PC_Info::__scrapData() {
	this->__getPC_Username();
	this->appdata_directory = R"(C:\Users\)" + this->computer_username + R"(\AppData\Roaming\FillInHack Console\)";
	this->accounts_file = this->appdata_directory + R"(accounts.data)";
	this->temp_directory = R"(C:\Users\)" + this->computer_username + R"(\AppData\Local\Temp\)";
	this->versions_file = this->temp_directory + "versions.fih";
}

void PC_Info::__getPC_Username() {
	char pc_username[UNLEN + 1] = { 0 };
	DWORD username_len = UNLEN + 1;
	// Gather pc username.
	GetUserNameA(pc_username, &username_len);
	this->computer_username = pc_username;
}

bool PC_Info::__checkAppdataDir() {
	struct stat buffer;
	return (stat(this->appdata_directory.c_str(), &buffer) == 0);
}

bool PC_Info::__checkAccountsFile() {
	std::fstream __accounts_file(this->accounts_file.c_str(), std::ios::in | std::ios::binary);
	bool __file_status = __accounts_file.good();
	__accounts_file.close();
	return __file_status;
}

void PC_Info::__createAccountsFile() {
	std::fstream __accounts_file(this->accounts_file.c_str(), std::ios::out);
	__accounts_file << "# Official FillInHack - Console > 'accounts.data' File #";
	__accounts_file.close();
}

bool PC_Info::__checkVersionsOfAllPrograms() {
	std::fstream __versions_file(this->versions_file.c_str(), std::ios::in | std::ios::binary);
	bool __file_status = __versions_file.good();
	__versions_file.close();
	return __file_status;
}