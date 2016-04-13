#include<iostream>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
const int BURDEN = 25, BUF = 205;

int main(){
  int cases;
  cin >> cases;
  string s; 
  getline(cin,s);
  for(int kk=0;kk<cases;kk++){
    getline(cin,s);
    stringstream in(s);
    int nVal=0,val[BURDEN], v;
    while(in>>v) val[nVal++] = v;
    
    bool avail[BUF]={0};
    avail[0] = true;
    for(int i=0;i<nVal;i++)
      for(int j=BUF-1;j>=0;j--)
        if(avail[j])
          avail[j+val[i]] = true;

    if(accumulate(val,val+nVal,0)%2==0 && 
       avail[accumulate(val,val+nVal,0)/2])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
