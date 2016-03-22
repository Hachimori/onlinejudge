#include<iostream>
#include<cstring>

#define MAX_SIZE 510

using namespace std;

char digit1[MAX_SIZE], digit2[MAX_SIZE];

bool read(){
  

  if(!(cin >> digit1 >> digit2)) return false;

  return true;
}

void work(){
  
  int ans[MAX_SIZE];
  
  for(int i=0;i<MAX_SIZE;i++)
    ans[i] = 0;

  for(int i=strlen(digit1)-1, iCursor=0;i>=0;iCursor++,i--){    
    for(int j=strlen(digit2)-1, jCursor=0;j>=0;jCursor++,j--){
      ans[iCursor+jCursor] += (digit1[i]-'0')*(digit2[j]-'0');
    }
  }

  for(int i=0;i<MAX_SIZE-1;i++){
    if(ans[i]>=10){
      ans[i+1]+=ans[i]/10;
      ans[i]%=10;
    }
  }

  int cursor=MAX_SIZE-1;
  while(cursor>=0 && ans[cursor]==0)
    cursor--;

  if(cursor==-1) cout << 0 << endl;
  else{
    for(;cursor>=0;cursor--)
      cout << ans[cursor];
    cout << endl;
  }

}

int main(){

  while(read())
    work();

  return 0;
}
