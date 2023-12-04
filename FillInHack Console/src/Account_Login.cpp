// ----- Account_Login.cpp -----
#include "../Libs/Account_Login.h"
#include "../Libs/Program_Config.h"
#include "../Libs/Program_Manager.h"
#include "../Libs/Debugger.h"
#include "../Libs/Hashcrack_Bruteforce.h"
// -----------------------------------
#define EMPTY NULL
#define population users_list->size()
#define print_elements for (size_t i = 0; i < population; i++)\
std::cout << users_list->at(i).id << ' ' << users_list->at(i).username << ' ' << users_list->at(i).password << '\n'
// -----------------------------------

Authentificator::Authentificator() {
	LOG("(Authentificator)", "Object created.");
	
	users_list = new std::vector<User>();

	// Reading accounts file and populate the vector.
	hFile = new File(Program::pc_info->accounts_file.c_str());
	if(hFile->Open())
		__gatherData();
	hFile->Close();

	if(users_list->size() == EMPTY) {
		std::cerr << "Unable to read accounts file. Data may be corrupted!\n";
		console_pause;
		exit(-1);
	}
}

Authentificator::~Authentificator() {
	delete users_list;
	delete hFile;
	LOG("(Authentificator)", "Object deleted.");
}

/// <summary>
/// Scrap all information about users <usr:pass> in accounts.data file (READ FROM IT)
/// </summary>
void Authentificator::__gatherData() {
	std::string file_data = "";

	try {
		Hashcrack hashcrack;
		if(hFile->is_open())
			hFile->Close();

		// Hashcracking the accounts.data file to crack the key.
		hashcrack.Set(Program::pc_info->accounts_file.c_str());
		std::string key_found = hashcrack.Decrypt_File_Crack().Get_Cracked_Key();

		// Decrypt file with the key found.
		file_data = hFile->Decrypt_File(key_found).GetText();
	}
	catch (std::exception _ex) {
		// If the file was created recently get data & encrypt file.
		if (hFile->Open()) {
			file_data = hFile->GetAllText();
			hFile->Encrypt_File(Program::security_key).WriteText();

			// Close when done.
			hFile->Close();
		}
	}

	size_t pos = 0;
	std::string token;
	User user;
	while ((pos = file_data.find("\n")) != std::string::npos) {
		token = file_data.substr(0, pos);
		if (__assignData(usersCount_index, user, token))
			users_list->push_back(user);
		file_data.erase(0, pos + 1);
	}
	if (__assignData(usersCount_index, user, file_data))
		users_list->push_back(user);

	if (users_list->size() > NULL) {
		LOG_SUCCESS("(Authentificator)", "Data gathered.");
	}
	else {
		LOG_FAIL("(Authentificator)", "Data may be corrupted.");
	}
}

/// <summary>
/// Assign user & password to the vector variable of the struct
/// </summary>
/// <returns>If data can be assigned to the vector variable of the struct</returns>
bool Authentificator::__assignData(unsigned& id, User& _current, std::string _data) {
	// Check for null line to prevent program failure
	if (isNullOrEmpty(_data))
		return false;

	if (_data.find_first_of(':') == _data.npos)
		return false;

	// Get username
	_current.username.clear();
	for (size_t i = 0; i < _data.find_first_of(':'); i++)
		if (_data[i] != '\r' && _data[i] != '\n' && _data[i] != ' ' && _data[i] != '\0')
			_current.username.push_back(_data[i]);
		else
			return false; // returning false if username contains spaces

	// Get password
	_current.password.clear();
	for (size_t i = _data.find_first_of(':') + 1; i < _data.size(); i++)
		if (_data[i] != '\r' && _data[i] != '\n' && _data[i] != '\0')
			_current.password.push_back(_data[i]);

	// Assign data to new element at (index - 1)
	if (!isNullOrEmpty(_current.username) && !isNullOrEmpty(_current.password))
		_current.id = ++id;
	else
		return false;

	return true;
}

