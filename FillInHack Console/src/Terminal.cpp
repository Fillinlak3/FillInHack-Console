#include "../Libs/Terminal.h"
#include "FillInHack/Libs/Colored_Console.h"
#include "../Libs/Program_Manager.h"

Terminal::Terminal() {

}

Terminal::~Terminal() {

}

void Terminal::FlushCommandLineBuffer() const {
	std::cin.clear();
}

void Terminal::DisplayCommandLine() {
	Colored_Console::SetColor(4);
	std::cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	Colored_Console::ResetColor();
	Colored_Console::SetColor(2);
	std::cout << "(" << Program::auth_session->GetUsername() << ")";
	Colored_Console::ResetColor();
	Colored_Console::SetColor(4);
	std::cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	Colored_Console::ResetColor();
	//Colored_Console::SetColor(9);
	//std::cout << "(" << consoleLineDisplayDirPath << ")" << endl;
	//Colored_Console::ResetColor();
	Colored_Console::SetColor(4);
	std::cout << "\n" << char(192) << ">";
	Colored_Console::ResetColor();
	Colored_Console::SetColor(2);
	std::cout << "# ";
	Colored_Console::ResetColor();
}