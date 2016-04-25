#include<iostream>
#include<string>
#define RULE 1005
using namespace std;

class Rule{
public:
  int pos;
  char src, dst;
};

string src;
char enc[256];
int nRule;
Rule rule[RULE];

bool read(){
  if(!(cin >> src)) return false;
  
  for(int i='a';i<='z';i++)
    cin >> enc[i];
  
  cin >> nRule;
  for(int i=0;i<nRule;i++)
    cin >> rule[i].pos >> rule[i].src >> rule[i].dst;
  
  return true;
}

void work(int cases){
  string ans;
  
  for(int i=0;i<src.size();i++){
    char next[256];
    for(int j='a';j<='z';j++)
      next[j] = enc[j];
    
    for(int j=0;j<nRule;j++)
      if(rule[j].pos==i)
	next[rule[j].src] = rule[j].dst;

    for(int j='a';j<='z';j++)
      enc[j] = next[j];
    
    ans += enc[src[i]];
  }

  cout << "Case #" << cases << ": The encoding string is " << ans << '.' << endl;
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  
  return 0;
}
