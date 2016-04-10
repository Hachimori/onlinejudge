#include<iostream>
#include<algorithm>
#include<string>

#define MAX 1005



bool read(string &str1, string &str2){
  if(!getline(cin,str1)) return false;
  getline(cin,str2);
  
  return true;
}

void work(string &str1, string &str2){
  
  int score1[MAX];

  for(int i=0;i<str2.length();i++)
    score1[i]=0;
  
  for(int i=0;i<str1.length();i++){
    
    int score2[MAX];
    for(int j=0;j<str2.length();j++){
      if(j==0 && str1[i]==str2[j])
	score2[j] = 1;
      else if(str1[i]==str2[j])
	score2[j] = score1[j-1]+1;
      else if(j!=0 && score2[j-1]>=score1[j])
	score2[j] = score2[j-1];
      else 
	score2[j] = score1[j];
    }

    for(int j=0;j<str2.length();j++)
      score1[j] = score2[j];
  }

  
  int maxScore=0;
  for(int i=0;i<str2.length();i++)
    if(maxScore<score1[i])
      maxScore = score1[i];


  cout << maxScore << endl;
}

int main(){
  string str1, str2;
  
  while(read(str1,str2)) 
    work(str1,str2);
  
  return 0;
}
