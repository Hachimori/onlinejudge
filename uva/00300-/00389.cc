#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string source;
int sourceBase, targetBase;

bool read(){

  if(!(cin >> source >> sourceBase >> targetBase)) return false;

  return true;
}

void work(){
  
  unsigned long long sourceInt=0, p=1;

  for(int i=source.length()-1;i>=0;i--,p*=sourceBase){
    if(isalpha(source[i])) sourceInt+=(source[i]-'A'+10)*p;
    if(isdigit(source[i])) sourceInt+=(source[i]-'0')*p;
  }
  
  
  string target;
  if(sourceInt==0)
    target+='0';
  for(;sourceInt>0;sourceInt/=targetBase){    
    if(sourceInt%targetBase<10)
      target+=(char)(sourceInt%targetBase+'0');
    else
      target+=(char)(sourceInt%targetBase+'A'-10);
  }
  
  if(target.length()>7) cout << "  ERROR" << endl;
  else {
    for(int i=0;i<7-target.length();i++) cout << ' ';
    for(int i=target.length()-1;i>=0;i--)
      cout << target[i];
    cout << endl;
  }
  

}

int main(){

  while(read())
    work();

  return 0;
}
