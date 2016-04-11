/*
0 0 BBB:xyzzy
:bbbb:x:BBBB:
0 1 BBB:xyzzy
:bbbb:xy:BBBB:
0 2 BBB:xyzzy
:bbbb:xyz:BBBB:
0 3 BBB:xyzzy
:bbbb:xyzz:BBBB:
0 4 BBB:xyzzy
:bbbb:xyzza:BBBB:
1 4 BBB:yzzy
:bbbb:yzza:BBBB:
2 4 BBB:zzy
:bbbb:zza:BBBB:
3 4 BBB:zy
:bbbb:za:BBBB:
4 4 BBB:xyzzy
:bbbb:a:BBBB:
5 5 BBB:xyzzy
:bbbb:b:BBBB:
6 6 BBB:xyzzy
:bbbb:c:BBBB:
7 7 BBB:zy
:bbbb:z:BBBB:
7 8 BBB:zzy
:bbbb:zz:BBBB:
7 9 BBB:zzy
:bbbb:zzy:BBBB:
7 10 BBB:(null):bbbb:zzyy:BBBB:
8 10 BBB:zzy
:bbbb:zyy:BBBB:
8 11 BBB:zzy
:bbbb:zyy
:BBBB:

となってしまうのが問題。
strの先端のみの比較では
suffix: zzy
   str: zyy
がマッチしていると判断してしまう。
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define MAX_BUF 50005

using namespace std;

struct Data{
  int pos, num[2];
};

class Ans{
public:
  int leng, pos;
  char *s;
  
  Ans(){}
  Ans(int l, int p, char *s): leng(l), pos(p), s(s){}
  
  bool operator< (const Ans &a) const {
    if(leng!=a.leng) return leng>a.leng;
    return pos<a.pos;
  }
};

int toFind;
string src1, src2;

bool read(){
  cin >> toFind;
  if(toFind==0) return false;

  src1 = src2 = "";
  
  string str; getline(cin,str); getline(cin,str);
  while(true){
    getline(cin,str);
    if(str=="END TDP CODEBASE") break;
    src1 += str + '\n';
  }

  getline(cin,str);
  while(true){
    getline(cin,str);
    if(str=="END JCN CODEBASE") break;
    src2 += str + '\n';
  }

  return true;
}

vector<char*> construct(string &str){
  str += '\0';

  int leng = str.size();
  vector<int> id;
  vector<Data> buf;
  
  for(int i=0;i<leng;i++)
    id.push_back(str[i]);
  
  for(int p=1;p<leng;p*=2){
    int limit = *max_element(id.begin(),id.end());
    buf.clear();

    for(int i=0;i<leng;i++){
      Data toPush;
      toPush.pos = i;
      toPush.num[0] = i+p<leng ? id[i+p] : 0;
      toPush.num[1] = id[i];
      
      buf.push_back(toPush);
    }
  
    for(int c=0;c<2;c++){
      vector<int> bucket[MAX_BUF];
      
      for(int r=0;r<leng;r++)
	bucket[buf[r].num[c]].push_back(r);
      
      vector<Data> next;
      for(int i=0;i<=limit;i++){
	for(int j=0;j<bucket[i].size();j++)
	  next.push_back(buf[bucket[i][j]]);
	bucket[i].clear();
      }
      
      buf = next;
    }
      
    int n[] = {buf[0].num[0],buf[0].num[1]}, group[MAX_BUF], curr = 0;
    for(int i=0;i<leng;i++){
      if(n[0]!=buf[i].num[0] || n[1]!=buf[i].num[1]){
	n[0] = buf[i].num[0];
	n[1] = buf[i].num[1];
	curr++;
      }
      group[i] = curr;
    }

    for(int i=0;i<leng;i++)
      id[buf[i].pos] = group[i];
  }

  vector<char*> suffix;
  for(int i=0;i<leng;i++)
    suffix.push_back(&str[0]+buf[i].pos);
  
  return suffix;
}

void work(int cases){
  vector<char*> suffix = construct(src1);
  vector<Ans> ans;
  int head = 0, tail = 0;
  
  for(int i=0;i<suffix.size();i++)
    cout << ":" << suffix[i] << endl;
  cout << endl;
  
  while(head<src2.size()){
    vector<char*>::iterator toPush;

    string str;
    vector<char*>::iterator prev = suffix.end();
    bool succeed = false;
    while(tail<src2.size()){
      str = src2.substr(head,tail-head+1);
      vector<char*>::iterator pos;
      
      pos = lower_bound(suffix.begin(),suffix.end(),str);
      //str[str.size()-1]++;
      //end = lower_bound(suffix.begin(),suffix.end(),str);
      //str[str.size()-1]--;
      /*
      if(pos==prev){ 
	if(tail-head==4)
	  cout << *pos << ":bbbb:" << *prev << endl;
	break;
      }
      else toPush = pos;
      */
      
      //if(tail-head==4)
      cout << head << ' ' << tail << ' ' <<"BBB:" << *pos << ":bbbb:" << str << ":BBBB:" << endl;
      int idx = *pos-src1.c_str();
      if(idx+str.size()-1>=src1.size()) break;
      else if(str[str.size()-1]!=src1[idx+str.size()-1]){
	break;
      }
      
      succeed = true;
      toPush = pos;
      tail++;
    }
    
    if(succeed)
      ans.push_back(Ans(tail-head,head,*toPush));
    head++;
    if(tail<head)
      tail = head;
  }

  sort(ans.begin(),ans.end());
  
  cout << "CASE " << cases << endl;
  for(int i=0;i<min((int)ans.size(),toFind);i++){
    cout << "INFRINGING SEGMENT " << i+1 << " LENGTH " 
	 << ans[i].leng << " POSITION " << ans[i].pos << endl;
    for(int j=0;j<ans[i].leng;j++)
      cout << ans[i].s[j];
    cout << endl;
  }
}

int main(){
  for(int i=0;read();i++)
    work(i+1);
  
  return 0;
}
