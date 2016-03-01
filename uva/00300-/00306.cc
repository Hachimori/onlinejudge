#include<iostream>
using namespace std;
const int MOV = 205, QUERY = 100000;

struct Query{
  int nRot;
  string str;
};

int nMov, mov[MOV], nQuery;
Query query[QUERY];

bool read(){
  cin >> nMov;
  if(nMov==0) return false;
  for(int i=0;i<nMov;i++){
    cin >> mov[i];
    mov[i]--;
  }
  nQuery = 0;
  while(1){
    Query &q = query[nQuery];
    cin >> q.nRot;
    if(q.nRot==0) break;
    getline(cin,q.str);
    q.str.erase(q.str.begin());
    nQuery++;
  }
  return true;
}

int movOpe(int idx, int nRot){
  int visited[MOV], curIdx = idx;
  memset(visited,-1,sizeof(visited));
  for(int i=0;i<nRot;i++){
    if(visited[curIdx]!=-1){
      int cycle = i-visited[curIdx];
      for(int j=0;j<nRot%cycle;j++) curIdx = mov[curIdx];
      break;
    }
    visited[curIdx] = i;
    curIdx = mov[curIdx];
  }
  return curIdx;
}

void work(){
  for(int loop=0;loop<nQuery;loop++){
    Query &q = query[loop];
    q.str += string(nMov-q.str.size(),' ');
    string ans = string(nMov,'#');
    for(int idx=0;idx<nMov;idx++){
      int dst = movOpe(idx,q.nRot);
      ans[dst] = q.str[idx];
    }
    cout << ans << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    work();
    cout << endl;
  }
  return 0;
}
