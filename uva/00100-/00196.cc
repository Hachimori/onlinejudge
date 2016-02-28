// 26*26*26 + 26*26 + 26 = 18278

#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<cctype>

#define MAX_ROW 1000
#define MAX_COLUMN 18279

using namespace std;

int row, column;


class Pos{
public:

  int row, column;

  Pos(){}
  Pos(int r, int c): row(r), column(c){}
  
};


class Cell{
public:

  int number;
  vector<Pos> formula;

  Cell(){};

  void pushFormula(string str){
    vector<string> strList;
    split(str.substr(1,str.length()-1),strList,'+');
	
    /*
      for(int i=0;i<strList.size();i++){
      cout << strList[i] << ' ';
      }cout << endl;
      */
    
    
    for(int i=0;i<strList.size();i++){    
      int cursor, row, column;
      string rowStr, columnStr;
      
      for(cursor=0;!isdigit(strList[i][cursor]);cursor++)
	columnStr+=strList[i][cursor];
      
      rowStr=strList[i].substr(cursor,strList[i].length()-cursor);
      
      //cout << rowStr << " " << columnStr << endl;
      
      column = strToInt(columnStr);
      row = atoi(rowStr.c_str());

      //cout << column << " " << row << endl;
      
      formula.push_back(Pos(row,column));
    }
    
  }
  
  int strToInt(string str){
    if(str.length()==1)
      return str[0]-'A'+1;
    else if(str.length()==2)
      return 26 + 26*(str[0]-'A') + str[1]-'A'+1;
    else if(str.length()==3)
      return 26 + 26*26 + 26*26*(str[0]-'A') + 26*(str[1]-'A') + str[2]-'A'+1;
    else assert(false);
  }

  void split(string str, vector<string> &strList, char c){
    
    for(int i=0;i<str.length();i++){
      
      string substr;
      while(str[i]!=c && i<str.length())
	substr+=str[i++];
      
      strList.push_back(substr);
    }

  }

};

vector< vector<Cell> > matrix;

bool allIsNumber(){
  
  bool succeed=true;

  for(int i=1;i<=row;i++)
    for(int j=1;j<=column;j++)
      if(matrix[i][j].formula.size()!=0){
	
	vector<Pos>::iterator k;
	vector<Pos>::iterator begin = matrix[i][j].formula.begin();
	
	for(k=begin;k!=matrix[i][j].formula.end();){
	  Pos p = *k;
	  
	  if(matrix[p.row][p.column].formula.size()==0){
	    matrix[i][j].number+=matrix[p.row][p.column].number;
	    k = matrix[i][j].formula.erase(k);
	    continue;
	  }
	  k++;
	}
	
	succeed=false;
      }

  return succeed;
}

void read(){
  
  cin >> column >> row;

  matrix.assign(row+1, vector<Cell>());
  for(int i=1;i<=row;i++)
    matrix[i].assign(column+1,Cell());

  for(int i=1;i<=row;i++)
    for(int j=1;j<=column;j++){
      matrix[i][j].number=0;
      matrix[i][j].formula.clear();
    }
  

  for(int i=1;i<=row;i++)
    for(int j=1;j<=column;j++){
      string str;
      cin >> str;
      
      if(str[0]=='=')
	matrix[i][j].pushFormula(str);
      else
	matrix[i][j].number = atoi(str.c_str());

    }
  
  
}

void work(){
  
  while(true)
    if(allIsNumber()) break;
  

  for(int i=1;i<=row;i++){
    for(int j=1;j<=column;j++){
      if(j!=1) cout << ' ';
      cout << matrix[i][j].number;
    }
    cout << endl;
  }

}

int main(){
  
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}



