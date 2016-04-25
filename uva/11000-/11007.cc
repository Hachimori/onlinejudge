// $B7G<(HD$G$N5DO@$K$h$k$H!"(Bcube$B$r40@.$9$k$N$K$+$+$k:GBg<j?t$O(B14$B<j!#(B
// $B$^$?!"(B24$BDL$j$N2sE>$r=|$$$?$H$-!"(B7$B<j$NA`:n$G$G$-$k>uBV$OLs(B45000$B!#(B
// 
// 
// $B$3$N%W%m%0%i%`$O!"%4!<%k$+$i(B8$B<j$^$G$NA`:n$7$?>uBV$r(Bmap$B$KJ]B8$7$F(B
// $BN>B&C5:w$r$7$F$$$k!#$^$?!"=i4|>uBV$+$i(B5$B<j0JFb$G2r$,8+$D$+$i$J$1$l$P!"(B
// $B$=$N;~E@$G2r$,(B14$B<j$G$"$k$3$H$,J,$+$k$N$G!"C5:w$rBG$A@Z$C$F(B14$B$rJV$9!#(B
// $B$3$l$O7G<(HD$G$"$C$?%"%$%G%"$r;29M$K$7$?!#(B
//
//
// pair<map<Cube,int>::iterator,bool> ret = M.insert(make_pair(next,cost+1));
// if(ret.second)
//   Q.push(next);
//
// $B$3$N$h$&$K$9$k$H!"(B
//
// if(!M.count(next)){
//   M[next] = cost+1;
//   Q.push(next);
// }
//
// $B$HHf$Y$F(Bmap$B$NC5:w2s?t$r(B1$B2s8:$i$;$k!#(B


#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<cassert>
#include<vector>
#include<utility>
#define LIMIT 8
#define FRONT 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define TOP 4
#define BOTTOM 5
#define INF 10000
using namespace std;

class Cube{
public:
  char b[6][2][2];
  
  void faceRotate(int p){
    int t = b[p][0][0];
    b[p][0][0] = b[p][0][1];
    b[p][0][1] = b[p][1][1];
    b[p][1][1] = b[p][1][0];
    b[p][1][0] = t;
  }
  
  void frontRotate(){
    int t = b[TOP][1][0];
    b[TOP][1][0] = b[RIGHT][0][0];
    b[RIGHT][0][0] = b[BOTTOM][0][1];
    b[BOTTOM][0][1] = b[LEFT][1][1];
    b[LEFT][1][1] = t;

    t = b[TOP][1][1];
    b[TOP][1][1] = b[RIGHT][1][0];
    b[RIGHT][1][0] = b[BOTTOM][0][0];
    b[BOTTOM][0][0] = b[LEFT][0][1];
    b[LEFT][0][1] = t;
  }
  
  void backRotate(){
    int t = b[BOTTOM][1][0];
    b[BOTTOM][1][0] = b[LEFT][1][1];
    b[LEFT][1][1] = b[TOP][0][1];
    b[TOP][0][1] = b[RIGHT][0][0];
    b[RIGHT][0][0] = t;
    
    t = b[BOTTOM][1][1];
    b[BOTTOM][1][1] = b[LEFT][0][1];
    b[LEFT][0][1] = b[TOP][0][0];
    b[TOP][0][0] = b[RIGHT][1][0];
    b[RIGHT][1][0] = t;
  }

  void topRotate(){
    int t = b[BACK][1][0];
    b[BACK][1][0] = b[RIGHT][0][1];
    b[RIGHT][0][1] = b[FRONT][0][1];
    b[FRONT][0][1] = b[LEFT][0][1];
    b[LEFT][0][1] = t;

    t = b[BACK][1][1];
    b[BACK][1][1] = b[RIGHT][0][0];
    b[RIGHT][0][0] = b[FRONT][0][0];
    b[FRONT][0][0] = b[LEFT][0][0];
    b[LEFT][0][0] = t;
  }

  void rightRotate(){
    int t = b[TOP][1][1];
    b[TOP][1][1] = b[BACK][1][1];
    b[BACK][1][1] = b[BOTTOM][1][1];
    b[BOTTOM][1][1] = b[FRONT][1][1];
    b[FRONT][1][1] = t;

    t = b[TOP][0][1];
    b[TOP][0][1] = b[BACK][0][1];
    b[BACK][0][1] = b[BOTTOM][0][1];
    b[BOTTOM][0][1] = b[FRONT][0][1];
    b[FRONT][0][1] = t;
  }

  void leftRotate(){
    int t = b[TOP][0][0];
    b[TOP][0][0] = b[FRONT][0][0];
    b[FRONT][0][0] = b[BOTTOM][0][0];
    b[BOTTOM][0][0] = b[BACK][0][0];
    b[BACK][0][0] = t;

    t = b[TOP][1][0];
    b[TOP][1][0] = b[FRONT][1][0];
    b[FRONT][1][0] = b[BOTTOM][1][0];
    b[BOTTOM][1][0] = b[BACK][1][0];
    b[BACK][1][0] = t;
  }

  void bottomRotate(){
    int t = b[FRONT][1][0];
    b[FRONT][1][0] = b[RIGHT][1][0];
    b[RIGHT][1][0] = b[BACK][0][1];
    b[BACK][0][1] = b[LEFT][1][0];
    b[LEFT][1][0] = t;

    t = b[FRONT][1][1];
    b[FRONT][1][1] = b[RIGHT][1][1];
    b[RIGHT][1][1] = b[BACK][0][0];
    b[BACK][0][0] = b[LEFT][1][1];
    b[LEFT][1][1] = t;
  }

