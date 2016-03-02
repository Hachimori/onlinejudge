#include<iostream>
#include<string>

#define WALL -1
#define CONTINUE 0
#define OUTPUT 1
#define MAX 62

int row,column;
char board[MAX][MAX];
string command,font,str;
char letter[120][7][7];

void make_letter(){
  
  strcpy(letter['A'][0],".***..");
  strcpy(letter['A'][1],"*...*.");
  strcpy(letter['A'][2],"*****.");
  strcpy(letter['A'][3],"*...*.");
  strcpy(letter['A'][4],"*...*.");

  strcpy(letter['B'][0],"****..");
  strcpy(letter['B'][1],"*...*.");
  strcpy(letter['B'][2],"****..");
  strcpy(letter['B'][3],"*...*.");
  strcpy(letter['B'][4],"****..");

  strcpy(letter['C'][0],".****.");
  strcpy(letter['C'][1],"*...*.");
  strcpy(letter['C'][2],"*.....");
  strcpy(letter['C'][3],"*.....");
  strcpy(letter['C'][4],".****.");

  strcpy(letter['D'][0],"****..");
  strcpy(letter['D'][1],"*...*.");
  strcpy(letter['D'][2],"*...*.");
  strcpy(letter['D'][3],"*...*.");
  strcpy(letter['D'][4],"****..");

  strcpy(letter['E'][0],"*****.");
  strcpy(letter['E'][1],"*.....");
  strcpy(letter['E'][2],"***...");
  strcpy(letter['E'][3],"*.....");
  strcpy(letter['E'][4],"*****.");

  strcpy(letter['F'][0],"*****.");
  strcpy(letter['F'][1],"*.....");
  strcpy(letter['F'][2],"***...");
  strcpy(letter['F'][3],"*.....");
  strcpy(letter['F'][4],"*.....");

  strcpy(letter['G'][0],".****.");
  strcpy(letter['G'][1],"*.....");
  strcpy(letter['G'][2],"*..**.");
  strcpy(letter['G'][3],"*...*.");
  strcpy(letter['G'][4],".***..");

  strcpy(letter['H'][0],"*...*.");
  strcpy(letter['H'][1],"*...*.");
  strcpy(letter['H'][2],"*****.");
  strcpy(letter['H'][3],"*...*.");
  strcpy(letter['H'][4],"*...*.");

  strcpy(letter['I'][0],"*****.");
  strcpy(letter['I'][1],"..*...");
  strcpy(letter['I'][2],"..*...");
  strcpy(letter['I'][3],"..*...");
  strcpy(letter['I'][4],"*****.");

  strcpy(letter['J'][0],"..***.");
  strcpy(letter['J'][1],"...*..");
  strcpy(letter['J'][2],"...*..");
  strcpy(letter['J'][3],"*..*..");
  strcpy(letter['J'][4],".**...");

  strcpy(letter['K'][0],"*...*.");
  strcpy(letter['K'][1],"*..*..");
  strcpy(letter['K'][2],"***...");
  strcpy(letter['K'][3],"*..*..");
  strcpy(letter['K'][4],"*...*.");

  strcpy(letter['L'][0],"*.....");
  strcpy(letter['L'][1],"*.....");
  strcpy(letter['L'][2],"*.....");
  strcpy(letter['L'][3],"*.....");
  strcpy(letter['L'][4],"*****.");

  strcpy(letter['M'][0],"*...*.");
  strcpy(letter['M'][1],"**.**.");
  strcpy(letter['M'][2],"*.*.*.");
  strcpy(letter['M'][3],"*...*.");
  strcpy(letter['M'][4],"*...*.");

  strcpy(letter['N'][0],"*...*.");
  strcpy(letter['N'][1],"**..*.");
  strcpy(letter['N'][2],"*.*.*.");
  strcpy(letter['N'][3],"*..**.");
  strcpy(letter['N'][4],"*...*.");

  strcpy(letter['O'][0],".***..");
  strcpy(letter['O'][1],"*...*.");
  strcpy(letter['O'][2],"*...*.");
  strcpy(letter['O'][3],"*...*.");
  strcpy(letter['O'][4],".***..");

  strcpy(letter['P'][0],"****..");
  strcpy(letter['P'][1],"*...*.");
  strcpy(letter['P'][2],"****..");
  strcpy(letter['P'][3],"*.....");
  strcpy(letter['P'][4],"*.....");

  strcpy(letter['Q'][0],".***..");
  strcpy(letter['Q'][1],"*...*.");
  strcpy(letter['Q'][2],"*...*.");
  strcpy(letter['Q'][3],"*..**.");
  strcpy(letter['Q'][4],".****.");

  strcpy(letter['R'][0],"****..");
  strcpy(letter['R'][1],"*...*.");
  strcpy(letter['R'][2],"****..");
  strcpy(letter['R'][3],"*..*..");
  strcpy(letter['R'][4],"*...*.");

  strcpy(letter['S'][0],".****.");
  strcpy(letter['S'][1],"*.....");
  strcpy(letter['S'][2],".***..");
  strcpy(letter['S'][3],"....*.");
  strcpy(letter['S'][4],"****..");

  strcpy(letter['T'][0],"*****.");
  strcpy(letter['T'][1],"*.*.*.");
  strcpy(letter['T'][2],"..*...");
  strcpy(letter['T'][3],"..*...");
  strcpy(letter['T'][4],".***..");

  strcpy(letter['U'][0],"*...*.");
  strcpy(letter['U'][1],"*...*.");
  strcpy(letter['U'][2],"*...*.");
  strcpy(letter['U'][3],"*...*.");
  strcpy(letter['U'][4],".***..");

  strcpy(letter['V'][0],"*...*.");
  strcpy(letter['V'][1],"*...*.");
  strcpy(letter['V'][2],".*.*..");
  strcpy(letter['V'][3],".*.*..");
  strcpy(letter['V'][4],"..*...");

  strcpy(letter['W'][0],"*...*.");
  strcpy(letter['W'][1],"*...*.");
  strcpy(letter['W'][2],"*.*.*.");
  strcpy(letter['W'][3],"**.**.");
  strcpy(letter['W'][4],"*...*.");

  strcpy(letter['X'][0],"*...*.");
  strcpy(letter['X'][1],".*.*..");
  strcpy(letter['X'][2],"..*...");
  strcpy(letter['X'][3],".*.*..");
  strcpy(letter['X'][4],"*...*.");

  strcpy(letter['Y'][0],"*...*.");
  strcpy(letter['Y'][1],".*.*..");
  strcpy(letter['Y'][2],"..*...");
  strcpy(letter['Y'][3],"..*...");
  strcpy(letter['Y'][4],"..*...");

  strcpy(letter['Z'][0],"*****.");
  strcpy(letter['Z'][1],"...*..");
  strcpy(letter['Z'][2],"..*...");
  strcpy(letter['Z'][3],".*....");
  strcpy(letter['Z'][4],"*****.");

  strcpy(letter[' '][0],"......");
  strcpy(letter[' '][1],"......");
  strcpy(letter[' '][2],"......");
  strcpy(letter[' '][3],"......");
  strcpy(letter[' '][4],"......");
}

