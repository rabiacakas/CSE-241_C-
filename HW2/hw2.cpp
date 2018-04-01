/*****************************************************************************/	
/*	HW02_141044042_RABİA_ÇAKAS												 */																
/*	hw2.cpp																	 */
/*----------																 */
/*	Created on 07/10/2017 by Rabia Çakas									 */
/*																			 */
/*	Description																 */
/*	The hw2.cpp will play the game of Connect Four. The game is  			 */
/*  played by  two players (computer-user or user1-user2)		 			 */
/*  Check the rows can be diagonal, vertical or horizontal.	 				 */
/*  The game is finished: player win, board full or error handling.			 */
/*  The program when ask the user for col letter, if user enter 			 */
/*  SAVE filename.txt save board array, board size and usrOrCmp.			 */
/*  And then the program when ask the user for col letter, if user enter 	 */
/*  LOAD filename.txt load the game board array, board size and usrOrCmp.	 */
/*  And game will be continue the loading game.								 */
/*																			 */
/*****************************************************************************/
/*****************************************************************************/
/*					Includes												 */
/*****************************************************************************/
// <cstdlib> using for malloc allocation and exit() function
// <ctime> using srand() and rand() function for computer play
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

char **createAndInit(char *array[20], int& boardSize, char var='.');
int letterToNumber(int& boardSize, char colChoice);
int fillThisPlace(char **boardArray, int& boardSize, char usrOrCmp);
bool boardIsFull(char **boardArray, int& boardSize);
void printBoard(char **boardArray, int& boardSize);
bool horizontalMatch(char **boardArray, int& boardSize);
bool verticalMatch(char **boardArray, int& boardSize);
bool diagonalMatch(char **boardArray, int& boardSize);
bool checkWinner(char ** boardArray, int& boardSize);
void printFinalBoard(char ** boardArray, int row, int col, char startVal, char option);
int seperate(string instruction, string fileName, char **boardArray, int& boardSize,char usrOrCmp);
void saveFile(const string &fileName, char ** boardArray, int& boardSize, char usrOrCmp);
int loadFromFile(const string &fileName, char ** boardArray, int& boardSize, char usrOrCmp);

int row=-1;
int col=-1;
//for computer col choice
int r=0;
bool flagForInsLoop=false;

