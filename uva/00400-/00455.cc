#include<iostream>
#include<string>
using namespace std;


string str;

void read(){
  cin >> str;
}


void work(){
  for(int len=1;len<=str.size();len++){
    if(str.size()%len!=0) continue;
    bool ok = true;
    for(int i=0;i<str.size();i++)
      ok &= str[i]==str[i%len];
    if(ok){
      cout << len << endl;
      break;
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
