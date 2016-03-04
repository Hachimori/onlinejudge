#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>

#define INF 10000
#define MAX_SIZE 20

using namespace std;

class Car{
public:

  int origin, currPos, parkedPos;
  
  Car(){}
  Car(int o, int c, int p ): origin(o), currPos(c), parkedPos(p){}
};

vector<Car> car;
vector<int> move;

void read(){
  
  car.clear();
  move.clear();
  
  while(true){
    int n;
    cin >> n;
    if(n==99) break;
    
    n--;
    
    car.push_back(Car(n,n,-1));
  }
  
  string buf; getline(cin,buf);
  
  while(true){
    if(getline(cin,buf)==NULL) break;
    
    int n;
    istringstream is;

    is.str(buf);
    
    if(!(is >> n)) break;
    n--;
    
    move.push_back(n);
  }
}

void work(){
  for(int i=0;i<move.size();i++){
    int minMove=INF, moveCar;
    for(int j=0;j<car.size();j++){
      int toMove;
      
      if(car[j].parkedPos!=-1) continue;
      if(move[i]<car[j].currPos) toMove = move[i]+MAX_SIZE-car[j].currPos;
      else toMove = move[i]-car[j].currPos;

      if(minMove>toMove){
	minMove = toMove;
	moveCar = j;
      }
    }
    
    for(int j=0;j<car.size();j++){
      if(car[j].parkedPos!=-1) continue;
      if(j==moveCar){
	car[j].parkedPos = move[i];
	continue;
      }
      car[j].currPos = (car[j].currPos+minMove)%MAX_SIZE;
    }
  }
  
  for(int i=0;i<car.size();i++){
    if(car[i].parkedPos!=-1)
      cout << "Original position " << car[i].origin+1 
	   << " parked in " << car[i].parkedPos+1  << endl;
    else
      cout << "Original position " << car[i].origin+1 
	   << " did not park" << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
