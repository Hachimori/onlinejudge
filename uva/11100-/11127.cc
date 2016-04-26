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

// cursor�͐擪�̈ʒu��\���B
bool isValid(int cursor, int self){
  for(int len=1;len<=cursor/3;len++){
    // self�̐擪����len*3 bit�������o����t�ɕۑ��B
    int a, b, c, t = self>>(cursor-len*3); 

    // t����[0:len-1] bit�������o����a�ɕۑ�
    a = t&((1<<len)-1);
    
    // t����[len:len*2-1] bit�������o����b�ɕۑ�
    b  = t&((1<<(len*2))-1);
    b >>= len;

    // t����[len*2:len*3-1] bit�������o����c�ɕۑ�
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
