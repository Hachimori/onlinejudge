#include<iostream>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;
const int CARD = 52, DECK = 16;

class Card{
public:
  int val;

  Card(){}
  Card(string s){
    string c = "ATJQK";
    int v[] = {1,10,11,12,13};
    if(c.find(s[0])==string::npos)
      val = s[0]-'2'+2;
    else
      val = v[c.find(s[0])];
  }

  char convert(){
    string c = "A23456789TJQK";
    return c[val-1];
  }
  
  friend ostream& operator<<(ostream &os, const Card &card);
};

ostream& operator<<(ostream &os, const Card &card){
  string c = "ATJQK";
  int v[] = {1,10,11,12,13};

  if(find(v,v+5,card.val)==v+5)
    os << card.val;
  else
    os << c[find(v,v+5,card.val)-v];

  return os;
}

queue<Card> card;

bool read(){
  while(!card.empty()) card.pop();
  for(int i=0;i<CARD;i++){
    string s;
    cin >> s;
    if(s=="#") return false;
    card.push(Card(s));
  }
  return true;
}

void work(int cases){
  int cnt[4][4] = {0};
  Card deck[4][4];

  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      deck[i][j].val = -1;

 _extend:
  if(!card.empty()){
    for(int i=0;i<DECK;i++){
      int icard = deck[i/4][i%4].val;
      if(icard==-1) continue;
      for(int j=i+1;j<DECK;j++){
        int jcard = deck[j/4][j%4].val;
        if(jcard==-1) continue;
        if(icard+jcard==11){
          if(!card.empty()){
            deck[i/4][i%4] = card.front();
            cnt[i/4][i%4]++;
            card.pop();
          }
          if(!card.empty()){
            deck[j/4][j%4] = card.front();
            cnt[j/4][j%4]++;
            card.pop();
          }
          goto _extend;
        }
        for(int k=j+1;k<DECK;k++){
          int kcard = deck[k/4][k%4].val;
          if(kcard==-1) continue;
          if(((1<<icard)|(1<<jcard)|(1<<kcard))==((1<<11)|(1<<12)|(1<<13))){
            if(!card.empty()){
              deck[i/4][i%4] = card.front();
              cnt[i/4][i%4]++;
              card.pop();
            }
            if(!card.empty()){
              deck[j/4][j%4] = card.front();
              cnt[j/4][j%4]++;
              card.pop();
            }
            if(!card.empty()){
              deck[k/4][k%4] = card.front();
              cnt[k/4][k%4]++;
              card.pop();
            }
            goto _extend;
          }
        }
      }
    }
    
    for(int i=0;i<DECK;i++){
      int icard = deck[i/4][i%4].val;
      if(icard==-1){
        deck[i/4][i%4] = card.front();
        cnt[i/4][i%4]++;
        card.pop();
        goto _extend;
      }
    }
  }

  if(card.empty()){
    printf("%3d:",cases);
    for(int i=0;i<DECK;i++)
      if(deck[i/4][i%4].val!=-1)
        printf("%3d",cnt[i/4][i%4]);
    printf("\n");
  }
  else
    printf("%3d: Overflowed on card no%3d\n",cases,CARD-card.size()+1);
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  return 0;
}
