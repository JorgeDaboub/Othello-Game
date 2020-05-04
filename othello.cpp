// Othello Implementation
// By: Jorge Daboub

#include<iostream>
#include<cstdlib>
#include"othello.h"
using namespace std;

othello::othello() {
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = 0;

	board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)-1] = 1;
	board[(BOARD_SIZE/2)-1][(BOARD_SIZE/2)] = 2;
	board[(BOARD_SIZE/2)][(BOARD_SIZE/2)-1] = 2;
	board[(BOARD_SIZE/2)][(BOARD_SIZE/2)] = 1;
}

othello::~othello() {}

void othello::move() {

	int c,r;
	while(true){
		if((turn % 2) == 0)
			cout << "Player X moves: ";
		else
			cout << "Player O moves: ";
		cin >> r >> c;

		if(valid(r,c))
			break;
		else
			cout << "Illegal move." << endl;
	}
	turn++;
	if((turn % 2) == 1)
		board[r][c] = 1;
	else
		board[r][c] = 2;
	takeOver(r,c);
	display();
	checkWin();
}

void othello::display(){
	system("clear");
	cout << endl << " ";
	for(int i = 0; i < BOARD_SIZE;i++)
		cout << " " << i;
	cout << endl;

	for(int i = 0; i < BOARD_SIZE;i++){
		cout << i;
		for(int j = 0; j < BOARD_SIZE;j++){
			if(board[i][j] == 0)
				cout << " .";
			else if(board[i][j] == 1)
				cout << " X";
			else
				cout << " O";	
		}
		cout << endl;
	}
}

void othello::checkWin() {
	if(turn != ((BOARD_SIZE * BOARD_SIZE) - 4))
		return;

	int player1,player2;

	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++){
			if(board[i][j] == 1)
				player1++;
			else
				player2++;
		}
	if(player1 == player2){
		cout << "The game ends in a tie!" << endl;
		exit(1);
	}
	else if(player1 > player2){
		cout << "Player X has won!" << endl;
		exit(1);
	}
	else{
		cout << "Player O has won!" << endl;
		exit(1);
	}
}

void othello::takeOver(int r,int c){
	int tempr, tempc, a;
	a = board[r][c];

	if((r-2) >= 0)
		if(board[r-2][c] == a)
			if(board[r-1][c] != 0)
				board[r-1][c] = a;

	if((r+2) < BOARD_SIZE)
		if(board[r+2][c] == a)
			if(board[r+1][c] != 0)
				board[r+1][c] = a;

	if((c+2) < BOARD_SIZE)
		if(board[r][c+2] == a)
			if(board[r][c+1] != 0)
				board[r][c+1] = a;

	if((c-2) >= 0)
		if(board[r][c-2] == a)
			if(board[r][c-1] != 0)
				board[r][c-1] = a;

	if(((r-2) >= 0) && ((c-2) >= 0)) 
		if(board[r-2][c-2] == a)
			if(board[r-1][c-1] != 0)
				board[r-1][c-1] = a;

	if(((r-2) >= 0) && ((c+2) < BOARD_SIZE)) 
		if(board[r-2][c+2] == a)
			if(board[r-1][c+1] != 0)
				board[r-1][c+1] = a;

	if(((r+2) < BOARD_SIZE) && ((c+2) < BOARD_SIZE)) 
		if(board[r+2][c+2] == a)
			if(board[r+1][c+1] != 0)
				board[r+1][c+1] = a;

	if(((r+2) < BOARD_SIZE) && ((c-2) >= 0)) 
		if(board[r+2][c-2] == a)
			if(board[r+1][c-1] != 0)
				board[r+1][c-1] = a;

}


bool othello::valid(int r,int c) {
	if(board[r][c] != 0)
		return false;

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
	return false;
}


