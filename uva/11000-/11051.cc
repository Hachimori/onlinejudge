#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class State{
public:
  int pos;
  bool rev;
  
  State(){}
  State(int p, bool r): pos(p), rev(r){}

  void rotate(int n, int nNode){
    pos = (pos+n)%nNode;
  }

  void reverse(int nNode){
    pos = nNode-pos;
    rev = !rev;
  }
};

int nNode;
State last;

bool read(){
  cin >> nNode;
  if(nNode==0) return false;

  State curr = State(0,false);
  
  string dummy; getline(cin,dummy);
  string buf; getline(cin,buf);
  
  stringstream in;
  in.str(buf);
  
  int nOpe;
  char ope;
  while(in >> ope >> nOpe){
    if(ope=='m' && nOpe%2==1)
      curr.reverse(nNode);
    if(ope=='r')
      curr.rotate(nOpe,nNode);
  }
  
  last = curr;
  
  return true;
}

void work(){
  //cout << last.pos << ' ' << last.rev << endl;
  //if(last.pos>nNode/2){
  //  last.pos = nNode - last.pos;
  //  last.rev = !last.rev;
  //}
 
  if(last.rev){
    if(min(nNode-last.pos,last.pos)==0)
      cout << "m1" << endl;
    else if(last.pos<nNode-last.pos)
      cout << "m1 r" << last.pos << endl;
    else
      cout << "r" << nNode-last.pos << " m1" << endl;
  }
  else{
    if(min(nNode-last.pos,last.pos)==0)
      cout << endl;
    else if(2+nNode-last.pos<last.pos)
      cout << "m1 r" << nNode-last.pos << " m1" << endl;
    else
      cout << "r" << last.pos << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work();

  return 0;
}
