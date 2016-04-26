#include<iostream>
#include<complex>
#include<vector>
using namespace std;
typedef complex<int> Point;

Point init;

void read(){
  int r, i;
  cin >> r >> i;

  init = Point(r,i);
}

void work(int cases){
  if(init==Point(0,0)){
    cout << "Case #" << cases << ": 0" << endl;
    return;
  }
  
  vector<int> ans;
  Point curr = init;
  
  while(curr!=Point(1,0)){
    curr *= Point(-1,-1);
    
    if(abs(curr.real())%2==0 && abs(curr.imag())%2==0){
      curr = Point(curr.real()/2,curr.imag()/2);
      ans.push_back(0);
    }
    else{
      curr -= Point(-1,-1);
      curr = Point(curr.real()/2,curr.imag()/2);
      ans.push_back(1);
    }
    
  }ans.push_back(1);

  cout << "Case #" << cases << ": ";
  for(int i=ans.size()-1;i>=0;i--)
    cout << ans[i];
  cout << endl;
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
