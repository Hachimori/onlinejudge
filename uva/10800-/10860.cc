#include<iostream>
#include<string>
#include<climits>

#define MAX_SIZE 10005
#define MAX_SUBSTR 55

using namespace std;

int nSubstr, ans;
string source;
string substrList[MAX_SUBSTR];

void read(){
  
  cin >> source;
  
  cin >> nSubstr; 
  
  for(int i=0;i<nSubstr;i++)
    cin >> substrList[i];

}

bool substrMatch(int cursor, int substrId){
 
  if(cursor+substrList[substrId].length()-1>=source.length()) return false;

  bool succeed=true;
  for(int i=cursor,j=0;i<cursor+substrList[substrId].length();i++,j++)
    if(source[i]!=substrList[substrId][j]){
      succeed=false;
      break;
    }
  
  if(succeed) return true;
  succeed=true;

  for(int i=cursor,j=substrList[substrId].length()-1;
      i<cursor+substrList[substrId].length();i++,j--)
    if(source[i]!=substrList[substrId][j]){
      succeed=false;
      break;
    }

  
  return succeed;
}

void work(int cases){

  bool isMatch[MAX_SIZE][MAX_SUBSTR];
  int minUsed[MAX_SIZE];

  for(int i=0;i<=source.length();i++){
    minUsed[i] = INT_MAX;
    for(int j=0;j<nSubstr;j++){
      isMatch[i][j] = false;
    }
  }

  minUsed[0] = 0;

  for(int i=0;i<=source.length();i++)
    for(int j=0;j<nSubstr;j++)      
      if(substrMatch(i,j))
	isMatch[i][j] = true;    
  
  
  for(int i=0;i<source.length();i++){
    for(int j=0;j<nSubstr;j++){
      if(isMatch[i][j] && minUsed[i]!=INT_MAX)
	if(minUsed[i+substrList[j].length()]>minUsed[i]+1)
	  minUsed[i+substrList[j].length()] = minUsed[i]+1;	      
    }
  }
  
  if(minUsed[source.length()]!=INT_MAX)
    cout << "Set " << cases << ": " << minUsed[source.length()] << "." << endl;
  else
    cout << "Set " << cases << ": Not possible." << endl;

}

int main(){

  int cases;
  cin >> cases;

  for(int i=1;i<=cases;i++){
    read();
    work(i);
  }

  return 0;
}
