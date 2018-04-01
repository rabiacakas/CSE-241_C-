#include "ConnectFourAbstract.h"
namespace ConnectFourPlaying{
ConnectFourAbstract::ConnectFourAbstract(){
  set_height_weight(0, 0);
}

ConnectFourAbstract::ConnectFourAbstract(int heigth, int weight){
  set_height_weight(heigth, weight);
}
/*
* Cell dynamic olarak tutuldugu icin copy constructor ve assignment operator eklendi.
*/
ConnectFourAbstract::ConnectFourAbstract(const ConnectFourAbstract &other){

  heigth=other.get_height();
  weight=other.get_weigth();
  gameBoard= new Cell*[get_height()];
  for(int i=0; i<get_height(); i++){
    gameBoard[i]= new Cell[get_weigth()];
  }
  for(int i=0; i<get_height(); i++){
    for(int j=0; j<get_weigth(); j++){
      gameBoard[i][j]= other.gameBoard[i][j];
    }
  }
}
ConnectFourAbstract& ConnectFourAbstract::operator=(const ConnectFourAbstract& rtSide){

  if(this== &rtSide){
    return *this;
  }

  else{
    heigth=rtSide.get_height();
    weight=rtSide.get_weigth();

    for(int i= 0; i< get_height(); i++){
      delete[] gameBoard[i];   
    }
    delete[] gameBoard;
    
    gameBoard= new Cell*[get_height()];
    for(int i=0; i<get_height(); i++){
      gameBoard[i]= new Cell[get_weigth()];
    }

    for(int i=0; i<get_height(); i++){
      for(int j=0; j<get_weigth(); j++){
        gameBoard[i][j]= rtSide.gameBoard[i][j];
      }
   }

  }
  return *this;

}

void ConnectFourAbstract::set_height_weight(const int heigth_board, const int weight_board){
  heigth= heigth_board;
  weight = weight_board;
}
void ConnectFourAbstract::initBoard(){
  gameBoard= new Cell*[get_height()];
  for(int i=0; i<get_height(); i++){
    gameBoard[i]= new Cell[get_weigth()];
  }
  for(int i = 0; i < get_height(); ++i){
    for(int j = 0; j < get_weigth(); ++j){
          gameBoard[i][j].set_status('.');
    }
  }
}
void ConnectFourAbstract::PrintBoard(){

  string letterArray;
  letterArray+="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cout<<"\t";
  for(int i = 0; i < get_weigth(); ++i){
    cout<<letterArray[i]<<" ";
  }
  cout<<endl;

  for(int i=0; i<get_height(); i++){
    cout<<"\t";
    for(int j=0; j<get_weigth(); j++){

      cout<<gameBoard[i][j].getStatus()<<" ";
    }
    cout<<endl;
  }
}
int ConnectFourAbstract::letterToNumber(char colChoice){
  string letterArray;
  letterArray +="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int index=-1;
  for(int i=0; i<get_weigth(); ++i){
    if(letterArray[i]==colChoice){
      index=i;
    }
  }
  if(index==-1){
    cout<<"Invalid column choice! Please try again\n";
    exit(1);
  }
  return index;
}
int ConnectFourAbstract::fillThisPlace(){
  
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
    cin>>fileName;
    seperate(instruction, fileName, usrOrCmp);
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
    cin>>fileName;
    seperate(instruction, fileName, usrOrCmp);
    //flagForInsLoop save edilen oyun yuklendiginde kazanan olma durumuyla true olur
    if(flagForInsLoop==true){
      return 3;
    }
  }
  a.set_col(colChoice);
  int index2=letterToNumber(colChoice);
  a.set_col_int(index2);
  int j=get_height() -1;
  while(j>=0 && usr2==true && flag==false){
    if(gameBoard[j][index2].getStatus()=='.'){
      gameBoard[j][index2].set_status('O');
      row=j;
      col=index2;
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
int ConnectFourAbstract::fillThisPlaceForComputer(){
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
    cin>>fileName;
    seperate(instruction, fileName, usrOrCmp);
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
*  Abstract class da oyun ici kontroller ve oyun isleyisi playGame fonksiyonu ortak 
* oldugu icin virtual yapılmadı. Derived class lar base den inherit alarak
* calisiyor.
*/
bool ConnectFourAbstract::boardIsFull(){
  int count=0;
  for (int i = 0; i < get_height(); ++i){
    for (int j = 0; j < get_weigth(); ++j){
      if(gameBoard[i][j].getStatus()=='.'){
        count++;
      }
    }
  }
  if(count==0){
    return true;
  }
  return false;
}
bool ConnectFourAbstract::verticalMatch(){
  const char startVal=gameBoard[row][col].getStatus();
  char option='V';

  if((row<get_height() -3) && (gameBoard[row+1][col].getStatus()==startVal) && 
  (gameBoard[row+2][col].getStatus()==startVal) && (gameBoard[row+3][col].getStatus()==startVal)){
    printFinalBoard(row, col, startVal, option);
    return true;
  }
  
  return false;
}
bool ConnectFourAbstract::horizontalMatch(){
  char option='H';
  const char startVal=gameBoard[row][col].getStatus();
  int matchCount=0;
  int i=0;
  ///////////////////////////////////////////////////////
  //for rigth to left control
  i=col+1;
  while(i>get_weigth()){
    if(gameBoard[row][i].getStatus()==startVal){
      matchCount++;
    }
    else{
      break;
    }
    i++;
  }
    ///////////////////////////////////////////////////////
    //for left to rigth control
    i=col-1;
    while(i>=0){
      if(gameBoard[row][i].getStatus()==startVal){
        matchCount++;
      }
      else{
        break;
      }
      i--;
    }
    //if user matched 3 pieces, computer against
    if(matchCount==2){
      if(col<get_weigth() -1){
        r=col+1;
      }
      if(col==get_weigth()-1){
        r=col-3;
      }
      
    }
    if(matchCount>=3){
      printFinalBoard(row, col, startVal, option);
      return true;
    }

    return false;
}
bool ConnectFourAbstract::diagonalMatch(){

  const char startVal=gameBoard[row][col].getStatus();
  int matchCount1=0, matchCount2=0;
  char option;
  ///////////////////////////////////////////////////////
  //bottom to left- up diagonally control
  int i=row+1;
  int j=col+1;
  while(i<get_height() && j<get_weigth()){
    if(gameBoard[i][j].getStatus() ==startVal){
      matchCount1++;
    }
    else{
      break;
    }
    i++;
    j++;
  }
  i=row-1;
  j=col-1;
  while(i>=0 && j>=0){
    if(gameBoard[i][j].getStatus() ==startVal){
      matchCount1++;
    }
    else{
      break;
    } 
    i--;
    j--;
  }

  if(matchCount1>=3){
    option='d';
    printFinalBoard(row, col, startVal, option);
    return true;
  }
    ///////////////////////////////////////////////////////
    //bottom to right- up diagonally control
    i=row-1;
    j=col+1;
    while(i>=0 && j<get_weigth()){
    if(gameBoard[i][j].getStatus() ==startVal){
      matchCount2++;
    }
    else{
      break;
    }
      i--;
      j++;
    }
    i=row+1;
    j=col-1;
    while(i<get_height() && j>=0){
    if(gameBoard[i][j].getStatus() ==startVal){
      matchCount2++;
    }
    else{
      break;
    }
      i++;
      j--;
    }

    if(matchCount2>=3){
      option='D';
      printFinalBoard(row, col, startVal, option);
        return true;
    }
    else{
      return false;
    }
}

void ConnectFourAbstract::printFinalBoard(int row, int col, char startVal, char option){
  char change;
  change=startVal+32;
  if(option=='H'){
    for(int i=col; i>=col-3; i--){
      gameBoard[row][i].set_status(change);
    }
  }
  else if(option=='V'){
    for(int i=row; i<=row+3; ++i)
    {
      gameBoard[i][col].set_status(change);
    }
  }
  else if(option=='d'){
    for(int i=row, j=col; i<=row+3 && j<=col+3; i++,j++){
      gameBoard[i][j].set_status(change);
    }
  }
  else if(option=='D'){
    for(int i=row, j=col; i<=row+3 && j>=col-3; i++, j--){
      gameBoard[i][j].set_status(change);
    }
  }
  return;
}
/*user dan instruction ve fileName olmak uzere iki string okur,   */
/*gelen instruction save yada load ise ilgili fonksiyonlari cagirir.*/
int ConnectFourAbstract::seperate(string instruction, string fileName, char usrOrCmp){
  string ins;
  int size= fileName.size();
  ins = instruction.substr(0, 4);
  if(ins.compare("LOAD")==0){
    loadFromFile(fileName,usrOrCmp);
  }
  else if(ins.compare("SAVE")==0){
    saveFile(fileName, usrOrCmp);
  }
  else{
    cerr<<"Instruction was not defined here!\nPlease try again!"<<endl;
    return -1;
  }
  return 0;
}
void ConnectFourAbstract::saveFile(const string &fileName, char usrOrCmp){
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
  }
  fileWriter.close();
  return;
}
int ConnectFourAbstract::loadFromFile(const string &fileName, char usrOrCmp){
  ifstream fileReader;
  int newHeight, newWeight;
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
    /*
    if(isMultiple){
      if(newPlayChoice=='p' || newPlayChoice=='P'){
        retVal=fillThisPlace();
        return retVal;
      }
      else if(newPlayChoice=='c' || newPlayChoice=='C'){
        retVal=fillThisPlaceForComputer();
        return retVal;
      }
    }
    */
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
*  Eski versiyonda tum kontroller goz onunde bulundurularak bir deger hesaplaniyordu.
* Abstract class da virtual olarak define edildi ve abstract dan inherit alan ConnectFourDiag,
* ConnectFourPlus ve ConnectFourPlusUndo icin override edildi.
*/
bool ConnectFourAbstract::checkWinner(){
  if((horizontalMatch() || verticalMatch() || diagonalMatch())){
      return true;
  }
  else{
    return false;
  }
}
void ConnectFourAbstract::playGame(){
  int retVal=0;
  cout<<"Which one of the want to play? User-user or user-computer ->> ";
  cin>>playChoice;
  if(playChoice!='C' && playChoice!='c' && playChoice!='P' && playChoice!='p'){
    cerr<<"For User-user play press P, user-computer play press C\nPlease try again!"<<endl;
    return;
  }
  r = (rand() % get_weigth());
  initBoard();
  PrintBoard();
  while(!boardIsFull()){

    if(playChoice=='p' || playChoice=='P'){
      retVal=fillThisPlace();
      
    }
    else if(playChoice=='c' || playChoice=='C'){
      retVal= fillThisPlaceForComputer();
    }
    if(retVal==1){
      cout<<"\tGame over !\n  ****Wins : User 1****"<<endl;
      break;
    }
    if(retVal==2 && (playChoice=='P' || playChoice=='p')){
      cout<<"\tGame over !\n  ****Wins : User 2****"<<endl;
      break;
    }
    if(retVal==2 && (playChoice=='C' || playChoice=='c')){
      cout<<"\tGame over !\n  ****Wins : Computer****"<<endl;
      break;
    }
    if(retVal==3){
      break;
    }
    boardIsFull();
  }
  PrintBoard();
  if(retVal==0){
    cout<<"Game over but no-one winner.."<<endl;
  }
  
}
bool ConnectFourAbstract::gameEndedFunc(){
  if(boardIsFull()){
    return true;
  }
  return false;
}
// Dynamic memory de-allocate
ConnectFourAbstract::~ConnectFourAbstract(){
  
  for(int i= 0; i< get_height(); i++){
    delete[] gameBoard[i];   
  }
  delete[] gameBoard;
  gameBoard=nullptr;
}
} //ConnectFourPlaying
