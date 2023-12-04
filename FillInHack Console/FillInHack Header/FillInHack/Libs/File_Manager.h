	// File_Manager Header
#pragma once
#ifndef __FILEMANAGER_H
#define __FILEMANAGER_H

#ifndef _IOSTREAM_
#include <iostream>
#endif
#ifndef _FSTREAM_
#include <fstream>
#endif
#ifndef _WINDOWS_
#include <Windows.h>
#endif
#ifndef __FIH_Encryptor_H
#include "Encryptor.h"
#endif
#ifndef __FIH_EXCEPTIONS_H
#include "FIH_Exceptions.h"
#endif

#define MAX_KB 350000

class File : public Encryptor {
private:
	std::string m_filename;
	std::string m_data;
	std::string m_raw_data;

	typedef void* FileHandle;
	void* _mappedFile;
	void* _mappedView;
	FileHandle _file;
	ULONG64 _filesize;
	ULONG64 mappedBytes;
	ULONG64 fileKB;
	bool unlimited_size;

private:
	void __XOR_ERR();
	void __XOR_ERR_KB_EXCEED();
	void __readData();
	void __writeData();
	void __writeData(std::string _data);
	void __getFileKB();

	const ULONGLONG Size() const;
	bool __isAlreadyOpened() const;
	bool __remap(ULONG64, size_t);
	std::string GetData();

public:
	File();
	File(const char* filename);
	File(std::string filename);
	~File();

	File& Set(const char*);
	File& Size_Restriction(bool);
	File& Encrypt_File(std::string);
	File& Decrypt_File(std::string);

	std::string GetAllText();
	File& WriteText();
	File& WriteText(std::string text);
	
	bool Open();
	bool is_open() const;
	void Close();
	void Clear();
};


#endif // !__FILEMANAGER_H