#include<iostream>
#include<string>
using namespace std;
const int BUF = 85;

string src, dst, toConvert;

bool read(){
  getline(cin,src);
  if(src[0]=='#') return false;
  getline(cin,dst);
  getline(cin,toConvert);
  return true;
}

bool rec(int curr, bool used[BUF], int perm[BUF], int len, string &a, string &b){
  if(curr==len) return true;
  
  for(int i=0;i<len;i++){
    if(used[i]) continue;

    bool fail = false;
    for(int j=curr,k=0;j<a.size();j+=len,k+=len)
      if(a[j]!=b[k+i]){
        fail = true;
        break;
      }
    if(fail) continue;

    perm[curr] = i;
    used[i] = true;
    if(rec(curr+1,used,perm,len,a,b)) return true;
    used[i] = false;
  }
  return false;
}

void work(){
  for(int len=1;len<=src.size();len++){
    string src2 = src, dst2 = dst, toConvert2 = toConvert;
    
    if(src.size()%len!=0){
      src2 += string(len-src.size()%len,'?');
      dst2 += string(len-src.size()%len,'?');
      
    }
    if(toConvert.size()%len!=0)
      toConvert2 += string(len-toConvert.size()%len,'?');
   
    int perm[BUF];
    bool used[BUF] = {false};
    if(rec(0,used,perm,len,src2,dst2)){
      for(int i=0;i<toConvert2.size();i+=len)
        for(int j=i;j<i+len;j++)
          cout << toConvert2[perm[j-i]+i];
      cout << endl;
      return;
    }
  }
  cout << toConvert << endl;
}

int main(){
  while(read())
    work();

  return 0;
}
