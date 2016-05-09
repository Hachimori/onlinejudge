#include<iostream>
using namespace std;
const int VAL = 100005;

int nVal, val[VAL];

bool read(){
  cin >> nVal;
  if(nVal==0) return false;
  for(int i=0;i<nVal;i++) cin >> val[i];
  return true;
}


int msort(int L, int R){
  if(L==R) return 0;
  int ret = 0, mid = (L+R)/2;
  ret += msort(L,mid);
  ret += msort(mid+1,R);

  static int buf[VAL];
  for(int itL=L,itR=mid+1,idx=L;itL<=mid || itR<=R;){
    if((itL<=mid && itR<=R && val[itL]<val[itR]) || itR>R)
      buf[idx++] = val[itL++];
    else {
      ret += mid-itL+1;
      buf[idx++] = val[itR++];
    }
  }
  
  for(int i=L;i<=R;i++)
    val[i] = buf[i];
  
  return ret;
}


void work(){
  cout << (msort(0,nVal-1)%2==0 ? "Carlos" : "Marcelo") << endl;
}


int main(){
  while(read()) work();
  return 0;
}
