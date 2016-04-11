#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#define BUF 1005
#define ENTER 0
#define LEAVE 1
using namespace std;

class Event{
public:
  int type, curOffice, time, id, wait;

  Event(){}
  Event(int ty, int c, int ti, int i, int w):
    type(ty), curOffice(c), time(ti), id(i), wait(w){}

  bool operator< (const Event &e) const {
    if(time!=e.time) return time>e.time;
    if(type!=e.type) return type==ENTER;

    if(type==ENTER){
      if(wait!=e.wait) return wait<e.wait; // êÊÇ…ë“Ç¡ÇƒÇ¢ÇΩÇŸÇ§ÇóDêÊ
      return id>e.id;                      // idÇ™è¨Ç≥Ç¢ÇŸÇ§ÇóDêÊ
    }
    else
      return true;                         // ãéÇÈéûÇÕÇ«ÇÍÇêÊÇ…ÇµÇƒÇ‡ó«Ç¢
  }
};

int nMan, nBuild, enter[BUF];
vector<int> toVisit[BUF];

void read(){
  for(int i=0;i<BUF;i++) toVisit[i].clear();
  
  scanf("%d%d",&nMan,&nBuild);
  
  for(int i=0;i<nMan;i++){
    int nVisit;
    scanf("%d%d",&enter[i],&nVisit);
    for(int j=0;j<nVisit;j++){
      int num; scanf("%d",&num);
      toVisit[i].push_back(num-1);
    }
  }
}

void work(){
  int lastTime;
  queue<int> waitMan[BUF];
  priority_queue<Event> Q;
  
  for(int i=0;i<nMan;i++)
    Q.push(Event(ENTER,0,enter[i],i,0));

  while(!Q.empty()){
    Event e = Q.top();
    Q.pop();
    
    lastTime = e.time;
    
    if(e.type==ENTER){
      if(waitMan[toVisit[e.id][e.curOffice]].size()>0 &&
         waitMan[toVisit[e.id][e.curOffice]].front()!=e.id){
        if(e.wait==0)
         waitMan[toVisit[e.id][e.curOffice]].push(e.id);
        
        e.time += waitMan[toVisit[e.id][e.curOffice]].size()-1;
        e.wait += waitMan[toVisit[e.id][e.curOffice]].size()-1;
        Q.push(e);
      }
      else {
        if(e.wait==0) waitMan[toVisit[e.id][e.curOffice]].push(e.id);
        e.type = LEAVE;
        e.time++;
        Q.push(e);
      }
    }
    else {
      waitMan[toVisit[e.id][e.curOffice]].pop();
      if(e.curOffice+1<toVisit[e.id].size()){
        e.type = ENTER;
        e.curOffice++;
        e.wait = 0;
        Q.push(e);
      }
    }
  }

  cout << lastTime << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
