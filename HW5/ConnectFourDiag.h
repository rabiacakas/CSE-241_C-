#ifndef ConnectFourDiag_H
#define ConnectFourDiag_H
// Abstract class in header file i include edildi.
#include "ConnectFourAbstract.h"
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
namespace ConnectFourPlaying{

class ConnectFourDiag : public ConnectFourAbstract
{
public:
	ConnectFourDiag();
	ConnectFourDiag(int height, int weight);

private:
	bool checkWinner() override;

	
};


}

#endif /* ConnectFourDiag_H */