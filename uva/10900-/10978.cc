#include<iostream>
#include<string>
#include<utility>
#define INF "ZZ"
#define CARD 55
using namespace std;

int nCard;
pair<string,int> card[CARD];

bool read(){
  cin >> nCard;
  if(nCard==0) return false;
  
  for(int i=0;i<nCard;i++){
    string c, spell;
    cin >> c >> spell;
    card[i] = make_pair(c,spell.size());
  }
  
  return true;
}

void work(){
  int cur = 0;
  string ans[CARD];

  for(int i=0;i<nCard;i++)
    ans[i] = INF;
  
  for(int i=0;i<nCard;i++){
    for(int nMove=0;;cur=(cur+1)%nCard)
      if(ans[cur]==INF){
	nMove++;
	if(nMove==card[i].second) break;
      }
    ans[cur] = card[i].first;    
  }

  for(int i=0;i<nCard;i++){
    if(i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
