#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<cctype>
using namespace std;
const int PPL = 300;

int nppl;
string name[PPL];
string str;
vector< pair<char,int> > guess[PPL];

void read(){
  nppl = 0;
  for(int i=0;i<PPL;i++) guess[i].clear();

  getline(cin,str);
  while(1){
    string s;
    if(!getline(cin,s) || s.empty()) break;

    for(int i=0;i<s.size();i++)
      if(!isalnum(s[i]))
        s[i] = ' ';

    stringstream in(s);
    if(!(in >> name[nppl])) break;

    pair<char,int> toPush;
    while(in >> toPush.first >> toPush.second)
      guess[nppl].push_back(toPush);

    nppl++;
  }
}


void work(){
  map<string,int> earn;
  int totalGuess = 0, totalEarn = 0;

  for(int i=0;i<nppl;i++){
    for(int j=0;j<guess[i].size();j++)
      if(count(str.begin(),str.end(),guess[i][j].first)==guess[i][j].second){
        earn[name[i]] += 2;
        totalEarn += 2;
      }
      else if(abs(count(str.begin(),str.end(),guess[i][j].first)-guess[i][j].second)==1){
        earn[name[i]]++;
        totalEarn++;
      }
    totalGuess += guess[i].size();
  }
  

  for(map<string,int>::iterator i=earn.begin();i!=earn.end();i++)
    printf("%s %.2lf\n",i->first.c_str(),2.0*totalGuess/totalEarn*i->second);
}

int main(){
  int cases;
  cin >> cases;
  string dummy;;
  getline(cin,dummy); getline(cin,dummy);
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
