#ifndef ConnectFourPlusUndo_H
#define ConnectFourPlusUndo_H
/* ConnectFourPlusUndo ConnectFourPlus dan tureyen bir class oldugu icin 
* ConnectFourPlus class in header file i include edildi.
*/
#include "ConnectFourPlus.h"
/*  Undo komutunu gerceklemek icin her hamlenin row ve col bilgisi 
* savedRows ve savedCols vector lerine kaydedildi. Class a private member olarak eklendi.
*/
#include <vector>
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
namespace ConnectFourPlaying{

class ConnectFourPlusUndo : public ConnectFourPlus
{
public:
	ConnectFourPlusUndo();
	ConnectFourPlusUndo(int height, int weight);
private:
	int fillThisPlace() override;
	int fillThisPlaceForComputer() override;
	bool checkWinner() override;
	int seperate(string instruction, string fileName, char usrOrCmp) override;
	void saveFile(const string &fileName, char usrOrCmp) override;
	int loadFromFile(const string &fileName, char usrOrCmp) override;
	int commandUndo();
	bool changeStatus=false;
	vector<int> savedRows;
	vector<int> savedCols;
	
};
}
#endif /* ConnectFourPlusUndo_H */