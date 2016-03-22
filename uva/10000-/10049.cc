#include<iostream>
#include<vector>
using namespace std;
const int BUF = 1000000, LIMIT = 2000000000;

int main(){
  static int n2fn[BUF];
  n2fn[1] = 1;
  n2fn[2] = 2;
  for(int n=2,idx=2;n<BUF;idx++){
    int loop = n2fn[idx];
    for(int i=0;i<loop && n<BUF;i++)
      n2fn[n++] = idx;
  }

  vector< pair<int,long long> > vv; //(n, max idx of fn);
  for(long long n=1,sum=1;;){
    vv.push_back(make_pair(n,sum));
    if(sum>LIMIT) break;
    n++;
    sum += n2fn[n];
  }
  
  int n;
  while(cin >> n,n){
    if(n==1){
      cout << 1 << endl;
      continue;
    }
    int idx = 0;
    while(vv[idx].second<n) idx++;
    cout << idx+1 << endl;
  }

  return 0;
}