class Solver{
 public:

  void init(){
    for(int i=0;i<MAX;i++)
      for(int j=0;j<MAX;j++)
	board[i][j]=WALL;

    for(int i=1;i<MAX-1;i++)
      for(int j=1;j<MAX-1;j++)
	board[i][j]='.';
  }

  int read(){

    int arg;
    string tmp;

    cin >> command ;
    
    if(cin.eof()) return EOF;
    if(command.compare(".EOP")==0) return OUTPUT;
    
    cin >> font;

    str.erase(0,str.size());

    if(command.compare(".P")==0){
      cin >> row >> column;
      getline(cin,tmp);

      for(arg=0;;arg++) if(tmp[arg]=='|') break;
      arg++;
      for(;;arg++){
	if(tmp[arg]=='|') break;
	str+=tmp[arg];
      }
    }
    else {
      cin >> row;
      getline(cin,tmp);

      for(arg=0;;arg++) if(tmp[arg]=='|') break;
      arg++;
      for(;;arg++){
	if(tmp[arg]=='|') break;
	str+=tmp[arg];
      }

      if(command[1]=='R'){ 
	if(font[1]=='1') column = 60 - str.size()+1;
	else if(font[1]=='5') column = 60 - str.size()*6+1; 
      }      
      else if(command[1]=='L') column=1;
      else if(command[1]=='C'){
	if(font[1]=='1') column = 31 - str.size()/2;
	else if(font[1]=='5') column = 31 - str.size()*3;	  
      }
    }

    return CONTINUE;
  }

  void work(){
    
    if(font[1]=='1')
      for(int i=0,curr_row=row,curr_column=column;i<str.size();curr_column++,i++){
	if(str[i]==' ' || curr_row<1 || curr_row>60 || curr_column<0 || curr_column>60) continue;
	else board[curr_row][curr_column] = str[i];
      }
    else if(font[1]=='5')
      for(int i=0;i<str.size();i++){
	
	for(int curr_row=row,j=0;j<5;j++,curr_row++){
	  for(int curr_column=column+i*6,k=0;k<6;k++,curr_column++){
	    if(letter[str[i]][j][k]=='.'|| curr_row<1 || curr_row>60 || curr_column<0 || curr_column>60) continue;
	    else board[curr_row][curr_column] = letter[str[i]][j][k];
	  }
	}

      }      

  }

  void output(){

    for(int i=1;i<MAX-1;i++){
      for(int j=1;j<MAX-1;j++){
	cout << board[i][j];
      }cout << endl;
    }

    cout << endl;

    for(int i=0;i<60;i++) cout << '-';

    cout << endl;
    cout << endl;

  }

};

main(){

  Solver solver;
  int tmp;

  make_letter();
  solver.init();

  while(true){

    tmp = solver.read();

    if(tmp==OUTPUT){ solver.output(); solver.init(); }
    else if(tmp==EOF) break;
    else if(tmp==CONTINUE) solver.work();

  }

}
