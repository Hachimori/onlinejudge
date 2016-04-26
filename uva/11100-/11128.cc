// 探索 (1.668秒)
//
// 
// a_0 ~ a_2までの結果を全列挙して a_3~a_6 の結果を元に、
// バイナリサーチで正しい答えを求める。
//
// vectorのオーバーヘッドがひどいためか思ったより速くならなかった。

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#define LENG 7
#define MID 3
#define EPS (1.0e-4)
using namespace std;

double num[LENG];

void read(){
  num[0] = 1;
  for(int i=1;i<LENG;i++){
    double n;
    cin >> n;
    num[i] = sqrt(n);
  }
}

bool generate(int curr, map<double, vector<int> > &M, double sum, int chose[], bool step){
  if(step && curr==MID){
    M[sum] = vector<int>(chose,chose+MID);
    return false;
  }
  if(!step && curr==LENG){
    map<double,vector<int> >::iterator p = M.upper_bound(-sum-EPS);
    
    if(p==M.end() || fabs(sum+p->first)>EPS ||
       !(count(p->second.begin(),p->second.end(),0) || count(chose+MID,chose+LENG,0))) return false;
    
    for(int i=0;i<p->second.size();i++) cout << ' ' << p->second[i];
    for(int i=MID;i<LENG;i++)           cout << ' ' << chose[i];
    cout << endl;
    
    return true;
  }
  
  for(int i=-9;i<=(curr==0?0:9);i++){
    chose[curr] = i;
    if(generate(curr+1,M,sum+i*num[curr],chose,step)) return true;
  }
    
  return false;
}

void work(int cases){
  map<double, vector<int> > M;
  int chose[LENG];

  generate(0,M,0,chose,true);
  
  cout << "Case " << cases << ':';
  if(!generate(MID,M,0,chose,false))
    cout << "No Solution." << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  
  return 0;
}
