#ifndef ConnectFourPlus_H
#define ConnectFourPlus_H
// Abstract class in header file i include edildi.
#include "ConnectFourAbstract.h"
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
namespace ConnectFourPlaying{

class ConnectFourPlus : public ConnectFourAbstract
{
public:
	ConnectFourPlus();
	ConnectFourPlus(int height, int weight);

private:
	bool checkWinner() override;
	
};

}

#endif /*ConnectFourPlus_H*/