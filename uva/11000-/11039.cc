#include<iostream>
#include<algorithm>
#define BUF 500005
using namespace std;

int nVal, val[BUF];

void read(){
  cin >> nVal;
  for(int i=0;i<nVal;i++) cin >> val[i];
}

bool cmp(int a, int b){
  return abs(a)<abs(b);
}

void work(){
  sort(val,val+nVal,cmp);

  int cnt = 1;
  bool positive = val[0]>0;

  for(int i=1;i<nVal;i++)
    if(positive^(val[i]>0)){
      positive = !positive;
      cnt++;
    }
  
  cout << cnt << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
