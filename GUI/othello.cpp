// Othello Implementation
// By: Jorge Daboub

#include<iostream>
#include<cstdlib>
#include<vector>
#include"othello.h"
using namespace std;

othello::othello() {
	// Initializing the board as empty
	for(int i = 0; i < BOARD_SIZE; i++) {
		vector<int> temp;
		for(int j = 0; j < BOARD_SIZE; j++)
			temp.push_back(0);
		board.push_back(temp);
	}
	// Initial positions to start the game
	board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)-1] = 1;
	board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)] = 2;
	board[(BOARD_SIZE/2)][(BOARD_SIZE/2)-1] = 2;
	board[(BOARD_SIZE/2)][(BOARD_SIZE/2)] = 1;

}


othello::~othello() {}
// Pass the board to the main function to be displayed
vector<vector<int> > othello::getBoard() {return board;}

// small joke cheat just for laughs
void othello::cheat() 
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			if(board[i][j] == 2)
				board[i][j] = 1;
}

// Checking if a move is valid if it is then placing it, if not retuen error
int othello::move(int r, int c) {
	// If not valid
	if(!valid(r,c))
		return 2;
	
	turn++;
	if((turn % 2) == 1)
		board[r][c] = 1;
	else
		board[r][c] = 2;
	takeOver(r,c);

	// if the game is over return 3 to exit while loop
	if(checkWin() != 0)
		return 3;
	// else return 1
	return 1;
	
}

int othello::checkWin() {
	// if game is not over return 0
	if(turn != ((BOARD_SIZE * BOARD_SIZE) - 4))
		return 0;

	int player1,player2;
	// if not then check who won
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++){
			if(board[i][j] == 1)
				player1++;
			else
				player2++;
		}
	// tie
	if(player1 == player2)
		return 3;
	// player 1 won
	else if(player1 > player2)
		return 1;
	// player 2 won
	else
		return 2;
}

// take over if there are cells int he middle
void othello::takeOver(int r,int c){
	int a, b;
	a = board[r][c];
	if (a == 1)
		b = 2;
	else
		b = 1;
	

	if((r-2) >= 0)
	{
		// For loop is used to check back through the board for possible takes
		for(int i = 1; r - i >= 0; i++)
		{
			// if oposing piece keep going
			if(board[r-i][c] == b)
				continue;
			// if empty break
			if(board[r-i][c] == 0)
				break;
			// if your own, take all in the middle
			if(board[r-i][c] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r-j][c] = a;
				break;
			}
		}
	}
	// same logic as before is being reapeted here
	if((r+2) < BOARD_SIZE)
	{
		for(int i = 1; r + i < BOARD_SIZE; i++)
		{
			if(board[r+i][c] == b)
				continue;
			if(board[r+i][c] == 0)
				break;
			if(board[r+i][c] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r+j][c] = a;
				break;
			}
		}
	}

	if((c+2) < BOARD_SIZE)
	{
		for(int i = 1; c + i < BOARD_SIZE; i++)
		{
			if(board[r][c+i] == b)
				continue;
			if(board[r][c+i] == 0)
				break;
			if(board[r][c+i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r][c+j] = a;
				break;
			}
		}
	}

	if((c-2) >= 0)
	{
		for(int i = 1; c - i >= 0; i++)
		{
			if(board[r][c-i] == b)
				continue;
			if(board[r][c-i] == 0)
				break;
			if(board[r][c-i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r][c-j] = a;
				break;
			}
		}
	}

	if(((r-2) >= 0) && ((c-2) >= 0)) 
	{
		for(int i = 1; (c - i >= 0) && (r - i >= 0); i++)
		{
			if(board[r-i][c-i] == b)
				continue;
			if(board[r-i][c-i] == 0)
				break;
			if(board[r-i][c-i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r-j][c-j] = a;
				break;
			}
		}
	}

	if(((r-2) >= 0) && ((c+2) < BOARD_SIZE))
	{
		for(int i = 1; (c + i < BOARD_SIZE) && (r - i >= 0); i++)
		{
			if(board[r-i][c+i] == b)
				continue;
			if(board[r-i][c+i] == 0)
				break;
			if(board[r-i][c+i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r-j][c+j] = a;
				break;
			}
		}
	}


	if(((r+2) < BOARD_SIZE) && ((c+2) < BOARD_SIZE))
	{
		for(int i = 1; (c + i < BOARD_SIZE) && (r + i < BOARD_SIZE); i++)
		{
			if(board[r+i][c+i] == b)
				continue;
			if(board[r+i][c+i] == 0)
				break;
			if(board[r+i][c+i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r+j][c+j] = a;
				break;
			}
		}
	}

	if(((r+2) < BOARD_SIZE) && ((c-2) >= 0))
	{
		for(int i = 1; (c - i >= 0) && (r + i < BOARD_SIZE); i++)
		{
			if(board[r+i][c-i] == b)
				continue;
			if(board[r+i][c-i] == 0)
				break;
			if(board[r+i][c-i] == a)
			{
				for(int j = 1; i > j ; j++)
					board[r+j][c-j] = a;
				break;
			}
		}
	}
}

// checking if a placement is valid
bool othello::valid(int r,int c) {
	// if already in use
	if(board[r][c] != 0)
		return false;
	// check that it is a valid position with at least one adjacent cell
	if((c-1) >= 0)
		if(board[r][c-1] != 0)
			return true;
	if((c+1) < BOARD_SIZE)
		if(board[r][c+1] != 0)
			return true;

	if((r-1) >= 0) {
		if(board[r-1][c] != 0)
			return true;

		if((c-1) >= 0)
			if(board[r-1][c-1] != 0)
				return true;

		if((c+1) < BOARD_SIZE)
			if(board[r-1][c+1] != 0)
				return true;
	}

	if((r+1) < BOARD_SIZE) {
		if(board[r+1][c] != 0)
			return true;

		if((c-1) >= 0)
			if(board[r+1][c-1] != 0)
				return true;
		if((c+1) < BOARD_SIZE)
			if(board[r+1][c+1] != 0)
				return true;
	}
	// if not return false
	return false;
}