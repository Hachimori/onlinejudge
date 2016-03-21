#include<iostream>
using namespace std;
const int DATA = 10000;


class Data{
public:
  string name;
  double cost;
  int nSatisfied;
};


int nMission, nData;
Data data[DATA];

bool read(){
  cin >> nMission >> nData;
  if(nMission==0 && nData==0) return false;

  string dummy; getline(cin,dummy);
  for(int i=0;i<nMission;i++) getline(cin,dummy);

  for(int i=0;i<nData;i++){
    getline(cin,data[i].name);
    cin >> data[i].cost >> data[i].nSatisfied;

    getline(cin,dummy);
    for(int j=0;j<data[i].nSatisfied;j++) getline(cin,dummy);
  }

  return true;
}


void work(int cases){
  Data minData = data[0];

  for(int i=0;i<nData;i++){
    Data toCmp = data[i];
    if(minData.nSatisfied==toCmp.nSatisfied){
      if(minData.cost>toCmp.cost)
        minData = toCmp;
    }
    else if(minData.nSatisfied<toCmp.nSatisfied)
      minData = toCmp;
  }
  cout << "RFP #" << cases << endl;
  cout << minData.name << endl;
}


int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  return 0;
}
