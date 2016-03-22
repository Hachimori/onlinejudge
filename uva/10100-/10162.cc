#include<iostream>
#include<string>

#define MAX_SIZE 10

using namespace std;

string digit;

bool read(){
  cin >> digit;
  if(digit=="0") return false;
  return true;
}

void work(){
  
  const static int tenList[MAX_SIZE]={7,7,7,7,7,7,7,7,7,7};
  const static int evenList[MAX_SIZE]={1,4,7,6,5,6,3,6,9,0};
  const static int oddList[MAX_SIZE]={1,6,3,6,5,6,7,4,9,0};


  int sum=0;
  
  if(digit.size()>=2)
    for(int i=0;i<digit[digit.size()-2]-'0';i++)
      sum+=tenList[i];
  
  for(int i=0;i<digit[digit.size()-1]-'0';i++){
    if(digit.size()>=2 && digit[digit.size()-2]%2==1) sum+=oddList[i];
    else  sum+=evenList[i];
  }

  cout << sum%10 << endl;

}

int main(){
  
  while(read())
    work();

  return 0;
}

