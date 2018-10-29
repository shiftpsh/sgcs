#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#define KEY_SPACE ' ' // not defined in ncurses.h
#define KEY_Enter 10
#define START_ROW 5
#define START_COL 5

int HEIGHT, WIDTH;

int** initBoard(int **board) {
	board = (int**) malloc(sizeof(int*)*HEIGHT);
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		board[i] = (int*) malloc(sizeof(int)*WIDTH);
	}
	printf("%d %d\n", HEIGHT, WIDTH);
	board[0][0] = ACS_ULCORNER;//'┌'
	for (i = 1; i < WIDTH - 1; i++)
		board[0][i] = ACS_TTEE;//'┬'
	board[0][WIDTH - 1] = ACS_URCORNER; //'┐'
	for (i = 1; i < HEIGHT - 1; i++) {
		board[i][0] = ACS_LTEE; // '├'
		for (j = 1; j < WIDTH - 1; j++)
			board[i][j] = ACS_PLUS; //'┼'
		board[i][WIDTH - 1] = ACS_RTEE; //'┤'
	}
	board[HEIGHT - 1][0] = ACS_LLCORNER; //'└'
	for (i = 1; i < WIDTH - 1; i++)
		board[HEIGHT - 1][i] = ACS_BTEE; //'┴'
	board[HEIGHT - 1][WIDTH - 1] = ACS_LRCORNER; // '┘'

	return board;
}


void saveGame(int **board, int players, int row, int col, int turn) {
	/*
		Save current game with given name
	*/

	FILE* data;
	char filename[100];
	int i, x, y;

	endwin();

	printf("Filename to save: ");
	scanf("%s", &filename);

	data = fopen(filename, "w");
	if (data == NULL) {
		printf("Failed to write file.\n");
		refresh();
		return;
	}

	fprintf(data, "%d %d %d %d %d %c\n", players, HEIGHT, WIDTH, row, col, turn);

	for (x = 0; x < HEIGHT; x++) {
		for (y = 0; y < WIDTH; y++) {
			if (board[x][y] == 'O' || board[x][y] == 'X' || board[x][y] == 'Y') {
				fprintf(data, "%c", (char) board[x][y]);
			} else {
				fprintf(data, " ");
			}
		}
		fprintf(data, "\n");
	}

	refresh();
	fclose(data);
	return;
}

int** readSavedGame(int *players, int *row, int *col, int *turn) {
	/*
		Read the existing game
	*/
	int** board;

	FILE* data;
	char filename[100];
	char _, t;
	int i, x, y;

	printf("Filename to load: ");
	scanf("%s", &filename);

	data = fopen(filename, "r");
	while (data == NULL) {
		printf("Failed to open file.\n");
		printf("Filename to load: ");
		scanf("%s", &filename);
		data = fopen(filename, "r");
	}

	fscanf(data, "%d %d %d %d %d %c", &(*players), &HEIGHT, &WIDTH, &(*row), &(*col), &t);
	*turn = (int) t; // turn is an integer

	initscr(); // to use box drawing chars

	board = initBoard(board);
	fscanf(data, "%c", &_); // not necessarily needed
	
	for (x = 0; x < HEIGHT; x++) {
		for (y = 0; y < WIDTH; y++) {
			fscanf(data, "%c", &t);
			if (t != ' ') {
				board[x][y] = t;
			}
		}
		fscanf(data, "%c", &_); // newline: not necessarily needed
	}
	fclose(data);
	return board;
}

void paintBoard(int **board, WINDOW *win, int row, int col) {
	/*
		Print the board to the given WINDOW
		using functions of the ncurses library.
	*/
	int x, y, attr;

	for (x = 0; x < HEIGHT; x++) for (y = 0; y < WIDTH; y++) {
		switch (board[x][y]) {
			case 'O': attr = 3; break;
			case 'X': attr = 4; break;
			case 'Y': attr = 5; break;
			default: attr = 2; break;
		}
		wmove(win, x, y);
		if (x == row && y == col) {
			waddch(win, board[x][y] | COLOR_PAIR(attr) | A_UNDERLINE);
		} else {
			waddch(win, board[x][y] | COLOR_PAIR(attr));
		}
	}

	wrefresh(win);
	return;
}

void clearMenu(WINDOW *menu) {
	// Clear menu area
	int x, y;

	for (x = 0; x < 7; x++) for (y = 0; y < 60; y++) if (x != 3) {
		wmove(menu, x, y);
		waddch(menu, ' ');
	}

	wrefresh(menu);
	return;
}

void paintMenu(WINDOW *menu, int turn) {
	clearMenu(menu);

	// Paint informations
	wmove(menu, 2, 2);
	waddstr(menu, "Current Turn : ");
	wmove(menu, 2, 17);
	waddch(menu, (char) turn);
	wmove(menu, 4, 2);
	waddstr(menu, "Keyboard commands:");
	wmove(menu, 5, 2);
	waddstr(menu, "[1] Save");
	wmove(menu, 6, 2);
	waddstr(menu, "[2] Exit without save");

	wrefresh(menu);
	return;
}

