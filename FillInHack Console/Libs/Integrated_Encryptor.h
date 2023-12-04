#pragma once
#include <iostream>

namespace Integrated {
	class Encryptor {
	public:
		Encryptor();
		~Encryptor();

	public:
		static std::string Code(std::string input);
		static std::string Decode(std::string input);
		static bool check_security_key(std::string argument);
	};
	extern Encryptor enc;
}