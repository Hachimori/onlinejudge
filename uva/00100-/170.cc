#include<iostream>
#include<string>
#include<vector>
#define BUF 14
#define CARD 52
using namespace std;

vector<string> pile[BUF];

bool read(){
  for(int i=0;i<BUF;i++) pile[i] = vector<string>();

  for(int i=0;i<CARD;i++){
    string s;
    cin >> s;
    if(s=="#") return false;
    pile[13-i%13].insert(pile[13-i%13].begin(),s);
  }

  return true;
}

void work(){
  string last;
  int cur = 13, cnt = 0;

  while(!pile[cur].empty()){
    last = pile[cur].back();
    pile[cur].pop_back();
    cnt++;

    if(last[0]=='A') cur = 1;
    if(last[0]=='T') cur = 10;
    if(last[0]=='J') cur = 11;
    if(last[0]=='Q') cur = 12;
    if(last[0]=='K') cur = 13;
    if(isdigit(last[0])) cur = last[0]-'0';
  }

  printf("%02d,%s\n",cnt,last.c_str());
}

int main(){
  while(read())
    work();

  return 0;
}
