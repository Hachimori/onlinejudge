// DP
//
//
// それぞれの位のに11の余り(0~10)が出る確率を保存するテーブルを用意する。
// 現在の位の11の余りが出る確率は、
// 一つ前の位の余り(0~10)が出る確率×現在の位が生成する数字(0~9)の確率の和。
// 
// 漸化式は以下のとおり。
//
// REP(i,11)
//   REP(j,10)
//     curr[(i*10+j)%11] += prev[i]*p[j];

#include<iostream>
#include<string>
#include<utility>
#include<cstdio>
#define QUERY 25
#define BUF 55
#define MOD 11
using namespace std;

double p[10];
int nQuery;
pair<string,int> query[QUERY];

bool read(){
  int dummy; cin >> dummy;
  if(dummy==0) return false;
  
  for(int i=0;i<10;i++){
    int d; cin >> d;
    cin >> p[d];
  }
  
  cin >> nQuery;
  for(int i=0;i<nQuery;i++)
    cin >> query[i].first >> query[i].second;
  
  return true;
}

double calc(string &s, int &r){
  double mod[MOD][BUF];
  
  for(int i=0;i<MOD;i++)
    for(int j=0;j<=s.size();j++)
      mod[i][j] = 0;
  mod[0][0] =  1;
  
  for(int i=1;i<=s.size();i++)
    if(s[i-1]=='*')
      for(int j=0;j<MOD;j++)
	for(int k=0;k<10;k++)
	  mod[(j*10+k)%MOD][i] +=  mod[j][i-1]*p[k];
    else {
      int d = s[i-1]-'0';
      for(int j=0;j<MOD;j++)
	mod[(j*10+d)%MOD][i] +=  mod[j][i-1];
    }

  return mod[r][s.size()];
}

void work(int cases){
  cout << "Case " << cases << ":" << endl;
  for(int i=0;i<nQuery;i++)
    printf("%.8lf\n",calc(query[i].first,query[i].second));
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
