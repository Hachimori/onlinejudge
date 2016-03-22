#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;
const int BUF = 1000, REG = 10;


int nOpe;
string ope[BUF];

void read(){
  for(int i=0;i<BUF;i++) ope[i] = "000";
  nOpe = 0;
  while(1){
    if(!getline(cin,ope[nOpe]) || ope[nOpe].empty()) break;
    nOpe++;
  }
}


string itoa(int v){
  stringstream out;
  out << v;
  return out.str();
}


void work(){
  int reg[REG]={}, cnt = 0;

  for(int loop=0;loop<BUF;loop++){
    cnt++;
    if(ope[loop]=="100"){
      cout << cnt << endl;
      break;
    }
    
    int ch1 = ope[loop][0]-'0';
    int ch2 = ope[loop][1]-'0';
    int ch3 = ope[loop][2]-'0';
    
    switch(ch1){
    case 2:
      reg[ch2] = ch3;
      break;
    case 3:
      reg[ch2] = (reg[ch2]+ch3)%BUF;
      break;
    case 4:
      reg[ch2] = (reg[ch2]*ch3)%BUF;
      break;
    case 5:
      reg[ch2] = reg[ch3];
      break;
    case 6:
      reg[ch2] = (reg[ch2]+reg[ch3])%BUF;
      break;
    case 7:
      reg[ch2] = (reg[ch2]*reg[ch3])%BUF;
      break;
    case 8:
      reg[ch2] = atoi(ope[reg[ch3]].c_str());
      break;
    case 9:
      ope[reg[ch3]] = itoa(reg[ch2]);
      break;      
    case 0:
      if(reg[ch3]) loop = reg[ch2]-1;
      break;
    }
  }
}


int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
