#include<iostream>

#define MAX_SIZE 3000

using namespace std;

class BigInt{
public:

  int digit[MAX_SIZE];
  int digitLength;

  BigInt(){}
  BigInt(int n){
    int cursor=0;
    
    for(;n>0;cursor++,n/=10)
      digit[cursor] = n%10;

    digitLength = cursor;
    
  }

  int operator[] (int n) const {
    return digit[n];
  } 

  BigInt operator+( BigInt bi ){
    for(int i=0;i<digitLength;i++)
      bi.digit[i]+=digit[i];
    
    for(int i=0;i<bi.digitLength;i++)
      if(bi.digit[i]>=10){
	bi.digit[i]%=10;
	bi.digit[i+1]++;
	
	if(bi.digitLength<i+1)
	  bi.digitLength = i+1;
      }
    
    return bi;
  }

  BigInt operator*( BigInt bi ){
    int result[MAX_SIZE];
    
    for(int i=0;i<MAX_SIZE;i++)
      result[i] = 0;
    
    for(int i=0;i<digitLength;i++)
      for(int j=0;j<bi.digitLength;j++)
	result[i+j] += bi.digit[j]*digit[i];
    
    for(int i=0;i<MAX_SIZE;i++)
      if(result[i]>=10){
	result[i+1]+=result[i]/10;
	result[i]%=10;
      }

    for(int i=0;i<MAX_SIZE;i++){
      bi.digit[i] = result[i];
      
      if(result[i]>0 && bi.digitLength<i+1)
	bi.digitLength = i+1;
    }

    return bi;
  }

  bool input(){
    char c;
    int i;
    
    int tmpDigit[MAX_SIZE];

    while(true){
      if(cin.get(c)==NULL) return false;
      if('0'<=c && c<='9'){
	tmpDigit[0] = c;
	break;
      }
    }

    for(i=1;;i++){
      char c;
      if(cin.get(c)==NULL) break;
      if(c=='\n' || c==' ' || c=='\t') break;

      tmpDigit[i] = c;
    }

    digitLength = i;

    for(int j=i;j<MAX_SIZE;j++)
      digit[j] = 0;

    for(int k=0,j=i-1;k<i;k++,j--)
      digit[k] = tmpDigit[j];
    
    return true;
  }

  void print(){    
    int cursor=MAX_SIZE-1;
    
    while(cursor>=0 && digit[cursor]==0) cursor--;

    for(int i=cursor;i>=0;i--)
      cout << digit[i];
  }

};

int target;

bool read(){
  if(!(cin >> target)) return false;

  return true;
}

void work(){

  BigInt bi = BigInt(1);
  
  for(int i=2;i<=target;i++){
    bi = bi*BigInt(i);
    
    //bi.print(); cout << endl;
  }

  int ans=0;
  for(int i=0;i<MAX_SIZE;i++)
    ans+=bi[i];

  cout << ans << endl;
}

int main(){
  
  while(read())
    work();

  return 0;
}
