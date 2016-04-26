// ad-hoc
//
//
// 1. Not に関しては!(!(!(WFF))) というような式を構成できるので、
//    WFF が出来るならば、最初に全てのNを出力する。
//
// 2. WFF における、Operatorの数nOとLeafの数nLは常に nO==nL+1 である。
//
// 3. K,A,C,E に関して、右側にp,q,r,s,tを優先的に入れて,
//    左側にK,A,C,Eを優先的に入れると,文字列がNNNNNOOOLLLL
//    N: Not, O: Operator, L: Leaf というようになり、実装しやすくなる。

#include<iostream>
#include<string>

using namespace std;

class State{
public:
  int num[256];
  
  int getNumLeaf(){
    return num['p']+num['q']+num['r']+num['s']+num['t'];
  }
  
  int getNumParent(){
    return num['K']+num['A']+num['C']+num['E'];
  }

  char getLeaf(){
    if(num['p']>0){num['p']--; return 'p'; }
    if(num['q']>0){num['q']--; return 'q'; }
    if(num['r']>0){num['r']--; return 'r'; }
    if(num['s']>0){num['s']--; return 's'; }
    if(num['t']>0){num['t']--; return 't'; }
  }
  
  char getParent(){
    if(num['K']>0){num['K']--; return 'K'; }
    if(num['A']>0){num['A']--; return 'A'; }
    if(num['C']>0){num['C']--; return 'C'; }
    if(num['E']>0){num['E']--; return 'E'; }
  }
  
  int getNumNot(){
    return num['N'];
  }
};

State s;

bool read(){
  string buf;
  cin >> buf;
  if(buf=="0") return false;
  
  for(int i=0;i<256;i++) s.num[i] = 0;
  
  for(int i=0;i<buf.size();i++)
    s.num[buf[i]]++;
  
  return true;
}

void rec(){
  if(s.getNumLeaf()>=3){
    if(s.getNumParent()>0){
      cout << s.getParent();
      char ch = s.getLeaf();
      rec();
      cout << ch;
    }
    else
      cout << s.getLeaf();
  }
  else if(s.getNumLeaf()==2){
    if(s.getNumParent()>0){
      cout << s.getParent();
      cout << s.getLeaf();
      cout << s.getLeaf();
    }
    else
      cout << s.getLeaf();
  }
}

void work(){
  if(s.getNumLeaf()==0) cout << "no WFF possible" << endl;
  else if(s.getNumLeaf()==1){
    cout << string(s.getNumNot(),'N') << s.getLeaf() << endl;
  }
  else{
    cout << string(s.getNumNot(),'N');
    rec();
    cout << endl;
  }
}

int main(){
  while(read())
    work();
  
  return 0;
}
