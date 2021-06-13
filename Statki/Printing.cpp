#include <iostream>
#include "Battleship.hpp"

void print_title() {
	std::cout << "   ____        _   _   _           _     _\n";
	std::cout << "  |  _ \\      | | | | | |         | |   (_)\n";
	std::cout << "  | |_) | __ _| |_| |_| | ___  ___| |__  _ _ __\n";
	std::cout << "  |  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\\n";
	std::cout << "  | |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n";
	std::cout << "  |____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/\n";
	std::cout << "                                          | |    \n";
	std::cout << "                                          |_|    \n";
}

void print_win() { 
	std::cout<<" __     __          __          ___ \n";      
	std::cout<<" \\ \\   / /          \\ \\        / (_)\n";
	std::cout<<"  \\ \\_/ /__  _   _   \\ \\  /\\  / / _ _ __\n";
	std::cout<<"   \\   / _ \\| | | |   \\ \\/  \\/ / | | '_ \\\n";
	std::cout<<"    | | (_) | |_| |    \\  /\\  /  | | | | |\n";
	std::cout<<"    |_|\\___/ \\__,_|     \\/  \\/   |_|_| |_|\n\n";
}

void print_gameover() {
	std::cout<<"   _____                         ____\n";             
	std::cout<<"  / ____|                       / __ \\\n";
	std::cout<<" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __\n";
	std::cout<<" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n";
	std::cout<<" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |\n";
	std::cout<<"  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|\n\n";
}

void print_boards(char tab1[10][10], char tab2[10][10], int sunken, int si_sunken) {
	std::cout << "                   YOUR BOARD                                             SI BOARD \n";
	std::cout << "              SUNKEN MASTS : " << sunken << " / 20                                SUNKEN MASTS : " << si_sunken << " / 20\n\n";
	std::cout << "        A   B   C   D   E   F   G   H   I   J               A   B   C   D   E   F   G   H   I   J";
	print_line((char)201, (char)203, (char)187);
	for (int i = 0; i < 10; i++) {
		if (i != 9)
			std::cout << "    " << i + 1 << " " << (char)186 << " ";
		else
			std::cout << "   " << i + 1 << " " << (char)186 << " ";
		for (int j = 0; j < 10; j++) {
			std::cout << tab1[i][j] << " " << (char)186 << " ";
		}
		std::cout << "     ";
		if (i != 9)
			std::cout << "   " << i + 1 << " " << (char)186 << " ";
		else
			std::cout << "  " << i + 1 << " " << (char)186 << " ";
		for (int j = 0; j < 10; j++) {
			std::cout << tab2[i][j] << " " << (char)186 << " ";
		}
		if (i != 9) {
			print_line((char)204, (char)206, (char)185);
		}
	}
	print_line((char)200, (char)202, (char)188);
}

void print_line(char first, char middle, char last) {
	std::cout << "\n      " << first;
	for (int i = 0; i < 9; i++) {
		std::cout << (char)205 << (char)205 << (char)205 << middle;
	}
	std::cout << (char)205 << (char)205 << (char)205 << last;
	std::cout << "           " << first;
	for (int i = 0; i < 9; i++) {
		std::cout << (char)205 << (char)205 << (char)205 << middle;
	}
	std::cout << (char)205 << (char)205 << (char)205 << last << "\n";
}