#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define WALL (-2)
#define UNREACH (-1)
#define MAX 30

int goto_l[6]={1,0,0,0,0,-1},goto_r[6]={0,1,0,0,-1,0},goto_c[6]={0,0,1,-1,0,0};

class Point{
 public:
  int l,r,c;
  
  
  Point(){}
  Point( const int x, const int y, const int z ) {
    l = x, r = y, c = z;
  }
  bool operator== (const Point &p) const {
    if(p.l==l && p.r==r && p.c==c) return true;
    else return false;
  }
};

class Solver{
 public:
  int level,row,column;  
  int dungeon[MAX+2][MAX+2][MAX+2];
  Point start, escape;

  void init(){
    for(int i=0;i<level+2;i++){
      for(int j=0;j<row+2;j++){
	for(int k=0;k<column+2;k++){
	  dungeon[i][j][k]=WALL;
	}
      }
    }
  }
  
  bool read(){
    
    cin >> level >> row >> column;
    if(level==0 && row==0 && column ==0) return false;
    
    init();
    
    char ch;

    for(int i=1;i<level+1;i++){
      for(int j=1;j<row+1;j++){
	for(int k=1;k<column+1;k++){
	  cin >> ch;
	  if ( ch != '#' )	    
	    dungeon[i][j][k] = UNREACH;
	  if ( ch == 'S' ){
	    start.l = i, start.r = j, start.c = k;
	    dungeon[i][j][k] = 0;
	  }
	  if ( ch == 'E' )
	    escape.l = i, escape.r = j, escape.c = k;
	}
      }
    }    
    /*
    for(int i=0;i<level+1;i++){
      for(int j=0;j<row+1;j++){
	for(int k=0;k<column+1;k++){
	  cout << dungeon[i][j][k] ;
	}cout << endl;
      }cout << endl;
    }cout <<endl;
    */

    return true;
  }
  
  void work(){
    queue<Point> Q;
    
    Q.push(start);

    while(!Q.empty()){
      Point curr = Q.front();
      Q.pop();
      //cout << "l == " << curr.l << " r = " << curr.r << " c = " << curr.c << endl;
      for(int i=0;i<6;i++){
	const int next_l = curr.l+goto_l[i];
	const int next_r = curr.r+goto_r[i];
	const int next_c = curr.c+goto_c[i];
	if(dungeon[next_l][next_r][next_c] == UNREACH){
	  dungeon[next_l][next_r][next_c] = dungeon[curr.l][curr.r][curr.c] + 1;
	  Q.push(Point(next_l,next_r,next_c)); 
	}
	if(curr==escape) {
	  /*cout << curr.l << ' ' << escape.l << endl;
	  cout << curr.r << ' ' << escape.r << endl;
	  cout << curr.c << ' ' << escape.c << endl;*/
	  /*
	  for(int i=1;i<level+1;i++){
	    for(int j=1;j<row+1;j++){
	      for(int k=1;k<column+1;k++){
		cout << dungeon[i][j][k] ;
	      }cout << endl;
	    }cout << endl;
	  }cout <<endl; 
	  */
	  cout << "Escaped in " << dungeon[curr.l][curr.r][curr.c] << " minute(s)." << endl;
	  return;
	}
      }

    }

    cout << "Trapped!" << endl;

  }

};

main(){

  Solver sol;

  while(sol.read()){
    sol.work();
  }

}
