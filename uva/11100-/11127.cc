#include<iostream>
#define BUF 35
using namespace std;

int nCh;
char ch[BUF];

bool read(){
  cin >> nCh;
  if(nCh==0) return false;

  for(int i=0;i<nCh;i++)
    cin >> ch[i];
  
  return true;
}

// cursorは先頭の位置を表す。
bool isValid(int cursor, int self){
  for(int len=1;len<=cursor/3;len++){
    // selfの先頭からlen*3 bitだけ取り出してtに保存。
    int a, b, c, t = self>>(cursor-len*3); 

    // tから[0:len-1] bitだけ取り出してaに保存
    a = t&((1<<len)-1);
    
    // tから[len:len*2-1] bitだけ取り出してbに保存
    b  = t&((1<<(len*2))-1);
    b >>= len;

    // tから[len*2:len*3-1] bitだけ取り出してcに保存
    c  = t&((1<<(len*3))-1);
    c >>= len*2;

    if(a==b && b==c) return false;
  }
  
  return true;
}

void rec(int cur, int self, int &ans){
  if(!isValid(cur,self)) return;
  
  if(cur==nCh){
    ans++;
    return;
  }

  if(ch[cur]!='*'){
    if(ch[cur]=='0')
      rec(cur+1,self,ans);
    else
      rec(cur+1,self|(1<<cur),ans);
  }
  else{
    rec(cur+1,self,ans);
    rec(cur+1,self|(1<<cur),ans);
  }
}

void work(int cases){
  int ans = 0, self = 0;
  rec(0,self,ans);

  cout << "Case " << cases << ": " << ans << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
