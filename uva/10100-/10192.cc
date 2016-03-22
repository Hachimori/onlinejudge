#include<iostream>
#include<string>
#include<algorithm>

#define MAX_SIZE 105

using namespace std;

string strA, strB;

bool read(){
  
  getline(cin,strA);
  if(strA[0]=='#') return false;

  getline(cin,strB);
  if(strB[0]=='#') return false;

  return true;

}

bool isInside(int r, int c){
  return (0<=r && r<(int)strA.length() && 0<=c && c<(int)strB.length());
}

void work(int cases){
  
  int lcs[MAX_SIZE][MAX_SIZE];

  for(int i=0;i<strA.length();i++){
    for(int j=0;j<strB.length();j++){
      
      int maximum=0;

      if(isInside(i,j-1))
	maximum = max(maximum,lcs[i][j-1]);
     
      if(isInside(i-1,j))
	maximum = max(maximum,lcs[i-1][j]);
      
      if(isInside(i-1,j-1) && strA[i]==strB[j])
	maximum = max(maximum,lcs[i-1][j-1]+1);
      else if(strA[i]==strB[j])
	maximum = max(maximum,1);

      lcs[i][j] = maximum;
    }
  }
  
  if(strA.length()!=0 && strB.length()!=0)
    cout << "Case #" << cases << ": you can visit at most " << 
      lcs[strA.length()-1][strB.length()-1] << " cities." << endl;
  else
    cout << "Case #" << cases << ": you can visit at most " << 0 << " cities." << endl;
}

int main(){

  for(int cases=1;read();cases++)
    work(cases);

  return 0;
}
