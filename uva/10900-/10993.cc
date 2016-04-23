#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define BUF 100005
#define INF (1<<25)
using namespace std;

class Pi{
public:
  int mul, prev;

  Pi(){}
  Pi(int mul, int prev): mul(mul), prev(prev){}
};

bool avail[10];
int num;

bool read(){
  string s;
  cin >> s >> num;
  if(s=="0" && num==0) return false;
  
  for(int i=0;i<10;i++)
    avail[i] = false;

  for(int i=0;i<s.size();i++)
    avail[s[i]-'0'] = true;
  
  return true;
}

bool bfs(int mul[]){
  static vector<Pi> pi[BUF];
  static int cost[BUF];
  queue<int> Q;

  for(int i=0;i<num;i++){
    pi[i].clear();
    cost[i] = INF;
  }

  for(int i=0;i<=9;i++)
    if(avail[(num*i)%10] && i!=0){
      int next = (num*i)/10;
      if(next==0){
	pi[next].push_back(Pi(i,0));
	break;
      }
      else {
	pi[next].push_back(Pi(i,0));
	cost[next] = 0;
	Q.push(next);
      }
    }
  
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    for(int i=0;i<=9;i++){
      if(!avail[(curr+num*i)%10]) continue;
      int next = (curr+num*i)/10;
      
      if(cost[next]>cost[curr]+1){
	pi[next].push_back(Pi(i,curr));
	cost[next] = cost[curr]+1;
	Q.push(next);
      }
      else if(cost[next]==cost[curr]+1)
	pi[next].push_back(Pi(i,curr));
    }
  }

  if(pi[0].size()==0) return false;
  
  int idx = 0;
  for(int cur=0;;){
    int minV = INF, minMul;
    for(int i=0;i<pi[cur].size();i++)
      if(minV>pi[cur][i].prev){
	minV = pi[cur][i].prev;
	minMul = pi[cur][i].mul;
      }

    mul[idx++] = minMul;
    if(minV==0) break;
    cur = minV;
  }
  reverse(mul,mul+idx);
  
  return true;
}

void work(){
  int mul[BUF];
  
  if(!bfs(mul)) 
    cout << "impossible" << endl;
  else{
    int ans[BUF];
    for(int i=0;i<BUF;i++) ans[i] = -1;
    ans[0] = 0;
    
    int cur = 0;
    for(;;cur++){
      ans[cur] += num*mul[cur];
      if(ans[cur]>10) ans[cur+1] = ans[cur]/10;
      else break;
      ans[cur] %= 10;
    }

    while(cur>=0) cout << ans[cur--];
    cout << endl;
  }
}

int main(){
  while(read())
    work();

  return 0;
}
