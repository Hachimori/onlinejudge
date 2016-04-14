#include<iostream>
#include<cmath>
#define EPS (1e-8)
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LE(x,y) ((x)<=(y)+EPS)
using namespace std;
const int BUF = 65;

long double num;
string s;

void read(){
  int dummy;
  cin >> dummy >> s >> num;
}

void work(){
  double pos[BUF], neg[BUF];
  for(int i=0;i<s.size();i++){
    pos[i] =  (s[i]=='p' ? pow(2.0,1.0*s.size()-1-i) : 0);
    neg[i] = -(s[i]=='n' ? pow(2.0,1.0*s.size()-1-i) : 0);
  }
  for(int i=s.size()-2;i>=0;i--){
    pos[i] += pos[i+1];
    neg[i] += neg[i+1];
  }

  string ans;
  for(int i=0;i<s.size();i++){
    double toAdd = (s[i]=='p' ? 1 : -1)*pow(2.0,1.0*s.size()-1-i);
    if(LE(neg[i],num-toAdd) && LE(num-toAdd,pos[i])){
      ans += '1';
      num -= toAdd;
    }
    else{
      ans += '0';
    }
  }
  cout << (EQ(num,0)?ans:"Impossible") << endl;
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
