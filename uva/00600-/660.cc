#include<iostream>
#include<queue>
#include<cstdio>
#define INF (1<<20)
#define ROBO 25
#define TASK 10000
#define DONE 0
#define REQUEST 1
using namespace std;

class Robo{
public:
  bool isIdle;
  int cap, pos, workTime;
  
  Robo(){}
  Robo(int cap): isIdle(true), cap(cap), pos(0), workTime(0){}
};

class Task{
public:
  int time, src, dst, weight, timeTook;
};

int size, nRobo, nTask;
Robo robo[ROBO];
Task task[TASK];

class Event{
public:
  // type -> DONE: 0, REQUEST: 1    同時刻の時はDONEを優先する
  int type;

  // typeがDONEの時、ロボットのID
  // typeがREQUESTの時、タスクのID
  int id;   

  int time;

  Event(){}
  Event(int type, int id, int time): type(type), id(id), time(time){}

  bool operator< (const Event &e) const {
    if(time==e.time){
      if(type==REQUEST && e.type==REQUEST)
        return task[id].time>task[e.id].time;
      return type>e.type;
    }
    return time>e.time;
  }
};

bool read(){
  cin >> size >> nRobo;
  if(size==0 && nRobo==0) return false;

  for(int i=0;i<nRobo;i++){
    int cap;
    cin >> cap;
    robo[i] = Robo(cap);
  }
  
  nTask = 0;
  for(int i=0;;i++){
    cin >> task[i].time >> task[i].src >> task[i].dst >> task[i].weight;
    if(task[i].time==-1 && task[i].src==-1 && 
       task[i].dst==-1 && task[i].weight==-1) break;
    task[i].src--;
    task[i].dst--;
    nTask++;
  }
    
  return true;
}

void work(int cases){
  priority_queue<Event> Q;

  for(int i=0;i<nTask;i++)
    Q.push(Event(REQUEST,i,task[i].time));

  int bgn = Q.top().time, end;

  while(!Q.empty()){
    Event e = Q.top();
    Q.pop();

    
    end = e.time;
    
    if(e.type==REQUEST){
      Task &t = task[e.id];
      int minDist = INF, minRobo;
      for(int i=0;i<nRobo;i++)
        if(robo[i].isIdle && robo[i].cap>=t.weight && 
           minDist>(size+t.src-robo[i].pos)%size){
          minDist = (size+t.src-robo[i].pos)%size;
          minRobo = i;
        }
      
      if(minDist==INF){
        Q.push(Event(REQUEST,e.id,e.time+1));
        continue;
      }
      
      t.timeTook = e.time-t.time+10+minDist+(size+t.dst-t.src)%size;
      robo[minRobo].workTime += 10+minDist+(size+t.dst-t.src)%size;
      robo[minRobo].isIdle = false;
      robo[minRobo].pos = t.dst;
    
      Q.push(Event(DONE,minRobo,e.time+10+minDist+(size+t.dst-t.src)%size));
    }
    else
      robo[e.id].isIdle = true;
  }
  
  double aveTime = 0, aveUtil = 0;
  for(int i=0;i<nTask;i++)
    aveTime += task[i].timeTook;

  for(int i=0;i<nRobo;i++)
    aveUtil += robo[i].workTime;

  cout << "Simulation " << cases << endl;
  printf("Average wait time   = %.3lf minutes\n",aveTime/nTask);
  printf("Average utilization = %.3lf %%\n",aveUtil/nRobo/(end-bgn)*100);
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }

  return 0;
}
