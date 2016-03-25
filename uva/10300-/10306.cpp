#include<iostream>
#include<algorithm>
#include<math.h>

#define MAX 41

double absDouble(double num){

  if(num<0) return num*(-1);
  else return num;

}

class InfoCoin{

 public:

  int y,x;

  bool operator< ( InfoCoin const &ic ) const {
    if(sqrt(x*x + y*y) > sqrt(ic.x*ic.x + ic.y*ic.y)) return true;
    else return false;
  }

};

int num_coin,S;
InfoCoin coinList[MAX];

int Search_rec(int arg_coin, int curr_x, int curr_y, int curr_num_coin){

  double distance = sqrt(curr_x*curr_x + curr_y*curr_y); 

  if( absDouble(S - distance) < 0.00001 ){
    return curr_num_coin;
  }
  else if(distance > S) return false;
  
  for(int i=arg_coin;i<num_coin;i++){
    int check;
    
    if( (check=Search_rec(i,curr_x+coinList[i].x,curr_y+coinList[i].y,curr_num_coin+1) ) != false) return check;
    
  }

  return false;

}

class Solver{

 public:

  void read(){

    cin >> num_coin >> S;

    
    for(int i=0;i<num_coin;i++){
      
      int tmp_x,tmp_y;
      cin >> tmp_x >> tmp_y;

      coinList[i].x = tmp_x, coinList[i].y = tmp_y;
    }
  
  }

  void work(){
    
    int answer;

    sort(&coinList[0],&coinList[num_coin]);

    for(int i=0;i<num_coin;i++)
      if( (answer = Search_rec(i,0,0,0) ) != false ) break;

    if(answer!=false) cout << answer << endl;
    else cout << "not possible" << endl;

  }

};

main(){

  int cases;
  Solver solver;

  cin >> cases;

  for(int i=0;i<cases;i++){
    solver.read();
    solver.work();
  }

}
