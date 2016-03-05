#include<iostream>
using namespace std;

int pr, pc;

void read(){
  cin >> pr >> pc;
  pr--, pc--;
}

bool valid(int r, int c, int put[8]){
  for(int cc=0;cc<c;cc++)
    if(abs(r-put[cc])==0 || abs(r-put[cc])==abs(c-cc))
      return false;
  return true;
}

void rec(int c, int put[8], int &cnt){
  if(c==8){
    printf("%2d     ",++cnt);
    for(int i=0;i<8;i++)
      cout << ' ' << put[i]+1;
    cout << endl;
    return;
  }
  if(c==pc){
    if(valid(pr,c,put)){
      put[c] = pr;
      rec(c+1,put,cnt);
    }
    return;
  }
  for(int r=0;r<8;r++){
    if(!valid(r,c,put)) continue;
    put[c] = r;
    rec(c+1,put,cnt);
  }
}

void work(){
  int put[8], cnt = 0;
  rec(0,put,cnt);
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    read();
    work();
  }
  return 0;
}
