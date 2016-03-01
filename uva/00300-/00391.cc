#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

vector<string> strList;

void read(){
  string str;

  while(getline(cin,str)!=NULL)
    strList.push_back(str);
  
}

void work(){
  
  bool markUp=false;

  for(int i=0;i<strList.size();i++){    
    for(int j=0;j<strList[i].length();j++){
      
      if(strList[i][j]=='\\'){
	if(j+1<strList[i].size()){
	  if(strList[i][j+1]=='*'){
	    markUp=!markUp;
	    j++;
	  }
	  else if(markUp) cout << strList[i][j];
	  else if(strList[i][j+1]=='i' || strList[i][j+1]=='b') j++;
	  else if(strList[i][j+1]=='\\'){
	    j++;
	    cout << '\\';
	  }
	  else if(strList[i][j+1]=='s'){
	    j+=2;
	    while(j<strList[i].size() && isdigit(strList[i][j])) j++;
	    if(j<strList[i].size() && strList[i][j]=='.') j++;
	    while(j<strList[i].size() && isdigit(strList[i][j])) j++;
	    j--;
	  }
	}
	else cout << '\\';
      }
      else cout << strList[i][j];

    }
    cout << endl;
  }
  
}

int main(){

  read();
  work();

  return 0;
}
