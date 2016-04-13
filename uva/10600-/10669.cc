#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long integer;

integer n;

bool read(){
  cin >> n;
  return n!=0;
}

void work(){
  n--;
  if(n==0){
    cout << "{ }" << endl;
    return;
  }

  vector<string> str;
  
  for(int k=0;n>0;k++,n/=2){
    if((n&1)==0) continue;
    int array[1000];
    for(int i=0;i<1000;i++) array[i] = 0;
    array[0] = 1;
    
    for(int j=0;j<k;j++){
      for(int cur=0;cur<1000;cur++) array[cur] *= 3;
      for(int cur=0;cur<1000;cur++)
        if(array[cur]>=10){
          array[cur+1] += array[cur]/10;
          array[cur] %= 10;
        }
    }
    
    str.push_back("");
    int cur = 999;
    while(array[cur]==0) cur--;
    while(cur>=0) str.back() += array[cur--]+'0';
  }

  cout << "{ ";
  for(int i=0;i<str.size();i++){
    if(i) cout << ", ";
    cout << str[i];
  }
  cout << " }" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
