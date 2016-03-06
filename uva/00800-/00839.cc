#include<iostream>
#include<cassert>

#define NO -1

using namespace std;
  
int work(){

  int lw, ld, rw, rd;

  cin >> lw >> ld >> rw >> rd;
  
  if(lw==0) lw = work();
  if(rw==0) rw = work();
  
  //cout << lw << ' ' << ld << ' ' << rw << ' ' << rd << endl;
  
  if(lw==NO || rw==NO) return NO;
  if(lw*ld != rw*rd) return NO;

  return lw+rw;

}

int main(){
  
  int cases;
  cin >> cases;

  //char str[100];
  //gets(str);
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;

    if(work()==NO) cout << "NO" << endl;
    else cout << "YES" << endl;

    //gets(str);
  }

  return 0;
}
