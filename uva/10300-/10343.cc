#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

int c2i[256];
vector<unsigned char> v;

bool read(){
  v.clear();
  while(1){
    unsigned char ch;
    cin >> ch;
    if(ch=='#'){
      if(v.empty()) return false;
      break;
    }
    if(!(ch=='=' || c2i[ch]!=-1)) continue;
    v.push_back(ch);
  }
  return true;
}

void work(){
  for(int i=0;i<v.size();i+=4){
    int sum = 0;
    for(int j=0;j<4;j++)
      sum = (sum<<6)+c2i[v[i+j]];
    
    if(v[i+2]=='=' && v[i+3]=='=')
      cout << (char)(sum>>16);
    else if(v[i+3]=='=')
      cout << (char)(sum>>16) << (char)(sum>>8);
    else
      cout << (char)(sum>>16) << (char)(sum>>8) << (char)sum;
  }
  cout << "#";
}

int main(){
  memset(c2i,-1,sizeof(c2i));
  int cnt = 0;
  for(int i='A';i<='Z';i++) c2i[i] = cnt++;
  for(int i='a';i<='z';i++) c2i[i] = cnt++;
  for(int i='0';i<='9';i++) c2i[i] = cnt++;
  c2i['+'] = cnt++;
  c2i['/'] = cnt++;
  c2i['='] = 0;
  while(read()) work();
  return 0;
}
