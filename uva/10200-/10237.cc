#include<iostream>
#include<algorithm>

using namespace std;

int size, toPut;

bool read(){
  
  cin >> size >> toPut;
  if(size==0 && toPut==0) return false;
  
  return true;
}

void rec(int nChoice, long long &sum, long long currPattern, int nPut, int curr, int limit, int putLimit, bool middleExist){
  
  if(nPut==putLimit){
    sum+=currPattern;
    return;
  }
  if(limit==curr) return;
  if(nChoice>=2 && putLimit-nPut>(limit-curr)*2) return;
  
  // “ñŒÂ’u‚­
  if(putLimit-nPut>=2 && nChoice>=2 && ( !middleExist || curr!=limit-1) ){
    
    long long combi = nChoice*(nChoice-1);
    
    rec(nChoice,sum,currPattern*combi,nPut+2,curr+1,limit,putLimit,middleExist);
  }
  
  // ˆêŒÂ’u‚­
  {
    
    long long combi;
    
    if(middleExist && curr==limit-1)
      combi = nChoice;
    else
      combi = 2*nChoice;
    rec(nChoice+1,sum,currPattern*combi,nPut+1,curr+1,limit,putLimit,middleExist);
  }
  
  // ’u‚©‚È‚¢
  rec(nChoice+2,sum,currPattern,nPut,curr+1,limit,putLimit,middleExist);
}

void work(){

  if(toPut==0){
    cout << 1 << endl;
    return;
  }
  
  long long ans=0;
  
  for(int i=0;i<=toPut;i++){
    long long pattern1=0,pattern2=0;
    
    if(max(toPut-i,i)>size) continue;
    if(size%2==0){
      rec(1,pattern1,1,0,0,(size+1)/2,i,false);
      rec(2,pattern2,1,0,0,size/2,toPut-i,true);
    }
    else{
      rec(1,pattern1,1,0,0,(size+1)/2,i,true);
      rec(2,pattern2,1,0,0,size/2,toPut-i,false);
    }
    
    ans+=pattern1*pattern2;
  }

  cout << ans << endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
