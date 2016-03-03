#include<iostream>
#include<map>
using namespace std;

int main(){
  int n;
  while(cin >> n){
    map<int,int> factor; //(factor,cnt)
    for(int ii=2;ii<=n;ii++){
      int v = ii;
      for(int i=2;i*i<=v;i++)
        if(v%i==0){
          int cnt = 0;
          while(v%i==0){
            cnt++;
            v /= i;
          }
          factor[i] += cnt;
        }
      if(v>1) factor[v]++;
    }
    
    if(factor.count(5)) factor[2] -= factor[5];
    factor.erase(5);

    int ans = 1;
    for(map<int,int>::iterator i=factor.begin();i!=factor.end();i++)
      for(int j=0;j<i->second;j++)
        ans = ans*i->first%10;
    printf("%5d -> %d\n",n,ans);
  }
  return 0;
}
