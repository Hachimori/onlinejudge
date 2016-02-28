#include<iostream>
using namespace std;
const int BUF = 10;

struct Dot{
  bool low, right;
};

int sz;
Dot dot[BUF][BUF];

bool read(){
  for(int i=0;i<BUF;i++) 
    for(int j=0;j<BUF;j++) 
      dot[i][j].low = dot[i][j].right = false;
  if(!(cin >> sz)) return false;
  int nInfo;
  cin >> nInfo;
  for(int i=0;i<nInfo;i++){
    char ch;
    int r, c;
    cin >> ch >> r >> c;
    (ch=='V' ? dot[c-1][r-1].low : dot[r-1][c-1].right) = true;
  }
  return true;
}


void work(int cases){
  cout << "Problem #" << cases << endl;
  cout << endl;
  bool exist = false;
  for(int len=1;len<sz;len++){
    int cnt = 0;
    for(int r=0;r+len<sz;r++)
      for(int c=0;c+len<sz;c++){
        bool isSquare = true;
        for(int i=0;i<len;i++){
          isSquare &= dot[r+  i][c    ].low;
          isSquare &= dot[r+  i][c+len].low;
          isSquare &= dot[r    ][c+  i].right;
          isSquare &= dot[r+len][c+  i].right;
        }
        cnt += isSquare;
      }
    if(cnt){
      cout << cnt << " square (s) of size " << len << endl;
      exist = true;
    }
  }
  if(!exist)
    cout << "No completed squares can be found." << endl;
}


int main(){
  for(int i=0;read();i++){
    if(i){
      cout << endl;
      cout << "**********************************" << endl;
      cout << endl;
    }
    work(i+1);
  }
  return 0;
}
