#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define LENG 35
using namespace std;

class Data{
public:
  char ch;
  int nCh;

  Data(){}
  Data(int n, char c): nCh(n), ch(c){}

  bool operator< (const Data &d) const {
    return nCh<d.nCh;
  }
};

int n;
string s;

void read(){
  cin >> s >> n;
  n--; 
  sort(s.begin(),s.end());  
}

int gcd(int a, int b){
  return (b==0 ? a : gcd(b,a%b));
}

long long combination(int nu, vector<Data> &data){
  vector<int> nume, deno;
  
  for(int i=2;i<=nu;i++)
    nume.push_back(i);
      
  for(int i=0;i<data.size();i++)
    for(int j=2;j<=data[i].nCh;j++)
      deno.push_back(j);
  
  for(int i=0;i<nume.size();i++)
    for(int j=0;j<deno.size();j++){
      int div = gcd(nume[i],deno[j]);
      nume[i] /= div;
      deno[j] /= div;
    }

  long long ret = 1;
  for(int i=0;i<nume.size();i++)
    ret *= nume[i];
  
  return ret;
}

void work(int cases){
  cout << "Case " << cases << ": ";
  
  vector<Data> data;

  for(int i=0,cntOdd=0;i<s.size();i++){
    int sum = 1;
    while(i+1<s.size() && s[i]==s[i+1]) sum++, i++;
    if(sum%2==1) cntOdd++;

    if(cntOdd==2){
      cout << "XXX" << endl;
      return;
    }
    data.push_back(Data(sum,s[i]));
  }
  
  char mid = -1;
  for(int i=0;i<data.size();i++){
    if(data[i].nCh%2==1)
      mid = data[i].ch;
    data[i].nCh /= 2;
  }
  
  int leng = s.size()/2;
  if(combination(leng,data)<=n){
    cout << "XXX" << endl;
    return;
  }
  
  char order[LENG];
  for(int i=0;i<leng;i++){
    for(int cur=0;cur<data.size();cur++){
      if(data[cur].nCh==0) continue;
      data[cur].nCh--;
      order[i] = data[cur].ch;
      
      if(combination(leng-i-1,data)>n)break;

      n -= combination(leng-i-1,data);
      data[cur].nCh++;
    }
  }

  for(int i=0;i<leng;i++)
    cout << order[i];
  if(mid!=-1) cout << mid;
  for(int i=leng-1;i>=0;i--)
    cout << order[i];
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
