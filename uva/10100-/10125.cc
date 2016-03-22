#include<iostream>
#include<map>
#define a first
#define b second
using namespace std;
typedef pair<int,int> ii;
const int BUF = 1005, INF = 1<<30;

int nVal, val[BUF];

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  return true;
}

void work(){
  multimap<int,ii> data;
  for(int i=0;i<nVal;i++)
    for(int j=i+1;j<nVal;j++)
      data.insert(make_pair(val[i]+val[j],ii(val[i],val[j])));

  int maxV = -INF;
  for(int i=0;i<nVal;i++)
    for(int j=0;j<nVal;j++){
      if(i==j) continue;
      multimap<int,ii>::iterator lo, hi;
      lo = data.lower_bound(val[i]-val[j]);
      hi = data.upper_bound(val[i]-val[j]);
      for(multimap<int,ii>::iterator k=lo;k!=hi;k++)
        if(k->second.a!=val[i] && k->second.b!=val[i] &&
           k->second.a!=val[j] && k->second.b!=val[j])
          maxV = max(maxV,val[i]);
    }

  if(maxV==-INF)
    cout << "no solution" << endl;
  else
    cout << maxV << endl;
}

int main(){
  while(read()) work();
  return 0;
}
