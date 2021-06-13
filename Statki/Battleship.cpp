#include <iostream>
#include <string>
#include "Battleship.hpp"
#include <Windows.h>

int main()
{
	srand(time(0));
	print_title();
	launch_menu();
	return 0;
}
