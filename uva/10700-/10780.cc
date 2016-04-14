#include<iostream>
#include<vector>
using namespace std;
const int BUF = 10000;

int divider, factorial;

void read(){
  cin >> divider >> factorial;
}

void work(int cases){
  int factor[BUF] = {0};
  for(int i=2;i<=factorial;i++){
    int n = i;
    for(int j=2;j*j<=n;j++)
      while(n%j==0){
        n /= j;
        factor[j]++;
      }
    if(n>1) factor[n]++;
  }

  vector<pair<int,int> > divFactor; // (factor,cnt)
  for(int i=2;i*i<=divider;i++)
    if(divider%i==0){
      int cnt = 0;
      while(divider%i==0){
        cnt++;
        divider /= i;
      }
      divFactor.push_back(make_pair(i,cnt));
    }
  if(divider>1) divFactor.push_back(make_pair(divider,1));

  cout << "Case " << cases << ":" << endl;
  for(int ans=1;;ans++)
    for(int i=0;i<divFactor.size();i++)
      if(factor[divFactor[i].first]<divFactor[i].second*ans){
        if(ans==1)
          cout << "Impossible to divide" << endl;
        else
          cout << ans-1 << endl;
        return;
      }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
