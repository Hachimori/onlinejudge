#include<iostream>
#include<algorithm>
using namespace std;

int n;

void read(){
  cin >> n;
}

int calc(int a, int b, int c){
  return 2*(a*b+a*c+b*c);
}

void work(){
  int minV = 1<<30;
  for(int i=1;i<=n;i++)
    for(int j=i;;j++){
      int k = n/(i*j) + (n%(i*j)?1:0);
      if(i*j*k==n) minV = min(minV,calc(i,j,k));
      if(i*j>=n) break;
    }
  cout << minV << endl;
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
