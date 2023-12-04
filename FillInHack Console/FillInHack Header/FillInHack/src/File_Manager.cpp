#include "../Libs/File_Manager.h"

File::File()
	: m_filename(""),
	m_data(""),
	_filesize(0),
	_file(0),
	mappedBytes(0),
	fileKB(0),
	unlimited_size(false),
	_mappedFile(NULL),
	_mappedView(NULL)
{}

File::File(const char* filename)
	: m_filename(filename),
	m_data(""),
	_filesize(0),
	_file(0),
	mappedBytes(0),
	fileKB(0),
	unlimited_size(false),
	_mappedFile(NULL),
	_mappedView(NULL) 
{
}

File::File(std::string filename)
	: m_filename(filename),
	m_data(""),
	_filesize(0),
	_file(0),
	mappedBytes(0),
	fileKB(0),
	unlimited_size(false),
	_mappedFile(NULL),
	_mappedView(NULL)
{
}

File::~File() {
	Close();
}

void File::__XOR_ERR() {
	if (__isAlreadyOpened())
		Close();
	throw FIH_Exceptions("file not found");
}
void File::__XOR_ERR_KB_EXCEED() {
	if (__isAlreadyOpened())
		Close();
	throw FIH_Exceptions("file too big");
}

const ULONGLONG File::Size() const {
	return _filesize;
}

void File::__readData() {
	if (__isAlreadyOpened())
		Close();

	m_data.clear();

	std::ifstream fin(m_filename, std::ios::binary);

	char c;
	while (fin >> std::noskipws >> c)
		m_data += c;

	fin.close();
}
void File::__writeData() {
	if (__isAlreadyOpened())
		Close();

	std::ofstream _fwrite(m_filename.c_str(), std::ios::binary);

	_fwrite.write(m_data.c_str(), m_data.length());

	_fwrite.close();
}
void File::__writeData(std::string _data) {
	std::ofstream _fwrite(m_filename, std::ios::binary);

	_fwrite.write(_data.c_str(), _data.length());

	_fwrite.close();
}
void File::__getFileKB() {
	if (__isAlreadyOpened())
		Close();

	std::ifstream f(m_filename.c_str(), std::ios::binary);

	f.seekg(0, std::ios::end);
	fileKB = f.tellg() / 1000;

	f.close();
}

bool File::__isAlreadyOpened() const {
	return _mappedView != NULL;
}

bool File::__remap(ULONG64 offset, size_t mappedBytes) {
	if (!_file)
		return false;

	if (mappedBytes == NULL)
		mappedBytes = _filesize;

	if (_mappedView) {
		::UnmapViewOfFile(_mappedView);
		_mappedView = NULL;
	}


	// don't go further than end of file
	if (offset > _filesize)
		return false;
	if (offset + mappedBytes > _filesize)
		mappedBytes = size_t(_filesize - offset);


	DWORD offsetLow = DWORD(offset & 0xFFFFFFFF);
	DWORD offsetHigh = DWORD(offset >> 32);

	// get memory address
	_mappedView = ::MapViewOfFile(_mappedFile, FILE_MAP_READ, offsetHigh, offsetLow, mappedBytes);

	if (_mappedView == NULL)
	{
		mappedBytes = 0;
		_mappedView = NULL;
		return false;
	}

	// if all is fine
	return true;
}

bool File::Open() {
	if (__isAlreadyOpened())
		return false;


	_file = NULL;
	_filesize = NULL;
	_mappedFile = NULL;
	_mappedView = NULL;


	//DWORD winHint = FILE_ATTRIBUTE_NORMAL;
	DWORD winHint = FILE_ATTRIBUTE_READONLY;

	// open file
	_file = ::CreateFileA(m_filename.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, winHint, NULL);
	if (!_file)
		return false;


	// get file size
	LARGE_INTEGER result;
	if (!GetFileSizeEx(_file, &result))
		return false;
	_filesize = static_cast<ULONG64>(result.QuadPart);


	// convert to mapped mode
	_mappedFile = ::CreateFileMapping(_file, NULL, PAGE_READONLY, 0, 0, NULL);
	if (!_mappedFile)
		return false;


	// initial mapping
	__remap(0, mappedBytes);

	if (!_mappedView)
		return false;

	// everything's fine
	return true;
}

void File::Close() {
	if (_mappedView) {
		::UnmapViewOfFile(_mappedView);
		_mappedView = nullptr;
	}

	if (_mappedFile) {
		::CloseHandle(_mappedFile);
		_mappedFile = nullptr;
	}

	if (_file) {
		::CloseHandle(_file);
		_file = nullptr;
	}
	_filesize = NULL;
}

std::string File::GetData() {
	return std::string(static_cast<const char*>(_mappedView), Size());
}

/// <summary>
/// Set the filename to access
/// </summary>
File& File::Set(const char* filename) {
	m_filename = filename;

	return *this;
}

File& File::Size_Restriction(bool restricted_size) {
	unlimited_size = restricted_size;
	return *this;
}

/// <summary>
/// Encrypt a file
/// </summary>
/// <param name="key">Encryption Key</param>
File& File::Encrypt_File(std::string key) {
	__getFileKB();

	if (unlimited_size == false && fileKB > MAX_KB)
		__XOR_ERR_KB_EXCEED();

	else {
		if(!__isAlreadyOpened())
			Open();
		Encrypt(GetData(), key);
		m_data = GetText();
		Close();
	}
	return *this;
}

/// <summary>
/// Decrypt a file
/// </summary>
/// <param name="key">Decryption Key</param>
File& File::Decrypt_File(std::string key) {
	__getFileKB();

	if (unlimited_size == false && fileKB > MAX_KB)
		__XOR_ERR_KB_EXCEED();

	else {
		if (!__isAlreadyOpened())
			Open();
		Decrypt(GetData(), key);
		m_data = GetText();
		Close();
	}
	return *this;
}

/// <summary>
/// Get a string with all content ONLY from ONE file
/// </summary>
std::string File::GetAllText() {
	if (!__isAlreadyOpened())
		Open();
	
	return GetData();
}

/// <summary>
/// Write file after Encryption or Decryption
/// </summary>
File& File::WriteText() {
	if (m_data.empty() || m_data.length() == NULL)
		throw FIH_Exceptions("Empty data string.\n");

	__writeData();

	return *this;
}

/// <summary>
/// Write file given text
/// </summary>
File& File::WriteText(std::string text) {
	__writeData(text);

	return *this;
}

/// <summary>
///	Unselect the current file
/// </summary>
void File::Clear() {
	m_data.clear();
	m_filename.clear();
}

bool File::is_open() const {
	return __isAlreadyOpened();
}