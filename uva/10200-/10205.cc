#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cctype>
using namespace std;
const int OPE = 105, CARD = 52, QUERY = 100000;

int nOpe, ope[OPE][CARD], nQuery, query[QUERY];

void read(){
  cin >> nOpe;
  for(int i=0;i<nOpe;i++)
    for(int j=0;j<CARD;j++){
      cin >> ope[i][j];
      ope[i][j]--;
    }
  
  string dummy; getline(cin,dummy);
  nQuery = 0;
  while(1){
    string s; 
    if(!getline(cin,s) || s.empty()) break;
    query[nQuery++] = atoi(s.c_str())-1;
  }
}

string toStr(pair<int,int> card){
  string value[] = {"Jack","Queen","King","Ace"};
  string suit[]={"Clubs","Diamonds","Hearts","Spades"};
  string ret = "";

  if(card.first<=10){
    stringstream out;
    out << card.first;
    ret += out.str();
  }
  else
    ret += value[card.first-11];
  ret += " of "+suit[card.second];
  
  return ret;
}

void work(){
  int nCard = 0;
  pair<int,int> card[CARD];  //(value,suit)
  for(int suit=0;suit<4;suit++)
    for(int val=2;val<=14;val++)
      card[nCard++] = make_pair(val,suit);
  
  for(int kk=0;kk<nQuery;kk++){
    pair<int,int> shuffle[CARD];    
    for(int i=0;i<CARD;i++)
      shuffle[i] = card[ope[query[kk]][i]];
    memcpy(card,shuffle,sizeof(shuffle));
  }

  for(int i=0;i<CARD;i++)
    cout << toStr(card[i]) << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
