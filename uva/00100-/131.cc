#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define CARD 5
using namespace std;

enum HAND{NONE, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH,
          FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH};

string card[CARD], deck[CARD];

bool read(){
  for(int i=0;i<5;i++) if(!(cin >> card[i])) return false;
  for(int i=0;i<5;i++) if(!(cin >> deck[i])) return false;
  return true;
}

int judge(){
  vector<int> cntN(13), cntS(4);
  for(int i=0;i<5;i++){
    cntN[string("A23456789TJQK").find(card[i][0])]++;
    cntS[string("CHSD").find(card[i][1])]++;
  }

  bool straight = false;
  for(int i=0;i+4<=13;i++)
    if(cntN[i] && cntN[i+1] && cntN[i+2] && cntN[i+3] && cntN[(i+4)%13])
      straight = true;

  bool flush = false;
  for(int i=0;i<4;i++)
    if(cntS[i]==5)
      flush = true;

  sort(cntN.rbegin(),cntN.rend());
  
  if(straight && flush) return STRAIGHT_FLUSH;
  if(cntN[0]==4) return FOUR_OF_A_KIND;
  if(cntN[0]==3 && cntN[1]==2) return FULL_HOUSE;
  if(flush) return FLUSH;
  if(straight) return STRAIGHT;
  if(cntN[0]==3) return THREE_OF_A_KIND;
  if(cntN[0]==2 && cntN[1]==2) return TWO_PAIR;
  if(cntN[0]==2) return ONE_PAIR;
  return NONE;
}

void rec(int idx, int nSwap, int &maxV){
  if(idx==CARD){
    maxV = max(maxV,judge());
    return;
  }

  rec(idx+1,nSwap,maxV);
  
  swap(card[idx],deck[nSwap]);

  rec(idx+1,nSwap+1,maxV);

  swap(card[idx],deck[nSwap]);
}

void work(){
  int maxV = 0;
  rec(0,0,maxV);
  
  string best[]={"highest-card", "one-pair", "two-pairs",
                 "three-of-a-kind", "straight", "flush",
                 "full-house", "four-of-a-kind", "straight-flush"};
  
  cout << "Hand:";
  for(int i=0;i<CARD;i++)
    cout << ' ' << card[i];

  cout << " Deck:";
  for(int i=0;i<CARD;i++)
    cout << ' ' << deck[i];

  cout << " Best hand: " << best[maxV] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}