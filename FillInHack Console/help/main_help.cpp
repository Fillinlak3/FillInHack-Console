#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cout << "HELP or WHATIS\t\t Provides help information for console commands.\n";
		std::cout << "CLEAR\t\t\t Clears the screen.\n";
		std::cout << "CLS\t\t\t Clears the screen.\n";
		std::cout << "USERWD\t\t\t Changes the username.\n";
		std::cout << "PASSWD\t\t\t Changes the password.\n";
		std::cout << "ENCRYPTOR\t\t Encrypts or decrypts a file.\n";
		std::cout << "EXIT\t\t\t Exit the console.\n";
	}
	else if (argc > 2 || std::string(argv[1]) == "/?") {
		std::cout << "Provides help information for console commands.\n\n";
		std::cout << "HELP [command] or WHATIS [command]\n\n";
		std::cout << "\t command - displays help information on that command.\n";
	}
	else if (argc == 2) {
		if (std::string(argv[1]) == "clear" || std::string(argv[1]) == "cls") {
			std::cout << "Clears the screen.\n";
			if(std::string(argv[1]) == "clear")
				std::cout << "CLEAR\n";
			else
				std::cout << "CLS\n";
		}
		else if (std::string(argv[1]) == "userwd") {
			std::cout << "Changes the current username into a new one.\n";
		}
		else if (std::string(argv[1]) == "passwd") {
			std::cout << "Changes the current password into a new one.\n";
		}
		else std::cout << "This command is not supported by the help utility.  Try \"" << argv[1] << " /?\".\n";
	}


	std::cout << "\n";
	return 0;
}

