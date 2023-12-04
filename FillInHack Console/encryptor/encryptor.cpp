#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <algorithm>
// --------------------------------------
#include "../Libs/Program_Config.h"
#include "../Libs/Integrated_Encryptor.h"
#include "FillInHack/Libs/File_Manager.h"
#include "FillInHack/Libs/Timer.h"
#include "FillInHack/Libs/Colored_Console.h"
#include "../Libs/Hashcrack_Bruteforce.h"
// --------------------------------------

/*
	argv[0] program name
	argv[1] security key
	argv[2]...argv[7] command parameters
*/

bool isNullOrEmpty(std::string _data);
std::string toLower(std::string text);
void PrintInvalidArguments();
void animation_loading_text(std::string text);
DWORD GetProcId(const wchar_t* procName);
// --------------------------------------

int main(int argc, char* argv[])
{
	// Check security key and deny access from outside the program
	if (argc <= 1 || !Integrated::Encryptor::check_security_key(std::string(argv[1])) || !GetProcId(L"FillInHack Console.exe")) {
		std::cerr << "Access denied. Program cannot be used outside the console.\n";
		return 0;
	}

	// Help Panel
	if (argc == 2 || std::string(argv[2]) == "/?") {
		std::cout << "Encrypts or decrypts a file.\n\n";
		std::cout << "ENCRYPTOR --F <filename> --M <encrypt(e)/decrypt(d)> --K <key> --USE-CHRONO\n";
		std::cout << "\t --F --> sets (path of) the file to encrypt/decrypt.\n";
		std::cout << "\t --M --> mode: encrypt or decrypt.\n";
		std::cout << "\t --K --> key to encrypt/decrypt file.\n";
		std::cout << "\t --USE-CHRONO --> time how long the encryption/decryption takes.\n";
		std::cout << "If the path or key contains spaces, you must use quotation marks (\").\n";
		return 0;
	}
	else if (argc < 8) {
		bool hashcrack_status = false;
		if (argc == 7 && toLower(std::string(argv[2])) == "hashcrack" && toLower(std::string(argv[3])) ==
			"--bruteforce" && toLower(std::string(argv[4])) == "--crack-key" && 
			toLower(std::string(argv[5])) == "--file") {
			std::cout << "Initiating bruteforce on specified file.\n";
			std::string filename = argv[6];
			if (!isNullOrEmpty(filename)) {
				File* file = new File();
				file->Set(filename.c_str());
				if (file->Open()) {
					file->Close();
					animation_loading_text("Cracking Key");
					Sleep(3000);
					//	Running hashcrack bruteforce algorithm
					try {
						Hashcrack* hashcrack = new Hashcrack();
						hashcrack->Set(filename.c_str()).Open();
						std::string key_found = hashcrack->Decrypt_File_Crack().Get_Cracked_Key();

						Colored_Console::print_in_color("\n\n\t^#--#^ HASHCRACK --> SUCCESSFULLY CRACKED KEY ^#--#^\n", Color_Palette::Color::green);
						std::cout << "\thashcrack > KEY FOUND: [#-->";
						Colored_Console::print_in_color(key_found, Color_Palette::Color::bright_red);
						std::cout << "<--#]\n\n";

						hashcrack->Close();
						delete hashcrack;
						hashcrack_status = true;
					}
					/*
						If there was an error occured while bruteforcing file, it means that
						the file wasn't encrypted, so it will print a fail message then quit.
					*/
					catch (std::exception e) {
						std::cerr << "The file you chose was checked and no encryption trace was found.\n";
						return 0;
					}
				}
				delete file;
			}
			if (hashcrack_status == false)
				PrintInvalidArguments(); // If bruteforce fails bc of empty file.

			// If everything fine, the program should exit here after the bruteforce action.
			return 0;
		}
		else // To hide the identity of bruteforce command.
			PrintInvalidArguments();
	}

	// ENCRYPTOR       -F      <filename>      -M      <encrypt(e)/decrypt(d)>      -K    <key>
	//                 arg[2]      arg[3]      arg[4]      arg[5]                 arg[6]  arg[7]
	if (toLower(std::string(argv[2])) == "--f" || toLower(std::string(argv[2])) == "--file" || toLower(std::string(argv[2])) == "--filename") {
		std::string filename = argv[3];
		if (isNullOrEmpty(filename)) {
			std::cerr << "Invalid filename.\n";
			return 0;
		}

		if (toLower(std::string(argv[4])) == "--m" || toLower(std::string(argv[4])) ==
			"--mode") {
			std::string mode = toLower(std::string(argv[5]));
			if (isNullOrEmpty(mode)) {
				std::cerr << "Invalid mode.\n";
				return 0;
			}

			if (toLower(std::string(argv[6])) == "--k" || toLower(std::string(argv[6])) == "--key") {
				std::string key = argv[7];
				if (isNullOrEmpty(key)) {
					std::cerr << "Invalid key.\n";
					return 0;
				}

				bool use_chrono = false;
				bool unlimited_size = false;
				if (argc >= 9) {
					if (argc == 10 && toLower(std::string(argv[8])) == "--no-size") {
						unlimited_size = true;
						if(toLower(std::string(argv[9])) == "--use-chrono")
							use_chrono = true;
					}
					else if(argc == 9 && toLower(std::string(argv[8])) == "--no-size")
						unlimited_size = true;
					else if (argc == 9 && toLower(std::string(argv[8])) == "--use-chrono")
						use_chrono = true;
				}

				// Begin action here
				File* file = new File();
				file->Set(filename.c_str());
				file->Size_Restriction(unlimited_size);
				if (file->Open()) {
					//	Encrypt File
					if (mode == "encrypt" || mode == "e") {
						try {
							Chrono* Timer_Encryption = nullptr;
							if (use_chrono) {
								Timer_Encryption = new Chrono();
								Timer_Encryption->Initialize("Encryption").Start();
							}

							file->Encrypt_File(key).WriteText();
							std::cout << "Successfully encrypted file ";
							Colored_Console::print_in_color("<" + filename + ">\n", Color_Palette::Color::magenta);

							if (use_chrono && Timer_Encryption != nullptr) {
								Timer_Encryption->Stop().PrintTime<Literals::seconds>();
								delete Timer_Encryption;
							}
						}
						catch (FIH_Exceptions& any) {
							std::cerr << "Couldn't encrypt file. " << any.what() << '\n';
						}
					}
					//	Decrypt File
					else if (mode == "decrypt" || mode == "d") {
						try {
							Chrono* Timer_Decryption = nullptr;
							if (use_chrono) {
								Timer_Decryption = new Chrono();
								Timer_Decryption->Initialize("Decryption").Start();
							}

							file->Decrypt_File(key).WriteText();
							std::cout << "Successfully decrypted file ";
							Colored_Console::print_in_color("<" + filename + ">\n", Color_Palette::Color::magenta);

							if (use_chrono && Timer_Decryption != nullptr) {
								Timer_Decryption->Stop().PrintTime<Literals::seconds>();
								delete Timer_Decryption;
							}
						}
						catch (FIH_Exceptions& any) {
							std::cerr << "Couldn't decrypt file. " << any.what() << '\n';
						}
					}
					else {
						std::cerr << "Invalid mode.\n";
					}
				}
				else {
					std::cerr << "Couldn't open file: ";
					Colored_Console::print_in_color("<" + filename + ">", Color_Palette::Color::magenta);
					std::cerr << " try again.\n";
				}
				file->Close();
				delete file;
			}
			else PrintInvalidArguments();
		}
		else PrintInvalidArguments();
	}
	else PrintInvalidArguments();


	return 0;
}


