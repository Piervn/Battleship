#include <iostream>
#include "Battleship.hpp"

void clear_logic(bool logic[10][10]) {
	for (int i = 0; i < 100; i++) {
		logic[i / 10][i % 10] = 0;
	}
}

void update_board(char board[10][10], bool logic[10][10]) {
	for (int i = 0; i < 100; i++) {
		if (logic[i / 10][i % 10])
			board[i / 10][i % 10] = 'O';
		else
			board[i / 10][i % 10] = ' ';
	}
}

void testing() {
	bool logic[10][10] = { 0 };
	bool your_logic[10][10] = { 0 };
	char board[10][10];
	char si_board[10][10];
	int your_sunken = 0;
	int si_sunken = 0;
	for (int i = 0; i < 100; i++) {
		board[i / 10][i % 10] = ' ';
		si_board[i / 10][i % 10] = ' ';
	}
	seed_all_ships(logic);
	seed_all_ships(your_logic);
	//POTE¯NE CHEATY
	//  |
	//  V
	//update_board(board, your_logic);
	//update_board(si_board, logic);
	//  ^
	//  |
	bool vs = true;
	bool repeated = false;
	bool si_shot = false;
	char si_number = ' ';
	char si_letter = ' ';
	char si_shots_buffer[20][2];
	int number_of_si_shots = 0;
	std::string x = "";
	int prev_points = 0;
	while (true) {
		if (si_sunken == 20 || x == "iziwin") {//WYGRAÑSKO
			system("cls");
			print_win();
			return end_menu();
		}
		if (your_sunken == 20 || x == "izilose") {//PRZEGRAÑSKO
			system("cls");
			print_gameover();
			return end_menu();
		}
		print_boards(board, si_board, your_sunken, si_sunken);
		if (!vs)
			std::cout << "  \n| == !!! INVALID SHOT !!! - TRY AGAIN == |\n";
		if (repeated)
			std::cout << "  \n| == !!! THIS CELL IS ALREADY DOWN !!! == |\n";
		if (prev_points != si_sunken)
			std::cout << "  \n| == !!! YOU HIT - SHOOT AGAIN !!! == |\n";
		if (si_shot) {
			std::cout << "  \n| == !!! COMPUTER SHOT IN "<<si_letter<<(int)si_number + 1<<" !!! == |\n";
			for (int i = 1; i < number_of_si_shots; i++) {
				std::cout << "  \n| == !!! COMPUTER SHOT IN " << si_shots_buffer[i][0] << (int)si_shots_buffer[i][1] + 1 << " !!! == |\n";
			}
		}
		std::cout << "  \nInput your shot or Q to quit: ";
		std::cin >> x;
		if (x != "Q") {
			system("cls");
			//clear_logic(logic);
			vs = valid_shot(x);
			if (vs) {
				prev_points = si_sunken;
				repeated = take_shot_and_if_repeat(logic, si_board, x, si_sunken);
				if (prev_points == si_sunken && !repeated) {
					if (si_move(board, your_logic, your_sunken, si_letter, si_number)) {
						number_of_si_shots = 1;
						si_shots_in_row(si_shots_buffer, board, your_logic, your_sunken, number_of_si_shots);
					}
					else
						number_of_si_shots = 1;
					si_shot = true;
				}
				else
					si_shot = false;
			}
			else
				si_shot = false;
			continue;
		}
		else {
			system("cls");
			clear_logic(logic);
			clear_logic(your_logic);
			print_title();
			return launch_menu();
		}
	}
}

bool si_move(char board[10][10], bool logic[10][10], int& sunken, char& letter, char& number) {
	int shot = std::rand() % 100;
	while (true) {
		if (board[shot / 10][shot % 10] != 'X' && board[shot / 10][shot % 10] != (char)254) {
			letter = (shot % 10) + 65;
			number = (shot / 10);
			if (logic[shot / 10][shot % 10]) {
				board[shot / 10][shot % 10] = (char)254;
				sunken++;
				return true;
			}
			else {
				board[shot / 10][shot % 10] = 'X';
				return false;
			}
		}
		shot++;
		shot %= 100;
	}
}

void si_shots_in_row(char buffer[20][2], char board[10][10], bool logic[10][10], int& sunken, int& number_of_shots) {
	char letter;
	char number;
	bool k = true;

	while (k) {
		k = si_move(board, logic, sunken, letter, number);
		buffer[number_of_shots][0] = letter;
		buffer[number_of_shots][1] = number;
		number_of_shots++;
	}
}

bool take_shot_and_if_repeat(bool logic[10][10], char board[10][10], std::string shot, int& hitted) {
	int letter = shot[0] - 96;
	int number;
	if (shot.length() == 3)
		number = 10;
	else
		number = shot[1] - '0';
	if (logic[number - 1][letter - 1]) {
		if (board[number - 1][letter - 1] != (char)254) {
			hitted++;
		}
		else
			return true;
		board[number - 1][letter - 1] = (char)254;
		return false;

	}
	else {
		if (board[number - 1][letter - 1] == 'X')
			return true;
		board[number - 1][letter - 1] = 'X';
		return false;
	}
}

bool valid_shot(std::string shot) {
	if (shot.length() == 2) {
		if ((shot[0] == 'a' ||
			shot[0] == 'b' ||
			shot[0] == 'c' ||
			shot[0] == 'd' ||
			shot[0] == 'e' ||
			shot[0] == 'f' ||
			shot[0] == 'g' ||
			shot[0] == 'h' ||
			shot[0] == 'i' ||
			shot[0] == 'j') &&
			(shot[1] == '1' ||
				shot[1] == '2' ||
				shot[1] == '3' ||
				shot[1] == '4' ||
				shot[1] == '5' ||
				shot[1] == '6' ||
				shot[1] == '7' ||
				shot[1] == '8' ||
				shot[1] == '9'))
			return true;
		else
			return false;
	}
	else {
		if (shot.length() == 3)
			if ((shot[0] == 'a' ||
				shot[0] == 'b' ||
				shot[0] == 'c' ||
				shot[0] == 'd' ||
				shot[0] == 'e' ||
				shot[0] == 'f' ||
				shot[0] == 'g' ||
				shot[0] == 'h' ||
				shot[0] == 'i' ||
				shot[0] == 'j') && shot[1] == '1' && shot[2] == '0')
				return true;
		return false;
	}
}
