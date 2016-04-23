#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstdio>

#define MODULO 10000
#define UNIT_LENGTH  4
#define DATA_LENGTH 400
#define MAX_SIZE 1005

using namespace std;

class BigInt{
public:

  int pos;
  int data[DATA_LENGTH];
  
  BigInt(){
    setData("0");
  }
  
  BigInt(const char *data){
    setData(data);
  }
  
  void init(){
    fill(data,data+DATA_LENGTH,0);
    pos = 0;
  }

  void setData(const char str[]){
    init();
    
    int length = strlen(str);
    for(int i=0;length>0;i++){
      if(i==UNIT_LENGTH){
	i = 0;
	pos++;
      }
      data[pos] += (str[--length]-'0')*(int)(pow(10.0,i)+0.5);
    }
    pos++;
  }
  
  void output() const {
    cout << data[pos-1];
    cout << setfill('0');
    for(int i=pos-2;i>=0;i--){
      cout  << setw(UNIT_LENGTH) << data[i];
    }
  }
  
  void operator+=(const BigInt &bint){
    pos = max(pos,bint.pos);
    for(int i=0;i<pos;i++){
      data[i] += bint.data[i];
      data[i+1] += data[i]/MODULO;
      data[i] %= MODULO;
    }
    
    if(data[pos]>0)
      pos++;
  }
  
  
  void operator/=( const int &divider){
    for(int i=pos-1;i>0;--i){
      int reminder = data[i] % divider;
      data[i]/=divider;
      data[i-1] += reminder*MODULO;
    }
    while(data[pos-1]<=0)
      --pos;
    
    data[0] /= divider;
  }
  
};

int nBeer, nPerson;
BigInt costList[MAX_SIZE];

bool read(){
  
  cin >> nBeer >> nPerson;
  if(nBeer==0 && nPerson==0) return false;
  
  for(int i=0;i<nBeer;i++){
    string str;
    cin >> str;
    
    costList[i] = BigInt(str.c_str());
  }
    
  
  return true;
}

void work(int cases){
  
  BigInt sum;
  
  sum.init();

  for(int i=0;i<nBeer;i++){
    sum+=costList[i];
  }
  
  printf("Bill #%d costs ",cases);
  sum.output();
  printf(": each friend should pay ");
  
  sum/=nPerson;
  
  sum.output();
  cout << endl;
}

int main(){
  
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}