#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#define BUF 26
using namespace std;

int in[BUF], cost[BUF];
bool adj[BUF][BUF];

void read(){
  for(int i=0;i<BUF;i++){
    cost[i] = in[i] = 0;
    for(int j=0;j<BUF;j++)
      adj[i][j] = false;
  }
  
  while(true){
    string str; getline(cin,str);
    if(str.empty()) break;

    stringstream sin(str);
    char dst, src;
    sin >> dst;
    sin >> cost[dst-'A'];
    while(sin>>src){
      adj[src-'A'][dst-'A'] = true;
      in[dst-'A']++;
    }
  }
}

void work(){
  int maxV[BUF];
  bool finish[BUF];
  for(int i=0;i<BUF;i++){
    maxV[i] = 0;
    finish[i] = false;
  }
  
  for(int loop=0;loop<BUF;loop++)
    for(int i=0;i<BUF;i++){
      int curr = i;
      if(in[curr]!=0 || finish[curr]) continue;
      finish[curr] = true;
      for(int j=0;j<BUF;j++){
        if(!adj[curr][j]) continue;
        maxV[j] = max(maxV[j],maxV[curr]+cost[curr]);
        in[j]--;
      }
    }
  for(int i=0;i<BUF;i++)
    maxV[i] += cost[i];
  
  cout << *max_element(maxV,maxV+BUF) << endl;
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
