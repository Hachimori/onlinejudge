#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int rem[13], val[5];
string card[5];

int convert(char c){
  switch(c){
  case 'A':
    return 0;
  case 'T':
    return 9;
  case 'J':
    return 10;
  case 'Q':
    return 11;
  case 'K':
    return 12;
  default:
    return c-'0'-1;
  }
}

bool read(){
  for(int i=0;i<13;i++) rem[i] = 4;
  
  for(int i=0;i<5;i++){
    cin >> card[i];
    if(card[i]=="#") return false;
    
    val[i] = convert(card[i][0]);
    rem[convert(card[i][0])]--;
  }
  
  return true;
}

int calc(int v[]){
  int avail[13];
  for(int i=0;i<13;i++) avail[i] = 0;
  for(int i=0;i<5;i++) avail[v[i]]++;
  
  int maxRun = 0, maxPos;
  for(int i=0;i<13;i++){
    int cnt = 0;
    for(int j=i;avail[j];j=(j+1)%13,cnt++);
    if(maxRun<cnt){
      maxRun = cnt;
      maxPos = i;
    }
  }

  
  for(int i=maxPos,j=0;j<maxRun;i=(i+1)%13,j++) avail[i]--;
  

  switch(maxRun){
  case 5:
    return 100;
  case 4:
    return 10;
  case 3:
    maxRun = 0;
    for(int i=0;i<13;i++){
      int cnt = 0;
      for(int j=i;avail[j];j=(j+1)%13,cnt++);
      maxRun = max(maxRun,cnt);
    }
    return (maxRun==2 ? 5 : 3);
  case 2:
    maxRun = 0;
    for(int i=0;i<13;i++){
      int cnt = 0;
      for(int j=i;avail[j];j=(j+1)%13,cnt++);
      maxRun = max(maxRun,cnt);
    }
    return (maxRun==2 ? 1 : 0);
  default:
    return 0;
  }
}

void work(){
  double maxV = calc(val);
  int ans = -1;
  
  for(int i=0;i<5;i++){
    double sum = 0;
    for(int j=0;j<13;j++){
      if(rem[j]<=0) continue;
      int t = val[i];
      val[i] = j;
      sum += rem[j]*calc(val)/47.0;
      val[i] = t;
    }
    
    if(maxV<sum-1){
      maxV = sum-1;
      ans = i;
    }
  }
  
  if(ans==-1) cout << "Stay" << endl;
  else
    cout << "Exchange " << card[ans] << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
