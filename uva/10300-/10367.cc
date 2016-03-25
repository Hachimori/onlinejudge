#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#define nume first
#define deno second
using namespace std;
typedef pair<long long,long long> Frac;
const int INF = 1<<29;

int x[2], y[2], v[2];

void read(){
  x[0] = x[1] = y[0] = y[1] = v[0] = v[1] = 0;
  string str;
  getline(cin,str); // dummy
  for(int i=0;i<2;i++){
    getline(cin,str); 
    stringstream in(str);
    bool afterEQ = false;
    bool minus = false;

    string s;
    while(in>>s){
      if(s=="+"){
        minus = false;
        continue;
      }
      else if(s=="-"){
        minus = true;
        continue;
      }
      else if(s=="="){
        afterEQ = true;
        minus = false;
        continue;
      }
      int &toAdd = s[s.size()-1]=='x' ? x[i] : s[s.size()-1]=='y' ? y[i] : v[i];
      if(s[s.size()-1]=='x' || s[s.size()-1]=='y') s = s.substr(0,s.size()-1);
      if(s.size()>0 && s[0]=='-'){
        minus = !minus;
        s = s.substr(1);
      }
      int digit = s.empty() ? 1 : atoi(s.c_str()); 
      toAdd += afterEQ^minus ? -digit : digit;
      minus = false;
    }
  }

  v[0] *= -1;
  v[1] *= -1;
}

Frac add(Frac a, Frac b){
  return Frac(a.nume*b.deno+a.deno*b.nume,a.deno*b.deno);
}

Frac sub(Frac a, Frac b){
  return Frac(a.nume*b.deno-a.deno*b.nume,a.deno*b.deno);
}

Frac mul(Frac a, Frac b){
  return Frac(a.nume*b.nume,a.deno*b.deno);
}

Frac div(Frac a, Frac b){
  return Frac(a.nume*b.deno,a.deno*b.nume);
}

long long gcd(long long a, long long b){
  return b==0 ? a : gcd(b,a%b);
}

Frac normalize(Frac a){
  long long toDiv = llabs(gcd(a.nume,a.deno));
  return Frac(a.nume/toDiv,a.deno/toDiv);
}

void work(){
  Frac m[2][3];
  for(int i=0;i<2;i++){
    m[i][0] = Frac(x[i],1);
    m[i][1] = Frac(y[i],1);
    m[i][2] = Frac(v[i],1);
  }
  
  for(int i=0;i<2;i++){
    if(m[i][i].nume==0 && (i==0 || (i==1 && m[0][0].nume==0 && m[1][0].nume==0))){
      swap(m[i][0],m[(i+1)%2][0]);
      swap(m[i][1],m[(i+1)%2][1]);
      swap(m[i][2],m[(i+1)%2][2]);
    }
    if(m[i][i].nume==0) continue;

    for(int j=i+1;j<3;j++){
      m[i][j] = div(m[i][j],m[i][i]);
      if(m[i][j].deno<0)
        m[i][j] = mul(m[i][j],Frac(-1,-1));
    }
    m[i][i] = Frac(1,1);

    for(int j=i+1;j<3;j++){
      m[(i+1)%2][j] = sub(m[(i+1)%2][j],mul(m[(i+1)%2][i],m[i][j]));
      if(m[(i+1)%2][j].deno<0)
        m[(i+1)%2][j] = mul(m[(i+1)%2][j],Frac(-1,-1));
    }
    m[(i+1)%2][i] = Frac(0,1);
  }

  if((m[0][0].nume==0 && m[0][2].nume!=0) || (m[1][1].nume==0 && m[1][2].nume!=0) ||
     m[0][1].nume!=0 || m[1][0].nume!=0 ){
    cout << "don't know" << endl;
    cout << "don't know" << endl;
    return;
  }

  for(int i=0;i<2;i++){
    m[i][i] = normalize(m[i][i]);
    m[i][2] = normalize(m[i][2]);
    if(m[i][i].nume==0)
      cout << "don't know" << endl;
    else{
      cout << m[i][2].nume;
      if(m[i][2].deno!=1)
        cout << '/' << m[i][2].deno;
      cout << endl;
    }
  }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  return 0;
}
