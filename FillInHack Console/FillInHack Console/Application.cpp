#include "../Libs/Program_Config.h"
#include "../Libs/Program_Manager.h"
#include "../Libs/Debugger.h"

int main(int argc, char* argv[])
{
	LOG_SUCCESS("(main)", "<!> FIH Console ACTIVE <!>");

	Program* hInstance = new Program(argv[0]);
	delete hInstance;

	LOG_SUCCESS("(main)", "<!> FIH Console SUCCESSFULLY QUIT  <!>");

#if defined _DEBUG
	console_pause;
#endif
	exit(0);
}