void paintWinMessage(WINDOW *menu, int turn) {
	int attr;
	switch (turn) {
		case 'O': attr = 3; break;
		case 'X': attr = 4; break;
		case 'Y': attr = 5; break;
	}

	clearMenu(menu);

	wattron(menu, COLOR_PAIR(attr));
	wmove(menu, 2, 2);
	waddstr(menu, "PLAYER x WIN!!");

	wmove(menu, 2, 9);
	switch (turn) {
		case 'O':
			waddstr(menu, "1");
			break;
		case 'X':
			waddstr(menu, "2");
			break;
		case 'Y':
			waddstr(menu, "3");
			break;
	}
	wattroff(menu, COLOR_PAIR(attr));

	wmove(menu, 3, 2);
	waddstr(menu, "Press any key to exit.");

	wrefresh(menu);
	return;
}

void paintDrawMessage(WINDOW *menu) {
	clearMenu(menu);

	wmove(menu, 2, 2);
	waddstr(menu, "DRAW");
	wmove(menu, 3, 2);
	waddstr(menu, "Press any key to exit.");

	wrefresh(menu);
	return;
}

void clearErrorMessage(WINDOW *menu) {
	int y;

	for (y = 0; y < 60; y++) {
		wmove(menu, 3, y);
		waddch(menu, ' ');
	}

	wrefresh(menu);
	return;
}

void paintTerminationMessage(WINDOW *menu) {
	clearMenu(menu);
	clearErrorMessage(menu);

	wmove(menu, 2, 2);
	waddstr(menu, "Game terminated");

	wmove(menu, 3, 2);
	waddstr(menu, "Press any key to exit.");

	wrefresh(menu);
	return;
}

void paintErrorMessage(WINDOW *menu, char str[]) {
	wmove(menu, 3, 2);
	wattron(menu, COLOR_PAIR(6));
	waddstr(menu, str);
	wattroff(menu, COLOR_PAIR(6));

	wrefresh(menu);
	return;
}

int checkWin(int **board, int players) {
	/*
		Check if the game is over.
		Returns the winner if the game is over; -1 if draw; else returns 0.
	*/

	int len = 5, stoneCount = 0;
	int x, y, d, i, j, k, flag, value;

	// Directions to check:
	int dxarr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
	int dyarr[8] = {1, 0, -1, 1, -1, 1, 0, -1};
	int dx, dy;

	// 4-mok when 3 players
	if (players == 3) len = 4;

	// Check for all cells in board
	for (x = 0; x < HEIGHT; x++) for (y = 0; y < WIDTH; y++) {
		value = board[x][y];

		if (
			(players == 2 && value != 'X' && value != 'O') ||
			(players == 3 && value != 'X' && value != 'O' && value != 'Y')
			) continue; // Stone not placed here
		stoneCount++;
		for (d = 0; d < 8; d++) {
			dx = dxarr[d];
			dy = dyarr[d];
			flag = 1;

			i = x;
			j = y;

			for (k = 0; k < len; k++) {
				i += dx;
				j += dy;

				// If the checking coordinates goes out of bounds, check next case.
				if (i < 0) break;
				if (i > HEIGHT - 1) break;
				if (j < 0) break;
				if (j > WIDTH - 1) break;

				if (board[i][j] == value) {
					flag++;
					if (flag == len) return value;
				} else {
					break;
				}
			}
		}
	}

	if (x * y == stoneCount) {
		return -1; // DRAW
	} else {
		return 0;
	}
}

int Action(WINDOW *win, WINDOW *menu, int **board, int keyin, int *row, int *col, int *turn, int players) {
	/*
		Following right after the keyboard input,
		performs a corresponding action.

		returns 0 if game is not over,
		1 if game is over.
	*/

	int check, error = 0;

	switch (keyin) {
		case KEY_DOWN:
			if (*row < HEIGHT - 1) (*row)++;
			break;
		case KEY_UP:
			if (*row > 0) (*row)--;
			break;
		case KEY_RIGHT:
			if (*col < WIDTH - 1) (*col)++;
			break;
		case KEY_LEFT:
			if (*col > 0) (*col)--;
			break;
		case KEY_Enter:
		case KEY_SPACE:
			// O - X - Y - O - X - Y - ...
			if (board[*row][*col] == 'O' ||
				board[*row][*col] == 'X' ||
				board[*row][*col] == 'Y') {
				// Stone already exists
				error = 1;
			} else {
				board[*row][*col] = *turn;

				if (players == 2) {
					switch (*turn) {
						case 'O': *turn = 'X'; break;
						case 'X': *turn = 'O'; break;
					}
				} else if (players == 3) {
					switch (*turn) {
						case 'O': *turn = 'X'; break;
						case 'X': *turn = 'Y'; break;
						case 'Y': *turn = 'O'; break;
					}
				}
			}
			break;
		case '1':
			keypad(win, FALSE);
			saveGame(board, players, *row, *col, *turn);
			keypad(win, TRUE);
			break;
		case '2':
			paintTerminationMessage(menu);
			return 1;
			break;
	}

	wmove(win, *row, *col);
	
	if (error) {
		paintErrorMessage(menu, "Stone already exists there!");
	} else {
		clearErrorMessage(menu);
	}

	check = checkWin(board, players);

	if (check != 0) {
		if (check == -1) { // DRAW
			paintDrawMessage(menu);
			return 1;
		} else { // WIN
			paintWinMessage(menu, check);
			return 1;
		}
	}

	wrefresh(win);
	wrefresh(menu);

	return 0;
}

