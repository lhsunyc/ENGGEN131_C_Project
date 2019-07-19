/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
*** Name: Yicheng Sun   ID: 883301019 ***

*/

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
        // This function will take three input integers and returns the middle
	// value(i.e.the 2nd place prize).
	int sum = prize1 + prize2 + prize3;
	double mean = sum / 3.0;
	double d1 = prize1 - mean;
	double d2 = prize2 - mean;
	double d3 = prize3 - mean;
	if (d1 < 0){
       d1 = d1 * (-1);
	}
	if (d2 < 0){
		d2 = d2 * (-1);
	}
	if (d3 < 0){
		d3 = d3 * (-1);
	}
	if ((d1 <= d2) && (d1 <= d3)) {
		return prize1;
	}
	if ((d2 <= d1) && (d2 <= d3)) {
		return prize2;
	}
        if ((d3 <= d1) && (d3 <= d2)) {
		return prize3;
	}
	return 0;
}

int FourInARow(int values[], int length)
{
	// A function called FourInARow() which takes two inputs: an array of integers and the
	// length of the array(i.e.the number of elements in the array that should be examined).The
	// function will return the index position of the first element in the array that begins a four - in - arow
	// sequence(of any value).If the array does not contain a four - in - a - row sequence, then the
	// function will return -1.

	for (int i = 0; i < length - 3; i++) {
		if ((values[i + 1] == values[i]) && (values[i + 2] == values[i]) && (values[i + 3] == values[i])) {
			return i;
		}
	}
	return -1;
}

int BinaryToDecimal(int binary)
{
	// This function will convert binary number to decimal number. 
	// The input this function will be an integer,
	// consisting only of the digits 0 and 1, representing a binary number.
	// The output from this function should be the equivalent decimal value.
	
	int temp = binary;
	int num = 1;
	int decimal = 0;
	while (temp != 0) {
		int bit = temp % 10;
		if (bit == 1) {
			decimal += num;
		}
		else {
			decimal += 0;
		}
		num = num * 2;
		temp = temp / 10;
	}
	return decimal;
}

double MedianAbility(double abilities[], int length)
{
	// This funciton will find the median number from a sequence of numbers.
	// This function takes two inputs: an array of double values(representing the estimated ability scores)
        // and the length of the array.
	// The output of this function will be the median ability score.
	
	
	int maxValues = length;
	while (maxValues != 0) {
		for (int i = 0; i < maxValues - 1; i++) {
			if (abilities[i] > abilities[i + 1]) {
				double temp;
				temp = abilities[i];
				abilities[i] = abilities[i + 1];
				abilities[i + 1] = temp;
			}

		}
		maxValues--;
	}
	if (length % 2 != 0) {
		return abilities[(length / 2)];
	}
	else {
		return (abilities[length / 2] + abilities[(length / 2) - 1]) / 2;
	}
}

