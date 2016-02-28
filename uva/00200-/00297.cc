#include<iostream>
using namespace std;
const int BUF = 32;

string a, b;

void read(){
  cin >> a >> b;
}

void rec(int &idx, int r1, int c1, int r2, int c2, string &s, bool p[BUF][BUF]){
  char ch = s[idx++];
  if(ch=='f' || ch=='e')
    for(int i=r1;i<=r2;i++)
      for(int j=c1;j<=c2;j++)
        p[i][j] |= ch=='f';
  else{
    int midR = (r1+r2)/2, midC = (c1+c2)/2;
    rec(idx,r1,midC+1,midR,c2,s,p);
    rec(idx,r1,c1,midR,midC,s,p);
    rec(idx,midR+1,c1,r2,midC,s,p);
    rec(idx,midR+1,midC+1,r2,c2,s,p);
  }
}

void work(){
  int idx = 0;
  bool pix[BUF][BUF]={};
  rec(idx,0,0,BUF-1,BUF-1,a,pix);
  idx = 0;
  rec(idx,0,0,BUF-1,BUF-1,b,pix);

  int cnt = 0;
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      cnt += pix[i][j];
  cout << "There are " << cnt << " black pixels." << endl;
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
