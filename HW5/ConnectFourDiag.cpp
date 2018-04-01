#include "ConnectFourDiag.h"
namespace ConnectFourPlaying{
ConnectFourDiag::ConnectFourDiag()
		:ConnectFourAbstract()
{
	//empty
}
ConnectFourDiag::ConnectFourDiag(int height, int weight)
		: ConnectFourAbstract(height, weight)
{
	//empty
}
/*
*  Yalnizca checkWinner fonksiyonu override edildi, kazanan kosulu sadece 
* diagonal check olarak degistirildi.
*/
bool ConnectFourDiag::checkWinner(){
	return (diagonalMatch());
}
}