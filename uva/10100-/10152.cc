#include<iostream>
#include<string>
#include<vector>
using namespace std;


int nMan;
vector<string> src, dst;

void read(){
  cin >> nMan;
  src = dst = vector<string>(nMan);
  string dummy; getline(cin,dummy);
  for(int i=0;i<nMan;i++) getline(cin,src[i]);
  for(int i=0;i<nMan;i++) getline(cin,dst[i]);
}

void ope(vector<string> &self, int idx){
  self.insert(self.begin(),self[idx]);
  self.erase(self.begin()+idx+1);
}

void work(){
  vector<string> ans;
  while(src!=dst){
    int srcIdx = nMan-1;
    for(int dstIdx=nMan-1;;dstIdx--){
      while(srcIdx>=0 && src[srcIdx]!=dst[dstIdx]) srcIdx--;
      if(srcIdx==-1){
        int idx = find(src.begin(),src.end(),dst[dstIdx])-src.begin();
        ope(src,idx);
        ans.push_back(dst[dstIdx]);
        break;
      }
    }
  }
  for(int i=0;i<ans.size();i++)
    cout << ans[i] << endl;
  cout << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
