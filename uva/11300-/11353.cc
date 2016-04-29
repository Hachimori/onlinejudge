#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 2000001;

int main(){
  static pair<int,int> val[BUF];
  val[0] = make_pair(0,0);
  val[1] = make_pair(0,1);
  for(int i=2;i<BUF;i++){
    int v = i, cnt = 0;
    for(int p=2;p*p<=v;p++)
      while(v%p==0){
        v /= p;
        cnt++;
      }
    if(v>1) cnt++;
    val[i] = make_pair(cnt,i);
  }
  sort(val,val+BUF);

  for(int i=0,n;cin>>n,n;i++)
    cout << "Case " << i+1 << ": " << val[n].second << endl;

  return 0;
}
