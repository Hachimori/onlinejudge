// Greedy
//
// (�I��点��̂ɂ����鎞��)/(�x���ɂ�锱��) ���ŏ��ƂȂ�
// �d�����������Ă����B
//

#include<iostream>
#include<algorithm>
#include<cfloat>

#define EPS FLT_EPSILON
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define MAX_SIZE 1005

using namespace std;

class Data{
public:
  int id, time, cost;
  
  Data(){}
  Data(int i, int t, int c): id(i), time(t), cost(c) {}

  bool operator<(const Data &d) const {
    if(EQ(((double)time)/cost,((double)d.time)/d.cost)) return id<d.id;
    return ((double)time)/cost<((double)d.time)/d.cost;
  }
};

int nData;
Data data[MAX_SIZE];

void read(){
  cin >> nData;
  
  for(int i=0;i<nData;i++){
    cin >> data[i].time >> data[i].cost;
    data[i].id = i;
  }
}

void work(){
  sort(data,data+nData);

  for(int i=0;i<nData;i++){
    if(i!=0) cout << ' ' << data[i].id+1;
    else cout << data[i].id+1;
  }
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
