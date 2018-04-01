#include "Cell.h"
namespace ConnectFourPlaying{
Cell::Cell(){}
Cell::Cell(int row, char colChr){
	row =row;
	colChr = colChr;
}
Cell::Cell(int row, int colInt, char status){
	row= row;
	colInt =colInt;
	status=status;
}

void Cell::set_row(const int row_cell){
	row = row_cell;
}
void Cell::set_col(const char col_cell){
	colChr = col_cell;
}
void Cell::set_col_int(const int col){
	colInt = col;
}
void Cell::set_status(const char status_cell){
	status = status_cell;
}
}