#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int num;

bool read(){
  cin >> num;
  return num!=0;
}

int gcd(int a, int b){
  return (b==0 ? a : gcd(b,a%b));
}

ll calcCombi(int a, int b){
  if(a==1) return 1;
  if(b<=0) return 1;
  
  vector<int> nume, deno;
  
  for(int i=2;i<=a;i++) nume.push_back(i);
  for(int i=2;i<=b;i++) deno.push_back(i);
  for(int i=2;i<=a-b;i++) deno.push_back(i);
  
  for(int i=0;i<nume.size();i++)
    for(int j=0;j<deno.size();j++){
      int div = gcd(nume[i],deno[j]);
      nume[i] /= div;
      deno[j] /= div;
    }

  long long ret = 1;
  for(int i=0;i<nume.size();i++)
    ret *= nume[i];
  
  return ret;
}

void work(){
  if(num==1){
    cout << "Cos(A)" << endl;
    return;
  }
  
  for(int i=0,j=0;i<=num;i+=2,j++){
    ll combi = calcCombi(num-j-1,j-1);
    ll power = (1LL<<(num-i));
    if(num-i==0) power = 1;
    ll coeff = (j==0 ? power/2 : power*combi*num/2/j);
    
    if(i!=0 && j%2==0) cout << '+';
    if(j%2==1) cout << '-';
    
    if(coeff!=1) cout << coeff;
    else {
      cout << 1;
      continue;
    }
    if(num-i>1) cout << "Cos^" << num-i << "(A)";
    else if(num-i==1) cout << "Cos(A)";
  }cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
