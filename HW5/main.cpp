/*****************************************************************************/	
/*		HW05_141044042_RABİA_ÇAKAS											 */																
/*		main.cpp															 */
/*----------------------------------------------------------------			 */
/*		Created on 26/11/2017 by Rabia Çakas								 */
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


#include "ConnectFourAbstract.cpp"
#include "ConnectFourDiag.cpp"
#include "ConnectFourPlus.cpp"
#include "ConnectFourPlusUndo.cpp"

using namespace ConnectFourPlaying;
int main(int argc, char const *argv[]){
	
	char game_mod;
	cout<<"Enter the game mod ->>";
	cin>>game_mod;
	if(game_mod!='D' && game_mod!='U' && game_mod!='P' && game_mod!='d' && game_mod!='u' && game_mod!='p'){
		cerr<<"Please check your game mod !\n\tFor the ConnectFourDiag press D\n\tFor the ConnectFourPlusUndo press U\n\tFor the ConnectFourPlus press P"<<endl;
		exit(1);
	}
	int heigth, weight;
	char playChoice;
	cout<<"Please enter the board's heigth ->>";
	cin>>heigth;
	cout<<"Please enter the board's weight ->>";
	cin>>weight;

	if(heigth<4 || weight<4 || weight>26){
    	cerr<<"Please check the heigth or weight input ! (Minimum 4)(Weight maximum 26)"<<endl;
    	return 0;
  	}
   
	//ConnectFourAbstract *connectFourObject;

  	if(game_mod == 'D' || game_mod == 'd'){
  		//connectFourObject = &game_d;
  		ConnectFourDiag game_d(heigth, weight);
  		game_d.playGame();
  	}
	if(game_mod == 'P' || game_mod =='p'){
		//connectFourObject = &game_p;
		ConnectFourPlus game_p(heigth, weight);
		game_p.playGame();
	}
	if(game_mod == 'U' || game_mod == 'u'){
		//connectFourObject = &game_u;
		ConnectFourPlusUndo game_u(heigth, weight);
		game_u.playGame();
		
	}
	
	return 0;
}