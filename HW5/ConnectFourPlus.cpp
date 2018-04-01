#include "ConnectFourPlus.h"
namespace ConnectFourPlaying{
ConnectFourPlus::ConnectFourPlus()
		:ConnectFourAbstract()
{
	//empty
}
ConnectFourPlus::ConnectFourPlus(int height, int weigth)
		:ConnectFourAbstract(height, weigth)
{
	//empty
}
/*
*  Yalnizca checkWinner fonksiyonu override edildi, kazanan kosulu yatay ve dikey 
*  check olarak degistirildi.
*/
bool ConnectFourPlus::checkWinner(){
	return (horizontalMatch() || verticalMatch());
}
}