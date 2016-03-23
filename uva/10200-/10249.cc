#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int GROUP = 75, SEAT = 55;


int nGroup, nSeat, nMan[GROUP], cap[SEAT];

bool read(){
  cin >> nGroup >> nSeat;
  if(nGroup==0 && nSeat==0) return false;
  for(int i=0;i<nGroup;i++) cin >> nMan[i];
  for(int i=0;i<nSeat;i++) cin >> cap[i];
  return true;
}


void work(){
  vector<int> s2g[SEAT],g2s[GROUP];

  for(int loop=0;loop<nGroup;loop++){
    int maxV = 0, maxGroup;
    for(int i=0;i<nGroup;i++)
      if(maxV<nMan[i]){
        maxV = nMan[i];
        maxGroup = i;
      }

    pair<int,int> cap_id[SEAT];
    for(int i=0;i<nSeat;i++) cap_id[i] = make_pair(cap[i]-s2g[i].size(),i);
    sort(cap_id,cap_id+nSeat,greater<pair<int,int> >());
    
    for(int i=0;i<nMan[maxGroup];i++){
      if(cap[cap_id[i].second]==s2g[cap_id[i].second].size()){
        cout << 0 << endl;
        return;
      }
      s2g[cap_id[i].second].push_back(maxGroup);
      g2s[maxGroup].push_back(cap_id[i].second);
    }

    nMan[maxGroup] = 0;
  }

  cout << 1 << endl;
  for(int i=0;i<nGroup;i++){
    for(int j=0;j<g2s[i].size();j++){
      if(j) cout << ' ';
      cout << g2s[i][j]+1;
    }
    cout << endl;
  }
}


int main(){
  while(read()) work();
  return 0;
}
