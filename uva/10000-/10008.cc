#include<iostream>
#include<string>
#include<cctype>

#define MAX_SIZE 256

using namespace std;

int nLine;
int charToInt[MAX_SIZE];

void work(){

  string str; getline(cin,str);
  
  for(int i=0;i<MAX_SIZE;i++)
    charToInt[i] = 0;


  for(int i=0;i<nLine;i++){
    
    getline(cin,str);
    
    for(int j=0;j<str.length();j++)
      if(isalpha(str[j]))	
	charToInt[toupper(str[j])]++;        
  }

  for(int i=0;i<MAX_SIZE;i++){
    
    int maxVal=0;
    char maxChar;

    for(int j=0;j<MAX_SIZE;j++)
      if(maxVal<charToInt[j]){
	maxVal = charToInt[j];
	maxChar = j;
      }

    if(maxVal==0) break;

    cout << maxChar << ' ' << maxVal << endl;
    
    charToInt[(int)maxChar] = -1;
  }

}

int main(){

  
  cin >> nLine;

  work();

  return 0;
}
