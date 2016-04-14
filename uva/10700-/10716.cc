#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 257

using namespace std;

string source;

void read(){
  cin >> source;
}

void work(){

  // analysis
  int nChar[MAX_SIZE];  
  for(int i=0;i<MAX_SIZE;i++)
    nChar[i] = 0;

  for(int i=0;i<source.length();i++)
    nChar[source[i]]++;


  int nOdd=0;
  for(int i=0;i<MAX_SIZE;i++)
    if(nChar[i]%2==1)
      nOdd++;

  if(nOdd>1) {
    cout << "Impossible" << endl;
    return;
  }

  
  // make palindrome
  int ans=0;  
  while(!(source.length()<=1)){
   
    int minDistance=500;
    int firstPos, endPos;
    for(int i=0;i<source.length();i++){
      for(int j=source.length()-1;j>=0;j--){
	if(source[i]==source[j]){
	  if(minDistance>i+source.length()-1-j){
	    minDistance=i+source.length()-1-j;
	    firstPos = i;
	    endPos = j;
	    break;
	  }
	}
      }
    }
    
    for(int i=firstPos;i-1>=0;i--){
      swap(source[i],source[i-1]);
      ans++;
    }
    
    for(int i=endPos;i+1<source.length();i++){
      swap(source[i],source[i+1]);
      ans++;
    }    
    
    source = source.substr(1,source.length()-2);

  }

  cout << ans << endl;
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
