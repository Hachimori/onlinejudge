#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<sstream>
using namespace std;

string s;

void read(){
  getline(cin,s);
}

pair<int,int> convert(string fracS){
  stringstream in(fracS);
  vector<int> num;
  
  for(int n;in>>n;) num.push_back(n);
  if(num.size()==1) return make_pair(num[0],1);
  if(num.size()==2) return make_pair(num[0],num[1]);
  if(num.size()==3) return make_pair(num[1]+num[0]*num[2],num[2]);
}

int gcd(int a, int b){
  return (b==0 ? a : gcd(b,a%b));
}

void work(){
  int nume = 1, deno = 1;

  for(int cur=0;cur<s.size();){
    string fracS;
    while(cur<s.size() && !isdigit(s[cur])) cur++;
    while(cur<s.size() && 
	  (isdigit(s[cur]) || s[cur]=='/' || s[cur]=='-')){
      if(isdigit(s[cur])) fracS += s[cur];
      else fracS += ' ';
      cur++;
    }
    
    if(fracS.size()==0) continue;
    pair<int,int> frac = convert(fracS);

    nume *= frac.first;
    deno *= frac.second;

    int div = gcd(nume,deno);
    nume /= div;
    deno /= div;
  }

  if(deno==1) cout << nume << endl;
  else {
    if(nume>deno) cout << nume/deno << '-';
    cout << nume%deno << '/' << deno << endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  string dummy; getline(cin,dummy);

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
