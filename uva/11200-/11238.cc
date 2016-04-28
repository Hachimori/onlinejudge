#include<iostream>
using namespace std;
typedef long long integer;

enum State{NORMAL, SPARE, STRIKE};

integer dp[12][401][3][3];

int calc(int prepre, int pre, int fst, int scd){
  if(prepre==STRIKE && pre==STRIKE)
    return fst*3+scd*2;
  
  switch(pre){
  case STRIKE: return fst*2+scd*2;
  case SPARE:  return fst*2+scd;
  case NORMAL: return fst+scd;
  }
}

void makeTable(){
  for(int i=0;i<12;i++)
    for(int j=0;j<401;j++)
      for(int k=0;k<3;k++)
        for(int l=0;l<3;l++)
          dp[i][j][k][l] = 0;
  dp[0][0][0][0] = 1;
  
  for(int k=0;k<10;k++)
    for(int score=0;score<=300;score++)
      for(int prepre=0;prepre<3;prepre++)
        for(int pre=0;pre<3;pre++){
          integer curr = dp[k][score][prepre][pre];

          for(int fst=0;fst<=9;fst++)
            for(int scd=0;fst+scd<=10;scd++){
              if(fst+scd==10){
                dp[k+1][score+calc(prepre,pre,fst,scd)][pre][SPARE] += curr;
              }
              else{
                dp[k+1][score+calc(prepre,pre,fst,scd)][pre][NORMAL] += curr;
              }
            }

          dp[k+1][score+calc(prepre,pre,10,0)][pre][STRIKE] += curr;
        }
    
  for(int score=0;score<=300;score++){
    
    // prepre: STRIKE 
    // pre: STRIKE
    for(int fst=0;fst<=9;fst++)
      for(int scd=0;fst+scd<=10;scd++){
        integer curr = dp[10][score][STRIKE][STRIKE];
        dp[11][score+calc(STRIKE,STRIKE,fst,scd)-fst-scd][STRIKE][STRIKE] += curr;
      }
    for(int scd=0;scd<=10;scd++){
      integer curr = dp[10][score][STRIKE][STRIKE];
      dp[11][score+calc(STRIKE,STRIKE,10,scd)-10-scd][STRIKE][STRIKE] += curr;
    }
    
    // prepre: !STRIKE
    // pre: STRIKE
    for(int prepre=0;prepre<2;prepre++)
      for(int fst=0;fst<=9;fst++)
        for(int scd=0;fst+scd<=10;scd++){
          integer curr = dp[10][score][prepre][STRIKE];
          dp[11][score+calc(prepre,STRIKE,fst,scd)-fst-scd][prepre][STRIKE] += curr;
        }
    for(int prepre=0;prepre<2;prepre++)
      for(int scd=0;scd<=10;scd++){
        integer curr = dp[10][score][prepre][STRIKE];
        dp[11][score+calc(prepre,STRIKE,10,scd)-10-scd][prepre][STRIKE] += curr;
      }
    
    // prepre: ALL
    // pre: SPARE
    for(int prepre=0;prepre<3;prepre++)
      for(int fst=0;fst<=10;fst++){
        integer curr = dp[10][score][prepre][SPARE];
        dp[11][score+calc(prepre,SPARE,fst,0)-fst][prepre][SPARE] += curr;
      }

    // prepre: ALL
    // pre: NORMAL
    for(int prepre=0;prepre<3;prepre++)
      dp[11][score][prepre][NORMAL] += dp[10][score][prepre][NORMAL];
  }      
}

int n;

bool read(){
  cin >> n;
  return n!=-1;
}

void work(){
  integer ans = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      ans += dp[11][n][i][j];
  
  cout << ans << endl;
}

int main(){
  makeTable();
  
  while(read())
    work();
  
  return 0;
}
