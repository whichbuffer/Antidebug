#include "antidebug.h"

int main(int argc, char* argv[])
{

	NtGlobalFlag();

	MessageBoxA(NULL, "Congratulations! You made it!", "You Win!", 0);

	return 0;
}