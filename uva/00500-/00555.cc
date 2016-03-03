#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool mysort(string a, string b){
  string suit = "CDSH";
  if(a[0]!=b[0]) return suit.find(a[0])<suit.find(b[0]);
  string rank = "23456789TJQKA";
  return rank.find(a[1])<rank.find(b[1]);
}

int main(){
  char dealer;
  while(cin >> dealer, dealer!='#'){
    string dealer2idx = "NESW";
    int idx = dealer2idx.find(dealer)+1;

    vector<string> cards[4];
    for(int i=0;i<52;i++){
      char ch1, ch2;
      cin >> ch1 >> ch2;
      cards[(idx+i)%4].push_back(string()+ch1+ch2);
    }

    for(int i=0;i<4;i++)
      sort(cards[i].begin(),cards[i].end(),mysort);

    for(int i=0;i<4;i++){
      cout << dealer2idx[(i+2)%4] << ":";
      for(int j=0;j<cards[(i+2)%4].size();j++)
        cout << ' ' << cards[(i+2)%4][j];
      cout << endl;
    }
  }
  return 0;
}
