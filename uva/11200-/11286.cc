#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  while(1){
    int nVec;
    cin >> nVec;
    if(nVec==0) break;
    
    map<vector<int>,int> M;
    for(int i=0;i<nVec;i++){
      vector<int> toPush;
      for(int j=0;j<5;j++){
        int v;
        cin >> v;
        toPush.push_back(v);
      }
      sort(toPush.begin(),toPush.end());
      M[toPush]++;
    }

    int maxV = 0, cnt = 0;
    for(map<vector<int>,int>::iterator i=M.begin();i!=M.end();i++)
      if(maxV<i->second){
        cnt = i->second;
        maxV = i->second;
      }
      else if(maxV==i->second)
        cnt += i->second;
    cout << cnt << endl;
  }
  return 0;
}
