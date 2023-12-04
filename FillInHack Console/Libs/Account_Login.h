#pragma once
#ifndef _ACCOUNT_LOGIN_
#define _ACCOUNT_LOGIN_

#include <vector>
#include <iostream>
#include "FillInHack/Libs/File_Manager.h"

class Authentificator /*: public File*/ {
public:
	Authentificator();
	~Authentificator();

private:
	struct User {
		unsigned id = 0;
		std::string username = "";
		std::string password = "";
	};

private:
	void __gatherData();
	bool __assignData(unsigned& id, User& _current, std::string _data);
	void __updateDataFile();
	void __dumpData();
	bool isNullOrEmpty(std::string _data) const;
	void PrintElements() const;

public:
	bool Login(std::string _input_username, std::string _input_password);
	bool Register(std::string _input_username, std::string _input_password);
	bool Delete(std::string _input_username);
	bool ChangeUsername(std::string _new_username);
	bool ChangePassword(std::string _new_password);

	std::string GetUsername() const;

private:
	std::vector<User>* users_list;
	unsigned usersCount_index = 0;
	int logged_user_id = -1;
	File* hFile;
};

#endif