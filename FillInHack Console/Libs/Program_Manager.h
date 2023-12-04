/*
	application_name = FillInHack - Console.exe
*/

#pragma once

#include <iostream>
#include "PC_Info.h"
#include "Account_Login.h"
#include "Scene_Builder.h"
// ------------------------

class Program {
public:
	Program() { exit(0); }
	Program(char* application_name);
	~Program();

private:
	void __loadSetup();
	void __generateSecurityKey();
	std::string __toUpperString(std::string input);

public:
	static void GenerateSecurityKeyTempFile();
	static void DeleteSecurityKeyTempFile();

public:
	static PC_Info* pc_info;
	static Authentificator* auth_session;
	static bool login_status;
	static std::string security_key;
	static Scene* scene;
};