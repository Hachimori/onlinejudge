#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int nAdd, range;
string str;

bool read(){
  char d;
  cin >> nAdd >> d >> range;
  if(nAdd==0 && range==0) return false;
  getline(cin,str);  getline(cin,str);
  return true;
}

void work(){
  int sum = 0, p = 0;
  
  for(int k=range-1;k>0;p++,k>>=1);
  
  for(int cur=0;cur+p<=str.size() && nAdd!=0;cur+=p){
    int toAdd = 0;
    for(int i=cur;i<cur+p;i++){
      toAdd <<= 1;
      toAdd += (str[i]=='T');
    } 
    toAdd++;
    
    if(toAdd<=range){
      sum += toAdd;
      nAdd--;
    }
  }
  
  cout << (nAdd==0 ? sum : -1) << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
