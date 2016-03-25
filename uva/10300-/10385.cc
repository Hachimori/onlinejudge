#include<iostream>
#include<algorithm>
#include<cstdio>
#define PREC 1000
#define BUF 25
#define INF (1<<30)
using namespace std;

int total, nMan;
double run[BUF], bike[BUF];

bool read(){
  if(!(cin >> total)) return false;
  
  cin >> nMan;
  for(int i=0;i<nMan;i++)
    cin >> run[i] >> bike[i];
  
  return true;
}

double getTime(double runL, double bikeL, int id){
  return runL/run[id]+bikeL/bike[id];
}

void work(){
  double maxRun;
  double minV = INF;
  
  for(int i=0;i<=total*PREC;i++){
    double runL = 1.0*i/PREC, bikeL = total-runL;

    double t = -INF;
    for(int j=0;j<nMan-1;j++)
      t = max(t,getTime(runL,bikeL,nMan-1)-getTime(runL,bikeL,j));
    
    if(minV>t){
      maxRun = runL;
      minV = t;
    }
  }
  
  if(minV>1.0e-8)
    cout << "The cheater cannot win." << endl;
  else{
    printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n",
           (int)(-minV*3600+0.5),maxRun,total-maxRun);
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
