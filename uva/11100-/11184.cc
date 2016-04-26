#include<iostream>
#define BUF 1005
using namespace std;

int num;

bool read(){
  cin >> num;
  return num!=0;
}

void work(int cases){
  if(num%4==1 || num%4==2){
    cout << "Case " << cases << ": -1" << endl;
    return;
  }
  
  int order[BUF], cur = 1;
  for(int i=0;i<num;i+=2)
    order[i] = cur++;
  
  bool used[BUF];
  for(int i=0;i<BUF;i++) used[i] = false;
  if(num%2==1) used[abs(order[0]-order[num-1])] = true;
  
  for(int i=num-(num%2+1);i>=0;i-=2){
    int pre = order[i-1], next = order[(i+1)%num];
    if(used[abs(cur-pre)] || used[abs(cur-next)]) cur++;
    used[abs(cur-pre)] = used[abs(cur-next)] = true;
    order[i] = cur++;
  }

  cout << "Case " << cases << ":";
  for(int i=0;i<num;i++)
    cout << ' ' << order[i];
  cout << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
