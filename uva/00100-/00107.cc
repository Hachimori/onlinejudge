#include<iostream>
#include<cmath>
#include<cfloat>

using namespace std;

int initHeight, nWorker;

bool read(){
  
  cin >> initHeight >> nWorker;
  if(initHeight==0 && nWorker==0) return false;
  return true;
  
}

void work(){
  
  int N,X;
  
  if(initHeight==1 && nWorker==1){
    cout << 0 << ' ' << 1 << endl;
    return;
  }
  
  if(nWorker==0){
    cout << initHeight << ' ' << 1 << endl;
    return;
  }
  
  for(int i=1;;i++){
    if(fabs(1.0-pow(1.0/initHeight,1.0/i)*(pow(nWorker,1.0/i)+1))<FLT_EPSILON){
      X = i;
      break;
    }
  }
  
  
  N = (int)(pow(nWorker,1.0/X)+0.5);
  
  int totalH=0, totalN=0;
  
  for(int i=0;i<X;i++)
    totalN+=(int)(pow((double)N,(double)i)+0.5);
  
  for(int i=0;i<=X;i++)
    totalH+=(int)(initHeight*pow(1.0/(N+1),i)*pow((double)N,(double)i)+0.5);
  
  
  cout << totalN << ' ' << totalH << endl;
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
