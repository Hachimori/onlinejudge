#include<iostream>
#include<map>
#include<queue>
#define PRIME 20
#define BUF 8
using namespace std;

bool isPrime[PRIME];

void makeTable(){
  for(int i=0;i<PRIME;i++) isPrime[i] = true;

  for(int i=2;i*i<PRIME;i++)
    if(isPrime[i])
      for(int j=i*2;j<PRIME;j+=i)
	isPrime[j] = false;
}

int init[BUF];
bool isMale[9];

bool read(){
  for(int i=0;i<BUF;i++){
    cin >> init[i];
    if(init[i]==0) return false;
    isMale[abs(init[i])] = (init[i]>0);
  }
  return true;
}

int toInt(int a[BUF]){
  int ret = 0;
  for(int i=0;i<BUF;i++){
    ret *= 10;
    ret += abs(a[i]);
  }
  return ret;
}

void toArray(int num, int a[BUF]){
  for(int i=BUF-1;i>=0;i--){
    a[i] = num%10;
    num /= 10;
  }
}

void insert(int src, int dst, int array[BUF]){
  if(src<dst)
    for(int i=src;i+1<dst;i++) swap(array[i],array[i+1]);
  else
    for(int i=src;i-1>=dst;i--) swap(array[i],array[i-1]);
}

int bfs(){
  map<int,int> visited;
  queue<int> Q;
  
  visited[toInt(init)] = 0;
  Q.push(toInt(init));
  
  if(toInt(init)==12345678) return 0;
  
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();

    int curCost = visited[curr];
    int curArray[BUF];
    toArray(curr,curArray);

    for(int i=0;i<BUF;i++)
      for(int j=0;j<BUF;j++){
	if(i==j || i+1==j) continue;

	bool ok = false;
	if(isPrime[curArray[i]+curArray[j]] && isMale[curArray[i]]!=isMale[curArray[j]]) ok = true;
	if(j!=0 && isPrime[curArray[i]+curArray[j-1]] && isMale[curArray[i]]!=isMale[curArray[j-1]]) ok = true;
	if(!ok) continue;

	int nextArray[BUF];
	for(int k=0;k<BUF;k++) nextArray[k] = curArray[k];
	insert(i,j,nextArray);

	int t = toInt(nextArray);
	if(t==12345678) return curCost+1;
	if(!visited.count(t)){
	  visited[t] = curCost+1;
	  Q.push(t);
	}
      }
  }
  
  return -1;
}

void work(int cases){
  cout << "Case " << cases << ": " << bfs() << endl;
}

int main(){
  makeTable();
  
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
