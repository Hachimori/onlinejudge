#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
  map<string,int> n2i;
  int nWord, nDescription;

  cin >> nWord >> nDescription;
  for(int i=0;i<nWord;i++){
    string s;
    int v;
    cin >> s >> v;
    n2i[s] = v;
  }

  for(int i=0;i<nDescription;i++){
    int sum = 0;
    while(1){
      string s;
      cin >> s;
      if(s==".") break;
      sum += n2i.count(s) ? n2i[s] : 0;
    }
    cout << sum << endl;
  }

  return 0;
}
