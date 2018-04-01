#ifndef Cell_H
#define	Cell_H

using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
namespace ConnectFourPlaying{

class Cell
	{
	public:

		Cell();
		Cell(int row, char colChr);
		Cell(int row, int colInt, char status);

		void set_row(const int row_cell);
		void set_col(const char col_cell);
		void set_col_int(const int col);
		void set_status(const char status_cell);

		inline const int getRow() const {
        	return row;
    	}
    	inline const char getColChr() const {
        	return colChr;
		}
		inline const int getColInt() const{
			return colInt;
		}
		inline const char getStatus() const{
			return status;
		}

	private:
		int row;
		char colChr;
		int colInt;
		char status;

};
}
#endif	/* Cell_H */