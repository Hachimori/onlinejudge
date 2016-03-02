#include<iostream>
#include<string>
using namespace std;
const int BUF = 15;


int sz;
string src[BUF], dst[BUF];

bool read(){
  if(!(cin >> sz)) return false;
  for(int i=0;i<sz;i++)
    cin >> src[i] >> dst[i];
  return true;
}


void rot90(string s[BUF]){
  char nex[BUF][BUF];
  for(int r=0;r<sz;r++)
    for(int c=0;c<sz;c++)
      nex[c][sz-r-1] = s[r][c];

  for(int r=0;r<sz;r++)
    for(int c=0;c<sz;c++)  
      s[r][c] = nex[r][c];
}


void reflect(string s[BUF]){
  for(int r=0;r<sz/2;r++)
    for(int c=0;c<sz;c++)
      swap(s[r][c],s[sz-r-1][c]);
}


bool same(string a[BUF], string b[BUF]){
  for(int i=0;i<sz;i++)
    if(a[i]!=b[i])
      return false;
  return true;
}


void work(int cases){
  cout << "Pattern " << cases << " was ";
  for(int ref=0;ref<2;ref++){
    for(int rot=0;rot<4;rot++){
      if(same(src,dst)){
        if(ref==0 && rot==0)
          cout << "preserved." << endl;
        else if(ref==0)
          cout << "rotated " << rot*90 << " degrees." << endl;
        else if(rot==0)
          cout << "reflected vertically." << endl;
        else
          cout << "reflected vertically and rotated " << rot*90 << " degrees." << endl;
        return;
      }
      rot90(src);
    }
    reflect(src);
  }
  cout << "improperly transformed." << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
