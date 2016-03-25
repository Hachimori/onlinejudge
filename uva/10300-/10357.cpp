#include<iostream>
#include<stdio.h>

class Info_Player{
 public:

  int x,y,v;

  Info_Player(){}

  Info_Player(int tmp_x, int tmp_y, int tmp_v){
    x = tmp_x, y = tmp_y, v = tmp_v;
  }

};

class Info_Ball{
 public:

  int a,b,c,d,e,f,g;

  Info_Ball(){}

  Info_Ball(int tmp_a, int tmp_b, int tmp_c, int tmp_d, int tmp_e, int tmp_f, int tmp_g){
    a = tmp_a, b = tmp_b, c = tmp_c, d = tmp_d;
    e = tmp_e, f = tmp_f, g = tmp_g;
  }

};

int cases;
int time,drop_x,drop_y;
int num_player;
Info_Player list[30]; 
Info_Ball Ball;

void calculate_time(){
  
  for(time=1;;time++){
    if(Ball.a*time*time + Ball.b*time + Ball.c <=0 ) break;
  }

}

bool calculate_x_y(){

  drop_x = Ball.d*time + Ball.e;
  drop_y = Ball.f*time + Ball.g;

  if(drop_x<0 || drop_y<0) return false;
  else return true;

}

bool judge_safety(){

  for(int i=0;i<num_player;i++){

    //cout << int(sqrt( double((drop_x-list[i].x)*(drop_x-list[i].x)+(drop_y-list[i].y)*(drop_y-list[i].y)) )+0.5) << endl;
    //cout << list[i].v*time << endl;

    if( (drop_x-list[i].x)*(drop_x-list[i].x)+(drop_y-list[i].y)*(drop_y-list[i].y) <= (list[i].v*time)*(list[i].v*time) ) return false;
  }

  return true;

}

class Solver{
 public:

  bool read_player(){

    while(true){ 
      char c;
      if(scanf("%c",&c)==EOF) return false;
      if(c=='=') break; 
    }

    cin >> num_player;

    for(int i=0;i<num_player;i++){
      cin >> list[i].x >> list[i].y >> list[i].v;
    }

    return true;
  }

  void read_ball(){
    cin >> Ball.a >> Ball.b >> Ball.c >> Ball.d >> Ball.e >>  Ball.f >> Ball.g; 
  }

  void work(){

    calculate_time();
    
    if(calculate_x_y()==false){
      cout << "Ball " << cases << " was foul at (" << drop_x << "," << drop_y << ")" << endl;
      return;
    }
    
    if(judge_safety()==true){
      cout << "Ball " << cases << " was safe at (" << drop_x << "," << drop_y << ")" << endl;
      return;
    }
    else{
      cout << "Ball " << cases << " was caught at (" << drop_x << "," << drop_y << ")" << endl;
      return;
    }

  }

};

main(){
  
  Solver solver;
  int num_ball;

  for(cases=1;;){
    
    if(solver.read_player()==false) break;

    while(true){ 
      char c;
      if(scanf("%c",&c)==EOF) return false;
      if(c=='=') break; 
    }
    
    cin >> num_ball;
    
    for(int i=0;i<num_ball;i++,cases++){
      solver.read_ball();
      solver.work();
    }

  }

}
