#include "FillInHack/Libs/File_Manager.h"
#include <iostream>

class Hashcrack : public File {
private:
	long double N;
	std::string m_crypted_text;
	std::string m_data;
	std::string m_salt;
	std::string m_pepper;
	std::string cracked_key;

private:
	void XOR_ERR() const;
	void __getSalt();
	void __getPepperCrack(int len);
	void __runAlgorithm(std::string text, std::string key);
	void BruteforceDecrypt(std::string text);

public:
	Hashcrack();
	~Hashcrack();

	Hashcrack& Decrypt_File_Crack();
	std::string Get_Cracked_Key() const;
};