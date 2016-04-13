#include<iostream>
using namespace std;
const int BUF = 25;

int nAgency[3], cost[3][BUF], can[3][BUF][BUF];

bool read(){
  if(!(cin >> nAgency[0] >> nAgency[1]>> nAgency[2])) return false;
  for(int type=0;type<3;type++)
    for(int i=0;i<nAgency[type];i++){
      cin >> cost[type][i];
      for(int j=0;j<nAgency[(type+1)%3];j++){
        cin >> can[type][i][j];
        can[type][i][j] = !can[type][i][j];
      }
    }
  return true;
}

void work(){
  int best[3], minV = 1<<30;
  for(int i=0;i<nAgency[0];i++)
    for(int j=0;j<nAgency[1];j++)
      for(int k=0;k<nAgency[2];k++)
        if(can[0][i][j] && can[1][j][k] && can[2][k][i] && minV>cost[0][i]+cost[1][j]+cost[2][k]){
          best[0] = i;
          best[1] = j;
          best[2] = k;
          minV = cost[0][i]+cost[1][j]+cost[2][k];
        }

  if(minV==1<<30)
    cout << "Don't get married!" << endl;
  else
    cout << best[0] << ' ' << best[1] << ' ' << best[2] << ":" << minV << endl;
}


int main(){
  while(read()) work();
  return 0;
}
