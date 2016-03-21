#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define MAX_SIZE 103

using namespace std;

class BigInt{
public:
  
  int digit[MAX_SIZE];

  BigInt(){}
  BigInt(string strDigit){
    
    for(int i=strDigit.length();i<MAX_SIZE;i++)
      digit[i]=0;

    for(int i=strDigit.length()-1,j=0;i>=0;j++,i--)
      digit[j]=strDigit[i]-'0';
  }

  void print(){
    int cursor=MAX_SIZE-1;

    while(cursor>=0 && digit[cursor]==0) cursor--;

    for(;cursor>=0;cursor--)
      cout << digit[cursor];
    cout << endl;
  }

  int operator[] (int n) const {
    return digit[n];
  }

  BigInt operator+ ( BigInt bi ) {

    for(int i=0;i<MAX_SIZE;i++)
      bi.digit[i]+=digit[i];
    
    for(int i=0;i<MAX_SIZE;i++)
      if(bi.digit[i]>=10){
	bi.digit[i]%=10;
	bi.digit[i+1]++;
      }
    
    return bi;
  }

  bool operator< ( const BigInt &bi ) const {
    for(int i=MAX_SIZE-1;i>=0;i--)
      if(digit[i]<bi.digit[i]) 
	return true;
      else if(digit[i]>bi.digit[i])
	return false;
    
    return false;
  }

};

string a, b;
vector<BigInt> biList;

void makeTable(){
  
  biList.push_back(BigInt("1"));
  biList.push_back(BigInt("2"));
  
  while(true){
    biList.push_back(biList[biList.size()-1]+biList[biList.size()-2]);
    
    if(biList.back()[100]>=1) break;
  }
  
}

bool read(){

  cin >> a >> b;
  if(a=="0" && b=="0") return false;

  return true;
}

void work(){
  
  BigInt aBI=BigInt(a), bBI=BigInt(b);

  cout << upper_bound(biList.begin(),biList.end(),bBI)
    - lower_bound(biList.begin(),biList.end(),aBI) << endl;

}

int main(){

  makeTable();

  while(read())
    work();

  return 0;
}
