#include<iostream>
#include<vector>
using namespace std;

vector<string> card;

void read(){
  card.clear();
  for(int i=0;i<52;i++){
    string s;
    cin >> s;
    card.push_back(s);
  }
}

void work(int cases){
  vector<string> hand = vector<string>(card.end()-25,card.end());
  card.erase(card.end()-25,card.end());

  int Y = 0;
  for(int i=0;i<3;i++){
    int X = isdigit(card.back()[0]) ? card.back()[0]-'0' : 10;
    Y += X;
    for(int j=0;j<11-X;j++) card.pop_back();
  }
  
  card.insert(card.end(),hand.begin(),hand.end());

  cout << "Case " << cases << ": " << card[Y-1] << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
