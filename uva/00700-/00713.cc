#include<iostream>
#include<string>
#include<algorithm>

#define MAX_NUM 205

using namespace std;

string aStr, bStr;
int a[MAX_NUM], b[MAX_NUM];

void read(){

  cin >> aStr >> bStr;
  
  for(int i=0;i<MAX_NUM;i++){
    a[i] = 0;
    b[i] = 0;
  }

  for(int i=0;i<aStr.length();i++)
    a[i] = aStr[i]-'0';

  for(int i=0;i<bStr.length();i++)
    b[i] = bStr[i]-'0';

}

void work(){

  int ans[MAX_NUM];

  for(int i=0;i<MAX_NUM;i++)
    ans[i] = 0;

  for(int i=0;i<max(aStr.length(),bStr.length());i++){
    ans[i] += a[i]+b[i];
    
    if(ans[i]>=10){
      ans[i]-=10;
      ans[i+1]++;
    }
  }

  int cursor=0;    
  while(cursor<max(aStr.length(),bStr.length()) && ans[cursor]==0)
    cursor++;
  
  for(;cursor<MAX_NUM;){
    
    cout << ans[cursor];

    bool nonZeroExist=false;
    int nonZeroPos;
    
    for(int i=cursor+1;i<MAX_NUM;i++){
      if(ans[i]!=0){ 
	nonZeroExist=true;
	nonZeroPos = i;
	break;
      }
    }
    
    if(nonZeroExist){
      for(cursor+=1;cursor<=nonZeroPos-1;cursor++)
	cout << ans[cursor];
    }
    else break;
  }
  
  cout << endl;

}

int main(){

  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work();
  }


  return 0;
}
