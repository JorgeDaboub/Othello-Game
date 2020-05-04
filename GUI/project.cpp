// Othello main
// By: Jorge Daboub

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <cmath>
#include "othello.h"
#include "gfx.h"

using namespace std;
// Size of the cells and how many there are
int cell;
int sz;

// displaying the board into the graphics window
void display(vector<vector<int>> board, bool valid, bool last, vector<string> names)
{
	gfx_color(255, 255, 255);
	unsigned int Px = 0, Po = 0, turn = 0;
	// checking the current score and current turn
	for (int i = 0; i < board.size(); i++)
		for (auto j : board[i])
		{
			if (j == 1)
			{
				// checking the score of each player and the current turn
				Px++;
				turn++;
			}
			else if (j == 2)
			{
				Po++;
				turn++;
			}
		}
	// Clearing
	gfx_clear_color(0, 128, 255);
	gfx_clear();

	// displaying the current score
	if (names.size() == 0)
	{
		string temp = "Black Player: " + to_string(Px) + "   White Player: " + to_string(Po);
		int length = temp.size() + 1;
		char array[length];
		strcpy(array, temp.c_str());
		gfx_text(255, 75, array);
	}
	else if (names.size() == 1)
	{
		string temp = names[0] + ": " + to_string(Px) + "   White Player: " + to_string(Po);
		int length = temp.size() + 1;
		char array[length];
		strcpy(array, temp.c_str());
		gfx_text(255, 75, array);
	}
	else if (names.size() == 2)
	{
		string temp = names[0] + ": " + to_string(Px) + "   " + names[1] + ": " + to_string(Po);
		int length = temp.size() + 1;
		char array[length];
		strcpy(array, temp.c_str());
		gfx_text(255, 75, array);
	}

	// if there was an invalid placement atemmpt then display invalid move in red
	if (!valid)
	{
		gfx_color(204, 0, 0);
		gfx_text(390, 100, "Invalid Move!");
		gfx_color(255, 255, 255);
	}
	// Checking whos turn it is to play
	if (!last)
	{
		if (names.size() == 0)
		{
			if ((turn % 2) == 0)
				gfx_text(280, 100, "Black to move.");
			else
				gfx_text(280, 100, "White to move.");
		}
		else if (names.size() == 1)
		{
			// displaying the name of the player who is going to play
			if ((turn % 2) == 0)
			{
				gfx_color(0, 0, 0);
				string tempPlayer = names[0] + " to move.";
				int tempLength = tempPlayer.size() + 1;
				char tempArray[tempLength];
				strcpy(tempArray, tempPlayer.c_str());
				gfx_text(280, 100, tempArray);
				gfx_color(255, 255, 255);
			}
			else
				gfx_text(280, 100, "White to move.");
		}
		else if (names.size() == 2)
		{
			if ((turn % 2) == 0)
			{
				gfx_color(0, 0, 0);
				string tempPlayer = names[0] + " to move.";
				int tempLength = tempPlayer.size() + 1;
				char tempArray[tempLength];
				strcpy(tempArray, tempPlayer.c_str());
				gfx_text(280, 100, tempArray);
				gfx_color(255, 255, 255);
			}
			else
			{
				string tempPlayer = names[1] + " to move.";
				int tempLength = tempPlayer.size() + 1;
				char tempArray[tempLength];
				strcpy(tempArray, tempPlayer.c_str());
				gfx_text(280, 100, tempArray);
			}
		}
	}
	// if game is done then display the final score
	if (last)
		gfx_text(260, 55, "The Final Score for the Game is");
	else
		gfx_text(250, 55, "The Current Score for the Game is");

	cell = 70;
	sz = board.size();
	// Initial top left coordinates
	int x = 70, y = 120;
	// Get a green background
	gfx_color(0, 150, 0);
	for (int i = 0; i < (cell * 8); i++)
		gfx_line(x, y + i, x + (cell * 8), y + i);

	// two layers around the white border
	gfx_color(255, 255, 255);
	gfx_line(x - 1, y - 1, x + (cell * sz) + 1, y - 1);
	gfx_line(x - 1, y - 1, x - 1, y + (cell * sz) + 1);
	gfx_line(x - 1, y + (cell * sz) + 1, x + (cell * sz) + 1, y + (cell * sz) + 1);
	gfx_line(x + (cell * sz) + 1, y - 1, x + (cell * sz) + 1, y + (cell * sz) + 1);
	// seccond layer
	gfx_line(x, y, x + (cell * sz), y);
	gfx_line(x, y, x, y + (cell * sz));
	gfx_line(x + (cell * sz), y, x + (cell * sz), y + (cell * sz));
	gfx_line(x, y + (cell * sz), x + (cell * sz), y + (cell * sz));

	// Drawing lines of the board
	for (int i = 0; i < sz; i++)
		gfx_line(x, y + (cell * i), x + (cell * sz), y + (cell * i));
	for (int i = 0; i < sz; i++)
		gfx_line(x + (cell * i), y, x + (cell * i), y + (cell * sz));

	int radius = 25;
	int circleX, circleY;
	// disaplying the circles on the board
	// I did it through two separate iterations as changing the color makes the display super laggy
	gfx_color(0,0,0);
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
		{
			// if black then print
			if (board[i][j] == 1)
			{
				// getting x and y origin of the circle
				circleX = (x + cell / 2) + (j * cell);
				circleY = (y + cell / 2) + (i * cell);

				// displaying the shape
				gfx_point(circleX, circleY);
				for (int i = radius; i >= 1; i--)
				{
					gfx_circle(circleX, circleY, i);
					i--;
				}
			}
		}
	gfx_color(255, 255, 255);

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
		{
			// if white then print
			if (board[i][j] == 2)
			{
				// getting x and y origin of the circle
				circleX = (x + cell / 2) + (j * cell);
				circleY = (y + cell / 2) + (i * cell);

				// displaying the shape
				gfx_point(circleX, circleY);
				for (int i = radius; i >= 1; i--)
				{
					gfx_circle(circleX, circleY, i);
					i--;
				}
			}
		}		
	gfx_flush();
}
// Function to send a firework
void firework(int x, int y, int length, int width, char* tempArray)
{
	gfx_color(255,0,0);
	for (int i = 0; i < 450; i++)
	{
		gfx_clear();
		for (int j = 0; j < width; j++)
		{
			// drawing the rockets
			gfx_line(x + j, y - (i*2/3), x + j, y - length - (i*2/3));
			gfx_line(500+j, 700 - 40 - i, 500+j, 700 - 50 - i);
			gfx_line(351+j, 550-40-(i*2/5), 351+j, 550-45-(i*2/5));
			gfx_line(349+j, 550-40-(i*2/5), 349+j, 550-45-(i*2/5));
			gfx_text(300,350, tempArray);
		}
		gfx_flush();
		usleep(5000);
	}
	int x1 = x, x2 = 500, y1 = y - length - (450*2/3), y2 = 700 - 50 - 450;
	int x3 = 350, y3 = 550 - 40 - (450*2/5);

	float angle = M_PI_4;
	gfx_color(0,255,0);
	// drawing the explosions
	for (int i = 0; i < 70; i++)
	{
		gfx_clear();
		for(int j = 0; j < 8; j++)
		{
			gfx_line(x1 + (cos(angle * j) * i), y1 + (sin(angle * j) * i), x1 + (cos(angle * j) * (i + 5)), y1 + sin(angle * j) * (i + 5));
		}
		for(int j = 0; j < 8; j++)
		{
			gfx_line(x2 + (cos(angle * j) * (i*2)), y2 + (sin(angle * j) * i * 2), x2 + (cos(angle * j) * (i + 5) * 2), y2 + sin(angle * j) * (i + 5) * 2);
		}
		for(int j = 0; j < 8; j++)
		{
			gfx_line(x3 + (cos(angle * j) * (i*3)), y3 + (sin(angle * j) * i * 3), x3 + (cos(angle * j) * (i + 6) * 3), y3 + sin(angle * j) * (i + 6) * 3);
			gfx_line(1 + x3 + (cos(angle * j) * (i*3)),1 + y3 + (sin(angle * j) * i * 3), 1+  x3 + (cos(angle * j) * (i + 6) * 3), y3 + sin(angle * j) * (i + 6) * 3);
		}
		gfx_flush();
		usleep(10000);
	}
}

