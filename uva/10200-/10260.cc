#include<iostream>
#include<string>

#define MAX_SIZE 257

using namespace std;

string str;
int table[MAX_SIZE];

void makeTable(){
  
  for(int i=0;i<MAX_SIZE;i++)
    table[i] = -1;

  table['B'] = table['F'] = table['P'] = table['V'] = 1;
  table['C'] = table['G'] = table['J'] = table['K'] = table['Q']
    = table['S'] = table['X'] = table['Z'] = 2;
  table['D'] = table['T'] = 3;
  table['L'] = 4;
  table['M'] = table['N'] = 5;
  table['R'] = 6;
  
  
}

bool read(){
  if(!(cin >> str)) return false;
  return true;
}

void work(){
  
  int cursor=0;

  while(cursor<str.length()){
    if(cursor==0 && table[str[cursor]]!=-1){
      cout << table[str[cursor]];
      cursor++;      
    }
    else if(cursor==0) cursor++;
    else{
      while(cursor<str.length() && table[str[cursor]]==table[str[cursor-1]]) cursor++;
      if(cursor<str.length() && table[str[cursor]]!=-1) cout << table[str[cursor]];
      cursor++;
    }
  }
  
  cout << endl;
}

int main(){

  makeTable();

  while(read())
    work();

  return 0;
}
