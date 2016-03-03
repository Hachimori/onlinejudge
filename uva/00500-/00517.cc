#include<iostream>
#include<string>
#include<algorithm>
#define LENG 15
#define BUF (1<<LENG)
using namespace std;

int leng, init[LENG], pattern[8][4], nRotate;

bool read(){
  if(!(cin >> leng)) return false;
  string str; 
  cin >> str;
  for(int i=0;i<leng;i++) init[i] = str[i]-'a';
  for(int i=0;i<8;i++){
    cin >> str;
    for(int j=0;j<4;j++) pattern[i][j] = str[j]-'a';
  }
  cin >> nRotate;
  return true;
}

void ope(int v[LENG]){
  int nex[LENG];
  for(int i=0;i<leng;i++)
    for(int j=0;j<8;j++)
      if(pattern[j][0]==v[(i-2+leng)%leng] &&
         pattern[j][1]==v[i] &&
         pattern[j][2]==v[(i+1)%leng]){
        nex[i] = pattern[j][3];
        break;
      }
  for(int i=0;i<leng;i++)
    v[i] = nex[i];
}

int gen(int array[LENG]){
  int val = 0;
  for(int i=0;i<leng;i++){
    val *= 2;
    val += array[i];
  }
  return val;
}

void work(){
  int visited[BUF];
  memset(visited,-1,sizeof(visited));

  int curr[LENG];
  for(int i=0;i<leng;i++) curr[i] = init[i];

  
  for(int i=0;i<nRotate;i++){
    int val = gen(curr);
    visited[val] = i;
    ope(curr);
    if(visited[gen(curr)]!=-1){
      val = gen(curr);
      for(int j=0;j<(nRotate-1-i)%(i-visited[val]+1);j++)
        ope(curr);
      break;
    }
  }
  
  int minV = 1<<20;
  for(int i=0;i<leng;i++){
    int val = 0;
    for(int j=0;j<leng;j++){
      val *= 2;
      val += curr[(i+j)%leng];
    }
    minV = min(minV,val);
  }
  
  for(int i=leng-1;i>=0;i--)
    cout << ((minV&(1<<i))>0?'b':'a');
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
