#include<iostream>
#include<algorithm>

#define BUF 1000
#define BASE 10000

using namespace std;

class BI{
 public:
  int leng, num[BUF];
    
  BI(){}
  BI(int n){
    leng = 0;
    fill(num,num+BUF,0);
    
    while(n>0){ 
      num[leng++] = n%BASE; 
      n /= BASE;
    }
  }
  
  void print(){
    if(leng==0) cout << 0;
    for(int i=leng-1;i>=0;i--){
      if(i!=leng-1)
	for(int t=num[i],p=BASE/10;p>=1;t%=p,p/=10)
	  cout << t/p;
      else
	  cout << num[i];
    }
    cout << endl;
  }

  BI operator* (BI bi) {
    int tmp[BUF], tLeng = 0;
    fill(tmp,tmp+BUF,0);
    
    for(int i=0;i<leng;i++)
      for(int j=0;j<bi.leng;j++){
	tmp[i+j] += num[i]*bi.num[j];

	if(tmp[i+j]>=BASE){
	  tmp[i+j+1] += tmp[i+j]/BASE;
	  tmp[i+j] %= BASE;
	  tLeng = max(tLeng,i+j+2);
	}
	else if(tmp[i+j]>0)
	  tLeng = max(tLeng,i+j+1);
      }
    
    for(int i=0;i<tLeng;i++)
      bi.num[i] = tmp[i];
    bi.leng = tLeng;
    
    return bi;
  }
};

int N, D;

bool read(){
  cin >> N >> D;
  if(N==0 && D==0) return false;
  return true;
}

void work(){
  BI ans = BI(1);

  for(int i=0;i<D;i++)
    ans = ans*BI(N);

  ans.print();
}

int main(){
  while(read())
    work();
  return 0;
}
