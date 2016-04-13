#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 50005, QUERY = 25005;

int main(){
  int nVal, val[BUF], nQuery;
  scanf("%d",&nVal);
  for(int i=0;i<nVal;i++)
    scanf("%d",&val[i]);

  scanf("%d",&nQuery);
  for(int i=0;i<nQuery;i++){
    int v;
    scanf("%d",&v);
    int idx1 = lower_bound(val,val+nVal,v)-val;
    int idx2 = upper_bound(val,val+nVal,v)-val;
    if(idx1==0)
      printf("X");
    else
      printf("%d",val[idx1-1]);
    if(idx2==nVal)
      printf(" X\n");
    else
      printf(" %d\n",val[idx2]);
  }
  return 0;
}
