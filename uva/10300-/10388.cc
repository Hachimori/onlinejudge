#include<iostream>
#include<string>
#include<vector>
using namespace std;

int nCard;
vector<char> a, b; // vec[0]: top,  vec[n]: bottom

void read(){
  a = b = vector<char>();
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++) a.push_back(s[i]);
  cin >> s;
  for(int i=0;i<s.size();i++) b.push_back(s[i]);
  nCard = a.size()+b.size();
}

void work(){
  vector<char> aPile, bPile; // vec[0]: bottom,  vec[n]: top
                             // the cards are faced up

  for(int turn=0;turn<1000;turn++){
    if(a.empty()){
      a.insert(a.end(),aPile.begin(),aPile.end()); // need fix?
      aPile.clear();
    }
    if(b.empty()){
      b.insert(b.end(),bPile.begin(),bPile.end());
      bPile.clear();
    }
    aPile.push_back(a[0]);
    bPile.push_back(b[0]);
    a.erase(a.begin());
    b.erase(b.begin());

    if(aPile.back()==bPile.back()){
      if(rand()/141%2){
        bPile.insert(bPile.end(),aPile.begin(),aPile.end());
        aPile.clear();
        cout << "Snap! for John: ";
        for(int i=bPile.size()-1;i>=0;i--) cout << bPile[i];
        cout << endl;
      }
      else{
        aPile.insert(aPile.end(),bPile.begin(),bPile.end());
        bPile.clear();
        cout << "Snap! for Jane: ";
        for(int i=aPile.size()-1;i>=0;i--) cout << aPile[i];
        cout << endl;        
      }
    }

    if(aPile.size()+a.size()==nCard){
      cout << "Jane wins." << endl;
      return;
    }
    if(bPile.size()+b.size()==nCard){
      cout << "John wins." << endl;
      return;
    }
  }
  cout << "Keeps going and going ..." << endl;
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
