#include<iostream>
#include<vector>
using namespace std;

int fact, divide;

bool read(){
  return cin >> fact >> divide;
}

void work(){
  vector< pair<int,int> > factor; //(factor,pow)
  int n = divide;
  for(int i=2;i*i<=n;i++)
    if(n%i==0){
      int cnt = 0;
      while(n%i==0){
        n /= i;
        cnt++;
      }
      factor.push_back(make_pair(i,cnt));
    }
  if(n>1) factor.push_back(make_pair(n,1));
  
  for(int i=0;i<factor.size();i++){
    long long cnt = 0;
    for(long long v=factor[i].first;v<=fact;cnt+=fact/v,v*=factor[i].first);
    if(cnt<factor[i].second){
      cout << divide << " does not divide " << fact << '!' << endl;
      return;
    }
  }
  cout << divide << " divides " << fact << '!' << endl;
}

int main(){
  while(read()) work();
  return 0;
}
