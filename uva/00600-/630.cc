#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int DICT = 1005, QUERY = 100005;

int nDict, nQuery;
string dict[DICT], query[QUERY];


void read(){
  cin >> nDict;
  for(int i=0;i<nDict;i++) cin >> dict[i];
  nQuery = 0;
  while(1){
    cin >> query[nQuery];
    if(query[nQuery]=="END") break;
    nQuery++;
  }
}


vector<int> cnv(string &s){
  vector<int> ret(26);
  for(int i=0;i<s.size();i++) ret[s[i]-'a']++;
  return ret;
}


void work(){
  for(int qIdx=0;qIdx<nQuery;qIdx++){
    cout << "Anagrams for: " << query[qIdx] << endl;
    vector<int> qVec = cnv(query[qIdx]);
    int nMatch = 0;
    for(int i=0;i<nDict;i++)
      if(qVec==cnv(dict[i]))
        printf("%3d) %s\n",++nMatch,dict[i].c_str());
    if(nMatch==0)
      cout << "No anagrams for: " << query[qIdx] << endl;
  }
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
