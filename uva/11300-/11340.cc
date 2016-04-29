#include<iostream>
#include<cstdio>
using namespace std;
const int LINE = 150005;

int ch2val[256], nLine;
string line[LINE];

void read(){
  memset(ch2val,0,sizeof(ch2val));
  int nCh;
  cin >> nCh;
  for(int i=0;i<nCh;i++){
    char ch;
    int v;
    cin >> ch >> v;
    ch2val[(unsigned char)ch] = v;
  }
  cin >> nLine;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nLine;i++)
    getline(cin,line[i]);
}

void work(){
  long long sum = 0;
  for(int i=0;i<nLine;i++)
    for(int j=0;j<line[i].size();j++)
      sum += ch2val[(unsigned char)line[i][j]];
  printf("%lld.%02lld$\n",sum/100,sum%100);
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
