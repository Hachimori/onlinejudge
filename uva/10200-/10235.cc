#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>

#define MAX_SIZE 1000000

using namespace std;

string strDigit;
bool isPrime[MAX_SIZE];

void makePrime(){

  for(int i=0;i<MAX_SIZE;i++)
    isPrime[i] = true;

  isPrime[1] = true;
  isPrime[2] = true;
  
  for(int i=2;i*i<MAX_SIZE;i++)
    if(isPrime[i])
      for(int j=i*2;j<MAX_SIZE;j+=i)
	isPrime[j]=false;

}

bool read(){
  if(!(cin >> strDigit)) return false;
  return true;
}

void work(){
  
  int num, reverseNum;

  num = atoi(strDigit.c_str());

  reverse(strDigit.begin(),strDigit.end());

  reverseNum = atoi(strDigit.c_str());
  
  if(num!=reverseNum && isPrime[reverseNum] && isPrime[num]) cout << num << " is emirp." << endl;
  else if(isPrime[num]) cout << num << " is prime." << endl;
  else cout << num << " is not prime." << endl;



}

int main(){

  makePrime();

  while(read())
    work();

  return 0;
}
