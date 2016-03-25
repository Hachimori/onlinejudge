#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int INF = 1<<30, BUF = 105;

int nLap;
double timePerLap, timePerFuel, fuelPerLap, fuelReducePerFuel;
double timePerPit, timePerPitfuel;

bool read(){
  return cin >> nLap >> timePerLap >> timePerFuel >> fuelPerLap
             >> fuelReducePerFuel >> timePerPit >> timePerPitfuel;
}

double bisect(int nRunLap, double &chargeFuel, double &needTime){
  double L = 0, R = INF;
  for(int it=0;it<100;it++){
    double t = (L+R)/2;
    for(int i=0;i<nRunLap;i++)
      t = t*(1-fuelReducePerFuel)-fuelPerLap;
    if(t>0)
      R = (L+R)/2;
    else
      L = (L+R)/2;
  }
  chargeFuel = (L+R)/2;
  double t = chargeFuel;
  needTime = timePerPitfuel*chargeFuel+timePerPit;
  for(int i=0;i<nRunLap;i++){
    needTime += t*timePerFuel+timePerLap;
    t = t*(1-fuelReducePerFuel)-fuelPerLap;
  }
    
}

double rec(int lap, vector< pair<int,double> > pit[BUF], double dp[BUF]){
  double &ret = dp[lap];
  if(lap==nLap) return 0;
  if(dp[lap]>-0.5) return ret;

  vector< pair<int,double> > minPit;
  ret = INF;
  for(int nRunLap=1;lap+nRunLap<=nLap;nRunLap++){
    double chargeFuel, needTime;
    bisect(nRunLap,chargeFuel,needTime);
    if(lap==0){
      needTime -= chargeFuel*timePerPitfuel+timePerPit;
    }
    if(ret>needTime+rec(lap+nRunLap,pit,dp)){
      ret = needTime+rec(lap+nRunLap,pit,dp);
      minPit = pit[lap+nRunLap];
      minPit.insert(minPit.begin(),make_pair(lap,chargeFuel));
    }
  }
  pit[lap] = minPit;
  return ret;
}


void work(){
  vector<pair<int,double> > pit[BUF]; // (totalLap,chargeFuel)
  double dp[BUF];
  for(int i=0;i<=nLap;i++)
    dp[i] = -1;
  
  rec(0,pit,dp);

  printf("%d %.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",
         nLap,timePerLap,timePerFuel,fuelPerLap,
         fuelReducePerFuel,timePerPit,timePerPitfuel);

  printf("%.3lf %.3lf %d\n",dp[0],pit[0][0].second,pit[0].size()-1);
  for(int i=1;i<pit[0].size();i++)
    printf("%d %.3lf\n",pit[0][i].first,pit[0][i].second);
}

int main(){
  while(read()) work();
  return 0;
}
