#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int BUF = 100000;

int nOpe, ope[BUF][3];
string i2n[BUF];

void read(){
  while(1){
    string s;
    getline(cin,s);
    if(s.substr(0,3)=="000") break;
    i2n[atoi(s.substr(0,3).c_str())] = s.substr(3);
  }

  nOpe = 0;
  while(1){
    string s;
    getline(cin,s);
    if(s.substr(0,3)=="000") break;
    ope[nOpe][0] = atoi(s.substr(0,3).c_str());
    ope[nOpe][1] = atoi(s.substr(3,6).c_str());
    ope[nOpe][2] = atoi(s.substr(6  ).c_str());
    nOpe++;
  }
}

void work(){
  for(int L=0;L<nOpe;){
    int R = L, sum = 0;
    while(R<nOpe && ope[L][0]==ope[R][0]){
      sum += ope[R][2];
      R++;
    }
    
    if(sum!=0){
      cout << "*** Transaction " << ope[L][0] << " is out of balance ***" << endl;
      for(int i=L;i<R;i++)
        printf("%d %-30s %10.2lf\n",ope[i][1],i2n[ope[i][1]].c_str(),0.01*ope[i][2]);
      printf("%d %-30s %10.2lf\n",999,"Out of Balance",-0.01*sum);
      cout << endl;
    }
    L = R;
  }
}

int main(){
  read();
  work();
  return 0;
}