void gameStart(WINDOW *win, WINDOW *menu, int load, int** loadedBoard, int players, int row, int col, int turn) {
	int **board;
	int finished = 0;
	int keyin, result;
	wmove(win, row, col);

	// Initializing the board
	if (load == 'Y' || load == 'y') {
		board = loadedBoard;
	} else {
		board = initBoard(board);
	}

	while (1) {
		/*
			This While loop constantly loops in order to
			draw every frame of the WINDOW.
		*/

		// Paint board
		paintBoard(board, win, row, col);

		// Terminate game if finished
		if (finished) {
			keyin = wgetch(win);
			break;
		}

		// Paint menu
		paintMenu(menu, turn);		

		// Move cursor to last action point
		wmove(win, row, col);

		// Get keyboard input
		keyin = wgetch(win);

		// Do action and save its result according to the keypress
		result = Action(win, menu, board, keyin, &row, &col, &turn, players);

		// Refresh windows
		wrefresh(win);
		wrefresh(menu);

		if (result == 1) {
			// Game is over
			finished = 1;
		}
	}
	return;
}

int main() {
	WINDOW *win, *menu;
	char load;
	int players, row = 0, col = 0, turn = 'O';
	int** loadedBoard;

	/*
		Prompts to ask options of the game
	*/

	// Option #1: load saved game
	printf("Load saved game? [Y/N] : ");
	scanf("%c", &load);

	// Invalid option checking
	while (load != 'Y' && load != 'N' && load != 'y' && load != 'n') {
		printf("Invalid option.\nAvailiable options are 'Y', 'N' : ");
		scanf("%c", &load);
	}

	if (load == 'Y' || load == 'y') {
		loadedBoard = readSavedGame(&players, &row, &col, &turn);
	} else {
		// Option #2-1: height
		printf("Enter the HEIGHT of the board [8 - 32] : ");
		scanf("%d", &HEIGHT);

		while (HEIGHT < 8 || HEIGHT > 32) {
			printf("Invalid height.\nHeight should be in [8 - 32] : ");
			scanf("%d", &HEIGHT);
		}

		// Option #2-2: width
		printf("Enter the WIDTH of the board [8 - 64] : ");
		scanf("%d", &WIDTH);

		while (WIDTH < 8 || WIDTH > 64) {
			printf("Invalid width.\nWidth should be in [8 - 64] : ");
			scanf("%d", &WIDTH);
		}

		// Option #3: players
		printf("Enter the number of players [2 - 3] : ");
		scanf("%d", &players);

		// Invalid option checking
		while (players != 2 && players != 3) {
			printf("Invalid option.\nAvailiable options are 2 - 3 : ");
			scanf("%d", &players);
		}
	}

	// Window initialization
	initscr();
	win = newwin(HEIGHT, WIDTH, 0, 0);
	menu = newwin(7, 60, HEIGHT, 0);
	noecho();
	keypad(win, TRUE);
	cbreak();

	// Color initialization
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLACK); // [1] default = white on black
	init_pair(2, COLOR_BLACK, COLOR_YELLOW); // [2] board   = black on yellow

	if (players == 2) {
		init_pair(3, COLOR_WHITE, COLOR_BLACK); // [3] O = white on black
		init_pair(4, COLOR_BLACK, COLOR_WHITE); // [4] X = black on white
	} else if (players == 3) {
		init_pair(3, COLOR_BLACK, COLOR_RED); // [3] O = black on red
		init_pair(4, COLOR_BLACK, COLOR_GREEN); // [4] X = black on green
		init_pair(5, COLOR_WHITE, COLOR_BLUE); // [5] Y = white on blue
	}

	init_pair(6, COLOR_WHITE, COLOR_RED); // [6] error   = red on white

	gameStart(win, menu, load, loadedBoard, players, row, col, turn);

	// Game ended
	endwin();
	return 0;
}
