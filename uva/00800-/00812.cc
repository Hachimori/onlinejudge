#include<iostream>
#include<vector>
using namespace std;
const int BLOCK = 55, PILE = 25, BUF = BLOCK*PILE;

int nBlock;
vector<int> val[BLOCK];

bool read(){
  for(int i=0;i<BLOCK;i++) val[i].clear();
  cin >> nBlock;
  if(nBlock==0) return false;
  for(int i=0;i<nBlock;i++){
    int nPile;
    cin >> nPile;
    for(int j=0;j<nPile;j++){
      int v;
      cin >> v;
      val[i].push_back(v);
    }
  }
  return true;
}

pair<int,vector<int> > getSubAns(vector<int> block){
  int maxV = 0, curSum = 0;
  vector<int> nGet(1,0);
  for(int i=0;i<block.size();i++){
    curSum += 10-block[i];
    if(maxV<curSum){
      maxV = curSum;
      nGet.clear();
      nGet.push_back(i+1);
    }
    else if(maxV==curSum)
      nGet.push_back(i+1);
  }
  return make_pair(maxV,nGet);
}

void work(int cases){
  vector< pair<int,vector<int> > > subAns; //(maxV,the number of piles to reach maxV)
  for(int i=0;i<nBlock;i++)
    subAns.push_back(getSubAns(val[i]));
  
  int maxProfit = 0;
  for(int i=0;i<nBlock;i++) maxProfit += subAns[i].first;

  bool toGet[BLOCK][BUF]={};
  toGet[0][0] = true;
  for(int i=0;i<nBlock;i++)
    for(int j=0;j<BUF;j++)
      if(toGet[i][j])
        for(int k=0;k<subAns[i].second.size();k++)
          toGet[i+1][j+subAns[i].second[k]] = true;

  cout << "Workyards " << cases << endl;
  cout << "Maximum profit is " << maxProfit << "." << endl;
  cout << "Number of pruls to buy:";
  for(int i=0,cnt=0;i<BUF && cnt<10;i++){
    if(toGet[nBlock][i]){
      cout << ' ' << i;
      cnt++;
    }
  }
  cout << endl;
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  return 0;
}
