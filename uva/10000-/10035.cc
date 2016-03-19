#include<iostream>
#include<string>
#include<algorithm>

#define MAX_NUM 14

using namespace std;

int aNum, bNum;
int aDigit[MAX_NUM], bDigit[MAX_NUM];

bool read(){
  
  string a,b;
  cin >> a >> b;
  if(a=="0" && b=="0") return false;

  aNum=a.length();
  bNum=b.length();

  
  for(int i=0;i<MAX_NUM;i++)
    aDigit[i]=bDigit[i]=0;
  

  for(int i=aNum-1,j=0;i>=0;i--,j++)
    aDigit[j] = a[i]-'0';

  for(int i=bNum-1,j=0;i>=0;i--,j++)
    bDigit[j] = b[i]-'0';


  return true;
}

void work(){

  int nCarry=0;

  for(int i=0;i<max(aNum,bNum);i++){
    if(aDigit[i]+bDigit[i]>=10){
      nCarry++;
      aDigit[i+1]++;
    }      
  }

  if(nCarry==0) cout << "No carry operation." << endl;
  else if(nCarry==1) cout << nCarry << " carry operation." << endl;
  else cout << nCarry << " carry operations." << endl;

}

int main(){
  
  while(read())
    work();
  
  return true;
}
