#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int BUF = 7005;

int n;

bool read(){
  cin >> n;
  return n>0;
}


long long gcd(long long a, long long b){
  return b==0 ? a : gcd(b,a%b);
}


long long lcm(long long a, long long b){
  return a/gcd(a,b)*b;
}


void work(){
  queue<int> Q;
  stack<int> minute, fiveMin, hour;
  
  for(int i=0;i<n;i++) Q.push(i);

  for(int loop=0;loop<24*60;loop++){
    int cur = Q.front();
    Q.pop();

    if(minute.size()==4){
      for(int i=0;i<4;i++){
        Q.push(minute.top());
        minute.pop();
      }
      if(fiveMin.size()==11){
        for(int i=0;i<11;i++){
          Q.push(fiveMin.top());
          fiveMin.pop();
        }
        if(hour.size()==11){
          for(int i=0;i<11;i++){
            Q.push(hour.top());
            hour.pop();
          }
          Q.push(cur);
        }
        else
          hour.push(cur);
      }
      else
        fiveMin.push(cur);
    }
    else
      minute.push(cur);
  }
  
  int idx = 0, pre[BUF];
  while(!Q.empty()){ pre[idx++] = Q.front(); Q.pop(); }
  while(!minute.empty()){ pre[idx++] = minute.top(); minute.pop(); }
  while(!fiveMin.empty()){ pre[idx++] = fiveMin.top(); fiveMin.pop(); }
  while(!hour.empty()){ pre[idx++] = hour.top(); hour.pop(); }
  
  long long ans = 1;
  for(int i=0;i<n;i++){
    int nCycle = 1;
    for(int cur=pre[i];cur!=i;nCycle++,cur=pre[cur]);
    ans = lcm(ans,nCycle);
  }

  cout << n << " balls cycle after " << ans << " days." << endl;
}


int main(){
  while(read()) work();
  return 0;
}
