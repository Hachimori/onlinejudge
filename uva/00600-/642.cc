#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int QUERY = 10000;

set<string> word;
int nQuery;
string query[QUERY];

void read(){
  while(1){
    string s;
    cin >> s;
    if(s=="XXXXXX") break;
    word.insert(s);
  }
  nQuery = 0;
  while(1){
    cin >> query[nQuery];
    if(query[nQuery]=="XXXXXX") break;
    nQuery++;
  }
}

void work(){
  for(int i=0;i<nQuery;i++){
    int cnt = 0;
    sort(query[i].begin(),query[i].end());
    do{
      if(word.count(query[i])){
        cout << query[i] << endl;
        cnt++;
      }
    }while(next_permutation(query[i].begin(),query[i].end()));
    if(cnt==0)
      cout << "NOT A VALID WORD" << endl;
    cout << "******" << endl;
  }
}

int main(){
  read();
  work();
  return 0;
}
