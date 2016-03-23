#include<iostream>
#include<string>
#include<map>
#define BUF 1005
#define QUERY 10000
using namespace std;

string str;
int nQuery, query[QUERY];

bool read(){
  if(getline(cin,str)==NULL) return false;
  for(int i=0;i<str.size();i++) str[i] = tolower(str[i]);
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++)
    cin >> query[i];

  return true;
}

void work(){
  for(int k=0;k<nQuery;k++){
    map<string,int> M;
    for(int bgn=0;bgn+query[k]<=str.size();bgn++){
      string s = str.substr(bgn,query[k]);
      if(M.count(s))
	M[s]++;
      else
	M[s] = 1;
    }
      
    int maxOccur = 0;
    string minS;
    for(map<string,int>::iterator i=M.begin();i!=M.end();i++)
      if(maxOccur<i->second){
	maxOccur = i->second;
	minS = i->first;
      }

    cout << maxOccur << ' ' << minS << endl;
  }
}

int main(){
  while(read()){
    work();
    string dummy; getline(cin,dummy);
  }
  
  return 0;
}
