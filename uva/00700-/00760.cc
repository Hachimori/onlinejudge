#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string A, B;

bool read(){
  if(getline(cin,A)==NULL) return false;
  if(getline(cin,B)==NULL) return false;
  return true;
}

void work(){
  int maxLen = 0;
  vector<string> ans;
  
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B.size();j++){
      int len = 0;
      for(int aa=i,bb=j;aa<A.size() && bb<B.size() && A[aa]==B[bb];){
	aa++;
	bb++;
	len++;
      }
      
      if(maxLen<len){
	maxLen = len;
	ans.clear();
	ans.push_back(string(A.c_str()+i,A.c_str()+i+len));
      }
      else if(maxLen==len)
	ans.push_back(string(A.c_str()+i,A.c_str()+i+len));
    }
  }
  
  if(maxLen==0)
    cout << "No common sequence." << endl;
  else {
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0;i<ans.size();i++)
      cout << ans[i] << endl;
  }
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work();
    string dummy; getline(cin,dummy);
  }
    
  return 0;
}
