#include<iostream>
#include<queue>
#include<algorithm>
#define BUF 400000
using namespace std;

int nNum, num[9];

int v2id(int v[]){
  int ret = 0;

  for(int i=0;i<nNum;i++){
    int sum = 1, cnt = 0;
    for(int j=i+1,p=1;j<nNum;j++,p++){
      sum *= p;
      if(v[i]>v[j]) cnt++;
    }
    ret += cnt*sum;
  }
    
  return ret;
}

void id2v(int id, int ret[]){
  bool used[10];
  for(int i=0;i<=nNum;i++) used[i] = false;
  
  for(int i=0;i<nNum;i++){
    int sum = 1;
    for(int j=i+1,p=1;j<nNum;j++,p++)
      sum *= p;
    
    ret[i] = 1;
    for(int j=0;j<nNum;j++){
      while(used[ret[i]]) ret[i]++;
      if(id-sum>=0){
        id -= sum;
        ret[i]++;
      }
    }
    while(used[ret[i]]) ret[i]++;

    used[ret[i]] = true;
  }
}

bool read(){
  cin >> nNum;
  if(nNum==0) return false;

  for(int i=0;i<nNum;i++)
    cin >> num[i];

  return true;
}

int bfs(int init[], int M[], int GM[], int limit){
  queue<int> Q;
  
  M[v2id(init)] = 0;
  Q.push(v2id(init));
  
  while(!Q.empty()){
    int id = Q.front();
    Q.pop();
    
    int curr[9];
    id2v(id,curr);
    
    if(M[id]==limit) continue;
    if(GM[id]!=-1) return M[id]+GM[id];
    
    for(int i=0;i<nNum;i++)
      for(int j=i;j<nNum;j++){
        int toBePut[9], toPut[9];

        for(int k=0,idx=0;k<nNum;k++)
          if(k<i || j<k)
            toBePut[idx++] = curr[k];
        
        for(int k=0;k<=j-i;k++)
          toPut[k] = curr[i+k];
        
        for(int k=0;k<=nNum-(j-i+1);k++){
          int next[9], idx = 0;
          
          for(int l=0;l<k;l++)
            next[idx++] = toBePut[l];
          
          for(int l=0;l<=j-i;l++)
            next[idx++] = toPut[l];

          for(int l=k;l<nNum-(j-i+1);l++)
            next[idx++] = toBePut[l];
          
          if(M[v2id(next)]==-1){
            Q.push(v2id(next));
            M[v2id(next)] = M[id]+1;
          }
        }
      }
  }
  
  return -1;
}

void work(int cases){
  static int self[BUF], opp[BUF], oppInit[9];
  
  for(int i=0;i<BUF;i++)
    self[i] = opp[i] = -1;
  
  for(int i=0;i<nNum;i++)
    oppInit[i] = i+1;
  
  bfs(oppInit,opp,self,3);
  
  cout << "Case " << cases << ": " << bfs(num,self,opp,100) << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
