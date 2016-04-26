// 参考: http://www.geocities.jp/m_hiroi/light/pyalgo07.html

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<cassert>
#define BUF 1000005
using namespace std;

class IList{
public:
  int n, bgn, inc;
  
  IList(){}
  IList(int n, int b, int i): n(n), bgn(b), inc(i){}
};

class RList{
public:
  int n;
  long long l, r, s;
  
  RList(){}
  RList(int n, long long l, long long r, long long s): n(n), l(l), r(r), s(s){}
};

bool chk(char c){
  return isdigit(c) || isalpha(c) || c=='-';
}

vector<string> split(string &s){
  vector<string> ret;
  for(int cur=0;cur<s.size();){
    string toPush;
    while(cur<s.size() && !chk(s[cur])) cur++;
    while(cur<s.size() &&  chk(s[cur])) toPush+=s[cur++];
    if(toPush.size()>0) ret.push_back(toPush);
  }
  return ret;
}

long long myatoi(string &s){
  bool minus = s[0]=='-';
  long long ret = 0;

  for(int cur=(s[0]=='-'?1:0);cur<s.size();cur++){
    ret *= 10;
    ret += s[cur]-'0';
  }
  
  return (minus?-ret:ret);
}

int nThNum;
vector< vector<int> > nList;
vector<IList> iList;
vector<RList> rList;

bool read(){
  nList.clear();
  iList.clear();
  rList.clear();
  
  cin >> nThNum;
  if(nThNum==0) return false;
  nThNum--;
  
  string str;
  cin >> str;
  
  
  vector<string> sList = split(str);
  
  for(int i=0;i<sList.size();){
    int cur = i+1;
    if(sList[i]=="NList"){
      vector<int> toPush;
      cur++;
      while(cur<sList.size() && (isdigit(sList[cur][0]) || sList[cur][0]=='-'))
	toPush.push_back(atoi(sList[cur++].c_str()));
      nList.push_back(toPush);
    }
    if(sList[i]=="IList"){
      IList toPush;
      toPush.n = atoi(sList[cur++].c_str());
      toPush.bgn = atoi(sList[cur++].c_str());
      toPush.inc = atoi(sList[cur++].c_str());
      iList.push_back(toPush);
    }
    if(sList[i]=="RList"){
      RList toPush;
      toPush.n = atoi(sList[cur++].c_str());
      toPush.l = atoi(sList[cur++].c_str());
      toPush.r = atoi(sList[cur++].c_str());
      toPush.s = myatoi(sList[cur++]);
      rList.push_back(toPush);
    }
    i = cur;
  }
  
  return true;
}

void radix(int A[], int nNum){
  const static int BASE = 256;
  static int count[BASE], W[BUF];
  
  int *work = W, *array = A;
  
  for(int cur=0;cur<32;cur+=8){
    for(int i=0;i<BASE;i++) count[i] = 0;
    for(int j=0;j<nNum;j++) count[(array[j]>>cur)&0xff]++;
    for(int i=1;i<BASE;i++) count[i] += count[i-1];
    
    for(int i=nNum-1;i>=0;i--)
      work[--count[(array[i]>>cur)&0xff]] = array[i];
    
    swap(work,array);
  }
  int tail = 0;
  static int buf[BUF];
  
  int cur;
  for(cur=nNum-1;cur>=0 && array[cur]<0;cur--); cur=(cur+1)%nNum;
  for(int i=0;i<nNum;i++,cur=(cur+1)%nNum) buf[i] = array[cur];
  for(int i=0;i<nNum;i++) array[i] = buf[i];
}

void work(int cases){
  int tail = 0;
  static int array[BUF];
  
  for(int i=0;i<nList.size();i++)
    for(int j=0;j<nList[i].size();j++)
      array[tail++] = nList[i][j];
  
  for(int i=0;i<iList.size();i++)
    for(int j=0;j<iList[i].n;j++)
      array[tail++] = iList[i].bgn+iList[i].inc*j;
  
  for(int i=0;i<rList.size();i++){
    long long cur = rList[i].s;
    for(int j=0;j<rList[i].n;j++){
      cur = (cur*17+11)&((1LL<<32)-1);
      array[tail++] = rList[i].l+cur%(rList[i].r-rList[i].l+1);
    }
  }

  radix(array,tail);

  for(int i=1;i<tail;i++)
    assert(array[i-1]<=array[i]);

  cout << "Case " << cases << ": " << array[nThNum] << endl;
}

int main(){
  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
