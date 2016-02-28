#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

string ch = "IXCMVLD";
int ch2v[] = {1,10,100,1000,5,50,500};
string a, b, c;

bool read(){
  string str;
  getline(cin,str);
  if(str=="#") return false;

  for(int i=0;i<str.size();i++)
    if(!isalpha(str[i]))
      str[i] = ' ';

  stringstream in(str);
  in >> a >> b >> c;
  
  return true;
}

int get(string &s){
  int ret = 0;
  for(int i=0;i<s.size();i++){
    int sum = 0, pre = i;
    for(;i<s.size() && s[i]==s[pre];i++)
      sum += ch2v[ch.find(s[i])];

    if(i<s.size() && ch2v[ch.find(s[pre])]<ch2v[ch.find(s[i])])
      ret += ch2v[ch.find(s[i])]-sum;
    else{
      ret += sum;
      i--;
    }
  }
  return ret;
}

int get(string &s, int ch2n[128]){
  int ret = 0;
  for(int i=0;i<s.size();i++){
    ret *= 10;
    ret += ch2n[s[i]];
  }
  return ret;
}

void rec(int curr, int ch2n[128], bool used[10], bool chFound[7], int &cnt){
  if(curr==ch.size()){
    if(ch2n[a[0]]==0 || ch2n[b[0]]==0 || ch2n[c[0]]==0) return;
    if(get(a,ch2n)+get(b,ch2n)==get(c,ch2n)) cnt++;
    return;
  }
  
  if(!chFound[curr]){
    rec(curr+1,ch2n,used,chFound,cnt);
    return;
  }

  for(int i=0;i<10;i++){
    if(used[i]) continue;
    used[i] = true;
    ch2n[ch[curr]] = i;
    rec(curr+1,ch2n,used,chFound,cnt);
    used[i] = false;
  }
}

void work(){
  int av = get(a), bv = get(b), cv = get(c);

  int ch2n[128], cnt = 0;
  bool used[10] = {false}, chFound[7] = {false};
  for(int i=0;i<7;i++)
    chFound[i] = a.find(ch[i])!=string::npos ||
                 b.find(ch[i])!=string::npos ||
                 c.find(ch[i])!=string::npos;
  rec(0,ch2n,used,chFound,cnt);

  if(av+bv==cv) cout << "Correct ";
  else cout << "Incorrect ";

  if(cnt>=2)
    cout << "ambiguous" << endl;
  else if(cnt==1)
    cout << "valid" << endl;
  else
    cout << "impossible" << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
