#include<iostream>
#include<cstdio>
#define EPS (1e-8)
using namespace std;
const int BUF = 35, INF = 1<<20, ITER = 1000;

int row, col, b[BUF][BUF], water;

bool read(){
  cin >> row >> col;
  if(row==0 && col==0) return false;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      cin >> b[i][j];
  cin >> water;
  return true;
}

void work(int cases){
  double L = -INF, R = INF;
  for(int i=0;i<ITER;i++){
    double mid = L+(R-L)/2;
    double sum = 0;
    for(int r=0;r<row;r++)
      for(int c=0;c<col;c++)
        sum += max(0.0,(mid-b[r][c])*100);
    if(sum>water)
      R = mid;
    else
      L = mid;
  }

  int cntFlood = 0;
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      if(b[i][j]<(L+R)/2-EPS)
        cntFlood++;

  printf("Region %d\n",cases);
  printf("Water level is %.2lf meters.\n",(L+R)/2);
  printf("%.2lf percent of the region is under water.\n",100.*cntFlood/row/col);
}

int main(){
  for(int i=0;read();i++){   
    work(i+1);
    cout << endl;
  }
  return 0;
}
