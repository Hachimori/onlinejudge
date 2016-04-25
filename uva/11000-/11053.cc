#include<iostream>
#include<map>
#include<vector>
#define BUCKET 50021
using namespace std;

class Data{
public:
  long long key;
  int step;
  
  Data(){}
  Data(long long k, int s): key(k), step(s){}
};

class Hash{
public:
  vector<Data> bucket[BUCKET];
  
  void init(){
    for(int i=0;i<BUCKET;i++)
      bucket[i].clear();
  }
  
  void insert(int key, int step){
    bucket[key%BUCKET].push_back(Data(key,step));
  }
  
  int find(int key){
    for(int i=0;i<bucket[key%BUCKET].size();i++)
      if(bucket[key%BUCKET][i].key==key) 
	return bucket[key%BUCKET][i].step;

    return -1;
  }
};

Hash hash;
long long N, A, B;

bool read(){
  cin >> N;
  if(N==0) return false;
  
  cin >> A >> B;
  
  return true;
}

void work(){
  int step = 1;
  long long curr = 0;
  
  hash.init();
  hash.insert(curr,0);
  
  while(true){
    int next = ((((A*curr)%N)*curr)%N+B)%N;
    
    int prevN = hash.find(next);
    if(prevN!=-1){
      int currN = hash.find(curr);
      cout << N-(currN-prevN+1) << endl;
      break;
    }
    else
      hash.insert(next,step);
    
    curr = next;
    step++;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
