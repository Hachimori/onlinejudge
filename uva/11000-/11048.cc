#include<iostream>
#include<string>
#include<map>
using namespace std;
const int QUERY = 1005;

map<string,int> dict;
int nQuery;
string query[QUERY];

void read(){
  int nDict;
  cin >> nDict;
  for(int i=0;i<nDict;i++){
    string s;
    cin >> s;
    dict[s] = i;
  }
  cin >> nQuery;
  for(int i=0;i<nQuery;i++)
    cin >> query[i];
}

void work(){
  for(int kk=0;kk<nQuery;kk++){
    string &q = query[kk];
    if(dict.count(q)){
      cout << q << " is correct" << endl;
      continue;
    }

    string minS;
    int minV = 1<<20;
    for(int i=0;i<=q.size();i++)
      for(int j='a';j<='z';j++){
        string nex = q;
        nex.insert(nex.begin()+i,j);
        if(dict.count(nex) && minV>dict[nex]){
          minV = dict[nex];
          minS = nex;
        }
      }
    
    for(int i=0;i<q.size();i++){
      string nex = q;
      nex.erase(nex.begin()+i);
      if(dict.count(nex) && minV>dict[nex]){
        minV = dict[nex];
        minS = nex;
      }
    }

    for(int i=0;i<q.size();i++)
      for(int j='a';j<='z';j++){
        string nex = q;
        nex[i] = j;
        if(dict.count(nex) && minV>dict[nex]){
          minV = dict[nex];
          minS = nex;
        }        
      }
        

    for(int i=0;i+1<q.size();i++){
      string nex = q;
      swap(nex[i],nex[i+1]);
      if(dict.count(nex) && minV>dict[nex]){
        minV = dict[nex];
        minS = nex;
      }
    }

    if(minV==(1<<20))
      cout << q << " is unknown" << endl;
    else
      cout << q << " is a misspelling of " << minS << endl;
  }

}

int main(){
  read();
  work();
  return 0;
}
