#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstdio>
#define RANGE 10000201
#define UNAVAIL 1000000
using namespace std;

int nNum, num[2];
int nUnAvail, unAvail[UNAVAIL];

void makeTable(){
  static bool avail[RANGE];
  fill(avail,avail+RANGE,false);
  int curSod = 1;
  for(int i=1;i<=10000000;i++){
    if(i%10==0){
      int n = i;
      while(n%10==0){
	n /= 10;
	curSod -= 9;
      }
    }
    avail[i+curSod] = true;
    curSod++;
  }

  nUnAvail = 0;
  for(int i=1;i<=10000000;i++)
    if(!avail[i])
      unAvail[nUnAvail++] = i;
}

void read(){
  char buf[1000]; gets(buf);
  nNum = sscanf(buf,"%d%d",&num[0],&num[1]);
}

int sod(int n){
  int ret = 0;
  while(n>0){
    ret += n%10;
    n /= 10;
  }
  return ret;
}

int get(int n){
  for(int i=max(1,n-100)+1;i<=n;i++)
    if(i+sod(i)==n) return i;
  return -1;
}

void work(int cases){
  printf("Case %d: ",cases);

  if(nNum==1)
    printf("%d\n",get(num[0]));
  else {
    int low = lower_bound(unAvail,unAvail+nUnAvail,num[0])-unAvail;
      int up = upper_bound(unAvail,unAvail+nUnAvail,num[1])-unAvail;
      printf("%d\n",up-low);
  }
}

int main(){
  makeTable();

  int cases;
  cin >> cases;

  char dummy[10];  gets(dummy);

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
