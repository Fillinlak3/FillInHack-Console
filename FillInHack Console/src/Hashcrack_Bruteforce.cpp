#include "../Libs/Hashcrack_Bruteforce.h"
#include "FillInHack/Libs/FIH_Exceptions.h"
#include "../Libs/Debugger.h"
#include <math.h>

Hashcrack::Hashcrack() {
	LOG("(Hashcrack_Bruteforce)", "Object created.");
	N = pow(2, 256);
	m_crypted_text = "";
	m_data = "";
	m_salt = "";
	m_pepper = "";
	cracked_key = "";
}

Hashcrack::~Hashcrack() {
	LOG("(Hashcrack_Bruteforce)", "Object deleted.");
}

void Hashcrack::XOR_ERR() const {
	throw FIH_Exceptions("Invalid string range");
}

void Hashcrack::__runAlgorithm(std::string text, std::string key)
{
	m_crypted_text.clear();

	int		intKey = NULL;
	for (int j = 0; j < m_salt.length(); j++)
		intKey += (int)m_salt[j];

	// [WPA] - Word Processing Algorithm
	for (int i = 0, ctor = 0; i < text.length(); i++, ctor++)
	{
		if (i >= key.length()) ctor = 0;
		m_crypted_text += (char)(fmod(((int)text[i] ^ (intKey - ((int)key[ctor] + i))), N));
	}
}

void Hashcrack::__getSalt() {
	std::string gS = m_data;
	m_salt = gS.erase(m_data.find("$FIH$"), m_data.length());
}

void Hashcrack::__getPepperCrack(int len) {
	std::string gP = m_data;
	m_pepper = gP.erase(len, m_data.length());
	__runAlgorithm(m_pepper, m_salt);
	m_pepper = m_crypted_text;
}

void Hashcrack::BruteforceDecrypt(std::string text) {
	m_data = text;

	if (m_data.find("FillInHack!") != NULL)
		XOR_ERR();
	else {
		m_data.erase(0, 11);
		__getSalt();

		m_data.erase(0, m_salt.length() + 5);
		__getPepperCrack((int)m_salt.length());

		if (m_pepper.length() != m_salt.length())
			XOR_ERR();
		else {
			cracked_key = m_pepper;
			LOG_SUCCESS("(Hashcrack_Bruteforce)", "Crack succeded!");
		}
	}
}

Hashcrack& Hashcrack::Decrypt_File_Crack() {
	LOG("(Hashcrack_Bruteforce)", "Cracking file decryption key.");
	Open();
	BruteforceDecrypt(GetAllText());
	Close();

	return *this;
}

std::string Hashcrack::Get_Cracked_Key() const {
	return this->cracked_key;
}