#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const int BUF = 10, OPE = 55;

int sz, b[BUF][BUF], nOpe;
string ope[OPE];

void read(){
  cin >> sz;
  for(int i=0;i<sz;i++)
    for(int j=0;j<sz;j++){
      char ch;
      cin >> ch;
      b[i][j] = ch-'0';
    }
  cin >> nOpe;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nOpe;i++)
    getline(cin,ope[i]);
}

void work(int cases){
  for(int k=0;k<nOpe;k++){
    if(ope[k]=="inc")
      for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
          b[i][j] = (b[i][j]+1)%10;
    else if(ope[k]=="dec")
      for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
          b[i][j] = (b[i][j]+9)%10;
    else if(ope[k]=="transpose")
      for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
          swap(b[i][j],b[j][i]);
    else if(ope[k].substr(0,3)=="row"){
      stringstream in(ope[k]);
      string s;
      int r1, r2;
      in >> s >> r1 >> r2;
      for(int i=0;i<sz;i++)
        swap(b[r1-1][i],b[r2-1][i]);
    }
    else{
      stringstream in(ope[k]);
      string s;
      int c1, c2;
      in >> s >> c1 >> c2;
      for(int i=0;i<sz;i++)
        swap(b[i][c1-1],b[i][c2-1]);
    }
  }

  cout << "Case #" << cases << endl;
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++)
      cout << b[i][j];
    cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
    cout << endl;
  }
  return 0;
}
