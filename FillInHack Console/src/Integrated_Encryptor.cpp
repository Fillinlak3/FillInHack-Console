#include "../Libs/Integrated_Encryptor.h"
#include "../Libs/PC_Info.h"
#include <iostream>
#include <fstream>
#include <string>

#define temp_key_filename Decode("C+:2/@4:&q967")

Integrated::Encryptor::Encryptor() {
}

Integrated::Encryptor::~Encryptor() {
}

std::string Integrated::Encryptor::Code(std::string input) {
	for (size_t i = 0; i < input.length(); i++)
		if ((int)input[i] != 32)
			input[i] = (char)(159 - (int)input[i]);
		else
			input[i] = (char)(158 - (int)input[i]);
	return input;
}

std::string Integrated::Encryptor::Decode(std::string input) {
	for (size_t i = 0; i < input.length(); i++)
		if ((int)input[i] != 126)
			input[i] = (char)(159 - (int)input[i]);
		else
			input[i] = (char)(158 - (int)input[i]);
	return input;
}

bool Integrated::Encryptor::check_security_key(std::string argument) {
	bool status = true;

	PC_Info pc_info;
	std::fstream fin((pc_info.temp_directory + temp_key_filename).c_str(), std::ios::in | std::ios::binary);
	std::string key;
	if (fin.is_open())
		std::getline(fin, key);
	else status = false;
	fin.close();

	if (status)
		if (key != argument)
			status = false;

	return status;
}