// 10473

#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>

#define MAX_SIZE 60

using namespace std;

string source;

bool read(){

  cin >> source;
  if(source[0]=='-') return false;

  return true;
}

void work(){

  long long digit=0;

  if(source.length()>2 && source[0]=='0' && source[1]=='x'){
    
    long long p=1;

    for(int i=source.length()-1;i>=2;p*=16,i--){
      if(isalpha(source[i]))
	digit+=p*(source[i]-'A'+10);
      else digit+=p*(source[i]-'0');
    }
    
    cout << digit << endl;
   
  }
  else {

    long long p=1;

    for(int i=source.length()-1;i>=0;p*=10,i--){
      digit+=p*(source[i]-'0');
    }
    
    
    int hexDigit[MAX_SIZE];

    for(int i=0;i<MAX_SIZE;i++)
      hexDigit[i] = 0;

    for(int i=0;digit>0;digit/=16,i++)
      hexDigit[i] = digit%16;
    
    
    cout << "0x";
    
    int cursor=MAX_SIZE-1;
    while(cursor>=0 && hexDigit[cursor]==0) cursor--;

    if(cursor==-1){ 
      cout << 0 << endl;
      return;
    }
    
    for(;cursor>=0;cursor--){
      if(hexDigit[cursor]>=10){
	cout << (char)(hexDigit[cursor]-10+'A');
      }
      else
	cout << hexDigit[cursor];
    }
    cout << endl;

  }
  
}

int main(){

  while(read())
    work();

  return 0;
}
