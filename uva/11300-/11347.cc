#include<iostream>
using namespace std;
const int BUF = 1001;

int num, nExc;

void read(){
  string s;
  getline(cin,s);
  nExc = 0;
  for(int i=s.size()-1;s[i]=='!';){
    nExc++;
    i--;
    s.erase(s.end()-1);
  }
  num = atoi(s.c_str());
}

void work(int cases){
  int nFactor[BUF]={};

  for(int n=num;n>=2;n-=nExc){
    int v = n;
    for(int p=2;p*p<=v;p++)
      while(v%p==0){
        nFactor[p]++;
        v /= p;
      }
    if(v>1)
      nFactor[v]++;
  }

  cout << "Case " << cases << ": ";
  long long ans = 1;
  for(int i=0;i<BUF;i++){
    if(1.0*ans*(nFactor[i]+1)>1e18){
      cout << "Infinity" << endl;
      return;
    }
    ans *= nFactor[i]+1;
  }
  cout << ans << endl;
}

int main(){
  int cases;
  cin >> cases;
  string dummy; getline(cin,dummy);
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
