#ifndef ConnectFourAbstract_H
#define	ConnectFourAbstract_H
/* Cell class i ve implementation file i include edildi. */
#include "Cell.h"
#include "Cell.cpp"
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
#include <string>
#include <cstdlib>
#include <fstream>
using std::istream;
using std::ifstream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::cerr;
using std::ofstream;
using std::vector;
// ConnectFourPlaying ismiyle bir namespace olusturuldu ve tum class lara eklendi.
namespace ConnectFourPlaying{

		class ConnectFourAbstract
	{

	public:

		ConnectFourAbstract();
		ConnectFourAbstract(int heigth, int weight);
		/* copy constructor is here */
		ConnectFourAbstract(const ConnectFourAbstract &other);
		/* assignment operator is here */
		ConnectFourAbstract& operator=(const ConnectFourAbstract& rtSide);

		/* member function is here */
		inline const int get_height() const{
			return heigth;
		}
		inline const int get_weigth() const{
			return weight;
		}
		inline const char get_play_choice() const{
			return playChoice;
		}

		void initBoard();
		void PrintBoard();
		virtual int fillThisPlace();
		virtual int fillThisPlaceForComputer();
		virtual void playGame();
		bool gameEndedFunc();
		/* destructor is here */
		~ConnectFourAbstract();

	protected:

		int heigth;
		int weight;
		char playChoice;
		Cell ** gameBoard;

		int letterToNumber(char colChoice);
		bool boardIsFull();
		bool verticalMatch();
		bool horizontalMatch();
		bool diagonalMatch();
		virtual bool checkWinner();
		void printFinalBoard(int row, int col, char startVal, char option);
		virtual int seperate(string instruction, string fileName, char usrOrCmp);
		virtual void saveFile(const string &fileName, char usrOrCmp);
		virtual int loadFromFile(const string &fileName, char usrOrCmp);
		void set_height(const int heigth_board);
		void set_weigth(const int weight_board);
		void set_height_weight(const int heigth_board, const int weight_board);
		void set_play_choice(const char play_choice);
		
	};

}



#endif /* ConnectFourAbstract_H */