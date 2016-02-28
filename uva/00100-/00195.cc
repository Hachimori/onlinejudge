#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cctype>

#define MAX_CHAR 1000

using namespace std;

string source;

void read(){
  cin >> source;
}

bool allUsed(int cursor, bool cUsed[MAX_CHAR]){
  
  if(cursor-1>=0 && source[cursor]==source[cursor-1] && !cUsed[cursor-1])
    return false;
  
  return true;
}

void calc(int nUsed, bool cUsed[MAX_CHAR], char anagram[MAX_CHAR]){
  
  if(nUsed==source.length()){
    for(int i=0;i<source.length();i++)
      printf("%c",anagram[i]);
    printf("\n");

    return;
  }

  for(int i=0;i<source.length();i++){
    if(!allUsed(i,cUsed) || cUsed[i]) continue;
    

    cUsed[i] = true;
    anagram[nUsed] = source[i];
    
    calc(nUsed+1,cUsed,anagram);
    
    cUsed[i] = false;
  }

}

bool myGreater(const char a, const char b){
  
  if(toupper(a)!=toupper(b))
    return toupper(a)<toupper(b);
  else if(isupper(a))
    return true;
  else return false;
    

     /*
  if( (isupper(a) && isupper(b)) || (islower(a) && islower(b)) ) return a<b;
  else if(isupper(a) && islower(b))
    return toupper(a)<toupper(b);
  else 
    return toupper(b)<toupper(a);
     */

}

void work(){
  
  char anagram[MAX_CHAR];
  bool cUsed[MAX_CHAR];

  sort(source.begin(),source.end(),myGreater);
  
  for(int i=0;i<source.length();i++)
    cUsed[i] = false;  

  calc(0,cUsed,anagram);

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
