#include<iostream>
#include<cstdio>
using namespace std;
const int COURSE = 15, TIME = 105, INF = 1<<20;

int course, limit, study[COURSE][TIME];

void read(){
  cin >> course >> limit;
  for(int i=0;i<course;i++)
    for(int j=0;j<limit;j++)
      cin >> study[i][j];
}

void work(){
  int dp[COURSE][TIME];
  for(int i=0;i<COURSE;i++)
    for(int j=0;j<TIME;j++)
      dp[i][j] = -INF;
  dp[0][limit] = 0;

  for(int r=0;r<course;r++)
    for(int remTime=0;remTime<=limit;remTime++)
      for(int studyTime=1;remTime-studyTime>=0;studyTime++){
        int score = study[r][studyTime-1];
        if(score>=5)
          dp[r+1][remTime-studyTime] = max(dp[r+1][remTime-studyTime],dp[r][remTime]+score);
      }
    

  int result = *max_element(dp[course],dp[course]+limit+1);
  if(result<0)
    cout << "Peter, you shouldn't have played billiard that much." << endl;
  else
    printf("Maximal possible average mark - %.2lf.\n",1.0*result/course+1e-6);
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
