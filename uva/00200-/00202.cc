#include<iostream>

#define MAX_LANGE 1000000
#define MAX_NUM 3001

using namespace std;

int divided, divide;

bool read(){

  if(!(cin >> divided >> divide)) return false;

  return true;
}

void work(){
  bool visited[MAX_LANGE], putDot=false;
  int modList[MAX_NUM], beginPos, endPos, endMod, quotientList[MAX_NUM] ;
  int backDiv=divide, backDivided=divided;

  for(int i=0;i<MAX_LANGE;i++)
    visited[i] = false;
  
  
  for(int i=0;;i++){
    //cout << divided << "  " << i << endl;
    quotientList[i]=divided/divide;
    modList[i] = divided;

    if(visited[divided]){ 
      endPos = i;
      endMod = divided;
      break;
    }    
    else if(putDot) visited[divided]=true;
    
    divided%=divide;
    
    if(divided<divide){
      divided*=10;
      putDot=true;
    }

  }

  cout << backDivided << '/' << backDiv << " = ";

  for(int i=0;i<endPos;i++){
    if(i==1) cout << '.';
    if(modList[i]==endMod){ 
      cout << '(';
      beginPos = i;
    }

    if(i-beginPos==50){ 
      cout << "...";
      break;
    }
    cout << quotientList[i];    
  }
  cout << ")" << endl;

  cout << "   " << endPos-beginPos << " = number of digits in repeating cycle" << endl;
  cout << endl;
}

int main(){
  
  for(int i=0;read();i++){
    work();
  }

  return 0;
}
