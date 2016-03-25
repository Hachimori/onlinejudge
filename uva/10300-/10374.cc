#include<iostream>
#include<string>
#include<map>
#include<cassert>
using namespace std;

int main(){
  int cases;
  cin >> cases;

  for(int k=0;k<cases;k++){
    if(k) cout << endl;
    int nPpl;
    cin >> nPpl;
    
    string dummy;
    getline(cin,dummy);

    map<string,string> name2pt;
    for(int i=0;i<nPpl;i++){
      string name, pt;
      getline(cin,name);
      getline(cin,pt);
      name2pt[name] = pt;
    }

    map<string,int> name2cnt;
    int nVote;
    cin >> nVote;
    getline(cin,dummy);
    for(int i=0;i<nVote;i++){
      string name;
      getline(cin,name);
      if(!name2pt.count(name)) continue;
      if(!name2cnt.count(name)) name2cnt[name] = 0;
      name2cnt[name]++;
    }

    string maxPt;
    int maxV = 0;
    for(map<string,int>::iterator i=name2cnt.begin();i!=name2cnt.end();i++){
      if(maxV<i->second){
        maxPt = name2pt[i->first];
        maxV = i->second;
      }
      else if(maxV==i->second)
        maxPt = "tie";
    }
    cout << maxPt << endl;
  }
  return 0;
}
