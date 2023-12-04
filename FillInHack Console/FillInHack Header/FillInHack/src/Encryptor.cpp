#include "../Libs/Encryptor.h"

Encryptor::Encryptor() {
	N = pow(2, 256);
}

Encryptor::~Encryptor() {
	m_text.clear();
	m_salt.clear();
	m_pepper.clear();
	m_key.clear();
}

void Encryptor::XOR_ERR() const {
	throw FIH_Exceptions("Invalid string range");
}

void Encryptor::__generateSalt() {
	Random rand;

	m_salt = rand.nextChar(m_key.length(), " ");
}

void Encryptor::__getSalt() {
	std::string gS = m_text;
	m_salt = gS.erase(m_text.find("$FIH$"), m_text.length());
}

void Encryptor::__generatePepper() {
	__runAlgorithm(m_key, m_salt);
	m_pepper = m_text;
}

void Encryptor::__getPepper() {
	std::string gP = m_text;
	m_pepper = gP.erase(m_key.length(), m_text.length());
	__runAlgorithm(m_pepper, m_salt);
	m_pepper = m_text;
}

void Encryptor::__runAlgorithm(std::string text, std::string key)
{
	m_text.clear();

	int		intKey = NULL;
	for (int j = 0; j < m_salt.length(); j++)
		intKey += (int)m_salt[j];

	// [WPA] - Word Processing Algorithm
	for (int i = 0, ctor = 0; i < text.length(); i++, ctor++)
	{
		if (i >= key.length()) ctor = 0;
		m_text += (char)(fmod(((int)text[i] ^ (intKey - ((int)key[ctor] + i))), N));
	}
}

void Encryptor::Encrypt(std::string text, std::string key) {
	m_key = key;
	__generateSalt();
	__generatePepper();

	__runAlgorithm(text, key);
	m_text = "FillInHack!" + m_salt + "$FIH$" + m_pepper + m_text;
}

void Encryptor::Decrypt(std::string text, std::string key) {
	std::string m_bkp;
	m_text = text;
	m_key = key;

	if (m_text.find("FillInHack!") != NULL)
		XOR_ERR();
	else {
		m_text.erase(0, 11);
		__getSalt();

		m_text.erase(0, key.length() + 5);
		m_bkp = m_text;
		__getPepper();

		//printf("[Key]: %s | [Pepper]: %s | [Salt]: %s\n", m_key.c_str(), m_pepper.c_str(), m_salt.c_str());
		if (m_pepper != key || m_pepper.length() != m_salt.length())
			XOR_ERR();
		else {
			m_text = m_bkp;
			m_text.erase(0, key.length());
			__runAlgorithm(m_text, key);
		}
	}
}

/// <summary>
/// Get a string after Encryption or Decryption
/// </summary>
std::string Encryptor::GetText() const {
	return m_text;
}
