#include<iostream>
#include<vector>
#include<string>
#define rank first
#define suit second
using namespace std;
typedef pair<char,char> Card;

Card init[52];

bool read(){
  for(int i=0;i<52;i++){
    string s;
    cin >> s;
    if(s[0]=='#') return false;
    init[i] = Card(s[0],s[1]);
  }

  return true;
}

bool match(Card &a, Card &b){
  return a.rank==b.rank || a.suit==b.suit;
}

void work(){
  vector< vector<Card> > curr;
  for(int i=0;i<52;i++)
    curr.push_back(vector<Card>(1,init[i]));
  
  while(true){
    bool moved = false;
    for(int i=0;i<curr.size();i++){
      if(i>=3 && match(curr[i-3].back(),curr[i].back())){
        curr[i-3].push_back(curr[i].back());
        curr[i].pop_back();
        if(curr[i].empty()) curr.erase(curr.begin()+i);
        moved = true;
        break;
      }
      
      if(i>=1 && match(curr[i-1].back(),curr[i].back())){
        curr[i-1].push_back(curr[i].back());
        curr[i].pop_back();
        if(curr[i].empty()) curr.erase(curr.begin()+i);
        moved = true;
        break;
      }
    }

    if(!moved) break;
  }
  
  if(curr.size()==1){
    cout << "1 pile remaining: 52" << endl;
  }
  else{
    cout << curr.size() << " piles remaining:";
    for(int i=0;i<curr.size();i++)
      cout << ' ' << curr[i].size();
    cout << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
