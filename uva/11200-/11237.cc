#include<iostream>
#include<map>
using namespace std;
const int VAL = 100005;

int nPpl, nVal, val[VAL];

bool read(){
  cin >> nPpl >> nVal;
  if(!(nPpl|nVal)) return false;
  for(int i=0;i<nVal;i++)
    cin >> val[i];
  return true;
}

void work(){
  map<int,int> sum; // (sum,idx)
  sum[0] = -1;

  long long curSum = 0;
  for(int i=0;i<nVal;i++){
    curSum += val[i];
    if(sum.count(curSum%nPpl)){
      for(int j=sum[curSum%nPpl]+1;j<=i;j++){
        if(j!=sum[curSum%nPpl]+1) cout << ' ';
        cout << j+1;
      }
      cout << endl;
      break;
    }
    sum[curSum%nPpl] = i;
  }
}

int main(){
  while(read()) work();
  return 0;
}
