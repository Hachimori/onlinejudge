// 全探索 + 強力な枝狩り
//
// 
// 枝狩り１、行数と列数が互いに素ならば、一つ目のqueenですべてのマスが埋まる。
//           よって (gcd(column,row)==1 && nQueen>1 ならば "0 0" を出力。
//
// 枝狩り２、最初の一つ目のqueenは一列目に置くならばどこにおいても同じ。
//           よって、一つ目のqueenは位置を固定する。
//
//
// 枝狩り２は、こういうことをいう
//
// 4*8 の行列において 1行1列に置いたとき
//
// ●○○○●○○○
// ○●○●○●○●
// ○○●○○○●○
// ○●○●○●○●
//
// 4*8 の行列において 2行1列に置いたとき
//
// ○●○●○●○●
// ●○○○●○○○
// ○●○●○●○●
// ○○●○○○●○
// 
// このように、行全体を下に一行シフトすることと同じである。 

#include<iostream>

#define MAX_SIZE 15

using namespace std;

class Point{
public:

  int r, c;
  
  Point(){}
  Point(int r, int c): r(r), c(c){}
};

int row, column, nQueen;

bool read(){
  if(!(cin >> column >> row >> nQueen)) return false;
  
  return true;
}

bool rec(int c, int nPut, bool isAvail[][MAX_SIZE], Point putList[]){
  

  static const int dr[3]={1,0,-1};
  
  /*
  for(int i=0;i<row;i++){
    for(int j=0;j<column;j++){
      cout << !isAvail[i][j];
    }cout << endl;
  }cout<<endl;
  */
  
  
  if(nPut==nQueen) return true;
  if(c==column) return false;
  if(column-c<nQueen-nPut) return false;
  
  int limit;
  if(c==0) limit = 1;
  else limit = row;
  
  for(int i=0;i<limit;i++){
    if(!isAvail[i][c]) continue;
    
    bool next[MAX_SIZE][MAX_SIZE];

    for(int j=0;j<row;j++)
      for(int k=0;k<column;k++)
	next[j][k] = isAvail[j][k];
    
    for(int j=0;j<3;j++){
      int currR=(i+dr[j]+row)%row, currC=c+1;
      while(!(currR==i && currC==c)){
	next[currR][currC] = false;
	currR = (currR+dr[j]+row)%row;
	currC = (currC+1)%column;
      }
    }
    
    putList[nPut] = Point(i,c);
    if(rec(c+1,nPut+1,next,putList)) return true;
    
  }

  if(rec(c+1,nPut,isAvail,putList)) return true;

  return false;
}

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

void work(){
  
  Point putList[MAX_SIZE];
  bool isAvail[MAX_SIZE][MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    for(int j=0;j<MAX_SIZE;j++)
      isAvail[i][j] = true;
  
  if( !(gcd(column,row)==1 && nQueen>1) && rec(0,0,isAvail,putList))
    for(int i=0;i<nQueen;i++)
      cout << putList[i].c+1 << ' ' << putList[i].r+1 << endl;
  else
    cout << 0 << ' ' << 0 << endl;
  
}

int main(){

  while(read())
    work();

  return 0;
}
