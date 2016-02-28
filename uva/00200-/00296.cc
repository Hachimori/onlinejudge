#include<iostream>
using namespace std;
const int GUESS = 15;

struct Guess{
  string s;
  int hit, blow;
};

int nGuess;
Guess guess[GUESS];

void read(){
  cin >> nGuess;
  for(int i=0;i<nGuess;i++){
    char dummy;
    cin >> guess[i].s >> guess[i].hit >> dummy >> guess[i].blow;
  }
}

void work(){
  int nAns = 0;
  string ans;

  for(int i=0;i<=9999;i++){
    char valStr[5];
    sprintf(valStr,"%04d",i);

    bool allMatch = true;
    for(int gLoop=0;gLoop<nGuess;gLoop++){
      Guess &g = guess[gLoop];

      bool usedSelf[4]={}, usedGues[4]={};
      int cntHit = 0, cntBlow = 0;
      for(int i=0;i<4;i++)
        if(valStr[i]==g.s[i]){
          cntHit++;
          usedSelf[i] = usedGues[i] = true;
        }
      
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
          if(usedSelf[i] || usedGues[j]) continue;
          if(valStr[i]==g.s[j]){
            cntBlow++;
            usedSelf[i] = usedGues[j] = true;
          }
        }

      allMatch &= g.hit==cntHit && g.blow==cntBlow;
    }

    if(allMatch){
      nAns++;
      ans = string(valStr);
    }
  }

  if(nAns==1)
    cout << ans << endl;
  else if(nAns==0)
    cout << "impossible" << endl;
  else
    cout << "indeterminate" << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
