// dp
//
//
//  $B$3$N$h$&$J%3!<%I$r=q$/$H!"(BO(n^4)$B$H$J$j!"(BTLE$B$K$J$k!#(B
//
//  for(int i=aa;i<nA;i++)
//    if(A[i]==C[cc])
//      sum += rec(i+1,bb,cc+1,dp);
//
//  for(int i=bb;i<nB;i++)
//    if(B[i]==C[cc])
//      sum += rec(aa,i+1,cc+1,dp);
//
//
// $B$h$C$F!"(Bfor$BJ8$r>C$9$?$a$K4X?t$K(BA,B$B$I$A$i$+$NJ8;z$K(B
// $B0lCW$9$k$^$G%+!<%=%k$r?J$a$k%V!<%kCM(BmatchA$B$r2C$($k!#(B
// 
// $B$3$N$h$&$K$9$k$H(Bfor$BJ8$r>C$;$k$N$G(BO(n^3)$B$N%"%k%4%j%:%`$K$J$k!#(B

#include<iostream>
#include<string>
#define BUF 65
#define MOD 10007
using namespace std;

int nA, nB, nC;
char A[BUF], B[BUF], C[BUF];

void read(){
  cin >> A >> B >> C;
  nA = strlen(A);
  nB = strlen(B);
  nC = strlen(C);
}

int rec(bool matchA, int aa, int bb, int cc, int dp[][BUF][BUF][BUF]){
  if(dp[matchA][aa][bb][cc]!=-1) return dp[matchA][aa][bb][cc];
  if(cc==nC) return dp[matchA][aa][bb][cc] = 1;
  
  int sum = 0;
  if(matchA && aa<nA && A[aa]==C[cc]){
    if(cc==nC-1)
      sum++;
    else{
      sum += rec(true,aa+1,bb,cc+1,dp);
      sum += rec(false,aa+1,bb,cc+1,dp);
    }
  }

  if(!matchA && bb<nB && B[bb]==C[cc]){
    if(cc==nC-1)
      sum++;
    else{
      sum += rec(true,aa,bb+1,cc+1,dp);
      sum += rec(false,aa,bb+1,cc+1,dp);
    }
  }
  
  if(matchA && aa+1<nA)
    sum += rec(matchA,aa+1,bb,cc,dp);
  
  if(!matchA && bb+1<nB)
    sum += rec(matchA,aa,bb+1,cc,dp);
  
  return dp[matchA][aa][bb][cc]=(sum%MOD);
}

void work(){
  static int dp[2][BUF][BUF][BUF];

  for(int i=0;i<2;i++)
    for(int j=0;j<=nA;j++)
      for(int k=0;k<=nB;k++)
	for(int l=0;l<=nC;l++)
	  dp[i][j][k][l] = -1;
  
  cout << (rec(false,0,0,0,dp)+rec(true,0,0,0,dp))%MOD << endl;
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
