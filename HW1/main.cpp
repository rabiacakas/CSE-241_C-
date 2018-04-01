/*****************************************************************************/	
/*	HW01_141044042_RABİA_ÇAKAS												 */																
/*	main.cpp																 */
/*----------																 */
/*	Created on 01/10/2017 by Rabia Çakas									 */
/*																			 */
/*	Description																 */
/*	The main.cpp will play the game of Connect Four. The game is played by   */
/*  two players (computer-user or user1-user2)		 			 			 */
/*  Check the rows can be diagonal, vertical or horizontal.	 				 */
/*  The game is finished: player win, board full or error handling.			 */
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
using namespace std;

char **createAndInit(char *array[20], int boardSize);
int letterToNumber(int boardSize, char colChoice);
int fillThisPlace(char **boardArray, int boardSize, char usrOrCmp);
bool boardIsFull(char **boardArray, int boardSize);
void printBoard(char **boardArray, int boardSize);
bool horizontalMatch(char **boardArray, int boardSize);
bool verticalMatch(char **boardArray, int boardSize);
bool diagonalMatch(char **boardArray, int boardSize);
bool checkWinner(char ** boardArray, int boardSize);
void printFinalBoard(char ** boardArray, int row, int col, char startVal, char option);

int row=-1;
int col=-1;
//for computer col choice
int r=0;

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
		cerr<<"Board size must be an even number, higher than 4 and lower than 20!"<<endl;
		cerr<<"Please try again!"<<endl;
		return 1;
	}
	cout<<"which one of the want to play? User-user or user-computer ->> ";
	cin>>playChoice;
	if(playChoice!='C' && playChoice!='c' && playChoice!='P' && playChoice!='p'){
		cerr<<"For User-user play press P, user-computer play press C"<<endl;
		cerr<<"Please try again!"<<endl;
		return 1;
	}
	r = (rand() % boardSize);
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
			boardIsFull(array, boardSize);
	}
	printBoard(array, boardSize);
	if(retVal==0){
		cout<<"Game over but no-one winner.."<<endl;
	}

	return 0;
}
void printBoard(char **boardArray, int boardSize){

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
char **createAndInit(char **array, int boardSize){
	for(int i=0; i<boardSize; i++){
         array[i]=(char *)malloc(boardSize * sizeof(char));
         
	}
	for(int i=0; i<boardSize; ++i){
		for (int j=0; j<boardSize; ++j){
			array[i][j]='.';
		}
	}

	return array;
}
int letterToNumber(int boardSize, char colChoice){
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
int fillThisPlace(char **boardArray, int boardSize,char usrOrCmp){

	bool usr1=false, usr2=false, computer=false, flag=false;
	char colChoice;

	if(usrOrCmp=='P' || usrOrCmp=='p'){
		usr1=true;
		int i=boardSize-1;
		cout<<"User 1's turn!!"<<endl;
		cout<<"Please enter the column ->>";
		cin>>colChoice;
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
		cin>>colChoice;
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
		cin>>colChoice;
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
bool checkWinner(char ** boardArray, int boardSize){
	if((horizontalMatch(boardArray, boardSize) || 
		verticalMatch(boardArray, boardSize) || 
		diagonalMatch(boardArray, boardSize))){
			return true;
	}
	else{
		return false;
	}
}
bool horizontalMatch(char **boardArray, int boardSize){
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
bool verticalMatch(char **boardArray, int boardSize){
	
	const char startVal=boardArray[row][col];
	int matchCount=0;
	char option='V';

	if((row<boardSize-3) && (boardArray[row+1][col]==startVal) && 
	(boardArray[row+2][col]==startVal) && (boardArray[row+3][col]==startVal)){
		printFinalBoard(boardArray, row, col, startVal, option);
		return true;
	}
	
	return false;
}
bool diagonalMatch(char **boardArray, int boardSize){

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
bool boardIsFull(char **boardArray, int boardSize){
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