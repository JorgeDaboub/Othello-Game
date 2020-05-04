// Othello main 
// By: Jorge Daboub

#include<iostream>
#include"othello.h"
using namespace std;

int main() {
	othello game;


	game.display();
	while(1)
		game.move();


	return 0;
}
