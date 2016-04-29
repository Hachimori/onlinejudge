// 点が縦に一直線に並んだ場合 O(n^2) となり、TLEとなるが、
// そのようなケースは無い模様

#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 100005;

int main(){
  int n;
  while(cin >> n){
    pair<int,int> pt[BUF];
    for(int i=0;i<n;i++) cin >> pt[i].first >> pt[i].second;
    sort(pt,pt+n);

    int minV = 1<<30;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
        if(pt[j].first-pt[i].first>=minV) break;
        minV = min(minV,max(abs(pt[i].first-pt[j].first),abs(pt[i].second-pt[j].second)));
      }
    cout << minV << endl;
  }
  return 0;
}
