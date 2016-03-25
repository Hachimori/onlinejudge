#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

enum HAND{STRAIGHT_FLUSH,FOUR_OF_A_KIND,FULL_HOUSE,
          FLUSH,STRAIGHT,THREE_OF_A_KIND,
          TWO_PAIR,ONE_PAIR,NONE};


vector<string> init[2];

bool read(){
  init[0] = init[1] = vector<string>();
  for(int i=0;i<2;i++)
    for(int j=0;j<5;j++){
      string s;
      if(!(cin >> s)) return false;
      init[i].push_back(s);
    }
  return true;
}

pair<long long,vector<int> > judge(vector<string> card){
  vector<int> cntN(13), cntS(4);
  for(int i=0;i<5;i++){
    cntN[string("23456789TJQKA").find(card[i][0])]++;
    cntS[string("CHSD").find(card[i][1])]++;
  }

  vector<int> straightV;
  bool straight = false;
  for(int i=0;i+4<13;i++)
    if(cntN[i] && cntN[i+1] && cntN[i+2] && cntN[i+3] && cntN[i+4]){
      straight = true;
      straightV.push_back(i+4);
    }
  
  bool flush = false;
  for(int i=0;i<4;i++)
    if(cntS[i]==5)
      flush = true;
  
  vector<int> cntV;
  int maxV = -1;
  for(int i=12;i>=0;i--)
    if(maxV<cntN[i]){
      cntV.clear();
      cntV.push_back(i);
      maxV = cntN[i];
    }
    else if(maxV==cntN[i])
      cntV.push_back(i);
  if(maxV==2)
    for(int i=12;i>=0;i--)
      if(cntN[i]==1)
        cntV.push_back(i);

  sort(cntN.rbegin(),cntN.rend());
  
  if(straight && flush) return make_pair(STRAIGHT_FLUSH,straightV);
  if(cntN[0]==4) return make_pair(FOUR_OF_A_KIND,cntV);
  if(cntN[0]==3 && cntN[1]==2) return make_pair(FULL_HOUSE,cntV);
  if(flush) return make_pair(FLUSH,cntV);
  if(straight) return make_pair(STRAIGHT,cntV);
  if(cntN[0]==3) return make_pair(THREE_OF_A_KIND,cntV);
  if(cntN[0]==2 && cntN[1]==2) return make_pair(TWO_PAIR,cntV);
  if(cntN[0]==2) return make_pair(ONE_PAIR,cntV);
  return make_pair(NONE,cntV);
}

void work(){
  pair<long long,vector<int> > b = judge(init[0]), w = judge(init[1]);
  if(b.first<w.first || (b.first==w.first && b.second>w.second))
    cout << "Black wins." << endl;
  else if(b.first>w.first || (b.first==w.first && b.second<w.second))
    cout << "White wins." << endl;
  else
    cout << "Tie." << endl;
}

int main(){
  while(read()) work();
  return 0;
}
