#ifndef HEADER_FILE
#define HEADER_FILE

//Drukowanie
void print_boards(char tab1[10][10], char tab2[10][10], int sunken, int si_sunken);
void print_title();
void print_line(char first, char middle, char last);
void print_win();
void print_gameover();

//Rozstawianie
void seed_all_ships(bool logic[10][10]);
void seed_ship(bool logic[10][10], int mast);
void insert_ship(bool logic[10][10], int mast, int cell, int direction);
int check_rest_directions(bool logic[10][10], int mast, int cell, int direction);
bool good_place_for_ship(bool logic[10][10], int mast, int cell, int direction);
bool ship_nearby(bool logic[10][10], int n);
bool cell_with_ship(bool logic[10][10], int cell);

//FunkcjeGry
void clear_logic(bool logic[10][10]);
void update_board(char board[10][10], bool logic[10][10]);
void testing();
bool valid_shot(std::string x);
bool take_shot_and_if_repeat(bool logic[10][10], char board[10][10], std::string shot, int& hitted);
bool si_move(char board[10][10], bool logic[10][10], int& sunken, char& letter, char& number);
void si_shots_in_row(char buffer[20][2], char board[10][10], bool logic[10][10], int& sunken, int& number_of_shots);

//Menu
void launch_menu();
void end_menu();
#endif