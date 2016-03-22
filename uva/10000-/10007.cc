#include<iostream>
#include<vector>
#include<list>

#define MAX_NUM 2000
#define MAX_SIZE 305

using namespace std;

class BigInt{
public:

  int digit[MAX_NUM];
  int digitLength;

  BigInt(){}
  BigInt(int n){
    int cursor=0;

    for(;n>0;cursor++,n/=10)
      digit[cursor] = n%10;

    digitLength = cursor;
  }
  
  void print(){
    int cursor=digitLength-1;
    
    while(cursor>=0 && digit[cursor]==0) cursor--;
    
    for(int i=cursor;i>=0;i--)
      cout << digit[i];
  }
  
  BigInt operator*( BigInt bi ){
    int result[MAX_NUM];

    for(int i=0;i<MAX_NUM;i++)
      result[i] = 0;

    for(int i=0;i<digitLength;i++)
      for(int j=0;j<bi.digitLength;j++)
	result[i+j] += bi.digit[j]*digit[i];

    for(int i=0;i<MAX_NUM;i++)
      if(result[i]>=10){
	result[i+1]+=result[i]/10;
	result[i]%=10;
      }

    for(int i=0;i<MAX_NUM;i++){
      bi.digit[i] = result[i];
      
      if(result[i]>0 && bi.digitLength<i+1)
	bi.digitLength = i+1;
    }
    
    return bi;
  }

};

BigInt catran[MAX_SIZE];
BigInt fract[MAX_SIZE];
BigInt table[MAX_SIZE];
int n;

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

void createTable(){
  
  catran[0] = 0;
  catran[1] = 1;

  for(int i=2;i<MAX_SIZE;i++){
    
    list<int> divided;
    list<int> divisor;
    
    for(int j=2*i;j>i;j--)
      divided.push_back(j);

    for(int j=i+1;j>1;j--)
      divisor.push_back(j);
    
    
    for(list<int>::iterator j=divided.begin();j!=divided.end();){
     for(list<int>::iterator k=divisor.begin();k!=divisor.end();){
	int ret=gcd(*j,*k);
	
	*j/=ret;
	*k/=ret;
	
	if(*k==1) k = divisor.erase(k);
	else k++;
      }

     if(*j==1) j = divided.erase(j);
     else j++;
    }

    BigInt ans=BigInt(1);

    for(list<int>::iterator j=divided.begin();j!=divided.end();j++)
      ans=ans*BigInt(*j);
    
    catran[i] = ans;
    //cout << "i " << i << "  "; catran[i].print(); cout << endl;
  }
  
  fract[1] = BigInt(1);
  
  for(int i=2;i<MAX_SIZE;i++)
    fract[i] = fract[i-1]*BigInt(i);
  
  
  for(int i=1;i<MAX_SIZE;i++){
    table[i] = catran[i]*fract[i];
  }
}

bool read(){
  cin >> n;
  if(n==0) return false;
  return true;
}

void work(){
  table[n].print(); cout << endl;
}

int main(){

  createTable();

  while(read())
    work();

  return 0;
}
