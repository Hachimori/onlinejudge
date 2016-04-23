// ad-hoc
//
// 2^n回 binary search する。 n: タイルの数
// nは高々10で、binary searchする空間は高々100000なので
// O((2^10)*log(100000)) となる。
//
// queryは最大1000個与えられるので、合計で1500万回の計算が
// 必要になる。これでTLEを免れる。

#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

#define MAX_WORD 100005
#define MAX_QUERY 1005
#define MAX_CHAR 26

using namespace std;

class Data{
public:
  
  int nChar[MAX_CHAR];

  Data(){}
  
  bool operator< (const Data &d) const {
    for(int i=0;i<MAX_CHAR;i++)
      if(nChar[i]!=d.nChar[i])
	return nChar[i]<d.nChar[i];

    return false;
  }
};

class Tile{
public:
  int val;
  char c;
};

class Query{
public:
  int nTile;
  Tile tile[10];
};

int nData, nQuery;
Data data[MAX_WORD];
Query query[MAX_QUERY];

void read(){
  cin >> nData;
  
  for(int i=0;i<nData;i++){
    string str;
    cin >> str;
    
    for(int j=0;j<MAX_CHAR;j++)
      data[i].nChar[j] = 0;

    for(int j=0;j<str.size();j++)
      data[i].nChar[str[j]-'a']++;
  }

  cin >> nQuery;
  
  for(int i=0;i<nQuery;i++){
    cin >> query[i].nTile;
    for(int j=0;j<query[i].nTile;j++)
      cin >> query[i].tile[j].c >> query[i].tile[j].val;
  }
}

void rec(int curr, int val, Data toFind, Query &q, int &maxScore){
  if(curr==q.nTile){
    
    if(maxScore>=val) return;
    if(binary_search(data,data+nData,toFind))
      maxScore = val;
    
    return;
  }
  
  toFind.nChar[q.tile[curr].c-'a']++;
  val += q.tile[curr].val;
  
  rec(curr+1,val,toFind,q,maxScore);
  
  toFind.nChar[q.tile[curr].c-'a']--;
  val -= q.tile[curr].val;

  rec(curr+1,val,toFind,q,maxScore);
}

void work(){
  sort(data,data+nData);
  
  for(int i=0;i<nQuery;i++){
    int maxScore = -1;
    Data toFind;

    for(int j=0;j<MAX_CHAR;j++)
      toFind.nChar[j] = 0;
    
    rec(0,0,toFind,query[i],maxScore);

    cout << maxScore << endl;
  }
}

int main(){
  read();
  work();
  
  return 0;
}
