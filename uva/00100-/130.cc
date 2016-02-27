#include<iostream>
#include<algorithm>
#define BUF 105
using namespace std;

int nMan, K;

bool read(){
  cin >> nMan >> K;
  return !(nMan==0 && K==0);
}

void work(){
  for(int init=0;init<nMan;init++){
    int id[BUF];
    bool killed[BUF];
    for(int i=0;i<nMan;i++){
      id[i] = i;
      killed[i] = false;
    }

    int cur = init-1;
    
    for(int k=0;k<nMan-1;k++){
      for(int cnt=0;cnt<K;){
        cur=(cur+1)%nMan;
        if(!killed[cur]) cnt++;
      }
      killed[cur] = true;

      int nex = cur;
      for(int cnt=0;cnt<K;){
        nex=(nex+1)%nMan;
        if(!killed[nex]) cnt++;
      }
    
      swap(id[nex],id[cur]);
      swap(killed[nex],killed[cur]);
    }

    for(int i=0;i<nMan;i++)
      if(!killed[i] && id[i]==0){
        cout << init+1 << endl;
        return;
      }
  }
}

int main(){
  while(read())
    work();

  return 0;
}
