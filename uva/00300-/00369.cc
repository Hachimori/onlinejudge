#include<iostream>
#include<vector>

using namespace std;

int denom, numer;

bool read(){

  cin >> numer >> denom;
  if(denom==0 && numer==0) return false;
  
  return true;
}

int gcd(int a, int b){

  if(b==0) return a;
  else return gcd(b,a%b);

}

void work(){
  
  vector<int> denomList, numerList;

  for(int i=2;i<=denom;i++)
    denomList.push_back(i);

  for(int i=numer-denom+1;i<=numer;i++)
    numerList.push_back(i);

  /*
  for(int i=0;i<denomList.size();i++)
    cout << denomList[i] << ' ';
  cout << endl;

  for(int i=0;i<numerList.size();i++)
    cout << numerList[i] << ' ';
  cout << endl;  
  */

  for(int i=0;i<denomList.size();i++){
    for(int j=0;j<numerList.size();j++){
      int ret = gcd(denomList[i],numerList[j]);

      denomList[i]/=ret;
      numerList[j]/=ret;
    }
  }

  unsigned long long ans = 1;

  for(int i=0;i<numerList.size();i++)
    ans*=numerList[i];

  cout << numer << " things taken " << denom << " at a time is " << ans 
       << " exactly." << endl;
       
}

int main(){
  
  while(read())
    work();    

  return true;
}
