#include<iostream>
#include<vector>
#include<algorithm>
#define A first
#define B second
#define QUERY 10005
#define BUF 100001
using namespace std;
typedef pair<int,int> Pair;

int K, nQuery;
int a[QUERY], b[QUERY];

void read(){
  cin >> K >> nQuery;

  for(int i=0;i<nQuery;i++){
    cin >> a[i] >> b[i];
    if(a[i]>b[i]) swap(a[i],b[i]);
  }
}

void work(){
  vector<Pair> lose;

  bool losing[BUF];
  for(int i=0;i<BUF;i++) losing[i] = false;
    
  losing[K+2] = true;
  lose.push_back(Pair(1,K+2));
  
  for(int aIt=2;;aIt++)
    if(losing[aIt]) continue;
    else {
      Pair last = lose.back();
      int bIt = (aIt-last.A)+K+1+last.B;
      if(bIt>=BUF) break;
      losing[bIt] = true;
      lose.push_back(Pair(aIt,bIt));
    }
  
  for(int i=0;i<nQuery;i++){
    vector<Pair>::iterator pos = lower_bound(lose.begin(),lose.end(),Pair(a[i],b[i]));

    if(*pos==Pair(a[i],b[i]))
      cout << "LOSING" << endl;
    else
      cout << "WINNING" << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
    cout << endl;
  }
  
  return 0;
}
