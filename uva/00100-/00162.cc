#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<cstdio>
using namespace std;

// 0: non-dealer
// 1: dealer

deque<char> deck[2];

bool read(){
  deck[0] = deck[1] = deque<char>();
  
  for(int i=0;i<52;i++){
    string s;
    cin >> s;
    if(s=="#") return false;
    deck[i%2].push_back(s[1]);
  }

  return true;
}

bool playCard(int turn, vector<char> &played){
  if(deck[turn].empty()){
    printf("%d%3d\n",turn==0?1:2,deck[!turn].size());
    return false;
  }

  played.push_back(deck[turn].back());
  deck[turn].pop_back();

  return true;
}

void work(){
  int turn = 0;
  string face = "_JQKA";
  vector<char> played;

  while(true){
    if(!playCard(turn,played)) return;

  _again:;
    int pos;
    if((pos=face.find(played.back()))!=string::npos){
      for(int i=0;i<pos;i++){
        if(!playCard(!turn,played)) return;
        if(face.find(played.back())!=string::npos){
          turn = !turn;
          goto _again;
        }
      }

      for(int i=0;i<played.size();i++)
        deck[turn].push_front(played[i]);

      played.clear();
      turn = !turn;
    }
      
    turn = !turn;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}

