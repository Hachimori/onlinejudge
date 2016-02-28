#include<iostream>
#define BUF 30
using namespace std;

int nMan, limit;

bool read(){
  cin >> nMan >> limit;
  return !(nMan==0 && limit==0);
}

void work(){
  int toPay = 0, store = 0;
  int get[BUF] = {false}, order[BUF];
  
  for(int nFinish=0,i=0;nFinish<nMan;i=(i+1)%nMan){
    if(get[i]==40) continue;
    
    if(store==0){
      store = max(0,get[i]+toPay+1-40);
      get[i] = min(40,get[i]+toPay+1);
      if(get[i]==40)
        order[nFinish++] = i;
      toPay = (toPay+1)%limit;
    }
    else {
      int pay = store;
      store = max(0,get[i]+pay-40);
      get[i] = min(40,get[i]+pay);
      if(get[i]==40)
        order[nFinish++] = i;
    }
  }

  for(int i=0;i<nMan;i++)
    printf("%3d",order[i]+1);
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}