#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

string source;

void read(){
  
  source="";

  string str;
  
  while(true){
    
    getline(cin,str);
    if(str.length()==0) break;
    
    source+=str;
  }
  
}

void makeList(vector< pair<char,int> > &cList){

  int cursor=0, currDepth=0;

  for(cursor=0;cursor<source.length();cursor++){
    
    if(source[cursor]=='*' || source[cursor]=='/')
      cList.push_back( make_pair(source[cursor],2+currDepth*10) );
    else if(source[cursor]=='+' || source[cursor]=='-')
      cList.push_back( make_pair(source[cursor],1+currDepth*10) );
    else if(source[cursor]=='(')
      currDepth++;
    else if(source[cursor]==')')
      currDepth--;
    else 
      cList.push_back( make_pair(source[cursor],10+currDepth*10) );
  }
  
}


void work(){

  vector< pair<char,int> > cList;
  stack< pair<char,int> > S;

  makeList(cList);


  for(int cursor=0;cursor<cList.size();cursor++){
    
    if(S.size()==0) S.push(cList[cursor]);
    else if(S.top().second<cList[cursor].second) S.push(cList[cursor]);
    else {
      
      while(S.size()>0 && S.top().second>=cList[cursor].second) {
	cout << S.top().first;
	S.pop();
      }
      S.push(cList[cursor]);
    }

  }

  while(S.size()>0) {
    cout << S.top().first;
    S.pop();
  }

  cout << endl;

}

int main(){

  int cases;
  cin >> cases;

  string str; getline(cin,str); getline(cin,str);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    read();
    work();
  }

  return 0;
}
