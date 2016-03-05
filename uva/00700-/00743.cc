#include<iostream>
#include<string>
#include<map>

using namespace std;

string source;

bool read(){
  cin >> source;
  if(source=="0") return false;
  return true;
}

bool isValid(string str){
  if(str.size()<2) return false;
  
  for(int i=0;i<source.size();i++)
    if(source[i]=='0') return false;
  
  if(str[0]=='2') return true;
  else if(str[0]=='3'){
    
    int cursor=1;
    while(cursor<str.size()){
      if(str[cursor]=='2') return true;
      if(str[cursor]!='3') return false;
      cursor++;
    }
    return false;
  }
  else 
    return false;
}

void calc(int curr, map<string,string> &mtm){
  
  if(curr==-1) return;


  if(source[curr]=='2'){
    string toProduce = source.substr(curr,source.size()-curr);
    string toReturn =  source.substr(curr+1,source.size()-(curr+1));
    mtm[toProduce] = toReturn;
  }
  else if(source[curr]=='3'){
    string toProduce = source.substr(curr,source.size()-curr);
    string toFind = source.substr(curr+1,source.size()-(curr+1));
    
    if(mtm.find(toFind)!=mtm.end()){
      string toReturn = mtm[toFind];
      toReturn += '2';
      toReturn += mtm[toFind];

      mtm[toProduce] = toReturn;
    }
  }

  calc(curr-1,mtm);
}

void work(){
  
  if(!isValid(source)){
    cout << "NOT ACCEPTABLE" << endl;
    return;
  }

  map<string,string> mtm;
  
  calc(source.size()-2,mtm);
  
  if(mtm.find(source)==mtm.end()){
    cout << "NOT ACCEPTABLE" << endl;
    return;
  }
  else{
    cout << mtm[source] << endl;
  }
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
