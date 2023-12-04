	// FIH_Encryptor Header
#pragma once
#ifndef __FIH_Encryptor_H
#define __FIH_Encryptor_H

#ifndef _IOSTREAM_
#include <iostream>
#endif
#include <math.h>
#ifndef __FIH_EXCEPTIONS_H
#include "FIH_Exceptions.h"
#endif
#ifndef __RANDOM_GENERATOR_H
#include "Random_Generator.h"
#endif

class Encryptor {
private:
	long double N;

	std::string m_text;
	std::string m_salt;
	std::string m_pepper;
	std::string m_key;

private:
	void __runAlgorithm(std::string, std::string);
	void __generateSalt();
	void __getSalt();
	void __generatePepper();
	void __getPepper();
	void XOR_ERR() const;

public:
	Encryptor();
	~Encryptor();

	void Encrypt(std::string, std::string);
	void Decrypt(std::string, std::string);

	std::string GetText() const;
};


#endif // !__FIH_Encryptor_H