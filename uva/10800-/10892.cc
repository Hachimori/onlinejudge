#include<iostream>
#include<vector>
#define factor first
#define count second
using namespace std;
typedef pair<int,int> Data;

int num;

bool read(){
  cin >> num;
  return num!=0;
}

void rec(int idx, int mul, vector<Data> &data, vector<int> &divisor){
  if(idx==data.size()){
    divisor.push_back(mul);
    return;
  }

  for(int i=0,p=1;i<=data[idx].count;i++,p*=data[idx].factor)
    rec(idx+1,mul*p,data,divisor);
}

int gcd(int a, int b){
  return b==0 ? a : gcd(b,a%b);
}

void work(){
  vector<Data> data;
  
  int cur = num;
  for(long long i=2;i*i<=num;i++){
    int cnt = 0;
    while(cur%i==0){
      cur /= i;
      cnt++;
    }

    if(cnt>0)
      data.push_back(Data(i,cnt));
  }
  if(cur!=1) data.push_back(Data(cur,1));


  vector<int> divisor;
  rec(0,1,data,divisor);
  

  int ans = 0;
  for(int i=0;i<divisor.size();i++)
    for(int j=i;j<divisor.size();j++)
      if(divisor[i]/gcd(divisor[i],divisor[j])*divisor[j]==num)
	ans++;

  cout << num << ' ' << ans << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
