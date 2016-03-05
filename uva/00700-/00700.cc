// それぞれのコンピュータが、disp年を示してrange年のサイクルを持つなら
// 実際の時間は disp+range*n (n=0,1,2,3,...) となる。
// 
// 最初のコンピュータのnを動かして、他のコンピューターが
// 上の式で時間を合わせられるかどうかを調べる。

#include<iostream>

#define MAX_TIME 10000
#define MAX_SIZE 25

using namespace std;

class Comp{
public:

  int disp, begin, end;

  Comp(){}
  Comp(int d, int b, int e): disp(d), begin(b), end(e) {}
};

int nComp;
Comp comp[MAX_SIZE];

bool read(){
  cin >> nComp;
  if(nComp==0) return false;

  for(int i=0;i<nComp;i++)
    cin >> comp[i].disp >> comp[i].begin >> comp[i].end;
  
  return true;
}

bool isValid(int currTime, int id){
  int range = comp[id].end-comp[id].begin;
  
  if(comp[id].disp>currTime) return false;
  
  return ((currTime-comp[id].disp)%range==0);
}

void work(int cases){
  int currTime = comp[0].disp, toAdd = comp[0].end-comp[0].begin;

  cout << "Case #" << cases << ":" << endl;
  
  if(nComp==1){
    cout << "The actual year is " << comp[0].disp << "." << endl;
    return;
  }
  
  for(;currTime<MAX_TIME;currTime+=toAdd){
    bool succeed = true;
    for(int i=1;i<nComp;i++)
      if(!isValid(currTime,i)){
	succeed = false;
	break;
      }
    
    if(succeed){
      cout << "The actual year is " << currTime << "." << endl;
      return;
    }
  }

  cout << "Unknown bugs detected." << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
