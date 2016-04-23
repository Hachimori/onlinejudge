#include<iostream>
#include<queue>
#include<cassert>
#define FINISHEAT 0
#define QUESTION 1
#define BUF 10000
#define EPS (1.0e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
#define LE(x,y) (LT(x,y) || EQ(x,y))
using namespace std;

class Event{
public:
  int type, toAdd;
  double time;

  Event(int type, int toAdd, double time): type(type), toAdd(toAdd), time(time){}
  
  bool operator< (const Event &e) const {
    if(EQ(time,e.time)) return type>e.type;
    return time>e.time;
  }
};

int rateD, rateL, nFood, nQuestion;
int food[BUF][2], question[BUF];

void read(){
  cin >> rateD >> rateL >> nFood >> nQuestion;
  assert(nFood<BUF && nQuestion<BUF);
  
  for(int i=0;i<nFood;i++)
    cin >> food[i][0] >> food[i][1];
  
  for(int i=0;i<nQuestion;i++)
    cin >> question[i];
}

void work(){
  priority_queue<Event> Q;
  double curr = 0;
  
  for(int i=0;i<nQuestion;i++)
    Q.push(Event(QUESTION,-1,question[i]));

  for(int i=0;i<nFood;i++){
    curr+=1.0*food[i][1]/rateD;
    Q.push(Event(FINISHEAT,food[i][0]-food[i][1],curr));
  }
  
  
  double remain = 0;
  curr = 0;
  while(!Q.empty()){
    Event event = Q.top();
    Q.pop();
    
    remain -= (event.time-curr)*rateL;
    
    if(event.type==FINISHEAT){
      if(LE(remain,0)) remain = 0;
      remain += event.toAdd;
    }

    if(event.type==QUESTION){
      if(LT(remain,0)){
	cout << "clear" << endl;
      }
      else
	cout << "full" << endl;
    }

    curr = event.time;
  }
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
