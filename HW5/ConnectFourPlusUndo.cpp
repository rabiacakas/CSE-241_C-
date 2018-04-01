#include "ConnectFourPlusUndo.h"
namespace ConnectFourPlaying{
ConnectFourPlusUndo::ConnectFourPlusUndo()
		:ConnectFourPlus()
{
		//empty
}
ConnectFourPlusUndo::ConnectFourPlusUndo(int height, int weight)
		:ConnectFourPlus(height, weight)
{
	//empty
}
/*
* ConnectFourPlusUndo icin ConnectFourPlus ile ayni durumlar kontrol edildi.
*/
bool ConnectFourPlusUndo::checkWinner(){
	return (horizontalMatch() || verticalMatch());
}
/*
* Undo komutunu gerceklemek icin her hamle yapildiginda hamle yapilacak yerin row ve col bilgisi
* savedRows ve savedCols vector lerinde kaydedildi.
*/
int ConnectFourPlusUndo::fillThisPlace(){

	Cell a;
	bool usr1=false, usr2=false, flag=false;
	string instruction, fileName;
	char colChoice, usrOrCmp='p';
	usr1=true;
	int i=get_height() -1;

	cout<<"User 1's turn!!"<<endl;
	cout<<"Please enter the column ->>";

	cin>>instruction;
	if(cin.eof()){
		exit(1);
	}
	if(instruction.size()==1){
		colChoice=instruction[0];
	}

	else if(instruction.size()>1){
		if(!(instruction.compare("UNDO")==0)){
			cin>>fileName;
		}
		seperate(instruction, fileName, usrOrCmp);
		//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
		//cout<<"changeStatus"<<changeStatus<<endl;
		if(changeStatus){
	      cout<<"Please enter the column ->>";
	      cin>>colChoice;
	    }
		if(flagForInsLoop==true){
		  return 3;
		}
	}

	a.set_col(colChoice);
	int index=letterToNumber(colChoice);
	a.set_col_int(index);
	while(i>=0 && usr1==true && flag==false){
		if(gameBoard[i][index].getStatus()=='.'){
		  gameBoard[i][index].set_status('X');
		  row=i;
		  col=index;
		  savedRows.push_back(row);
		  savedCols.push_back(col);
		  usr1=false;
		  flag=true;
		}
		else
		  i--;
	}
	
	usr1=false;
	PrintBoard();
	if(checkWinner()){
	cout<<"User 1 has win !"<<endl;
	return 1;
	}
	usr2=true;
	flag=false;


	cout<<"User 2's turn!!"<<endl;
	cout<<"Please enter the column ->>";
	cin>>instruction;
	if(cin.eof()){
		exit(1);
	}
	if(instruction.size()==1){
		colChoice=instruction[0];
	}
	else if(instruction.size()>1){
		if(!(instruction.compare("UNDO")==0)){
			cin>>fileName;
		}
	seperate(instruction, fileName, usrOrCmp);
	//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
	//cout<<"changeStatus"<<changeStatus<<endl;
	if(changeStatus){
      cout<<"Please enter the column ->>";
      cin>>colChoice;
    }
	if(flagForInsLoop==true){
	  return 3;
	}
	}
	a.set_col(colChoice);
	int index2=letterToNumber(colChoice);
	a.set_col_int(index2);
	int j=get_height() -1;
	while(j>=0 && usr2==true && flag==false ){
		if(gameBoard[j][index2].getStatus()=='.'){
		  gameBoard[j][index2].set_status('O');
		  row=j;
		  col=index2;
		  savedRows.push_back(row);
		  savedCols.push_back(col);
		  usr2=false;
		  flag=true;
		}
		else
		  j--;
	}
	
	usr2=false;
	flag=false;
	PrintBoard();
	if(checkWinner()){
		cout<<"User 2 has win !"<<endl;
		return 2;
	}
	
	return 0;

}
/*
* Undo komutunu gerceklemek icin her hamle yapildiginda hamle yapilacak yerin row ve col bilgisi
* savedRows ve savedCols vector lerinde kaydedildi.
*/
int ConnectFourPlusUndo::fillThisPlaceForComputer(){

	bool computer=false, usr1, flag=false, flag2=false;
	char colChoice, usrOrCmp='c';
	Cell a;
	string instruction, fileName;

	usr1=true;
	int i=get_height() -1;
	cout<<"User 1's turn!!"<<endl;
	cout<<"Please enter the column ->>";
	cin>>instruction;
	if(cin.eof()){
		exit(1);
	}
	if(instruction.size()==1){
		colChoice=instruction[0];
	}

	else if(instruction.size()>1){
		if(!(instruction.compare("UNDO")==0)){
			cin>>fileName;
		}
		seperate(instruction, fileName, usrOrCmp);
		cout<<"changeStatus"<<changeStatus<<endl;
		if(changeStatus){
	      cout<<"Please enter the column ->>";
	      cin>>colChoice;
	    }
		//flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
		if(flagForInsLoop==true){
		  return 3;
		}
	}

	a.set_col(colChoice);
	int index=letterToNumber(colChoice);
	a.set_col_int(index);
	while(i>=0 && usr1==true && flag==false){
		if(gameBoard[i][index].getStatus()=='.'){
		  gameBoard[i][index].set_status('X');
		  row=i;
		  col=index;
		  savedRows.push_back(row);
			savedCols.push_back(col);
		  usr1=false;
		  flag=true;
		}
		else
		  i--;
	}
	
	usr1=false;
	PrintBoard();
	if(checkWinner()){
		cout<<"User 1 has win !"<<endl;
		return 1;
	}
	computer=true;
	flag=false;
	cout<<"Computer 's turn!!"<<endl;
	//r: first play col for computer
	//r%3: (0, 1, 2) computer play for winner choose close col number
	int j=get_height() -1;
	while(j>=0 && computer==true && flag==false){
		if(gameBoard[j][r].getStatus()=='.'){
			gameBoard[j][r].set_status('O');
			row=j;
			col=r;
			savedRows.push_back(row);
			savedCols.push_back(col);
			computer=false;
			flag=true;
		}
		else
		  j--;
	}
	
	r=r%3;
	computer=false;
	flag=false;
	flag2=true;
	PrintBoard();
	if(checkWinner()){
		cout<<"Computer has win !"<<endl;
		return 2;
	}

	
	return 0;

}
/*
* Base class indan farkli olarak UNDO komutu eklendi ve UNDO geldiginde islemler icin
* commandUndo() cagrildi.
*/
int ConnectFourPlusUndo::seperate(string instruction, string fileName, char usrOrCmp){
	string ins;
	int size= fileName.size();
	ins = instruction.substr(0, 4);
	if(ins.compare("LOAD")==0){
	loadFromFile(fileName,usrOrCmp);
	}
	else if(ins.compare("SAVE")==0){
	saveFile(fileName, usrOrCmp);
	}
	else if(ins.compare("UNDO")==0){
		commandUndo();
	}
	else{
		cerr<<"Instruction was not defined here!\nPlease try again!"<<endl;
		return -1;
	}
	return 0;
}
/*
*  Bir ConnectFourPlusUndo objesi ile oynarken SAVE komutu geldiginde oyun basindan itibaren 
* yapılan hamle bilgisini kaybetmemek adina diger tum bilgilerle birlikte savedRows ve 
* savedCols da kaydedildi.
*/
void ConnectFourPlusUndo::saveFile(const string &fileName, char usrOrCmp){
	ofstream fileWriter;
	//The constructor for an ofstream and ifstream takes a const char*, not a string pre-C++11.
	fileWriter.open(fileName.c_str());
	if(fileWriter.is_open()){
		fileWriter<<get_height()<<" "<<get_weigth()<<usrOrCmp;
		for(int i = 0; i < get_height(); ++i){
			for(int j = 0; j < get_weigth(); ++j){
			fileWriter<<gameBoard[i][j].getStatus();
			}
		}
		for(unsigned int i=0; i<savedRows.size(); i++){
			fileWriter<<savedRows[i]<<" ";
		}
		for(unsigned int i=0; i<savedCols.size(); i++){
			fileWriter<<savedCols[i]<<" ";
		}
	}
	
	fileWriter.close();
	return;
}
/*
*  Bir ConnectFourPlusUndo objesi ile oynarken LOAD komutu geldiginde oyun basindan itibaren 
* yapılan hamle bilgisini de geri almak icin savedRows ve savedCols u guncelledim.
*/
int ConnectFourPlusUndo::loadFromFile(const string &fileName, char usrOrCmp){
	ifstream fileReader;
	int newHeight, newWeight, read_int;
	int retVal=0;
	char read;
	fileReader.open(fileName.c_str());
	if(fileReader.is_open()){
		fileReader>>newHeight>>newWeight>>usrOrCmp;
		newPlayChoice=usrOrCmp;
		if(newPlayChoice!= oldPlayChoice){
		  newIsDifferent=true;
		}
		set_height_weight(newHeight, newWeight);
		initBoard();
		for(int i = 0; i < get_height(); ++i){
		  for(int j = 0; j < get_weigth(); ++j){
		    fileReader>>read;
		    gameBoard[i][j].set_status(read);
		  }
		}
		int size1= savedRows.size();
		savedRows.clear();
		for(unsigned int i=0; i<size1; i++){
			fileReader>>read_int;
			savedRows.push_back(read_int);
		}
		/*cout<<savedRows.size()<<endl;
		for (unsigned int i = 0; i < savedRows.size(); ++i)
		{
			cout<<savedRows[i]<<" ";
		}*/
		int size2=savedCols.size();
		savedCols.clear();
		for(unsigned int i=0; i<size2; i++){
			fileReader>>read_int;
			savedCols.push_back(read_int);
		}
		/*cout<<savedCols.size()<<endl;
		for (unsigned int i = 0; i < savedCols.size(); ++i)
		{
			cout<<savedCols[i]<<" ";
		}*/
		  PrintBoard();
		  while(!boardIsFull() && isMultiple==false){
		    if(newPlayChoice=='p' || newPlayChoice=='P'){
		      retVal=fillThisPlace();
		    }
		    else if(newPlayChoice=='c' || newPlayChoice=='C'){
		      retVal= fillThisPlaceForComputer();
		    }
		    if(retVal==1){
		      cout<<"\tGame over !\n  ****Wins : User 1****"<<endl;
		      flagForInsLoop=true;
		      break;
		    }
		    if(retVal==2 && (newPlayChoice=='P' || newPlayChoice=='p')){
		      cout<<"\tGame over !\n  ****Wins : User 2****"<<endl;
		      flagForInsLoop=true;
		      break;
		    }
		    if(retVal==2 && (newPlayChoice=='C' || newPlayChoice=='c')){
		      cout<<"\tGame over !\n  ****Wins : Computer****"<<endl;
		      flagForInsLoop=true;
		      break;
		    }
		    boardIsFull();
	  }
	  PrintBoard();
	  if(retVal==0){
	    cout<<"Game over but no-one winner.."<<endl;
	  }    
	  
	}
	else{
		cerr<<"File was not found this directory!"<<endl;
		return 1;
	}

	fileReader.close();
	return 0;
}
/*
* UNDO geldiginde savedRows ve savedCols a kaydedilen bilgiler uzerinden gameBoard array inin
* ilgili elemanini eski hamle yapilmamis empty haline cevirir.
*/
int ConnectFourPlusUndo::commandUndo(){
	changeStatus=true;
	int rowSize, colSize, deletedRow, deletedCol;
	rowSize =savedRows.size();
	colSize=savedCols.size();
	
	deletedRow=savedRows[rowSize-1];
	deletedCol=savedCols[colSize-1];
	
	//cout<<"ESKİ HAL,"<<gameBoard[deletedRow][deletedCol].getStatus()<<" ";
	gameBoard[deletedRow][deletedCol].set_status('.');
	//cout<<gameBoard[deletedRow][deletedCol].getStatus();

	savedRows.pop_back();
	savedCols.pop_back();
	
	return 0;
}
}