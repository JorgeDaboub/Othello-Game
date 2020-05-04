// Othello.h
// By: Jorge Daboub

using namespace std;
// Must be an even number
const int BOARD_SIZE = 8;

class othello {

	public:
		othello();
		~othello();
		void display();
		void move();
		bool valid(int,int);
		void takeOver(int, int);
		void checkWin();

	private:
		int board[BOARD_SIZE][BOARD_SIZE];
		int turn = 0;

};
