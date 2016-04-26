// ad-hoc
//
//
// 1. Not $B$K4X$7$F$O(B!(!(!(WFF))) $B$H$$$&$h$&$J<0$r9=@.$G$-$k$N$G!"(B
//    WFF $B$,=PMh$k$J$i$P!":G=i$KA4$F$N(BN$B$r=PNO$9$k!#(B
//
// 2. WFF $B$K$*$1$k!"(BOperator$B$N?t(BnO$B$H(BLeaf$B$N?t(BnL$B$O>o$K(B nO==nL+1 $B$G$"$k!#(B
//
// 3. K,A,C,E $B$K4X$7$F!"1&B&$K(Bp,q,r,s,t$B$rM%@hE*$KF~$l$F(B,
//    $B:8B&$K(BK,A,C,E$B$rM%@hE*$KF~$l$k$H(B,$BJ8;zNs$,(BNNNNNOOOLLLL
//    N: Not, O: Operator, L: Leaf $B$H$$$&$h$&$K$J$j!"<BAu$7$d$9$/$J$k!#(B

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
