#include<iostream>
#define BUF 14
using namespace std;

int size;
bool safe[BUF][BUF];

bool read(){
  cin >> size;
  if(size==0) return false;
  
  for(int i=0;i<size;i++)
    for(int j=0;j<size;j++){
      char ch; cin >> ch;
      safe[i][j] = ch=='.';
    }
  
  return true;
}

void rec(int idx, int unsafeL, int unsafeMid, int unsafeR, int &cnt){
  if(idx==size){
    cnt++;
    return;
  }

  if(((unsafeL|unsafeMid|unsafeR)&((1<<size)-1))==(1<<size)-1) return;

  for(int r=0;r<size;r++){
    if(((1<<r)&(unsafeL|unsafeMid|unsafeR)) || !safe[r][idx]) continue;
    
    rec(idx+1,(unsafeL>>1)|(1<<(r-1)),unsafeMid|(1<<r),(unsafeR<<1)|(1<<(r+1)),cnt);
  }
}

void work(int cases){
  int cnt = 0;
  rec(0,0,0,0,cnt);
  
  cout << "Case " << cases << ": " << cnt << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
