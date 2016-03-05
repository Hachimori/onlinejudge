#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<utility>

#define MAX_SIZE 85
#define LPAREN 0
#define RPAREN 1
#define PLUS 2
#define MINUS 3
#define MUL 4
#define EQU 5

using namespace std;

class Ope{
public:

  bool isOpe;
  int num;

  Ope(){}
  Ope(bool i, int n): isOpe(i), num(n){}

  void print(){
    if(isOpe){
      switch(num){
      case LPAREN:
	cout << '(';
	break;
      case RPAREN:
	cout << ')';
	break;
      case PLUS:
	cout << '+';
	break;
      case MINUS:
	cout << '-';
	break;
      case MUL:
	cout << '*';
	break;
      case EQU:
	cout << '=';
	break;
      }
    }
    else
      cout << num;
  }
};

string buf;

bool read(){
  getline(cin,buf);
  if(buf=="0") return false;
  return true;
}

void split(string buf, vector< Ope > &nList){
  int cursor=0;

  while(cursor<buf.size()){
    
    while(buf[cursor]==' ') cursor++;
    
    string toPush;
    
    if(isdigit(buf[cursor])){
      while(cursor<buf.size() && isdigit(buf[cursor])){
	toPush+=buf[cursor];
	cursor++;
      }
    }
    else {
      toPush+=buf[cursor];
      cursor++;
    }
    
    //if(toPush.size()==0) continue;
    //cout << toPush << endl;
    if(toPush=="=")
      nList.push_back( Ope(true,EQU) );
    else if(toPush=="(")
      nList.push_back( Ope(true,LPAREN) );
    else if(toPush==")")
      nList.push_back( Ope(true,RPAREN) );
    else 
      nList.push_back( Ope(false,atoi(toPush.c_str())) );
    
    while(cursor<buf.size() && buf[cursor]==' ') cursor++;
  }
  
}

void pushParen(map<int,vector<Ope> > &source){
  for(map<int,vector<Ope> >::iterator i=source.begin();i!=source.end();i++){
    i->second.insert( i->second.begin(), Ope(true,LPAREN) );
    i->second.push_back( Ope(true,RPAREN) );
  }
}

map<int,vector<Ope> > rec(map<int, vector<Ope> > &currState, int cursor, vector< Ope > &nList){
  
  if(cursor==nList.size()) 
    return currState;
  if(nList[cursor].isOpe && nList[cursor].num==RPAREN) 
    return currState;
  
  
  vector<Ope> opList;
  map<int, vector<Ope> > toRet, result;
  map<int, vector<Ope> > state;
  map<int,vector<Ope> > nextState;
  
  if(nList[cursor].isOpe && nList[cursor].num==LPAREN){
    int depth=1;
    int next = cursor;
    
    while(depth!=0){
      next++;
      if(nList[next].isOpe && nList[next].num==LPAREN) depth++;
      if(nList[next].isOpe && nList[next].num==RPAREN) depth--;
    }
    
    result = rec(state,cursor+1,nList);
    pushParen(result);
    
    if(currState.size()==0) return rec(result,next+1,nList);
    
    for(map<int, vector<Ope> >::iterator i=currState.begin();i!=currState.end();i++){
      for(map<int, vector<Ope> >::iterator j=result.begin();j!=result.end();j++){
	if(nextState.find(i->first+j->first)==nextState.end()){
	  nextState[i->first+j->first] = i->second;
	  nextState[i->first+j->first].push_back( Ope(true,PLUS) );
	  nextState[i->first+j->first].insert(nextState[i->first+j->first].end(),j->second.begin(),j->second.end());
	}
	if(nextState.find(i->first-j->first)==nextState.end()){
	  nextState[i->first-j->first] = i->second;
	  nextState[i->first-j->first].push_back( Ope(true,MINUS) );
	  nextState[i->first-j->first].insert(nextState[i->first-j->first].end(),j->second.begin(),j->second.end());
	}
	if(nextState.find(i->first*j->first)==nextState.end()){
	  nextState[i->first*j->first] = i->second;
	  nextState[i->first*j->first].push_back( Ope(true,MUL) );
	  nextState[i->first*j->first].insert(nextState[i->first*j->first].end(),j->second.begin(),j->second.end());
	}
      }
    }
      
    return rec(nextState,next+1,nList);
    
  }
  
  if(cursor==2 || (nList[cursor-1].isOpe && nList[cursor-1].num==LPAREN) ){
    nextState[nList[cursor].num].push_back( nList[cursor] );
    return rec(nextState,cursor+1,nList);
  }
  else {
    for(map<int,vector<Ope> >::iterator i=currState.begin();
	i!=currState.end();i++){
      
      if(nextState.find(i->first+nList[cursor].num)==nextState.end()){
	nextState[i->first+nList[cursor].num] = i->second;
	nextState[i->first+nList[cursor].num].push_back( Ope(true,PLUS) );
	nextState[i->first+nList[cursor].num].push_back( nList[cursor] );
      }

      if(nextState.find(i->first-nList[cursor].num)==nextState.end()){
	nextState[i->first-nList[cursor].num] = i->second;
	nextState[i->first-nList[cursor].num].push_back( Ope(true,MINUS) );
	nextState[i->first-nList[cursor].num].push_back( nList[cursor] );
      }

      if(nextState.find(i->first*nList[cursor].num)==nextState.end()){
	nextState[i->first*nList[cursor].num] = i->second;
	nextState[i->first*nList[cursor].num].push_back( Ope(true,MUL) );
	nextState[i->first*nList[cursor].num].push_back( nList[cursor] );
      }
      
    }
    return rec(nextState,cursor+1,nList);
  }
  
}

void work(int cases){
  
  vector<Ope> nList;
  map< int, vector<Ope> > state;  // number, opeList
  map< int, vector<Ope> > ans;
  
  split(buf,nList);

  /*
  for(int i=0;i<nList.size();i++){
    nList[i].print();
  }
  cout << endl;
  */

  cout << "Equation #" << cases << ":" << endl;
  
  
  ans = rec(state,2,nList);

  /*
  for(map<int,vector<Ope> >::iterator i=ans.begin();i!=ans.end();i++){
    cout << i->first << ' ';
  }cout << endl;
  */
  if(ans.find(nList[0].num)==ans.end())
    cout << "Impossible." << endl;
  else{
    cout << nList[0].num << '=';
    for(int i=0;i<ans[nList[0].num].size();i++){
      if(i==0){
	ans[nList[0].num][i].print();
      }
      else{
	ans[nList[0].num][i].print();
      }
    }
    cout << endl;
  }
    
}

int main(){
  
  for(int i=1;read();i++){
    work(i);
    cout << endl;
  }
  
  return 0;
}
