#include<iostream>
#define NUM 105
#define BUF 20005
using namespace std;

int nNum, num[NUM];

bool read(){
  if(!(cin >> nNum)) return false;

  for(int i=0;i<nNum;i++) cin >> num[i];

  return true;
}

void work(int cases){
  cout << "Case #" << cases << ": ";
  
  bool ok = true;

  if(num[0]<1) ok = false;
  for(int i=1;i<nNum;i++)
    if(num[i-1]>=num[i])
      ok = false;

  bool used[BUF];
  for(int i=0;i<BUF;i++) used[i] = false;
  
  for(int i=0;i<nNum;i++)
    for(int j=i;j<nNum;j++){
      if(used[num[i]+num[j]]) ok = false;
      used[num[i]+num[j]] = true;
    }

  cout << (ok ? "It is a B2-Sequence." : "It is not a B2-Sequence.") << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
