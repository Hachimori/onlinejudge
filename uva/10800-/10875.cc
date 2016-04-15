#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>

#define PLUS -100000000
#define MINUS -200000000
#define MUL -300000000
#define DEV -400000000

using namespace std;
const int MAX = 80;
char table[14][6][4] = {
  {"000","0.0","0.0","0.0","000"},
  {".0.",".0.",".0.",".0.",".0."},
  {"000","..0","000","0..","000"},
  {"000","..0","000","..0","000"},
  {"0.0","0.0","000","..0","..0"},
  {"000","0..","000","..0","000"},
  {"0..","0..","000","0.0","000"},
  {"000","..0","..0","..0","..0"},
  {"000","0.0","000","0.0","000"},
  {"000","0.0","000","..0","..0"},
  {".0.",".0.","000",".0.",".0."},
  {"...","...","000","...","..."},
  {"0.0","0.0",".0.","0.0","0.0"},
  {".0.","...","000","...",".0."}
};

char equation[5][MAX];
vector<char> parseResult;
vector<int> formula;

bool isSame(int index, int current) {
//    cout << "TABLE" << endl;
//    for(int i = 0; i < 5; i++) {
//      for(int j = 0; j < 3; j++) {
//        cout << table[index][i][j];
      
//      }
//      cout << endl;
//    }
//    cout << endl;

//    cout << "EQU" << endl;
//    for(int i = 0; i < 5; i++) {
//      for(int j = 0; j < 3; j++) {
//        cout << equation[i][j + current];
//      }
//      cout << endl;
//    }
//    cout << endl;

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 3; j++) {

      if(equation[i][j+current]!=table[index][i][j]) {
	//cout << "FALSE"<<endl;
	return false;
      }
    }
  }
  return true;
}

int parse() {
  int current = 0;
  for(int k=0;k<strlen(equation[0]);k+=4){
    
    for(int i = 0; i < 14; i++) {
      if(isSame(i, k)) {
	if(strlen(equation[i]) == 3 && i == 0) return 0; 
	if(i == 10) {
	  parseResult.push_back('+');
	} else if (i == 11) {
	parseResult.push_back('-');
	} else if (i == 12) {
	  parseResult.push_back('*');
	} else if (i == 13) {
	  parseResult.push_back('/');
	} else {
	parseResult.push_back(i+'0');
	}
	break;
      }
    }
    
  }
  return 1;
}

void formulize(){

  int sum=0;
  
  for(int i=0;i<parseResult.size();){
    sum=0;
    
    while(i<parseResult.size() &&
	  parseResult[i]!='+' && parseResult[i]!='-' &&
	    parseResult[i]!='*' && parseResult[i]!='/'){
      sum*=10;
      sum+=parseResult[i]-'0';
      i++;
    }
    
    formula.push_back(sum);

    if(i<parseResult.size()){
      if(parseResult[i]=='/')
	formula.push_back(DEV);
      if(parseResult[i]=='+')
	formula.push_back(PLUS);
      if(parseResult[i]=='-')
	formula.push_back(MINUS);
      if(parseResult[i]=='*')
	formula.push_back(MUL);
      
      i++;
    }

  }

}


void outputResult(){
  /*
  for(int i=0;i<formula.size();i++){
    cout << formula[i] << ' ' ;
  }cout << endl;
  */

  while(formula.size()!=1){

    int firstMul=-1;
    for(int i=0;i<formula.size();i++)
      if(formula[i]==MUL || formula[i]==DEV){
	firstMul = i;
	break;
      }

    if(firstMul==-1){
    
      if(formula[1]==PLUS)
	formula[0] = formula[0]+formula[2];
      else
	formula[0] = formula[0]-formula[2];

      formula.erase(formula.begin()+1,formula.begin()+3);      

    }
    else {
      
      if(formula[firstMul]==MUL)
	formula[firstMul-1] = formula[firstMul-1]*formula[firstMul+1];
      else
	formula[firstMul-1] = formula[firstMul-1]/formula[firstMul+1];

      formula.erase(formula.begin()+firstMul,formula.begin()+firstMul-1+3);
    }

  }

  //cout << formula[0] << endl;
  

  stringstream ss;
  ss << formula[0];
  string ans =  ss.str();
  
  string output[5];

  for(int i=0;i<ans.size();i++){
    
    if(i!=0)
      for(int j=0;j<5;j++)
	output[j]+=' ';
    

    if(isdigit(ans[i]))      
      for(int j=0;j<5;j++)
	for(int k=0;k<3;k++)
	  output[j] += table[ans[i]-'0'][j][k];
    else 
      for(int j=0;j<5;j++)
	for(int k=0;k<3;k++)      
	  output[j] += table[11][j][k];
    
  }
  
  for(int i=0;i<5;i++){
    for(int j=0;j<output[i].length();j++){
      cout << output[i][j];
    }cout<< endl;
  }cout << endl;

}

void output() {
  for(int i = 0; i < parseResult.size(); i++) {
    cout << parseResult[i]<<" "; 
  }cout << endl;
}

int main() {
  
  while(true) {
    while(cin.peek() == '\n' || cin.peek() == ' ') cin.get(); 
    
    for(int i = 0;i < 5; i++) {
      cin.getline(equation[i],MAX);
    }

//      for(int i = 0; i < 14; i++) {
//        for(int j = 0; j < 5; j++) {
//  	for(int k = 0; k < 3; k++) {
//  	  cout << table[i][j][k];
//  	} cout << endl;
//        }
//        cout << endl;
    //    } 
    if(parse()==0) exit(0);
    //output();
    
    formulize();

    outputResult();

    formula.clear();
    parseResult.clear();
  }
}
