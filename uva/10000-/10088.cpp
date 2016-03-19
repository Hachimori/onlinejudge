#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cassert>

#define MAX 1005

class Point{
 public:

  long long x, y;

  Point(){}
  Point(int x, int y) : x(x) , y(y){}

};

int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

int min(int a, int b){
  if(a<=b) return a;
  else return b;
}

int gcd(int a, int b){
  
  int t;

  while(a>0){
    
    if(b>a){
      t = a;
      a = b;
      b = t;
    }
    
    a-=b;
  }
  
  return b;
}

int between(Point a, Point b){

  int counter=0;
  int dx, dy;
  int div;

  if(b.x<a.x){
    Point tmp;
    tmp = a;
    a = b;
    b = tmp;
  }

  dx = b.x-a.x;
  dy = b.y-a.y;
   
  if(dy!=0 && dx!=0){ 
    div = gcd(dx,abs(dy));
    dx/=div , dy/=div;
  }
 
  if(dy==0 && dx==0) assert(false);
  else if(dy!=0 && dx!=0)
    for(int curr_x=a.x+dx;curr_x<b.x;curr_x+=dx){
      counter++;
    }
  else if(dy==0)
    for(int curr_x=a.x+1;curr_x<b.x;curr_x++){
      counter++;
    }
  else if(dx==0)
    for(int curr_y=min(a.y,b.y)+1;curr_y<max(a.y,b.y);curr_y++){
      counter++;
    }
  
  return counter;
}

double num_point;
double num_between;
Point P[MAX];


long double culcurate_area(){
  
  long double sum=0;

  for(int i=0;i<num_point;i++){
    if(i==0) sum+=P[(int)num_point-1].x*P[0].y-P[0].x*P[(int)num_point-1].y;
    else sum+=P[i-1].x*P[i].y-P[i].x*P[i-1].y;
  }
  //cout << sum << endl;
  return sum/2;
  
}

class Solver{
 public:

  bool read(){
    cin >> num_point;
    if(num_point==0) return false;

    num_between=0;

    for(int i=0;i<num_point;i++){
      cin >> P[i].x >> P[i].y;
      
      if(i==num_point-1){ 
	num_between+=between(P[i],P[0]);
	num_between+=between(P[i],P[i-1]);
      }
      else if(i>0) num_between+=between(P[i-1],P[i]);
    }
    
    return true;
  }

  void work(){
    
    long double area = culcurate_area();
    
    long double answer = area - ((num_point+num_between)/2-1) ;

    if(answer<0) cout << 0 << endl;
    else cout << answer << endl;
    
  }
  
};

int main(){

  Solver solver;

  while(true){
    if(solver.read()==false) break;
    solver.work();
  }

  return 0;
}
