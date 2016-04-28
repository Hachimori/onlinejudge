#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

class Data{
public:
  int a,b,c;

  Data(){}
  Data(int a, int b, int c): a(a), b(b), c(c){}
  
  bool operator< (const Data &d) const {
    if(a!=d.a) return a<d.a;
    if(b!=d.b) return b<d.b;
    return c<d.c;
  }
};

set<Data> S;

void makeSet(){
  for(int i=0;i<50;i++){
    S.insert(Data(i+1,1,i+2));
    for(int j=1;j<50;j++)
      S.insert(Data(i+1,1+j,i+j+2));
  }
}

string str;

void read(){
  cin >> str;
}

void work(){
  for(int i=0;i<str.size();i++)
    if(str[i]!='M' && str[i]!='E' && str[i]!='?'){
      cout << "no-theorem" << endl;
      return;
    }

  if(count(str.begin(),str.end(),'M')!=1 ||
     count(str.begin(),str.end(),'E')!=1 ||
     str.find('M')>str.find('E') ){
    cout << "no-theorem" << endl;
    return;
  }

  int cnt[]={0,0,0}, idx = 0;

  for(int i=0;i<str.size();i++)
    if(str[i]=='M' || str[i]=='E') 
      idx++;
    else
      cnt[idx]++;
  
  if(S.count(Data(cnt[0],cnt[1],cnt[2])))
    cout << "theorem" << endl;
  else
    cout << "no-theorem" << endl;
}

int main(){
  makeSet();

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work();
  }
  
  return 0;
}
