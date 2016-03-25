#include<iostream>
#include<limits.h>

#define MAX 1025
#define MAX_point 20001

class Point{
 public:

  int x,y;

};

int d;
int max,max_y,max_x;
int matrix[MAX][MAX];
Point point[MAX_point];
Point left_up,right_low;

void smaller_check(int sum){

  if(max<sum){
    max = sum;
    max_y = right_low.y-d;
    max_x = right_low.x-d;
  }
  else if(max==sum){
    if(max_y>right_low.y-d){
      max_y = right_low.y-d;
      max_x = right_low.x-d;
    }
    else if(max_y==right_low.y-d && max_x>right_low.x-d){
      max_y = right_low.y-d;
      max_x = right_low.x-d;
    }      
  }
  
}

void define_points(Point point[MAX] , int i){
  
  if(point[i].x-d*2 < 0) left_up.x = 0;
  else left_up.x = point[i].x-d*2;
  
  if(point[i].y-d*2 < 0) left_up.y = 0;
  else left_up.y = point[i].y-d*2;

  if(point[i].x-d < 0) right_low.x = d;
  else right_low.x = point[i].x;

  if(point[i].y-d < 0) right_low.y = d;
  else right_low.y = point[i].y;
  

}

class Solver{
 public:


  void read_work(){

    int num_group;

    cin >> d;

    cin >> num_group;

    max = 0,max_y=INT_MAX,max_x=INT_MAX;
    

    for(int i=0;i<num_group;i++){
      int x,y,num_rat;
      cin >> y >> x >> num_rat;
      matrix[y][x] = num_rat;
      point[i].y = y;
      point[i].x = x;
    }


    

    for(int i=0;i<num_group;i++){
      
      define_points(point,i);
      
      //cout << "left_up.x = " << left_up.x << "   left_up.y = " << left_up.y << endl;
      //cout << "right_low.x = " << right_low.x << "   right_low.y = " << right_low.y << endl;
      
      int sum=0;

      for(int j=left_up.y;j<=right_low.y;j++){
	for(int k=left_up.x;k<=right_low.x;k++){
	  sum+=matrix[j][k];
	}
      }

      smaller_check(sum);
      
      for(int l=1;l<=d*2;l++){

	for(int j=left_up.y,k=left_up.x;k<=right_low.x;k++) sum-=matrix[j][k];
	left_up.y++;
	if(left_up.y>1024) break;
	right_low.y++;
	if(right_low.y>1024) break;
	for(int j=right_low.y,k=left_up.x;k<=right_low.x;k++) sum+=matrix[j][k];
	smaller_check(sum);
	
	//cout << "sum = " << sum  << endl; 
	//cout << "left_up.x = " << left_up.x << "   left_up.y = " << left_up.y << endl;
	//cout << "right_low.x = " << right_low.x << "   right_low.y = " << right_low.y << endl;
      }

    }

    cout << max_y << ' ' << max_x << ' ' << max << endl; 

    for(int i=0;i<num_group;i++)
      matrix[point[i].y][point[i].x]=0;

  }

};

main(){
  
  int cases;
  Solver solver;

  
  cin >> cases;

  for(int i=0;i<cases;i++){

    solver.read_work();

  }

}
