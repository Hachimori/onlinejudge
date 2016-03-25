#include<iostream>
using namespace std;
typedef long long integer;
const int BUF = 55;

int nRoot, root[BUF];

integer labs(integer v){
  return v<0 ? -v : v;
}

bool read(){
  if(!(cin >> nRoot)) return false;
  for(int i=0;i<nRoot;i++){
    cin >> root[i];
    root[i] *= -1;
  }
  return true;
}

void work(){
  integer ans[BUF]={0};
  ans[1] = 1;
  ans[0] = root[0];
  for(int i=1;i<nRoot;i++){
    integer t[BUF]={0};
    for(int j=0;j<BUF-1;j++){
      t[j+1] += ans[j];
      t[j] += ans[j]*root[i];
    }
    for(int j=0;j<BUF-1;j++)
      ans[j] = t[j];
  }
  
  bool fst = true;
  for(int i=BUF-1;i>0;i--){
    if(ans[i]==0) continue;
    if(fst) fst = false;
    else cout << ' ';
    if(nRoot!=i)
      cout << (ans[i]<0?"- ":"+ ");
    if(labs(ans[i])>1)
      cout << labs(ans[i]);
    cout << 'x';
    if(i>1)
      cout << "^" << i;
  }
  if(!fst) cout << ' ';
  cout << (ans[0]<0?"- ":"+ ") << labs(ans[0]) << " = 0" << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
