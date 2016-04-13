// 10635
// 前原さんのLISライブラリを参考にした

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int BUF = 250*250+5, INF = 1<<30;


vector<int> lis(vector<int> num){
  vector<int> seq(num.size(),INF); // 逐次更新される増加列
  vector<int> idx(num.size(),INF); // idx[n]: n番目のnumが増加列のどこにあるか
  
  for(int i=0;i<num.size();i++){
    int pos = lower_bound(seq.begin(),seq.end(),num[i])-seq.begin();
    seq[pos] = num[i];
    idx[i] = pos;
  }
  
  int len = *max_element(idx.begin(),idx.end())+1;
  vector<int> ret(len);
  for(int i=num.size()-1;i>=0;i--)
    if(idx[i]==len-1)
      ret[--len] = num[i];

  return ret;
}


int nVal, nA, nB, A[BUF], B[BUF];

void read(){
  cin >> nVal >> nA >> nB;
  nVal *= nVal;
  nA++;
  nB++;
  for(int i=0;i<nA;i++) cin >> A[i];
  for(int i=0;i<nB;i++) cin >> B[i];
}


void work(int cases){
  int aVal2aValIdx[BUF];
  memset(aVal2aValIdx,-1,sizeof(aVal2aValIdx));
  for(int i=0;i<nA;i++) aVal2aValIdx[A[i]] = i;

  vector<int> num;
  for(int i=0;i<nB;i++)
    if(aVal2aValIdx[B[i]]!=-1)
      num.push_back(aVal2aValIdx[B[i]]);

  cout << "Case " << cases << ": " << lis(num).size() << endl;
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
