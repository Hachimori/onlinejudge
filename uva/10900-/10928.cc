#include<iostream>
#include<string>
#include<vector>

#define MAX_SIZE 1004

using namespace std;

void split(string str, vector<string> &sList){
  
  int cursor=0;

  while(cursor<str.size()){
    
    while(cursor<str.size() && str[cursor]== ' ')
      cursor++;

    string toPush;

    while(cursor<str.size() && str[cursor]!=' '){
      toPush+=str[cursor];
      cursor++;
    }

    if(toPush.size()>0)
      sList.push_back(toPush);
    
  }
  
}

int nPlace;
int degree[MAX_SIZE];

void read(){
  
  cin >> nPlace;
  
  string str; getline(cin,str);
  
  for(int i=0;i<nPlace;i++){
    
    getline(cin,str);
    
    vector<string> sList;

    split(str,sList);
    
    degree[i] = sList.size();
    
  }
  
}

void work(){
  
  
  int minVal=99999;

  
  vector<int> pList;

  for(int i=0;i<nPlace;i++){
    
    if(minVal>degree[i]){
      pList.clear();
      pList.push_back(i);
      minVal = degree[i];
    }
    else if(minVal==degree[i])
      pList.push_back(i);
  }
  
  
  for(int i=0;i<pList.size();i++){
    if(i!=0) cout << ' ';
    cout << pList[i]+1;
  }
  cout << endl;
}

int main(){
  
  int cases;
  
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }

  return 0;
}