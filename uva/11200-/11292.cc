#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 20005;

int nToKill, toKill[BUF], nAttacker, attacker[BUF];

bool read(){
  cin >> nToKill >> nAttacker;
  if(!(nToKill|nAttacker)) return false;
  for(int i=0;i<nToKill;i++) cin >> toKill[i];
  for(int i=0;i<nAttacker;i++) cin >> attacker[i];
  return true;
}

void work(){
  sort(toKill,toKill+nToKill);
  sort(attacker,attacker+nAttacker);
  int ans = 0, attIdx = 0;
  for(int i=0;i<nToKill;i++){
    while(attIdx<nAttacker && attacker[attIdx]<toKill[i]) attIdx++;
    if(attIdx==nAttacker){
      cout << "Loowater is doomed!" << endl;
      return;
    }
    ans += attacker[attIdx++];
  }
  cout << ans << endl;
}

int main(){
  while(read()) work();
  return 0;
}