void RemoveSpaces(char *name)
{
	// This function will remove extra space from an original text.
	// Define a function called RemoveSpaces() which is passed a string as input.
	for (int i = strlen(name) - 1; i >= 0; i--) {
		if ((name[i] == ' ') && (name[i - 1] == ' ')) {
			for (unsigned int j = i; j < strlen(name); j++) {
				name[j] = name[j + 1];
			}
		}
	}
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	// This function will iniatialise a board for players.
	// this function takes a provided 2 - dimensional array as inputs and
	// the size of the board(between 4 and 10 inclusive).
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (size % 2 != 0) {
				board[i][j] = 0;
				board[size / 2][size / 2] = 3;
			}
			else {
				board[i][j] = 0;
				board[size / 2-1][size / 2-1] = 3;
				board[size / 2 - 1][size / 2] = 3;
				board[size / 2][size / 2 - 1] = 3;
				board[size / 2][size / 2] = 3;
			}
		}
	}
}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	// This function will add the move taken by user to the board.
	// The inputs to the function will be
	// the underlying 2 - dimensional array, the size of the board(which will be between 4 and 10 inclusive),
	// the side the user wants to drop the token into(which will be a character, and
	// will either be ¡®N¡¯, ¡®E¡¯, ¡®W¡¯ or ¡®S¡¯), the row or column the user wants to place the token into
	// (which will be an integer between 0 and size - 1), which player is placing the token(either 1 or 2),
	// and two pointers(which will be used to record the final position at which the token comes to rest).

	if (side == 'N') {
		for (int i = 0; i < size; i++) {
			// if move is blocked(or it is a invalid move)
			if (board[0][move] != 0) {
				*lastRow = -1;
				*lastCol = -1;
				return;
			}
			// if there is a token or # 
			if (board[i][move] > 0) {
				board[i - 1][move] = player;
				*lastRow = i - 1;
				*lastCol = move;
				return;
			}
			// if it goes to the last position
			else if (i == size - 1) {
				board[size - 1][move] = player;
				*lastRow = size - 1;
				*lastCol = move;
				
			}
		}
	}
	else if (side == 'S') {
		for (int i = size - 1; i >= 0; i--) {
			// if move is blocked(or it is a invalid move)
			if (board[size - 1][move] != 0) {
				*lastRow = -1;
				*lastCol = -1;
				return;
			}
			// if there is a token or # 
			if (board[i][move] > 0) {
				board[i + 1][move] = player;
				*lastRow = i + 1;
				*lastCol = move;
				return;
			}
			// if it goes to the last position
			else if (i == 0) {
			board[0][move] = player;
			*lastRow = 0;
			*lastCol = move;
			}
		}
	}
	else if (side == 'W') {
		for (int i = 0; i < size; i++) {
			// if move is blocked(or it is a invalid move)
			if (board[move][0] != 0) {
				*lastRow = -1;
				*lastCol = -1;
				return;
			}
			// if there is a token or # 
			if (board[move][i] > 0) {
			    board[move][i - 1] = player;
			   *lastRow = move;
			   *lastCol = i - 1;
			   return;
		    }
			// if it goes to the last position
			else if (i == size - 1) {
			    board[move][size - 1] = player;
			    *lastRow = move;
			    *lastCol = size - 1;
		    }
	    }
	}
	else if (side == 'E') {
		for (int i = size - 1; i >= 0; i--) {
			// if move is blocked(or it is a invalid move)
			if (board[move][size - 1] != 0) {
				*lastRow = -1;
				*lastCol = -1;
				return;
			}
			// if there is a token or # 
			if (board[move][i] > 0) {
			    board[move][i + 1] = player;
			    *lastRow = move;
			    *lastCol = i + 1;
				return;
			   
		    }
			// if it goes to the last position
			else if (i == 0) {
				board[move][0] = player;
			    *lastRow = move;
			    *lastCol = 0;
		    }
	    }
	}
}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// The function tests to see whether the last move made has ended the game.
	// this function takes current board as inputs,
	// the size of the board(which will be between 4 and 10 inclusive),
	// the row number which the token was taken at,
	// the collumn number which the token was taken at,
	// and this function will return the winning player.

	int spacecount = 0;
	int wincount1 = 0;
	int wincount2 = 0;
	int wincount3 = 0;
	int wincount4 = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				spacecount++;
			}
		}
	}
	// check wincount from each direction(horizontal,vertical and diagonal)
	for (int k = 0; k < 7; k++) {
		if (board[row - 3 + k][col - 3 + k] == player && row - 3 + k >= 0 && col - 3 + k >= 0) {
			wincount2++;
		}else{
			wincount2 = 0;
		}

		if (board[row - 3 + k][col + 3 - k] == player && row - 3 + k >= 0 && col + 3 + k >= 0) {
			wincount4++;
		}else{
			wincount4 = 0;
		}

		if (board[row - 3 + k][col] == player && row - 3 + k >= 0) {
			wincount1++;
		}else{
			wincount1 = 0;
		}

		if (board[row][col - 3 + k] == player && col - 3 + k >= 0) {
			wincount3++;
		}else{
			wincount3 = 0;
		}

		if (wincount1 == 4 || wincount2 == 4 || wincount3 == 4 || wincount4 == 4) {
			return player;
		}
	}

	if (spacecount == 0/*no available spaces to place token*/) {
		return player;
	}
	if (row == -1 && col == -1/*if there is a invalid move*/) {
		return 0;
	}
	return 0;
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	// This function will display the board string with different sizes chosen by users.
	// this function takes the current board (and size) as input,
	// as well as a string buffer(which is just an array of type char).

	// define variables
	char a = 0;
	char k = 0;

	// create a board string
	for (int i = 0; i < (size + 4)*(size + 5); i++) {
		boardString[i] = '.';
		if (i % (size + 5) == size + 4 && i != 0) {
			boardString[i] = '\n';
		}
		else if (i == 0 || i == 1 || i == size + 5 || i == size + 6 ||
			i == size + 2 || i == size + 3 || i == size + size + 7 || i == size + size + 8 ||
			i == (size + 3)*(size + 4) - 2 || i == (size + 3)*(size + 4) - 1 || i == (size + 3)*(size + 4) + size + 3 || i == (size + 3)*(size + 4) + size + 4 ||
			i == (size + 3)*(size + 4) + size || i == (size + 3)*(size + 4) + size + 1 || i == (size + 3)*(size + 4) + size + size + 5 || i == (size + 3)*(size + 4) + size + size + 6) {
			boardString[i] = '-';
		}
		else if (i % (size + 5) == 0 && boardString[i] != '-') {
			boardString[i] = 'W';
		}
		else if (i % (size + 5) == 1 && boardString[i] != '-') {
			boardString[i] = a + '0';
			a++;
		}
		else if (i % (size + 5) == size + 3 && boardString[i] != '-') {
			boardString[i] = 'E';
		}
		else if (i % (size + 5) == size + 2 && boardString[i] != '-') {
			boardString[i] = k + '0';
			k++;
		}
		boardString[(size + 4)*(size + 5)] = '\0';
	}
	for (int i = 2; i < size + 2; i++) {
		boardString[i] = 'N';
	}
	for (int i = (size + 3)*(size + 4) + size + 5; i < 2 * size + (size + 3)*(size + 4) + 5; i++) {
		boardString[i] = 'S';
	}
	for (char i = 0; i < size; i++) {
		boardString[i + size + 7] =  i + '0';
		boardString[i + (size + 3)*(size + 4)] = i + '0';
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 3) {
				boardString[(2 + i) * (size + 5) + 2 + j] = '#';
		    }
			if (board[i][j] == 0) {
				boardString[(2 + i) * (size + 5) + 2 + j] = '.';
			}
			if (board[i][j] == 1) {
				boardString[(2 + i) * (size + 5) + 2 + j] = 'X';
			}
			if (board[i][j] == 2) {
				boardString[(2 + i) * (size + 5) + 2 + j] = 'O';
			}
		}
	}
}

int BlockGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// This is a helper function.
	// The function tests to see if the bot needs to block other player's win move.
	// this function takes current board as inputs,
	// the size of the board(which will be between 4 and 10 inclusive),
	// the row number which the token was taken at,
	// the collumn number which the token was taken at,
	// and this function will return the winning player.

	int spacecount = 0;
	int wincount1 = 0;
	int wincount2 = 0;
	int wincount3 = 0;
	int wincount4 = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				spacecount++;
			}
		}
	}
	// check wincount from each direction(horizontal,vertical and diagonal)
	for (int k = 0; k < 7; k++) {
		if (board[row - 3 + k][col - 3 + k] == player && row - 3 + k >= 0 && col - 3 + k >= 0) {
			wincount2++;
		}
		else {
			wincount2 = 0;
		}

		if (board[row - 3 + k][col + 3 - k] == player && row - 3 + k >= 0 && col + 3 + k >= 0) {
			wincount4++;
		}
		else {
			wincount4 = 0;
		}

		if (board[row - 3 + k][col] == player && row - 3 + k >= 0) {
			wincount1++;
		}
		else {
			wincount1 = 0;
		}

		if (board[row][col - 3 + k] == player && col - 3 + k >= 0) {
			wincount3++;
		}
		else {
			wincount3 = 0;
		}

		if (wincount1 == 3 || wincount2 == 4 || wincount3 == 3 || wincount4 == 4) {
			return player;
		}
	}

	if (spacecount == 0/*no available spaces to place token*/) {
		return player;
	}
	if (row == -1 && col == -1/*if there is a invalid move*/) {
		return 0;
	}
	return 0;
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// This function will creat a bot for this game.(check winmove for itself only)
	// this function takes the current board(and size) as input,
	// the size of the board(which will be between 4 and 10 inclusive),
	// the side the bot wants to drop the token into(which will be a character, and
	// will either be ¡®N¡¯, ¡®E¡¯, ¡®W¡¯ or ¡®S¡¯), and 
	// the move the bot will go(which is an integer, and between 0 and size-1 inclusive).


	// define variables
	int numValidmoveN[MAX_SIZE] = { 0 };
	int numValidmoveS[MAX_SIZE] = { 0 };
	int numValidmoveW[MAX_SIZE] = { 0 };
	int numValidmoveE[MAX_SIZE] = { 0 };
	int gameOver, lastRow, lastCol;
	gameOver = 0;
	int newboard[MAX_SIZE][MAX_SIZE] = { 0 };

	// copy a newboard from the board(original)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			newboard[i][j] = board[i][j];
		}
	}

	// check valid move for bot
	for (int i = 0; i < size; i++) {
		if (board[i][0] == 0) {
			numValidmoveW[i] = i;
		}
		else {
			numValidmoveW[i] = -1;
		}
		if (board[i][size - 1] == 0) {
			numValidmoveE[i] = i;
		}
		else {
			numValidmoveE[i] = -1;
		}
		if (board[0][i] == 0) {
			numValidmoveN[i] = i;
		}
		else {
			numValidmoveN[i] = -1;
		}
		if (board[size - 1][i] == 0) {
			numValidmoveS[i] = i;
		}
		else {
			numValidmoveS[i] = -1;
		}
	}

	//Check win move...
	for (int i = 0; i < size; i++) {
		if (numValidmoveN[i] != -1) {
			//check win move in N direction 
			*side = 'N';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveW[i] != -1) {
			//check win move in W direction 
			*side = 'W';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveS[i] != -1) {
			//check win move in S direction 
			*side = 'S';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveE[i] != -1) {
			//check win move in E direction 
			*side = 'E';
			*move = i;	
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
	}
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// This function will creat a bot for this game.(check self winmove and block others' winmove)
	// this function takes the current board(and size) as input,
	// the size of the board(which will be between 4 and 10 inclusive),
	// the side the bot wants to drop the token into(which will be a character, and
	// will either be ¡®N¡¯, ¡®E¡¯, ¡®W¡¯ or ¡®S¡¯), and 
	// the move the bot will go(which is an integer, and between 0 and size-1 inclusive).


	// define variables
	int numValidmoveN[MAX_SIZE] = { 0 };
	int numValidmoveS[MAX_SIZE] = { 0 };
	int numValidmoveW[MAX_SIZE] = { 0 };
	int numValidmoveE[MAX_SIZE] = { 0 };
	int gameOver, lastRow, lastCol;
	gameOver = 0;
	int newboard[MAX_SIZE][MAX_SIZE] = { 0 };

	// copy a newboard from the board(original)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			newboard[i][j] = board[i][j];
		}
	}

	// check valid move for bot
	for (int i = 0; i < size; i++) {
		if (board[i][0] == 0) {
			numValidmoveW[i] = i;
		}
		else {
			numValidmoveW[i] = -1;
		}
		if (board[i][size - 1] == 0) {
			numValidmoveE[i] = i;
		}
		else {
			numValidmoveE[i] = -1;
		}
		if (board[0][i] == 0) {
			numValidmoveN[i] = i;
		}
		else {
			numValidmoveN[i] = -1;
		}
		if (board[size - 1][i] == 0) {
			numValidmoveS[i] = i;
		}
		else {
			numValidmoveS[i] = -1;
		}
	}

	//Check win move and block other player's winmove
	for (int i = 0; i < size; i++) {
		if (numValidmoveN[i] != -1) {
			//check win move in N direction 
			*side = 'N';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
			AddMoveToBoard(newboard, size, *side, *move, 3 - player, &lastRow, &lastCol);
			gameOver = BlockGameOver(newboard, size, 3 - player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveW[i] != -1) {
			//check win move in W direction 
			*side = 'W';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
			AddMoveToBoard(newboard, size, *side, *move, 3 - player, &lastRow, &lastCol);
			gameOver = BlockGameOver(newboard, size, 3 - player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveS[i] != -1) {
			//check win move in S direction 
			*side = 'S';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
			AddMoveToBoard(newboard, size, *side, *move, 3 - player, &lastRow, &lastCol);
			gameOver = BlockGameOver(newboard, size, 3 - player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
		if (numValidmoveE[i] != -1) {
			//check win move in E direction 
			*side = 'E';
			*move = i;
			AddMoveToBoard(newboard, size, *side, *move, player, &lastRow, &lastCol);
			gameOver = CheckGameOver(newboard, size, player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
			AddMoveToBoard(newboard, size, *side, *move, 3 - player, &lastRow, &lastCol);
			gameOver = BlockGameOver(newboard, size, 3 - player, lastRow, lastCol);
			if (gameOver) {
				return;
			}
			else {
				newboard[lastRow][lastCol] = 0;
			}
		}
	}
}