/// <summary>
/// Update data file with new values (WRITE TO IT)
/// </summary>
void Authentificator::__updateDataFile() {
	hFile->Close();

	std::ofstream fout(Program::pc_info->accounts_file.c_str());
	fout << "# Official FillInHack - Console > 'accounts.data' File #\n";
	for (size_t i = 0; i < population; i++) {
		fout << users_list->at(i).username << ':' << users_list->at(i).password;
		if (i < population - 1)
			fout << '\n';
	}
	fout.close();

	hFile->Encrypt_File(Program::security_key).WriteText();
}

/// <summary>
/// Clear vector variable
/// </summary>
void Authentificator::__dumpData() {
	users_list = nullptr;
}

/// <summary>
/// Check if data file is null or empty
/// </summary>
/// <param name="_data"></param>
/// <returns>If data file is null or empty</returns>
bool Authentificator::isNullOrEmpty(std::string _data) const {
	if (_data.size() == NULL)
		return true;
	for (size_t i = 0; i < _data.size(); i++)
		if (_data[i] != ' ')
			return false;
	return true;
}

bool Authentificator::Login(std::string _input_username, std::string _input_password) {
	LOG("(Authentificator)", "Initiating login stage for user: %s", _input_username.c_str());
	if (isNullOrEmpty(_input_username) || isNullOrEmpty(_input_password))
		return false;

	for (int i = 0; i < population; i++)
		if (users_list->at(i).username == _input_username) {
			if (users_list->at(i).password == _input_password) {
				logged_user_id = i;
				return true;
			}
			LOG_FAIL("(Authentificator)", "Incorrect password, try: %s", users_list->at(i).password.c_str());
			return false;
		}
	LOG_FAIL("(Authentificator)", "User not found!");
	return false;
}
bool Authentificator::Register(std::string _input_username, std::string _input_password) {
	if (isNullOrEmpty(_input_username) || isNullOrEmpty(_input_password))
		return false;

	for (size_t i = 0; i < population; i++)
		if (users_list->at(i).username == _input_username)
			return false;

	// Fast assignment for new registered user.
	User _data;
	_data.id = ++usersCount_index;
	_data.username = _input_username;
	_data.password = _input_password;

	__updateDataFile();
	return true;
}
bool Authentificator::Delete(std::string _input_username) {
	if (isNullOrEmpty(_input_username))
		return false;

	for (size_t i = 0; i < population; i++)
		if (users_list->at(i).username == _input_username) {
			users_list->erase(users_list->begin() + i);
			__updateDataFile();
			return true;
		}
	return false;
}
bool Authentificator::ChangeUsername(std::string _new_username) {
	if (isNullOrEmpty(_new_username) || logged_user_id < 0)
		return false;

	if (users_list->at(logged_user_id).username == _new_username)
		return false;

	users_list->at(logged_user_id).username = _new_username;

	/*for (size_t i = 0; i < population; i++)
		if (users_list->at(i).username == _old_username) {
			users_list->at(i).username = _new_username;
			__updateDataFile();
			return true;
		}*/
	__updateDataFile();
	return true;
}
bool Authentificator::ChangePassword(std::string _new_password) {
	if (isNullOrEmpty(_new_password) || logged_user_id < 0)
		return false;

	if (users_list->at(logged_user_id).password == _new_password)
		return false;

	users_list->at(logged_user_id).password = _new_password;

	/*for (size_t i = 0; i < population; i++)
		if (users_list->at(i).username == _input_username) {
			if (users_list->at(i).password != _new_password) {
				users_list->at(i).password = _new_password;
				__updateDataFile();
				return true;
			}
		}*/
	__updateDataFile();
	return true;
}
void Authentificator::PrintElements() const {
	print_elements;
}

std::string Authentificator::GetUsername() const {
	return users_list->at(logged_user_id).username;
}