int main(int argc, char *argv[])
{
	// starting the game with a small welcome screen
	othello game;
	int size = 700;
	gfx_open(size, size, "Othello");
	gfx_text(290, 350, "Lets play Othello!");
	gfx_text(235, 390, "To make a move click on an empty cell.");
	// waiting for any key to be pressed
	char input;
	input = gfx_wait();

	vector<string> names;
	// If the user inputs one name
	if (argc == 2)
	{
		string temp1 = argv[1];
		names.push_back(temp1);
	}
	// if two names are inputed
	else if (argc > 2)
	{
		string temp = argv[1];
		names.push_back(temp);
		temp = argv[2];
		names.push_back(temp);
	}

	// getting the board to be used
	auto board = game.getBoard();
	// displaying the board for the first time
	display(board, true, false, names);

	int r, c;
	int part = 0;
	int x, y;

	// beginning the loop
	while (part < 3)
	{
		input = gfx_wait(); // Getting row and column
		if (input == 'q')
			return 0;

		// Cheat code to make all cells for the first player
		// just for fun
		if (input == 'p') {
			game.cheat();
			display;
		}
		
		if (input != 1)
			continue;
		// Geting the coordiantes from the mouse
		x = gfx_xpos();
		y = gfx_ypos();
		// Checking for out of bounds
		if (x < 70 || y < 120 || x > (70 + (cell * sz)) || y > (120 + (cell * sz)))
			continue;
		r = (y - 120) / cell;
		c = (x - 70) / cell;
		part = game.move(r, c); //1 = valid and placed, 2 = invalid not placed,3 = game is over there is a winner
		board = game.getBoard();
		// dispaly the board check if there were invalid placements or not
		if (part == 1)
			display(board, true, false, names);
		else if (part == 2)
			display(board, false, false, names);
	}
	// displying the final board
	display(board, true, true, names);
	gfx_color(255, 255, 255);
	// displaying who the winner of the game is
	string winner;
	switch (game.checkWin())
	{
		case 1:
			if (names.size() > 0)
			{
				winner = names[0] + " is the Winner!";
			}
			else
				winner = "Winner is the Black Player";
			break;
		case 2:
			if (names.size() > 1)
			{
				winner = names[1] + " is the Winner!";
			}
			else
				winner = "Winner is the White Player";
			break;
		case 3:
			winner = "The Game ends in a tie";
			break;
	}
	gfx_clear_color(0, 0, 0);
	gfx_color(255, 255, 255);
	input = 'r';
	// converting the string into a char array
	int tempLength = winner.size() + 1;
	char tempArray[tempLength];
	strcpy(tempArray, winner.c_str());

	while (input != 'q')
	{
		gfx_clear();
		// some nice fireworks to celebrate the winner
		firework(200, size - 20, 25, 2, tempArray);

		gfx_clear();
		gfx_color(255,255,255);
		// displaying who won again
		gfx_text(300,350, tempArray);

		input = gfx_wait();
	}
	return 0;
}
