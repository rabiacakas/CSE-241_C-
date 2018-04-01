/*****************************************************************************/	
/*		HW03_141044042_RABİA_ÇAKAS											 */																
/*		main.cpp															 */
/*----------------------------------------------------------------			 */
/*		Created on 20/10/2017 by Rabia Çakas								 */
/*																			 */
/*****************************************************************************/
/*****************************************************************************/
/*					Includes												 */
/*****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "ConnectFour.h"
#include "ConnectFour.cpp"
using namespace std;

//ConnectFour static member initialize
int ConnectFour::livingCell=0;

int main(int argc, char const *argv[]){
	ConnectFour game1, game2, game3, game4, game5;
	char game_mod;
	int objectNumber, winControl1=0, winControl2=0, winControl3=0, winControl4=0, winControl5=0;
	cout<<"Enter the game mod ->>";
	cin>>game_mod;
	if(game_mod!='S' && game_mod!='M' && game_mod!='s' && game_mod!='m'){
		cerr<<"Please check your game mod, for single game press S or s, for multiple game press M or m"<<endl;
		exit(1);
	}
	if(game_mod=='S' || game_mod=='s'){
		game1.playGame();
	}
	if(game_mod=='M' || game_mod=='m'){
		game1.set_matched_counter(0);
		game2.set_matched_counter(0);
		game3.set_matched_counter(0);
		game4.set_matched_counter(0);
		game5.set_matched_counter(0);
		isMultiple=true;
		cout<<"For Game 1 -->>"<<endl;
		game1.playGameMultiple();
		game1.initBoard();
		cout<<"For Game 2 -->>"<<endl;
		game2.playGameMultiple();
		game2.initBoard();
		cout<<"For Game 3 -->>"<<endl;
		game3.playGameMultiple();
		game3.initBoard();
		cout<<"For Game 4 -->>"<<endl;
		game4.playGameMultiple();
		game4.initBoard();
		cout<<"For Game 5 -->>"<<endl;
		game5.playGameMultiple();
		game5.initBoard();

		cout<<"Choose an object for multiple game playing -->> ";
		cin>>objectNumber;
		if(objectNumber>5 || objectNumber<1){
			cerr<<"Please check your game number ! Must be higher than 1 lower than 5 !"<<endl;
		}
		while(objectNumber>=1 && objectNumber<=5){

			if(objectNumber==1){
				game1.PrintBoard();
				if(!game1.gameEndedFunc() && winControl1==0){
					if(game1.get_play_choice()=='p' || game1.get_play_choice()=='P'){
						oldPlayChoice=game1.get_play_choice();
						winControl1=game1.fillThisPlace();
						cout<<"Living Cell : "<<game1.get_living_cell()<<endl;
					}
					else if(game1.get_play_choice()=='c' || game1.get_play_choice()=='C'){
						oldPlayChoice=game1.get_play_choice();
						winControl1=game1.fillThisPlaceForComputer();
						cout<<"Living Cell : "<<game1.get_living_cell()<<endl;
					}
				}
				else if(game1.gameEndedFunc() || winControl1==1 || winControl1==2 || winControl1==3){
					cerr<<"This game ended before..Please choose again !"<<endl;
				}
			}
  			if(objectNumber==2){
  				game2.PrintBoard();
				if(!game2.gameEndedFunc() && winControl2==0){
					if(game2.get_play_choice()=='p' || game2.get_play_choice()=='P'){
						oldPlayChoice=game2.get_play_choice();
						winControl2=game2.fillThisPlace();
						cout<<"Living Cell : "<<game2.get_living_cell()<<endl;
					}
					else if(game2.get_play_choice()=='c' || game2.get_play_choice()=='C'){
						oldPlayChoice=game2.get_play_choice();
						winControl2=game2.fillThisPlaceForComputer();
						cout<<"Living Cell : "<<game2.get_living_cell()<<endl;
					}
				}
				else if(game2.gameEndedFunc() || winControl2==1 || winControl2==2 || winControl2==3){
						cerr<<"This game ended before..Please choose again !"<<endl;
				}
  			}
  			if(objectNumber==3){
  				game3.PrintBoard();
				if(!game3.gameEndedFunc() && winControl3==0){
					if(game3.get_play_choice()=='p' || game3.get_play_choice()=='P'){
						oldPlayChoice=game3.get_play_choice();
						winControl3=game3.fillThisPlace();
						cout<<"Living Cell : "<<game3.get_living_cell()<<endl;
					}
					else if(game3.get_play_choice()=='c' || game3.get_play_choice()=='C'){
						oldPlayChoice=game3.get_play_choice();
						winControl3=game3.fillThisPlaceForComputer();
						cout<<"Living Cell : "<<game3.get_living_cell()<<endl;
					}
				}
				else if(game3.gameEndedFunc() || winControl3==1 || winControl3==2 || winControl3==3){
						cerr<<"This game ended before..Please choose again !"<<endl;
				}
  			}
  			if(objectNumber==4){
  				game4.PrintBoard();
				if(!game4.gameEndedFunc() && winControl4==0){
					if(game4.get_play_choice()=='p' || game4.get_play_choice()=='P'){
							oldPlayChoice=game4.get_play_choice();
							winControl4=game4.fillThisPlace();
							cout<<"Living Cell : "<<game4.get_living_cell()<<endl;
					}
					else if(game4.get_play_choice()=='c' || game4.get_play_choice()=='C'){
						oldPlayChoice=game4.get_play_choice();
						winControl4=game4.fillThisPlaceForComputer();
						cout<<"Living Cell : "<<game4.get_living_cell()<<endl;
					}
				}
				else if(game4.gameEndedFunc() || winControl4==1 || winControl4==2 || winControl4==3){
						cerr<<"This game ended before..Please choose again !"<<endl;
				}	
  			}
  			if(objectNumber==5){
  				game5.PrintBoard();
				if(!game5.gameEndedFunc() && winControl5==0){
					if(game5.get_play_choice()=='p' || game5.get_play_choice()=='P'){
							oldPlayChoice=game5.get_play_choice();
							winControl5= game5.fillThisPlace();
							cout<<"Living Cell : "<<game5.get_living_cell()<<endl;
						}
					else if(game5.get_play_choice()=='c' || game5.get_play_choice()=='C'){
						oldPlayChoice=game5.get_play_choice();
						winControl5= game5.fillThisPlaceForComputer();
						cout<<"Living Cell : "<<game5.get_living_cell()<<endl;
					}
				}
				else if(game5.gameEndedFunc() || winControl5==1 || winControl5==2 || winControl5==3){
						cerr<<"This game ended before..Please choose again !"<<endl;
				}
  			}

  			game1.firstGameBetter(game2);

			cout<<"Choose an object for multiple game playing -->> ";
			cin>>objectNumber;
			if(objectNumber>5 || objectNumber<1){
				cerr<<"Please check your game number ! Must be higher than 1 lower than 5 !"<<endl;
			}

		}
	}
	return 0;
}