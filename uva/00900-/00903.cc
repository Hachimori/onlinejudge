// 座標 <-> 数字　をする関数を作ることが基本的な方針
//
//
// 区間を4つに分割する。
// このような感じ↓
//
//
//     \        /
//      \  1   /
//       \    /
//        \  /
//    4    ×   2 
//        /  \
//       /    \
//      /   3  \
//     /        \
//
//
// 座標 -> 数字: 
// 線上の数字は数式で求めることが出来る。
// あとは、区間のなかの数字の増加方向が明らかなので
// 線上の座標と差をとればnumの座標を求めることが出来る。
//
// 
// 数字 -> 座標
// 任意の2つの直線上にnumの座標があるかどうかを判定。
// 高速化のために、numの座標周辺のみを調べる。

#include<iostream>
#include<cstdio>
using namespace std;

class Point{
public:
  int x, y;

  Point(){}
  Point(int x, int y): x(x), y(y){}
};

int num, stage;

bool read(){
  return (scanf("%d",&num)!=EOF);
}

int funcLU(int n){
  return 4*n*n+2*n+1;
}

int funcRU(int n){
  return 4*n*n+4*n+2;
}

int funcRD(int n){
  return 4*n*n+6*n+3;
}

int funcLD(int n){
  return 4*n*n+8*n+5;
}

bool isOnline(Point a, Point b, Point c){
  if(a.x==b.x && b.x==c.x){
    return (a.y<=c.y && c.y<b.y) || 
           (a.y>=c.y && c.y>b.y) ;
  }
  if(a.y==b.y && b.y==c.y){
    return (a.x<=c.x && c.x<b.x) || 
           (a.x>=c.x && c.x>b.x) ;
  }
  return false;
}

int p2v(Point p){
  for(int i=stage-2;;i++){
    if(i<0) continue;
    Point lu = Point(-i,i);
    Point ru = Point(i+1,i);
    Point rd = Point(i+1,-i-1);
    Point ld = Point(-i-1,-i-1);
    Point nlu = Point(-(i+1),(i+1));

    if(isOnline(lu,ru,p)) return funcLU(i)+abs(-i-p.x);
    if(isOnline(ru,rd,p)) return funcRU(i)+abs(i-p.y);
    if(isOnline(rd,ld,p)) return funcRD(i)+abs(i+1-p.x);
    if(isOnline(ld,nlu,p)) return funcLD(i)+abs(-i-1-p.y);
  }
}

Point v2p(int v){
  stage=0;
  for(int i=0;;i++,stage++){
    if(funcLU(i)<=v && v<funcRU(i)){
      int nMov = v-funcLU(i);
      return Point(-i+nMov,i);
    }
    if(funcRU(i)<=v && v<funcRD(i)){
      int nMov = v-funcRU(i);
      return Point(i+1,i-nMov);
    }
    if(funcRD(i)<=v && v<funcLD(i)){
      int nMov = v-funcRD(i);
      return Point(i+1-nMov,-i-1);
    }
    if(funcLD(i)<=v && v<funcLU(i+1)){
      int nMov = v-funcLD(i);
      return Point(-i-1,-i-1+nMov);
    }
  }
}

void work(){
  Point c = v2p(num);
  for(int y=c.y+1;y>=c.y-1;y--){
    for(int x=c.x-1;x<=c.x+1;x++)
      printf("%d;",p2v(Point(x,y)));
    printf("\n");
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
