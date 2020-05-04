// Othello.h
// By: Jorge Daboub

using namespace std;
// Board Size It can be changed but it messes up the graphics still works tho
const int BOARD_SIZE = 8;

class othello {

	public:
		othello();
		~othello();
		int move(int,int);
		bool valid(int,int);
		void takeOver(int, int);
		int checkWin();
		void cheat();
		vector<vector<int> > getBoard();

	private:
		vector<vector<int> > board;
		int turn = 0;

};
