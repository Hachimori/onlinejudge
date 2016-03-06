#include<iostream>
#include<string>

#define MAX_SIZE 30

using namespace std;

int nLine;
string matrix[MAX_SIZE];

void read(){

  nLine=0;

  while(true){
    
    if(getline(cin,matrix[nLine])==NULL) break;
    
    if(matrix[nLine].length()==0) break;

    nLine++;
  }

}

void work(){
  
  int maxSize=0;
  
  for(int i=0;i<nLine;i++){
    for(int j=0;j<nLine;j++){
      
      char origin = matrix[i][j];
      if(origin=='0') continue;

      for(int k=1;k<=nLine;k++){
	for(int h=1;h<=nLine;h++){
	  
	  bool succeed=true;

	  if(!(i+k<=nLine && j+h<=nLine)) continue;
	  
	  for(int l=i;l<i+k;l++)
	    for(int m=j;m<j+h;m++)
	      if(matrix[l][m]!=origin) 
		succeed=false;
	  
	  if(succeed && maxSize<k*h)
	    maxSize = k*h;
	}
      }

    }
  }

  cout << maxSize << endl;

}

int main(){

  string str;
  
  int cases;
  cin >> cases;

  getline(cin,str);
  getline(cin,str);

  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;


    read();
    work();
  }

  return 0;
}
