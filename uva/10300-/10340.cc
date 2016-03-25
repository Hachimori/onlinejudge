#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 100000

using namespace std;

int lcsPrev[MAX_SIZE], lcsNext[MAX_SIZE];
string substr, str;

bool read(){
  if(!(cin >> substr >> str)) return false;

  return true;
}

void work(){
  /*
  if(substr.length()>str.length())
    swap(substr,str);
  */

  for(int i=0;i<=str.length();i++)
    lcsPrev[i]=0;
    
  for(int i=0;i<substr.length();i++){
    for(int j=0;j<str.length();j++){

      if(substr[i]==str[j])
	lcsNext[j+1] = max(lcsPrev[j]+1,max(lcsNext[j],lcsPrev[j+1]));
      else
	lcsNext[j+1] = max(lcsNext[j],lcsPrev[j+1]);

    }

    for(int j=0;j<=str.length();j++)
      lcsPrev[j] = lcsNext[j];   
  }

  if(lcsNext[str.length()]==substr.length())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

}

int main(){

  while(read())
    work();

  return 0;
}
