#include<iostream>
using namespace std;
const int DIM = 15, DATA = 10000;

struct Data{
  string name;
  int B, byte, nDim, L[DIM], U[DIM], C[DIM];
};

int nData, nQuery;
Data data[DATA];

void read(){
  cin >> nData >> nQuery;
  for(int i=0;i<nData;i++){
    cin >> data[i].name >> data[i].B >> data[i].byte >> data[i].nDim;
    for(int j=1;j<=data[i].nDim;j++)
      cin >> data[i].L[j] >> data[i].U[j];

    data[i].C[data[i].nDim] = data[i].byte;
    for(int j=data[i].nDim-1;j>=1;j--)
      data[i].C[j] = data[i].C[j+1]*(data[i].U[j+1]-data[i].L[j+1]+1);

    data[i].C[0] = data[i].B;
    for(int j=1;j<=data[i].nDim;j++)
      data[i].C[0] -= data[i].C[j]*data[i].L[j];
  }
}


void work(){
  for(int loop=0;loop<nQuery;loop++){
    string name;
    cin >> name;

    int dataId;
    for(int i=0;i<nData;i++) if(data[i].name==name) dataId = i;

    int mul[DIM];
    for(int i=1;i<=data[dataId].nDim;i++) cin >> mul[i];

    int ans = data[dataId].C[0];
    for(int i=1;i<=data[dataId].nDim;i++) 
      ans += data[dataId].C[i]*mul[i];

    cout << name << "[";
    for(int i=1;i<=data[dataId].nDim;i++){
      cout << mul[i];
      if(i!=data[dataId].nDim) cout << ", ";
    }
    cout << "] = " << ans << endl;
  }
}


int main(){
  read();
  work();
  return 0;
}
