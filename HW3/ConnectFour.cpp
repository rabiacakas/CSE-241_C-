#include "ConnectFour.h"

ConnectFour::ConnectFour(){}
ConnectFour::ConnectFour(int heigth){
  set_height(heigth);
}
ConnectFour::ConnectFour(int heigth, int weight){
  set_height_weight(heigth, weight);
}
ConnectFour::Cell::Cell(){}
void ConnectFour::set_height(const int heigth_board){
    heigth = heigth_board;
    if(heigth_board> 0){
      gameCells.resize(heigth_board);
    }
    
}
void ConnectFour::set_weigth(const int weight_board) {
    weight = weight_board;

}
void ConnectFour::set_height_weight(const int heigth_board,const int weight_board){

    heigth = heigth_board;
    weight = weight_board;
    if(heigth_board> 0){
      gameCells.resize(heigth_board);
    }
}
void ConnectFour::set_play_choice(const char play_choice){
  playChoice=play_choice;
}

void ConnectFour::set_matched_counter(const int matchCounter){
  gameMatchedCounter=matchCounter;
}
void ConnectFour::Cell::set_row(const int row_cell){
    row= row_cell;
}
void ConnectFour::Cell::set_col(const char col_cell){
    colChr= col_cell;
}
void ConnectFour::Cell::set_status(const char status_cell){
    if(status_cell=='X' || status_cell=='O' || status_cell=='.' || status_cell=='o' || status_cell=='x'){
      status=status_cell;
    }
}
void ConnectFour::Cell::set_col_int(const int col){
    colInt=col;
}
void ConnectFour::playGame(){
  int heigth, weight, retVal=0;
  char playChoice, colChoice;
  cout<<"Please enter the board's heigth ->>";
  cin>>heigth;
  cout<<"Please enter the board's weight ->>";
  cin>>weight;
  if(heigth<4 || weight<4 || weight>26){
    cerr<<"Please check the heigth or weight input ! (Minimum 4)(Weight maximum 26)"<<endl;
    return ;
  }
  set_height_weight(heigth, weight);
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
      cout<<"Living Cell : "<<livingCell<<endl;
    }
    else if(playChoice=='c' || playChoice=='C'){
      retVal= fillThisPlaceForComputer();
      cout<<"Living Cell : "<<livingCell<<endl;
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
      cout<<"retVal :"<<retVal<<endl;
      break;
    }
    boardIsFull();
  }
  PrintBoard();
  if(retVal==0){
    cout<<"Game over but no-one winner.."<<endl;
  }
  
}
void ConnectFour::initBoard(){
  Cell temp;
  for(int i = 0; i < get_height(); ++i){
    std::vector<Cell> temps;
    for(int j = 0; j < get_weigth(); ++j){
      temp.set_row(i);
      temp.set_col_int(j);
      temp.set_status('.');
      temps.push_back(temp);
    }
    gameCells.push_back(temps);
  }
}
void ConnectFour::PrintBoard(){
  string letterArray;
  letterArray+="abcdefghijklmnopqrstuvwxyz";
  cout<<"\t";
  for(int i = 0; i < get_weigth(); ++i){
    cout<<letterArray[i]<<" ";
  }
  cout<<endl;
  for(unsigned int i = get_height(); i < gameCells.size(); ++i){
    cout<<"\t";
    for(unsigned int j= 0; j <gameCells[i].size(); ++j){
      cout<<gameCells[i][j].getStatus()<<" ";
    }
    cout<<endl;
  }
}
int ConnectFour::letterToNumber(char colChoice){
  string letterArray;
  letterArray +="abcdefghijklmnopqrstuvwxyz";
  int index=-1;
  for(int i=0; i<get_weigth(); ++i){
    if(letterArray[i]==colChoice){
      index=i;
    }
  }
  if(index==-1){
    cout<<"Invalid column choice!\nPlease try again";
    exit(1);
  }
  return index;
}
int ConnectFour::fillThisPlace(){

  ConnectFour::Cell a;
  bool usr1=false, usr2=false, flag=false;
  string instruction, fileName;
  char colChoice, usrOrCmp='p';
  usr1=true;
  int i=gameCells.size() -1;

  cout<<"User 1's turn!!"<<endl;
  cout<<"Please enter the column ->>";
  cin>>instruction;

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
    if(!newIsDifferent){
      cout<<"Please enter the column ->>";
      cin>>colChoice;
    }
  }

  a.set_col(colChoice);
  int index=letterToNumber(colChoice);
  a.set_col_int(index);
  while(i>=get_height() && usr1==true && flag==false){
   if(gameCells[i][index].getStatus()=='.'){
      gameCells[i][index].set_status('X');
      livingCell++;
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
    if(!newIsDifferent){
      cout<<"Please enter the column ->>";
      cin>>colChoice;
    }
    
  }
  a.set_col(colChoice);
  int index2=letterToNumber(colChoice);
  a.set_col_int(index2);
  int j=gameCells.size() -1;
  while(j>=get_height() && usr2==true && flag==false){
    if(gameCells[j][index2].getStatus()=='.'){
      gameCells[j][index2].set_status('O');
      livingCell++;
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
int ConnectFour::fillThisPlaceForComputer(){
  bool computer=false, usr1, flag=false, flag2=false;
  char colChoice, usrOrCmp='c';
  ConnectFour::Cell a;
  string instruction, fileName;

  usr1=true;
  int i=gameCells.size() -1;
  cout<<"User 1's turn!!"<<endl;
  cout<<"Please enter the column ->>";
  cin>>instruction;
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
    if(!newIsDifferent){
      cout<<"Please enter the column ->>";
      cin>>colChoice;
    }
   
  }

  a.set_col(colChoice);
  int index=letterToNumber(colChoice);
  a.set_col_int(index);
  while(i>=get_height() && usr1==true && flag==false){
    if(gameCells[i][index].getStatus()=='.'){
      gameCells[i][index].set_status('X');
      livingCell++;
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
  int j=gameCells.size() -1;
  while(j>=get_height() && computer==true && flag==false){
    if(gameCells[j][r].getStatus()=='.'){
      gameCells[j][r].set_status('O');
      livingCell++;
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
bool ConnectFour::boardIsFull(){
  int count=0;
  for (int i = get_height(); i < gameCells.size(); ++i){
    for (int j = 0; j < gameCells[i].size(); ++j){
      if(gameCells[i][j].getStatus()=='.'){
        count++;
      }
    }
  }
  if(count==0){
    return true;
  }
  return false;
}
bool ConnectFour::verticalMatch(){
  const char startVal=gameCells[row][col].getStatus();
  char option='V';

  if((row<gameCells.size() -3) && (gameCells[row+1][col].getStatus()==startVal) && 
  (gameCells[row+2][col].getStatus()==startVal) && (gameCells[row+3][col].getStatus()==startVal)){
    printFinalBoard(row, col, startVal, option);
    return true;
  }
  
  return false;
}
bool ConnectFour::horizontalMatch(){
  char option='H';
  const char startVal=gameCells[row][col].getStatus();
  int matchCount=0;
  int i=0;
  ///////////////////////////////////////////////////////
  //for rigth to left control
  i=col+1;
  while(i>get_weigth()){
    if(gameCells[row][i].getStatus()==startVal){
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
      if(gameCells[row][i].getStatus()==startVal){
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
    set_matched_counter(matchCount);
    if(matchCount>=3){
      printFinalBoard(row, col, startVal, option);
      return true;
    }

    return false;
}
bool ConnectFour::diagonalMatch(){

  const char startVal=gameCells[row][col].getStatus();
  int matchCount1=0, matchCount2=0;
  char option;
  ///////////////////////////////////////////////////////
  //bottom to left- up diagonally control
  int i=row+1;
  int j=col+1;
  while(i<gameCells.size() && j<get_weigth()){
    if(gameCells[i][j].getStatus() ==startVal){
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
  while(i>=get_height() && j>=0){
    if(gameCells[i][j].getStatus() ==startVal){
      matchCount1++;
    }
    else{
      break;
    } 
    i--;
    j--;
  }
  set_matched_counter(matchCount1);
  if(matchCount1>=3){
    option='d';
    printFinalBoard(row, col, startVal, option);
    return true;
  }
    ///////////////////////////////////////////////////////
    //bottom to right- up diagonally control
    i=row-1;
    j=col+1;
    while(i>=get_height() && j<get_weigth()){
    if(gameCells[i][j].getStatus() ==startVal){
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
    while(i<gameCells.size() && j>=0){
    if(gameCells[i][j].getStatus() ==startVal){
      matchCount2++;
    }
    else{
      break;
    }
      i++;
      j--;
    }
    set_matched_counter(matchCount2);
    if(matchCount2>=3){
      option='D';
      printFinalBoard(row, col, startVal, option);
        return true;
    }
    else{
      return false;
    }
}
bool ConnectFour::checkWinner(){
  if((horizontalMatch() || verticalMatch() || diagonalMatch())){
      return true;
  }
  else{
    return false;
  }
}
bool ConnectFour::gameEndedFunc(){
  if(boardIsFull()){
    return true;
  }
  return false;
}
void ConnectFour::printFinalBoard(int row, int col, char startVal, char option){
  char change;
  change=startVal+32;
  if(option=='H'){
    for(int i=col; i>=col-3; i--){
      gameCells[row][i].set_status(change);
    }
  }
  else if(option=='V'){
    for(int i=row; i<=row+3; ++i)
    {
      gameCells[i][col].set_status(change);
    }
  }
  else if(option=='d'){
    for(int i=row, j=col; i<=row+3 && j<=col+3; i++,j++){
      gameCells[i][j].set_status(change);
    }
  }
  else if(option=='D'){
    for(int i=row, j=col; i<=row+3 && j>=col-3; i++, j--){
      gameCells[i][j].set_status(change);
    }
  }
  return;
}
/*user dan instruction ve fileName olmak uzere iki string okur,   */
/*gelen instruction save yada load ise ilgili fonksiyonlari cagirir.*/
int ConnectFour::seperate(string instruction, string fileName, char usrOrCmp){
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
void ConnectFour::saveFile(const string &fileName, char usrOrCmp){

  ofstream fileWriter;
  //The constructor for an ofstream and ifstream takes a const char*, not a string pre-C++11.
  fileWriter.open(fileName.c_str());
  if(fileWriter.is_open()){
    fileWriter<<get_height()<<" "<<get_weigth()<<usrOrCmp;
    for(int i = get_height(); i < gameCells.size(); ++i){
      for(int j = 0; j < gameCells[i].size(); ++j){
        fileWriter<<gameCells[i][j].getStatus();
      }
    }
  }
  fileWriter.close();
  return;
}
int ConnectFour::loadFromFile(const string &fileName, char usrOrCmp){
  ConnectFour game1;
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
    for(unsigned int i = get_height(); i < gameCells.size(); ++i){
      for(unsigned int j = 0; j < gameCells[i].size(); ++j){
        fileReader>>read;
        gameCells[i][j].set_status(read);
      }
    }
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
    
    if(!isMultiple){
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
      
  }
  else{
    cerr<<"File was not found this directory!"<<endl;
    return 1;
  }

  fileReader.close();
  return 0;
}
void ConnectFour::playGameMultiple(){
  int heigth, weight;
  char playChoice;
  cout<<"\tPlease enter the board's heigth ->>";
  cin>>heigth;
  if(heigth<4){
    cerr<<"Please check your heigth input ! (Minimum 4)"<<endl;
    exit(1);
  }
  cout<<"\tPlease enter the board's weight ->>";
  cin>>weight;
  if(weight<4 || weight>26){
    cerr<<"Please check the weight input ! (Minimum 4, maximum 26)"<<endl;
    exit(1);
  }
  set_height_weight(heigth, weight);
  cout<<"\tWhich one of the want to play? User-user or user-computer ->> ";
  cin>>playChoice;
  if(playChoice!='C' && playChoice!='c' && playChoice!='P' && playChoice!='p'){
    cerr<<"For User-user play press P, user-computer play press C\nPlease try again!"<<endl;
    return;
  }
  set_play_choice(playChoice);
  
}
bool ConnectFour::firstGameBetter(const ConnectFour &other) const{
  if(get_match_count()>other.get_match_count()){
    cout<<"First game better for matched count.."<<endl;
    return true;
  }
  return false;
}
