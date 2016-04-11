#include<iostream>

using namespace std;

int init;
int cipher[3];

bool read(){

  cin >> init >> cipher[0] >> cipher[1] >> cipher[2];
  if(init==0 && cipher[0]==0 && cipher[1]==0 && cipher[2]==0) return false;
  
  return true;
}

void work(){

  int sum=0;

  sum+=(360-(cipher[0]-init)*9)%360;
  //  cout << (cipher[0]-init)/40*360 << endl;
  sum+=(360+(cipher[1]-cipher[0])*9)%360;
  sum+=(360-(cipher[2]-cipher[1])*9)%360;
  
  
  cout << sum+1080 << endl;
}

int main(){

  while(read())
    work();

  return 0;
}
