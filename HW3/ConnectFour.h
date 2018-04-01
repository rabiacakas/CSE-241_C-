#ifndef ConnectFour_H
#define	ConnectFour_H
int row=-1;
int col=-1;
//for computer col choice
int r=0;
bool flagForInsLoop=false;
bool isMultiple=false;
char oldPlayChoice;
char newPlayChoice;
bool newIsDifferent=false;
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class ConnectFour
{
	public:
		ConnectFour();
		ConnectFour(int heigth);
		ConnectFour(int heigth, int weight);

		void playGame();
		void playGameMultiple();
		int fillThisPlace();
		int fillThisPlaceForComputer();
		void initBoard();
		void PrintBoard();
		bool gameEndedFunc();
		bool firstGameBetter(const ConnectFour &other) const;
		void set_matched_counter(const int matchCounter);
		inline const int get_height() const{
			return heigth;
		}
    	inline const int get_weigth() const{
    		return weight;
    	}
    	inline const char get_play_choice() const{
    		return playChoice;
    	}
    	inline const int get_living_cell() const{
    		return livingCell;
    	}
    	inline const int get_match_count() const{
    		return gameMatchedCounter;
    	}
private:
	class Cell
	{
	public:

		Cell();
		Cell(int row, char colChr);
		Cell(int row, int colInt, char status);

		void set_row(const int row_cell);
		void set_col(const char col_cell);
		void set_col_int(const int col);
		void set_status(const char status_cell);

		inline const int getRow() const {
        	return row;
    	}
    	inline const char getColChr() const {
        	return colChr;
		}
		inline const int getColInt() const{
			return colInt;
		}
		inline const char getStatus() const{
			return status;
		}
	private:
		int row;
		char colChr;
		int colInt;
		char status;
	};
private:
	int heigth;
	int weight;
	char playChoice;
	std::vector<std::vector<Cell> > gameCells;
	static int livingCell;
	int gameMatchedCounter;

	int letterToNumber(char colChoice);
	bool boardIsFull();
	bool verticalMatch();
	bool horizontalMatch();
	bool diagonalMatch();
	bool checkWinner();
	void printFinalBoard(int row, int col, char startVal, char option);
	int seperate(string instruction, string fileName, char usrOrCmp);
	void saveFile(const string &fileName, char usrOrCmp);
	int loadFromFile(const string &fileName, char usrOrCmp);
	void set_height(const int heigth_board);
	void set_weigth(const int weight_board);
	void set_height_weight(const int heigth_board, const int weight_board);
	void set_play_choice(const char play_choice);
	
	

	
};



#endif	/* ConnectFour_H*/
