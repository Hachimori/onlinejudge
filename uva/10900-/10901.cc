#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#define CAR 10005
#define LEFT 0
#define RIGHT 1
using namespace std;

class Event{
public:
  int time, pos, id;
  
  bool operator< (const Event &e) const {
    return time>e.time;
  }
};

int nEvent, cap, cost;
Event event[CAR];

void read(){
  cin >> cap >> cost >> nEvent;
  
  for(int i=0;i<nEvent;i++){
    string s;
    cin >> event[i].time >> s;
    event[i].id = i;
    if(s=="left") event[i].pos = LEFT;
    else event[i].pos = RIGHT;
  }
}

void work(){
  priority_queue<Event> Q;
  queue<int> waiting[2];
  int time = 0, pos = LEFT, arrive[CAR];
  
  for(int i=0;i<nEvent;i++)
    Q.push(event[i]);
  
  while(!Q.empty() || !waiting[0].empty() || !waiting[1].empty()){
    while(!Q.empty() && time>=Q.top().time){
      Event curr = Q.top();
      Q.pop();
      waiting[curr.pos].push(curr.id);
    }
    
    if(waiting[pos].empty() && waiting[!pos].empty()){
      time = Q.top().time;
      continue;
    }
    if(waiting[pos].empty() && !waiting[!pos].empty()){
      time += cost;
      pos = !pos;
      continue;
    }

    for(int i=0;i<cap && !waiting[pos].empty();i++){
      int car = waiting[pos].front();
      waiting[pos].pop();
      arrive[car] = time+cost;
    }
    time += cost;
    pos = !pos;
  }
  
  for(int i=0;i<nEvent;i++)
    cout << arrive[i] << endl;
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
