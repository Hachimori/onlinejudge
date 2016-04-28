#include<iostream>
#include<algorithm>
#include<vector>
#define BUF 1005
using namespace std;

class Data{
public:
  int time, rank;
  
  Data(){}
  Data(int t, int r): time(t), rank(r){}

  bool operator< (const Data &data) const {
    if(time!=data.time) return time<data.time;
    return rank<data.rank;
  }
};

int nData, myRank;
Data data[BUF];

void read(){
  cin >> nData >> myRank;
  
  nData--;

  for(int i=0;i<nData;i++){
    int m, s, d;
    char ch;
    cin >> data[i].rank >> m >> ch >> s >> ch >> d;
    data[i].time = m*100*60+s*100+d;
  }
}

void work(int cases){
  vector<int> times;
  for(int i=0;i<nData;i++)
    for(int j=-1;j<=1;j++)
      times.push_back(data[i].time+j);
  sort(times.begin(),times.end());
  times.erase(unique(times.begin(),times.end()),times.end());
  sort(data,data+nData);

  int maxRank = -(1<<20), finalRank;

  for(int i=0;i<times.size();i++){
    Data self = Data(times[i],myRank);

    int rank = 0;
    for(int k=0;k<nData;k++)
      if(self<data[k]);
      else{
        rank++;
        if(rank==8) break;
      }

    if(rank==8) continue;
    if(maxRank>=rank) continue;
      
    int t = 0;
    for(int j=0;j<rank;j++)
      if(data[j].rank<myRank)
        t++;

    if(t<3){
      maxRank = rank;
      finalRank = t;
    }
  }
  
  cout << "Case #" << cases << ":" << endl;      
  cout << "Gustavo should be #" << maxRank+1 << " during the qualification to achieve position #"
       << finalRank+1 << " in the final." << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
