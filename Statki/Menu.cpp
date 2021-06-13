#include <iostream>
#include "Battleship.hpp"

void launch_menu() {
	int opt;
	std::cout << "         1.\tPLAY\n     Other.\tEXIT\n\n";
	std::cout << "  Choose option by input a number! : ";
	std::cin >> opt;
	if (opt == 1) {
		system("cls");
		return testing();
	}
	else
		std::cout << "NAURA!";
}

void end_menu() {
	int opt;
	std::cout << "         1.\tPLAY AGAIN\n         2.\tBACK TO START\n     Other.\tEXIT\n\n";
	std::cout << "  Choose option by input a number! : ";
	std::cin >> opt;
	if (opt == 2) {
		system("cls");
		print_title();
		return launch_menu();
	}
	else if (opt == 1) {
		system("cls");
		return testing();
	}
	else
		std::cout << "NAURA!";
}