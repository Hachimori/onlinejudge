#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> tbl[9];
  for(int i=2;i<=8;i+=2){
    int p = 1;
    for(int j=0;j<i/2;j++,p*=10);
    for(int A=0;A<p;A++)
      for(int B=0;B<p;B++)
        if((A+B)*(A+B)==A*p+B)
          tbl[i].push_back(A*p+B);
  }
  
  int n;
  while(cin >> n)
    for(int i=0;i<tbl[n].size();i++)
      printf("%0*d\n",n,tbl[n][i]);
  return 0;
}
