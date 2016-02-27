#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<cctype>
#include<algorithm>

#define MAX_SIZE 300

using namespace std;

void split(string str, vector<string> &sList){
  
  int cursor=0;
  
  
  string digit;
  digit+='0';
  while(isdigit(str[cursor])){
    digit+=str[cursor];
    cursor++;
  }
    
  cursor++;

  string branch;
  while(cursor<str.length() && isalpha(str[cursor])){
    branch+=str[cursor];
    cursor++;
  }
  
  sList.push_back(digit);
  sList.push_back(branch);
}

bool great( const pair<int,string> &a,  const pair<int,string> &b){
  if(a.second.length()<b.second.length()) return true;
  else if(a.second.length()>b.second.length()) return false;

  return a.second<b.second;
}

int nNode;
pair<int,string> nodeList[MAX_SIZE];

bool read(){

  nNode=0;

  string str;

  while(true){
    
    if(!(cin >> str)) return false;

    if(str=="()") break;

    
    vector<string> sList;
    split(str.substr(1,str.length()-2),sList);
    
    nodeList[nNode]=make_pair(atoi(sList[0].c_str()),sList[1]);
    nNode++;
  }

  return true;
}

void work(){
 

  sort(nodeList,nodeList+nNode,great);
  
  /*
  for(int i=0;i<nNode;i++){
    cout << nodeList[i].first << ' ' << nodeList[i].second << endl;
  }cout << endl;
  */
  
  for(int i=0;i<nNode;i++){
    for(int j=i+1;j<nNode;j++){
      if(nodeList[i].second==nodeList[j].second){
	cout << "not complete" << endl;
	return;
      }
    }
  }
  
  if(nodeList[0].second.size()!=0){
    cout << "not complete" << endl;
    return;
  }
  
  for(int i=1;i<nNode;i++){

    bool succeed=false;
    
    for(int j=0;j<i;j++){
      if(nodeList[i].second.substr(0,nodeList[i].second.length()-1)==
	   nodeList[j].second){
	succeed=true;
	break;
      }      
    }

    if(!succeed){
      cout << "not complete" << endl;
      return;
    }
  }
  
  
  for(int i=0;i<nNode;i++){
    if(i==0) cout << nodeList[i].first;
    else cout << ' ' << nodeList[i].first;
  }cout << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
