#include<iostream>
#include<vector>
using namespace std;

int num;

bool read(){
  cin >> num;
  return num>=0;
}

void work(){
  if(num==0){
    cout << 0 << endl;
    return;
  }

  vector<int> digit;
  while(num>0){
    digit.push_back(num%3);
    num /= 3;
  }
  
  for(int i=digit.size()-1;i>=0;i--)
    cout << digit[i];
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