bool isNullOrEmpty(std::string _data) {
	if (_data.size() == NULL)
		return true;
	for (size_t i = 0; i < _data.size(); i++)
		if (_data[i] != ' ')
			return false;
	return true;
}

std::string toLower(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return text;
}

void PrintInvalidArguments() {
	std::cout << "Invalid arguments. Usage:\n";
	std::cout << "ENCRYPTOR --F <filename> --M <encrypt(e)/decrypt(d)> --K <key> --USE-CHRONO\n\n";
	std::cout << "Type \"encryptor /?\" for more informations.\n";
	exit(0);
}

void animation_loading_text(std::string text) {
	char x;
	for (int i = 0; i < 8; i++)
	{
		x = '/';
		std::cout << "[";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "] ";
		std::cout << text;
		std::cout << " [";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "]";
		Sleep(100);
		std::cout << "\r";

		x = '*';
		std::cout << "[";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "] ";
		std::cout << text;
		std::cout << " [";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "]";
		Sleep(100);
		std::cout << "\r";

		x = '\\';
		std::cout << "[";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "] ";
		std::cout << text;
		std::cout << " [";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "]";
		Sleep(100);
		std::cout << "\r";

		x = '*';
		std::cout << "[";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "] ";
		std::cout << text;
		std::cout << " [";
		Console.SetColor(Color_Palette::Color::magenta);
		std::cout << x;
		Console.ResetColor();
		std::cout << "]";
		Sleep(100);
		std::cout << "\r";
	}
}
DWORD GetProcId(const wchar_t* procName)
{
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!_wcsicmp(procEntry.szExeFile, procName))
				{
					procId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));

		}
	}
	CloseHandle(hSnap);
	return procId;
}