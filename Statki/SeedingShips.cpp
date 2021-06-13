#include <iostream>
#include <cstdlib>
#include "Battleship.hpp"

void seed_all_ships(bool logic[10][10]) {
	for (int i = 4; i > 0; i--) {
		for (int j = i; j <= 4; j++) {
			seed_ship(logic, i);
		}
	}
}

bool cell_with_ship(bool logic[10][10], int cell) {
	if (logic[cell / 10][cell % 10])
		return true;
	return false;
}

void seed_ship(bool logic[10][10], int mast) {
	int cell = std::rand() % 100;
	int direction = std::rand() % 4;
	int k = 0;
	while(true){
		if (cell_with_ship(logic, cell)) {//trafiliœmy na pole ze statkiem
			cell++;
			cell %= 100;
			continue;
		}
		else if (good_place_for_ship(logic, mast, cell, direction)) {//udalo sie trafic na puste pole na ktorym zmiesci sie statek
			insert_ship(logic, mast, cell, direction);
			break;
		}
		else {//jestesmy na pustym polu - patrzymy na reszte kierunków
			int tmp = check_rest_directions(logic, mast, cell, direction);
			if (tmp == -1) {
				cell++;
				cell %= 100;
				continue;
			}
			else {
				insert_ship(logic, mast, cell, tmp);
				break;
			}
		}
	}
}

void insert_ship(bool logic[10][10], int mast, int cell, int direction) {
	switch (direction) {
	case 0:
		for (int i = 0; i < mast; i++) {
			logic[(cell / 10) - i][cell % 10] = 1;
		}
		break;
	case 1:
		for (int i = 0; i < mast; i++) {
			logic[cell / 10][((cell % 10) + i)%10] = 1;
		}
		break;
	case 2:
		for (int i = 0; i < mast; i++) {
			logic[(cell / 10) + i][cell % 10] = 1;
		}
		break;
	default:
		for (int i = 0; i < mast; i++) {
			logic[cell / 10][(cell % 10) - i] = 1;
		}
		break;
	}
}

int check_rest_directions(bool logic[10][10], int mast, int cell, int direction) {
	for (int i = 1; i < 4; i++) {
		if (good_place_for_ship(logic, mast, cell, (direction + i) % 4))
			return (direction + i) % 4;
	}
	return -1;
}

bool good_place_for_ship(bool logic[10][10], int mast, int cell, int direction) {
	int offset = mast - 1;
	if (ship_nearby(logic, cell))
		return false;
	int factor;
	if (direction == 0)
		factor = -10;
	else if (direction == 1)
		factor = 1;
	else if (direction == 2)
		factor = 10;
	else
		factor = -1;
	factor *= offset;
	if (cell + factor < 100 &&
		cell + factor >= 0 &&
		((cell / 10) == ((cell + factor) / 10) || (cell % 10) == ((cell + factor) % 10))) {
		if (ship_nearby(logic, cell + factor))
			return false;
		else
			return true;
	}
	return false;
}

bool ship_nearby(bool logic[10][10], int n) {
	int letter = n % 10;
	int number = n / 10;
	if (number != 0 && number != 9 && letter != 0 && letter != 9) {
		if (logic[number - 1][letter - 1] ||
			logic[number - 1][letter] ||
			logic[number - 1][letter + 1] ||
			logic[number][letter + 1] ||
			logic[number + 1][letter + 1] ||
			logic[number + 1][letter] ||
			logic[number + 1][letter - 1] ||
			logic[number][letter - 1])
			return true;
		else
			return false;
	}
	else if (number == 0) {
		if (letter == 0) {
			if (logic[number + 1][letter] || logic[number][letter + 1] || logic[number + 1][letter + 1])
				return true;
			else
				return false;
		}
		else if (letter == 9) {
			if (logic[number + 1][letter] || logic[number][letter - 1] || logic[number + 1][letter - 1])
				return true;
			else
				return false;
		}
		else if (logic[number][letter + 1] ||
			logic[number][letter - 1] ||
			logic[number + 1][letter + 1] ||
			logic[number + 1][letter] ||
			logic[number + 1][letter - 1])
			return true;
		else
			return false;
	}
	else if (number == 9) {
		if (letter == 0) {
			if (logic[number - 1][letter] || logic[number - 1][letter + 1] || logic[number][letter + 1])
				return true;
			else
				return false;
		}
		else if (letter == 9) {
			if (logic[number - 1][letter] || logic[number][letter - 1] || logic[number - 1][letter - 1])
				return true;
			else
				return false;
		}
		else {
			if (logic[number][letter + 1] ||
				logic[number][letter - 1] ||
				logic[number - 1][letter + 1] ||
				logic[number - 1][letter] ||
				logic[number - 1][letter - 1])
				return true;
			else
				return false;
		}
	}
	else if (letter == 0) {
		if (logic[number - 1][letter] ||
			logic[number + 1][letter] ||
			logic[number - 1][letter + 1] ||
			logic[number][letter + 1] ||
			logic[number + 1][letter + 1])
			return true;
		else
			return false;
	}
	else if (letter == 9) {
		if (logic[number - 1][letter] ||
			logic[number + 1][letter] ||
			logic[number - 1][letter - 1] ||
			logic[number][letter - 1] ||
			logic[number + 1][letter - 1])
			return true;
		else
			return false;
	}
	return false;
}


/*
*   statki
*	4 - 1
*	3 - 2
*	2 - 3
*	1 - 4
*/