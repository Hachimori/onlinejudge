#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

bool isVerb(int &cur, vector<string> &sList){
  if(cur==sList.size()) return false;
  string s = sList[cur];
  if(s=="hate" || s=="love" || s=="know" || s=="like" ||
     s=="hates" || s=="loves" || s=="knows" || s=="likes"){
    cur++;
    return true;
  }
  return false;
}

bool isNoun(int &cur, vector<string> &sList){
  if(cur==sList.size()) return false;
  string s = sList[cur];
  if(s=="tom" || s=="jerry" || s=="goofy" || s=="mickey" || 
     s=="jimmy" || s=="dog" || s=="cat" || s=="mouse"){
    cur++;
    return true;
  }
  return false;
}

bool isArticle(int &cur, vector<string> &sList){
  if(cur==sList.size()) return false;
  if(sList[cur]=="a" || sList[cur]=="the"){
    cur++;
    return true;
  }
  return false;
}

bool isActor(int &cur, vector<string> &sList){
  if(isNoun(cur,sList)) return true;
  return isArticle(cur,sList) && isNoun(cur,sList);
}

bool isActList(int &cur, vector<string> &sList){
  while(true){
    if(!isActor(cur,sList)) return false;
    if(cur==sList.size()) break;
    if(sList[cur]=="and") cur++;
    else break;
  }
  return true;
}

bool isAct(int &cur, vector<string> &sList){
  if(!isActList(cur,sList)) return false;
  if(!isVerb(cur,sList)) return false;
  return isActList(cur,sList);
}

bool isState(int &cur, vector<string> &sList){
  while(true){
    if(!isAct(cur,sList)) return false;
    if(cur==sList.size()) break;
    if(sList[cur]==",") cur++;
  }
  return true;
}

int main(){
  while(true){
    string s;
    if(getline(cin,s)==NULL) break;
   
    vector<string> sList;
    stringstream in(s);
    while(in>>s) sList.push_back(s);

    int cur = 0;
    if(isState(cur,sList)) 
      cout << "YES I WILL" << endl;
    else
      cout << "NO I WON'T" << endl;
  }

  return 0;
}
