// tree
//
// 
// サブツリーがひとつしかないとき、そのサブツリーを右に配置するのか、
// 左に配置するのか、という選択肢があることに注意。

#include<iostream>
#include<algorithm>

#define INF 100000000
#define NODE 1005

using namespace std;

int nNode, val[NODE];

void read(){
  cin >> nNode;
  for(int i=0;i<nNode;i++)
    cin >> val[i];
}

void rec(int l, int r, int sum[][NODE]){
  if(l==r){ 
    cout << val[l];
    return;
  }
  
  int pos, minV = INF, leftV = -INF;
  for(int i=l;i<=r;i++){
    if(i!=r && val[i]==val[i+1]) continue;
    
    int toCmp;
    if(i==r)      toCmp = abs(sum[  l][i-1]);
    else if(i==l) toCmp = abs(sum[i+1][  r]);
    else          toCmp = abs(sum[i+1][r]-sum[l][i-1]);

    if(minV>toCmp){
      minV = toCmp;
      pos = i;
      leftV = sum[l][i-1];
    }
    else if(minV==toCmp){
      if(leftV<sum[l][i-1]){
	pos = i;
	leftV = sum[l][i-1];
      }
    }
  }
  
  cout << val[pos] << '(';
  if(pos==l){
    rec(pos+1,r,sum);
    cout << ')';
  }
  else if(pos==r){
    rec(l,pos-1,sum);
    cout << ')';
  }
  else{
    rec(l,pos-1,sum);
    cout << ',';
    rec(pos+1,r,sum);
    cout << ')';
  }
}

void work(int cases){
  static int sum[NODE][NODE];
  
  sort(val,val+nNode);

  for(int i=0;i<nNode;i++){
    sum[i][i] = val[i];
    for(int j=i+1;j<nNode;j++)
      sum[i][j] = val[j]+sum[i][j-1];
  }

  cout << "Case #" << cases << ": ";
  rec(0,nNode-1,sum);
  cout << endl;
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
