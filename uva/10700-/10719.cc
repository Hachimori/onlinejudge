#include<iostream>
#include<string>

#define MAX_SIZE 10005

using namespace std;

int k;
int nTerm;
int term[MAX_SIZE];

bool read(){

  if(!(cin >> k)) return false;
  
  string str;
  getline(cin,str); getline(cin,str);
  
  nTerm=0;
  int cursor=0;

  while(cursor<str.length()){
    
    bool minus=false;
    
    while(cursor<str.length() && str[cursor]==' ') cursor++;
    if(cursor<str.length() && str[cursor]=='-'){
      minus=true;
      cursor++;
    }
      
    if(cursor==str.length()) break;

    int sum=0;
    while(cursor<str.length() && str[cursor]!=' '){
      sum*=10;
      sum+=str[cursor]-'0';
      cursor++;
    }
    
    if(minus)
      sum*=(-1);

    term[nTerm] = sum;    
    nTerm++;
  }

  return true;
}

void work(){
  
  int coefficient[MAX_SIZE];

  for(int i=0;i+1<nTerm;i++){
    term[i+1] += term[i]*k;
    coefficient[i] = term[i];
  }
  

  cout << "q(x):";
  for(int i=0;i<nTerm-1;i++){
    cout << ' ' << coefficient[i];
  }cout << endl;
  
  cout << "r = " << term[nTerm-1] << endl;
  
}

int main(){

  for(int i=0;read();i++){
    work();
    cout << endl;
  }

  return 0;
}
