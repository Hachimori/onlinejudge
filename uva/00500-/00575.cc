#include<iostream>
#include<string>
#include<cmath>

using namespace std;

string source;

bool read(){
  getline(cin,source);

  if(source=="0") return false;

  return true;
}

void work(){
  
  long long sum=0;

  for(int i=source.length()-1,j=1;i>=0;i--,j++){
    sum += (source[i]-'0')*((int)(pow(2,j)+0.5)-1);
  }
  
  cout << sum << endl;
}

int main(){

  while(read())
    work();
  
  return 0;
}
