#include<iostream>
#include<string>
using namespace std;

string str;

bool read(){
  cin >> str;
  return str!="0";
}

int cntOne(int cur){
  int sum = 0;
  for(int i=cur;i>=0;i--)
    if(str[i]=='0') 
      break;
    else
      sum++;
  return sum;
}

void work(){
  string ans;
  
  for(int cur=str.size()-1;cur>=0;cur--){
    if(str[cur]=='0')
      ans += '0';
    else{
      int nOne = cntOne(cur);
      
      if((nOne==2 && cur-nOne!=-1) || nOne>=3){
	ans += '-';
	for(int i=0;i<nOne-1;i++) ans += '0';
	if(cur-nOne!=-1)
	  str[cur-nOne] = '1';
	else
	  ans += '+';
	cur -= nOne-1;
      }
      else
	ans += '+';
    }
  }
  
  for(int i=ans.size()-1;i>=0;i--)
    cout << ans[i];
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