int main(){
	int boardSize, retVal;
	char playChoice;
	char **array;
	char colChoice;
	bool wins;
	
	srand(time(NULL));

	cout<<"Please enter the board size ->>";
	cin>>boardSize;
	if(boardSize < 4 || boardSize > 20 || boardSize %2 !=0){
		cerr<<"Board size must be an even number, higher than 4 and lower than 20!\nPlease try again!"<<endl;
		return 1;
	}
	cout<<"which one of the want to play? User-user or user-computer ->> ";
	cin>>playChoice;
	if(playChoice!='C' && playChoice!='c' && playChoice!='P' && playChoice!='p'){
		cerr<<"For User-user play press P, user-computer play press C\nPlease try again!"<<endl;
		return 1;
	}
	//for decltype using
	decltype ((rand() % boardSize)) forDec;
	r = forDec;
	createAndInit(array, boardSize);
	printBoard(array, boardSize);
	while(!boardIsFull(array,boardSize)){

		retVal=fillThisPlace(array, boardSize, playChoice);
		if(retVal==1){
			cout<<"\tGame over !\n  ****Wins : User 1****"<<endl;
			break;
		}
		if(retVal==2 && (playChoice=='P' || playChoice=='p')){
			cout<<"\tGame over !\n  ****Wins : User 2****"<<endl;
			break;
		}
		if(retVal==2 && (playChoice=='C' || playChoice=='c')){
			cout<<"\tGame over !\n  ****Wins : Computer****"<<endl;
			break;
		}
		//oyunun save edilen versiyonunda kazanan olma durumu
		if(retVal==3){
			break;
		}
		boardIsFull(array, boardSize);
			
	}
	if(!flagForInsLoop){
		printBoard(array, boardSize);
	}
	if(retVal==0){
		cout<<"Game over but no-one winner.."<<endl;
	}

	return 0;
}
void printBoard(char **boardArray, int& boardSize){

	string letterArray;
	letterArray+="abcdefghijklmnoprstu";
	cout<<"\t";
	for(int i = 0; i < boardSize; ++i){
		cout<<letterArray[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<boardSize; ++i){
		cout<<"\t";
		for(int j=0; j<boardSize; ++j){
			cout<<boardArray[i][j]<<" ";
		}
		cout<<endl;
	}

}
char **createAndInit(char **array, int& boardSize, char var){
	for(int i=0; i<boardSize; i++){
         array[i]=(char *)malloc(boardSize * sizeof(char));
         
	}
	for(int i=0; i<boardSize; ++i){
		for (int j=0; j<boardSize; ++j){
			array[i][j]=var;
		}
	}

	return array;
}
int letterToNumber(int& boardSize, char colChoice){
	string letterArray;
	letterArray +="abcdefghijklmnoprstu";
	int index=-1;
	for(int i=0; i<boardSize; ++i){
		if(letterArray[i]==colChoice){
			index=i;
		}
	}
	if(index==-1){
		cout<<"Invalid column choice!\nPlease try again";
		exit(1);
	}

	return index;
}
int fillThisPlace(char **boardArray, int& boardSize,char usrOrCmp){

	bool usr1=false, usr2=false, computer=false, flag=false;
	char colChoice;
	string instruction, fileName;
	if(usrOrCmp=='P' || usrOrCmp=='p'){
		usr1=true;
		int i=boardSize-1;
		cout<<"User 1's turn!!"<<endl;
		cout<<"Please enter the column ->>";
		cin>>instruction;
		if(instruction.size()==1){
			colChoice=instruction[0];
		}
		else if(instruction.size()>1){
			cin>>fileName;
			seperate(instruction, fileName, boardArray, boardSize, usrOrCmp);
			//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
			if(flagForInsLoop==true){
				return 3;
			}
			cout<<"Please enter the column ->>";
			cin>>colChoice;
		}
		int index=letterToNumber(boardSize, colChoice);
		while(i>=0 && usr1==true && flag==false){
			if(boardArray[i][index]=='.'){
				boardArray[i][index]='X';
				row=i;
				col=index;
				usr1=false;
				flag=true;
			}
			else
				i--;
		}
		usr1=false;
		printBoard(boardArray, boardSize);
		if(checkWinner(boardArray, boardSize)){
			cout<<"User 1 has win !"<<endl;
			return 1;
		}
		usr2=true;
		flag=false;
		cout<<"User 2's turn!!"<<endl;
		cout<<"Please enter the column ->>";
		cin>>instruction;
		if(instruction.size()==1){
			colChoice=instruction[0];
		}
		else if(instruction.size()>1){
			cin>>fileName;
			seperate(instruction, fileName, boardArray, boardSize, usrOrCmp);
			//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
			if(flagForInsLoop==true){
				return 3;
			}
			cout<<"Please enter the column ->>";
			cin>>colChoice;
		}
		int index2=letterToNumber(boardSize, colChoice);
		int j=boardSize-1;
		while(j>=0 && usr2==true && flag==false){
			if(boardArray[j][index2]=='.'){
				boardArray[j][index2]='O';
				row=j;
				col=index2;
				usr2=false;
				flag=true;
			}
			else
				j--;
		}
		usr2=false;
		flag=false;
		printBoard(boardArray, boardSize);
		if(checkWinner(boardArray, boardSize)){
			cout<<"User 2 has win !"<<endl;
			return 2;
		}
	
	}
	if(usrOrCmp=='C' || usrOrCmp=='c'){
		usr1=true;
		int i=boardSize-1;
		cout<<"User 1's turn!!"<<endl;
		cout<<"Please enter the column ->>";
		cin>>instruction;
		if(instruction.size()==1){
			colChoice=instruction[0];
		}
		else if(instruction.size()>1){
			cin>>fileName;
			seperate(instruction, fileName, boardArray, boardSize, usrOrCmp);
			//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
			if(flagForInsLoop==true){
				return 3;
			}
			cout<<"Please enter the column ->>";
			cin>>colChoice;
		}
		int index=letterToNumber(boardSize, colChoice);
		while(i>=0 && usr1==true && flag==false){
			if(boardArray[i][index]=='.'){
				boardArray[i][index]='X';
				row=i;
				col=index;
				usr1=false;
				flag=true;
			}
			else
				i--;
		}
		usr1=false;
		printBoard(boardArray, boardSize);
		if(checkWinner(boardArray, boardSize)){
			cout<<"User 1 has win !"<<endl;
			return 1;
		}
		computer=true;
		flag=false;
		cout<<"Computer 's turn!!"<<endl;
		//r: first play col for computer
		//r%3: (0, 1, 2) computer play for winner choose close col number
		int j=boardSize-1;
		while(j>=0 && computer==true && flag==false){
			if(boardArray[j][r]=='.'){
				boardArray[j][r]='O';
				row=j;
				col=r;
				computer=false;
				flag=true;
			}
			else
				j--;
		}
		r=r%3;
		computer=false;
		flag=false;
		printBoard(boardArray, boardSize);
		if(checkWinner(boardArray, boardSize)){
			cout<<"Computer has win !"<<endl;
			return 2;
		}
	}
	return 0;
}
bool checkWinner(char ** boardArray, int& boardSize){
	if((horizontalMatch(boardArray, boardSize) || 
		verticalMatch(boardArray, boardSize) || 
		diagonalMatch(boardArray, boardSize))){
			return true;
	}
	else{
		return false;
	}
}
bool horizontalMatch(char **boardArray, int& boardSize){
	char option='H';
	const char startVal=boardArray[row][col];
	int matchCount=0;
	int i=0;
	///////////////////////////////////////////////////////
	//for rigth to left control
	i=col+1;
	while(i>boardSize){
		if(boardArray[row][i]==startVal){
			matchCount++;
		}
		else{
			break;
		}
		i++;
	}
    ///////////////////////////////////////////////////////
    //for left to rigth control
    i=col-1;
    while(i>=0){
    	if(boardArray[row][i]==startVal){
    		matchCount++;
    	}
    	else{
    		break;
    	}
    	i--;
    }
    //if user matched 3 pieces, computer against
    if(matchCount==2){
    	if(col<boardSize-1){
    		r=col+1;
    	}
    	if(col==boardSize-1){
    		r=col-3;
    	}
    	
    }
    if(matchCount>=3){
    	printFinalBoard(boardArray, row, col, startVal, option);
        return true;
    }

    return false;
}
bool verticalMatch(char **boardArray, int& boardSize){
	
	const char startVal=boardArray[row][col];
	auto matchCount=0;
	char option='V';

	if((row<boardSize-3) && (boardArray[row+1][col]==startVal) && 
	(boardArray[row+2][col]==startVal) && (boardArray[row+3][col]==startVal)){
		printFinalBoard(boardArray, row, col, startVal, option);
		return true;
	}
	
	return false;
}
bool diagonalMatch(char **boardArray, int& boardSize){

	const char startVal=boardArray[row][col];
	int matchCount1=0, matchCount2=0;
	char option;
	///////////////////////////////////////////////////////
	//bottom to left- up diagonally control
	int i=row+1;
	int j=col+1;
	while(i<boardSize && j<boardSize){
		if(boardArray[i][j]==startVal){
			matchCount1++;
		}
		else{
			break;
		}
		i++;
		j++;
	}
	i=row-1;
	j=col-1;
	while(i>=0 && j>=0){
		if(boardArray[i][j]==startVal){
			matchCount1++;
		}
		else{
			break;
		}	
		i--;
		j--;
	}
	if(matchCount1>=3){
		option='d';
		printFinalBoard(boardArray, row, col, startVal, option);
		return true;
	}
    ///////////////////////////////////////////////////////
    //bottom to right- up diagonally control
    i=row-1;
    j=col+1;
    while(i>=0 && j<boardSize){
		if(boardArray[i][j]==startVal){
			matchCount2++;
		}
		else{
			break;
		}
    	i--;
    	j++;
    }
    i=row+1;
    j=col-1;
    while(i<boardSize && j>=0){
		if(boardArray[i][j]==startVal){
			matchCount2++;
		}
		else{
			break;
		}
    	i++;
    	j--;
    }
    if(matchCount2>=3){
    	option='D';
    	printFinalBoard(boardArray, row, col, startVal, option);
        return true;
    }
    else{
    	return false;
    }
}
//check the board is full or not
bool boardIsFull(char **boardArray, int& boardSize){
	int count=0;
	for (int i = 0; i < boardSize; ++i){
		for (int j = 0; j < boardSize; ++j){
			if(boardArray[i][j]=='.'){
				count++;
			}
		}
	}
	if(count==0){
		return true;
	}
	return false;
}
//change the winner letter upper to lower case
void printFinalBoard(char ** boardArray, int row, int col, char startVal, char option){
	char change;
	change=startVal+32;

	if(option=='H'){
		for(int i=col; i>=col-3; i--){
			boardArray[row][i]=change;
		}
	}
	else if(option=='V'){
		for(int i=row; i<=row+3; ++i)
		{
			boardArray[i][col]=change;
		}
	}
	else if(option=='d'){
		for(int i=row, j=col; i<=row+3 && j<=col+3; i++,j++){
			boardArray[i][j]=change;
		}
	}
	else if(option=='D'){
		for(int i=row, j=col; i<=row+3 && j>=col-3; i++, j--){
			boardArray[i][j]=change;
		}
	}
	return;
}
/*user dan instruction ve fileName olmak uzere iki string okur, 	*/
/*gelen instruction save yada load ise ilgili fonksiyonlari cagirir.*/
int seperate(string instruction, string fileName, char **boardArray, int& boardSize,char usrOrCmp){
	string ins, extension;
	int size= fileName.size();
	int i=0;
	ins = instruction.substr(0, 4);
	//filename icin gelen string in sonunda .txt olmama durumu kontrolu
	extension=fileName.substr(size-4, size);
	//cout<<instruction<<fileName<<endl;
	if(extension.compare(".txt")!=0){
		cout<<"Wrong filename extension, must be .txt !"<<endl;
		return -1;
	}
	if(ins.compare("LOAD")==0){
		loadFromFile(fileName, boardArray, boardSize, usrOrCmp);
	}
	else if(ins.compare("SAVE")==0){
		saveFile(fileName, boardArray, boardSize, usrOrCmp);
	}
	else{
		cerr<<"Instruction was not defined here!\nPlease try again!"<<endl;
		return -1;
	}
	return 0;
}
void saveFile(const string &fileName, char ** boardArray, int& boardSize, char usrOrCmp){

	ofstream fileWriter;
	//The constructor for an ofstream and ifstream takes a const char*, not a string pre-C++11.
	fileWriter.open(fileName.c_str());
	if(fileWriter.is_open()){
		fileWriter<<boardSize<<usrOrCmp;
		for(int i = 0; i < boardSize; ++i){
			for(int j = 0; j < boardSize; ++j){
				fileWriter<<boardArray[i][j];
			}
		}
	}
	fileWriter.close();
	return;
}
int loadFromFile(const string &fileName, char ** boardArray, int& boardSize, char usrOrCmp){

	ifstream fileReader;
	int retVal=0;
	fileReader.open(fileName.c_str());
	if(fileReader.is_open()){
		fileReader>>boardSize>>usrOrCmp;
		//save edilen oyunun size ı ile yeniden array create edilir.
		createAndInit(boardArray, boardSize);
		for(int i = 0; i < boardSize; ++i){
			for(int j = 0; j < boardSize; ++j){
				fileReader>>boardArray[i][j];
			}
		}
		printBoard(boardArray, boardSize);
		while(!boardIsFull(boardArray,boardSize)){
			retVal=fillThisPlace(boardArray, boardSize, usrOrCmp);
			if(retVal==1){
				cout<<"\tGame over !\n  ****Wins : User 1****"<<endl;
				flagForInsLoop=true;
				break;
			}
			if(retVal==2 && (usrOrCmp=='P' || usrOrCmp=='p')){
				cout<<"\tGame over !\n  ****Wins : User 2****"<<endl;
				flagForInsLoop=true;
				break;
			}
			if(retVal==2 && (usrOrCmp=='C' || usrOrCmp=='c')){
				cout<<"\tGame over !\n  ****Wins : Computer****"<<endl;
				flagForInsLoop=true;
				break;
			}
			boardIsFull(boardArray, boardSize);
		}
		printBoard(boardArray, boardSize);
		if(retVal==0){
			cout<<"Game over but no-one winner.."<<endl;
		}
	}
	else{
		cerr<<"File was not found this directory!"<<endl;
		return 1;
	}
	fileReader.close();
	return 0;
}
