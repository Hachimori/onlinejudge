#include<iostream>
#include<cstdio>
#define EPS (0.8e-10)
#define GAME 505
#define QUEUE 300000
using namespace std;

class Point{
public:
  int game, best, curr;

  Point(){}
  Point(int g, int b, int c): game(g), best(b), curr(c){}
};

int nGame;
double p;

bool read(){
  cin >> nGame;
  if(nGame==0) return false;
  cin >> p;
  return true;
}

void work(){
  static Point Q[QUEUE], fix[QUEUE];
  static double dp[GAME][GAME], next[GAME][GAME];  // best streak, curr streak
  int curGame = 0, qh = 0, qt = 0, fh = 0, ft = 0;
  
  for(int i=0;i<=nGame;i++)
    for(int j=0;j<=nGame;j++)
      dp[i][j] = next[i][j] = -1;
  
  Q[qt] = Point(0,0,0);
  qt=(qt+1)%QUEUE;
  dp[0][0] = 1;
  
  while(true){
    Point &pt = Q[qh]; qh=(qh+1)%QUEUE;

    if(pt.game==nGame) break;
    
    if(curGame!=pt.game){
      curGame = pt.game;
      while(fh!=ft){
	Point &fp = fix[fh]; fh=(fh+1)%QUEUE;
	dp[fp.best][fp.curr] = next[fp.best][fp.curr];
	next[fp.best][fp.curr] = -1;
      }
    }
    
    double &curP = dp[pt.best][pt.curr];
    if(curP<EPS) continue;


    if(pt.best<pt.curr+1){
      if(next[pt.best+1][pt.curr+1]>=-EPS)
	next[pt.best+1][pt.curr+1] += p*curP;
      else{
	Q[qt].game = pt.game+1; Q[qt].best = pt.best+1; Q[qt].curr = pt.curr+1;
	qt = (qt+1)%QUEUE;

	fix[ft].game = pt.game+1; fix[ft].best = pt.best+1; fix[ft].curr = pt.curr+1;
	ft = (ft+1)%QUEUE;
	
	next[pt.best+1][pt.curr+1]  = p*curP;
      }
    }
    else{
      if(next[pt.best][pt.curr+1]>=-EPS)
	next[pt.best][pt.curr+1] += p*curP;
      else{
	Q[qt].game = pt.game+1; Q[qt].best = pt.best; Q[qt].curr = pt.curr+1;
	qt = (qt+1)%QUEUE;

	fix[ft].game = pt.game+1; fix[ft].best = pt.best; fix[ft].curr = pt.curr+1;
	ft = (ft+1)%QUEUE;
	
	next[pt.best][pt.curr+1]  = p*curP;
      }
    }
    
    if(next[pt.best][0]>=-EPS)
      next[pt.best][0] += (1-p)*curP;
    else{
      Q[qt].game = pt.game+1; Q[qt].best = pt.best; Q[qt].curr = 0;
      qt = (qt+1)%QUEUE;

      fix[ft].game = pt.game+1; fix[ft].best = pt.best; fix[ft].curr = 0;
      ft = (ft+1)%QUEUE;
      
      next[pt.best][0]  = (1-p)*curP;
    }
  }
  

  
  double sum = 0;

  for(int i=1;i<=nGame;i++)
    for(int j=0;j<=i;j++)
      if(next[i][j]>=-EPS)
	sum += i*next[i][j];

  printf("%.6lf\n",sum);
}

int main(){
  while(read())
    work();
  
  return 0;
}
