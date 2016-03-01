#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

vector<int> ansList;

void rec(int nVisited, int idx, int leng, string &cur, bool used[10], bool visited[10]){
  if(nVisited==leng){
    ansList.push_back(atoi(cur.c_str()));
    return;
  }
  visited[idx] = true;
  for(int mov=1;mov<=9;mov++){
    if(used[mov]) continue;
    if(!((nVisited==leng-1 && (idx+mov)%leng==0) || !visited[(idx+mov)%leng])) continue;
    used[mov] = true;
    cur[idx] = mov+'0';
    rec(nVisited+1,(idx+mov)%leng,leng,cur,used,visited);
    used[mov] = false;
  }
  visited[idx] = false;
}


void makeTable(){
  for(int leng=1;leng<=8;leng++){
    bool used[10]={}, visited[10]={};
    string cur = string(leng,'0');
    rec(0,0,leng,cur,used,visited);
  }
  sort(ansList.begin(),ansList.end());
}


int n;

bool read(){
  cin >> n;
  return n!=0;
}


void work(int cases){
  cout << "Case " << cases << ": " << *upper_bound(ansList.begin(),ansList.end(),n) << endl;
}


int main(){
  makeTable();
  for(int i=0;read();i++) work(i+1);
  return 0;
}
