#include<iostream>
using namespace std;
const int BUF = 15;

int main(){
  int sz, b[BUF][BUF];

  for(int kk=0;cin>>sz,sz;kk++){
    for(int i=0;i<sz;i++)
      for(int j=0;j<sz;j++)
        cin >> b[i][j];
    
    cout << "Case " << kk+1 << ":";
    for(int k=0;k<(sz+1)/2;k++){
      int sum = 0;
      for(int i=k;i<sz-k;i++)
        for(int j=k;j<sz-k;j++)
          if(i==k || i==sz-k-1 || j==k || j==sz-k-1)
            sum += b[i][j];
      cout << ' ' << sum;
    }
    cout << endl;
  }
  return 0;
}