  void rotate(int p){
    faceRotate(p);
    switch(p){
    case FRONT: frontRotate(); break;
    case BACK: backRotate(); break;
    case RIGHT: rightRotate(); break;
    case LEFT: leftRotate(); break;
    case TOP: topRotate(); break;
    case BOTTOM: bottomRotate(); break;
    }
  }

  void hShift(){
    int t = b[TOP][1][0];
    b[TOP][1][0] = b[TOP][1][1];
    b[TOP][1][1] = b[TOP][0][1];
    b[TOP][0][1] = b[TOP][0][0];
    b[TOP][0][0] = t;

    t = b[BOTTOM][0][0];
    b[BOTTOM][0][0] = b[BOTTOM][0][1];
    b[BOTTOM][0][1] = b[BOTTOM][1][1];
    b[BOTTOM][1][1] = b[BOTTOM][1][0];
    b[BOTTOM][1][0] = t;

    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++){
	int t = b[FRONT][i][j];
	b[FRONT][i][j] = b[RIGHT][i][j];
	b[RIGHT][i][j] = b[BACK][!i][!j];
	b[BACK][!i][!j] = b[LEFT][i][j];
	b[LEFT][i][j] = t;
      }
  }

  void vShift(){
    int t = b[LEFT][1][0];
    b[LEFT][1][0] = b[LEFT][1][1];
    b[LEFT][1][1] = b[LEFT][0][1];
    b[LEFT][0][1] = b[LEFT][0][0];
    b[LEFT][0][0] = t;

    t = b[RIGHT][0][0];
    b[RIGHT][0][0] = b[RIGHT][0][1];
    b[RIGHT][0][1] = b[RIGHT][1][1];
    b[RIGHT][1][1] = b[RIGHT][1][0];
    b[RIGHT][1][0] = t;

    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++){
	int t = b[FRONT][i][j];
	b[FRONT][i][j] = b[TOP][i][j];
	b[TOP][i][j] = b[BACK][i][j];
	b[BACK][i][j] = b[BOTTOM][i][j];
	b[BOTTOM][i][j] = t;
      }
  }

  bool operator< (const Cube &d) const {
    for(int i=0;i<6;i++)
      for(int j=0;j<2;j++)
	for(int k=0;k<2;k++)
	  if(b[i][j][k]!=d.b[i][j][k])
	    return b[i][j][k] < d.b[i][j][k];
    return false;
  }
};

Cube init;
map<Cube,int> GM;

void makeRotation(Cube &c, Cube ret[]){
  for(int i=0;i<6;i++){
    Cube toPush = c;
    switch(i){
    case FRONT:
      toPush.vShift(); toPush.vShift(); toPush.vShift();
      break;
    case BACK:
      toPush.vShift();
      break;
    case RIGHT:
      toPush.hShift(); toPush.vShift(); toPush.vShift(); toPush.vShift();
      break;
    case LEFT:
      toPush.hShift(); toPush.vShift();
      break;
    case TOP:
      break;
    case BOTTOM:
      toPush.vShift(); toPush.vShift();
      break;
    }
    for(int j=0;j<4;j++){
      toPush.hShift();
      ret[i*4+j] = toPush;
    }
  }
}

int bfs(Cube c, map<Cube,int> &M, map<Cube,int> &goal){
  queue<Cube> Q;
  Q.push(c);	  
  M[c] = 0;
  
  while(!Q.empty()){
    Cube curr = Q.front();
    Q.pop();

    int cost = M[curr];
    
    if(goal.size()!=0){
      int minV = INF;
      static Cube cubeList[24];
      makeRotation(curr,cubeList);
      for(int i=0;i<24;i++)
	if(goal.count(cubeList[i])) minV = min(minV,goal[cubeList[i]]);
      if(minV!=INF) return minV+cost;
    }

    if(cost==LIMIT-3 && goal.size()!=0) continue;
    if(cost==LIMIT   && goal.size()==0) break;
    
    for(int i=0;i<6;i+=2){
      Cube next = curr;

      next.rotate(i);
      pair<map<Cube,int>::iterator,bool> ret = M.insert(make_pair(next,cost+1));
      if(ret.second) Q.push(next);
      
      next.rotate(i); next.rotate(i);
      ret = M.insert(make_pair(next,cost+1));
      if(ret.second) Q.push(next);
    }
  }  

  return 14;
}

void read(){
  int pos[]={TOP,FRONT,RIGHT,BOTTOM,BACK,LEFT};

  for(int i=0;i<6;i++){
    string s;
    cin >> s;
    switch(pos[i]){
    case BACK:
      for(int j=0;j<4;j++)
	init.b[pos[i]][!(j/2)][!(j%2)] = s[j];
      break;
    default:
      for(int j=0;j<4;j++)
	init.b[pos[i]][j/2][j%2] = s[j];
      break;
    }
  }
}

void work(){
  map<Cube,int> M;
  cout << bfs(init,M,GM) << endl;
}

int main(){
  Cube c;
  char ch[] = {'W','B','R','O','Y','G'};
  map<Cube,int> empty;
  
  for(int i=0;i<6;i++)
    for(int j=0;j<4;j++)
      c.b[i][j/2][j%2] = ch[i];
  
  bfs(c,GM,empty);
  
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}
