/*
	The Console files such as accounts.data file and others will be stored in user's
	AppData/Roaming Path. >> Folder name = FillInHack Console
	Accounts file is in Console files path. >> Accounts file name = accounts.data
*/

#pragma once
#include <iostream>

class PC_Info {
public:
	PC_Info();
	~PC_Info();

	void RunUpdater();

private:
	void __scrapData();
	void __getPC_Username();
	bool __checkAppdataDir();
	bool __checkAccountsFile();
	bool __checkVersionsOfAllPrograms();
	void __createAccountsFile();

public:
	std::string application_name;
	std::string terminal_directory;
	std::string updater_program_path;

	std::string computer_username;
	std::string appdata_directory;
	std::string runnables_directory;
	std::string temp_directory;
	std::string accounts_file;
	std::string versions_file;
};