#include<iostream>
#include<cstdio>
using namespace std;
const int CARD = 10, MAN = 5;

enum Suit{CLUB, DIAMOND, HEART, SPADE};

class Card{
public:
  int suit, val;

  Card(){}
  Card(int s, int v): suit(s), val(v){}
  Card(string s){
    int v[] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    string vs = "23456789TJQKA";
    string suits = "CDHS";
    val = v[vs.find(s[0])];
    suit = suits.find(s[1]);
  }

  bool operator< (const Card &c) const {
    if(val!=c.val) return val<c.val;
    return suit<c.suit;
  }
};

int trump;
Card card[MAN][CARD];

bool read(){
  for(int i=0;i<MAN*CARD;i++){
    string s;
    cin >> s;
    if(s=="#") return false;
    card[i%MAN][i/MAN] = Card(s);
  }
  
  Card a[2];
  for(int i=0;i<2;i++){
    string s;
    cin >> s;
    a[i] = Card(s);
  }

  trump = a[0]<a[1] ? a[1].suit : a[0].suit;

  return true;
}

Card leaderTurn(int id, bool used[MAN][CARD]){
  int retId;
  Card ret(-1,-1); 
  
  for(int i=0;i<CARD;i++){
    if(used[id][i]) continue;
    if(ret.val<card[id][i].val || 
       (ret.val==card[id][i].val && card[id][i].suit==trump) ||
       (ret.val==card[id][i].val && ret.suit<card[id][i].suit) ){
      ret = card[id][i];
      retId = i;
    }
  }
  used[id][retId] = true;

  return ret;
}

Card followerTurn(int curSuit, int id, bool used[MAN][CARD]){
  int retId;
  Card ret(-1,-1); 
  
  bool curSuitExist = false, trumpExist = false;
  for(int i=0;i<CARD;i++){
    if(!used[id][i] && card[id][i].suit==curSuit)
      curSuitExist = true;
    if(!used[id][i] && card[id][i].suit==trump)
      trumpExist = true;
  }

  for(int i=0;i<CARD;i++){
    if(used[id][i]) continue;
    if(curSuitExist){
      if(card[id][i].suit==curSuit && ret<card[id][i]){
        ret = card[id][i];
        retId = i;
      }
    }
    else if(trumpExist){
      if(card[id][i].suit==trump && ret<card[id][i]){
        ret = card[id][i];
        retId = i;
      }      
    }
    else {
      if(ret<card[id][i]){
        ret = card[id][i];
        retId = i;
      }      
    }
  }
  used[id][retId] = true;

  return ret;
}

void work(){
  int lead = 0, score[MAN] = {0};
  bool used[MAN][CARD] = {false};

  for(int turn=0;turn<CARD;turn++){
    Card served[MAN];
    int man = (lead+1)%MAN;
    served[lead] = leaderTurn(lead,used);
    for(int i=0;i<MAN-1;man=(man+1)%MAN,i++)
      served[man] = followerTurn(served[lead].suit,man,used);

    bool trumpExist = false;
    for(int i=0;i<MAN;i++)
      if(trump==served[i].suit){
        trumpExist = true;
        break;
      }
    
    Card winCard(-1,-1);
    int winner;
    for(int i=0;i<MAN;i++){
      if(trumpExist){
        if(served[i].suit==trump && winCard<served[i]){
          winner = i;
          winCard = served[i];
        }
      }
      else if(served[lead].suit==served[i].suit && winCard<served[i]){
        winner = i;
        winCard = served[i];
      }
    }

    for(int i=0;i<MAN;i++)
      if(served[i].suit==HEART)
        score[winner] += served[i].val;
    lead = winner;
  }

  for(int i=0;i<MAN;i++)
    printf("%3d",score[(i+MAN-1)%MAN]);
  printf("\n");
}

int main(){
  while(read()) work();
  return 0;
}
