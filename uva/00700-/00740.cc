#include<iostream>
#include<string>
using namespace std;
const int BUF = 40, UP = 1, DOWN = 0;

char ch[2][BUF];

void makeTable(){
  for(int i=0;i<2;i++){
    string s;
    getline(cin,s);
    for(int j=0;j<32;j++)
      if(j==27) 
        ch[i][j] = DOWN;
      else if(j==31) 
        ch[i][j] = UP;
      else
        ch[i][j] = s[j];
  }
}

string s;

bool read(){
  return getline(cin,s);
}

void work(){
  int state = DOWN;
  for(int i=0;i<s.size();i+=5){
    int mask = 0;
    for(int j=0;j<5;j++)
      mask |= (s[i+j]=='1' ? 1<<(4-j) : 0);
    if(ch[state][mask]==UP)
      state = UP;
    else if(ch[state][mask]==DOWN)
      state = DOWN;
    else
      cout << ch[state][mask];
  }
  cout << endl;
}

int main(){
  makeTable();
  while(read()) work();
  return 0;
}
