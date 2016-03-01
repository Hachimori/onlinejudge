#include<iostream>
#include<cstdio>

#define LIMIT 370
#define MAX_SIZE 800

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

  
  BigInt operator*( BigInt bi ){
    int result[MAX_SIZE];

    for(int i=0;i<MAX_SIZE;i++)
      result[i] = 0;

    for(int i=0;i<digitLength;i++)
      for(int j=0;j<bi.digitLength;j++)
	result[i+j] += bi.digit[j]*digit[i];

    for(int i=0;i<MAX_SIZE;i++){
      if(result[i]>=10){
	result[i+1]+=result[i]/10;
	result[i]%=10;
      }
    }
    
    for(int i=0;i<MAX_SIZE;i++){
      bi.digit[i] = result[i];

      if(result[i]>0 && bi.digitLength<i+1)
	bi.digitLength=i+1;
    }
    
    return bi;
  }
  
  int &operator[] (int n) {
    return digit[n];
  }

};


BigInt biList[LIMIT];

void makeTable(){

  biList[0] = BigInt(0);
  biList[1] = BigInt(1);
  
  for(int i=2;i<LIMIT;i++)
    biList[i] = biList[i-1]*BigInt(i);
    
}

int main(){

  makeTable();

  while(true){
    int n;
    cin >> n;
    
    if(n==0) break;

    int nAppear[10];
    for(int i=0;i<10;i++)
      nAppear[i]=0;

    for(int i=0;i<biList[n].digitLength;i++)
      nAppear[biList[n][i]]++;

    
    cout << n << "! --" << endl;
    printf("   (0)%5d    (1)%5d",nAppear[0],nAppear[1]);
    printf("    (2)%5d    (3)%5d    (4)%5d\n",nAppear[2],nAppear[3],nAppear[4]);
    printf("   (5)%5d    (6)%5d",nAppear[5],nAppear[6]);
    printf("    (7)%5d    (8)%5d    (9)%5d\n",nAppear[7],nAppear[8],nAppear[9]);
    

  }

  return 0;
}
