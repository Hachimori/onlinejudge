#include<iostream>
using namespace std;
const int DIGIT = 100;

class Bi{
public:
 int digit[DIGIT], leng;

  Bi(){}
  Bi(int n){
    memset(digit,0,sizeof(digit));
    leng = 0;
    while(n){
      digit[leng++] = n%10;
      n /= 10;
    }
  }
  Bi(string s){
    memset(digit,0,sizeof(digit));
    leng = s.size();
    for(int i=0;i<s.size();i++)
      digit[i] = s[s.size()-i-1]-'0';
  }

  Bi operator+ (Bi opp) {
    for(int i=0;i<leng;i++){
      opp.digit[i] += digit[i];
      opp.digit[i+1] += opp.digit[i]/10;
      opp.digit[i] %= 10;
    }
    for(int i=0;i<DIGIT;i++)
      if(opp.digit[i])
        opp.leng = i+1;
    return opp;
  }

  Bi operator- (Bi opp) {
    Bi ret(0);
    for(int i=0;i<max(leng,opp.leng);i++)
      ret.digit[i] = digit[i]-opp.digit[i];
    
    for(int i=0;i<DIGIT;i++){
      if(ret.digit[i]<0){
        ret.digit[i] += 10;
        ret.digit[i+1]--;
      }
      if(ret.digit[i]) ret.leng = i+1;
    }
    return ret;
  }

  Bi operator* (Bi opp) {
    Bi ret(0);
    for(int i=0;i<leng;i++)
      for(int j=0;j<opp.leng;j++)
        ret.digit[i+j] += digit[i]*opp.digit[j];

    for(int i=0;i<DIGIT;i++){
      if(ret.digit[i]>=10){
        ret.digit[i+1] += ret.digit[i]/10;
        ret.digit[i] %= 10;
      }
      if(ret.digit[i]) ret.leng = i+1;
    }
    return ret;
  }

  bool operator>= (const Bi opp) const {
    if(leng!=opp.leng) return leng>opp.leng;
    for(int i=leng-1;i>=0;i--)
      if(digit[i]!=opp.digit[i])
        return digit[i]>opp.digit[i];
    return true;
  }
};

Bi pow2minus1(int n){
  Bi ret("1");
  for(int i=0;i<n;i++)
    ret = ret*2;
  ret.digit[0]--;
  for(int i=0;i<ret.leng;i++)
    if(ret.digit[i]<0){
      ret.digit[i] += 10;
      ret.digit[i+1]--;
    }
  
  for(int i=0;i<DIGIT;i++)
    if(ret.digit[i])
      ret.leng = i+1;
  return ret;
}


void rec(int src, int dst, int pegMov, int state[3], Bi &nMove){
  if(nMove.leng==0) return;

  Bi toCmp = pow2minus1(pegMov);
  if(nMove>=toCmp){
    nMove = nMove-toCmp;
    state[src] -= pegMov;
    state[dst] += pegMov;
    return;
  }

  for(int i=0;i<3;i++)
    if(src!=i && dst!=i){
      rec(src,i,pegMov-1,state,nMove);
      rec(src,dst,1,state,nMove);
      rec(i,dst,pegMov-1,state,nMove);
    }
}


int main(){
  int nPeg;
  string nMoveStr;
  while(cin >> nPeg >> nMoveStr){
    if(nPeg==0 && nMoveStr=="0") break;
    if(nMoveStr=="0") nMoveStr = "";
    int state[3]={nPeg,0,0};
    Bi nMove(nMoveStr);

    rec(0,nPeg%2 ? 1 : 2,nPeg,state,nMove);

    for(int i=0;i<3;i++){
      if(i) cout << ' ';
      cout << state[i];
    }
    cout << endl;
  }
  return 0;
}
