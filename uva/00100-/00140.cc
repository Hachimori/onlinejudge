#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#define BUF 26
using namespace std;

bool adj[BUF][BUF], exist[BUF];

bool read(){
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++){
      adj[i][j] = exist[j] = false;
    }

  string str;
  cin >> str;
  if(str=="#") return false;

  for(int i=0;i<str.size();i++)
    if(!isalpha(str[i]))
      str[i] = ' ';

  stringstream in(str);
  for(string s,t;in >> s >> t;)
    for(int i=0;i<t.size();i++){
      adj[s[0]-'A'][t[i]-'A'] = adj[t[i]-'A'][s[0]-'A'] = true;
      exist[s[0]-'A'] = exist[t[i]-'A'] = true;
    }

  return true;
}

int calc(string &s){
  int maxV = 1;
  for(int i=0;i<s.size();i++)
    for(int j=0;j<BUF;j++)
      if(adj[s[i]-'A'][j])
        maxV = max(maxV,abs((int)s.find(j+'A')-i));
  return maxV;
}

void work(){
  int minV = (1<<20);
  string curr, ans;
  
  for(int i=0;i<BUF;i++) 
    if(exist[i])
      curr += (char)(i+'A');
  sort(curr.begin(),curr.end());

  do {
    int t = calc(curr);
    if(minV>t){
      minV = t;
      ans = curr;
    }
  }while(next_permutation(curr.begin(),curr.end()));

  for(int i=0;i<ans.size();i++)
    cout << ans[i] << ' ';
  cout << "-> " << minV << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}