#include<iostream>
#include<algorithm>
using namespace std;

long long L[3];

void read(){
  cin >> L[0] >> L[1] >> L[2];
}

void work(int cases){
  sort(L,L+3);
  cout << "Case " << cases << ": ";
  if(L[0]+L[1]<=L[2])
    cout << "Invalid" << endl;
  else if(L[0]==L[1] && L[1]==L[2])
    cout << "Equilateral" << endl;
  else if(L[0]==L[1] || L[1]==L[2])
    cout << "Isosceles" << endl;
  else
    cout << "Scalene" << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
