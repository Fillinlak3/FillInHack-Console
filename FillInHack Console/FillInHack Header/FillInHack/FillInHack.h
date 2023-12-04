/*
█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
█░░░░░░░░░░░░░░█░░░░░░░░░░█░░░░░░█████████░░░░░░█████████░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░░░█
█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀░░█████████░░▄▀▄▀▄▀░░█░░▄▀░░░░░░░░░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀▄▀░░█
█░░▄▀░░░░░░░░░░█░░░░▄▀░░░░█░░▄▀░░█████████░░▄▀░░█████████░░░░▄▀░░░░█░░▄▀▄▀▄▀▄▀▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░░░█
█░░▄▀░░███████████░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░░░░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░██░░▄▀░░███
█░░▄▀░░░░░░░░░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░▄▀░░███
█░░▄▀▄▀▄▀▄▀▄▀░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀▄▀▄▀▄▀▄▀░░███
█░░▄▀░░░░░░░░░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░▄▀░░███
█░░▄▀░░███████████░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░██░░▄▀░░███
█░░▄▀░░█████████░░░░▄▀░░░░█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░█░░░░▄▀░░░░█░░▄▀░░██░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░░░█
█░░▄▀░░█████████░░▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░██░░░░░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀▄▀░░█
█░░░░░░█████████░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░░░█
█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
*/

/*
	// FillInHack Header
	// Developer Bucuriee
	// Copyright (c) FillInHack Corporation.
*/

#pragma once
#ifndef __FillInHack_Engine_H_
#define __FillInHack_Engine_H_

//#define _CRT_SECURE_NO_WARNINGS

// -- Libraries --
//#include <chrono>
//#include <sstream>
//#include <Windows.h>
//#include <fstream>
//#include <string>
// -----------------------------
#include "Libs/FIH_Exceptions.h"
#include "Libs/Colored_Console.h"
#include "Libs/Converters.h"
#include "Libs/Timer.h"
#include "Libs/Random_Generator.h"
#include "Libs/Array_Lists.h"
#include "Libs/Encryptor.h"
#include "Libs/File_Manager.h"
// -----------------------------

#endif // !__FillInHack_Engine_H_

// Last edit: 08/04/2021
//            MM/DD/YYYY


/*
   Changelog: 08/15/2022

	###################################
		-- FileManager Namespace --
	###################################
	|	added file limit (350000 KB)
	|	added new function for tracking limit when Encrypting / Decrypting File
	|	added new function to get current file kb
	|	reworked functions Encrypt_File & Decrypt_File to check if the file size is below limit
*/

/*
	Changelog: 08/18/2021
	
	Unpacked all classes into files.
	Every class has now it's own header file.
	FillInHack class is now the 'Bridge' between subclasses.
	Subclasses are called children, and FillInHack class is the parent.
	All children are included in parent class.
*/

/*
	Changelog: 08/15/2022

	This update focused on file organization.
	^ Header files are in \FillInHack\Libs ^
	^ Source files are in \FillInHack\src ^
	Class definitions are written in sepparate files as following: (definitions --> '.h' files) && (source --> '.cpp' files).
	Every class can be inherited as parent class into any subclass.
*/