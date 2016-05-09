#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 105;

int main(){
  int n, cnt[BUF];
  while(cin >> n,n){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
      int v;
      scanf("%d",&v);
      cnt[v]++;
    }
    bool fst = true;
    for(int i=0;i<BUF;i++)
      for(int j=0;j<cnt[i];j++){
        if(!fst) printf(" ");
        else fst = false;
        printf("%d",i);
      }
    printf("\n");
  }
  return 0;
}
