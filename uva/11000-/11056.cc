#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int BUF = 105;

int nPpl;
pair<string,int> buf[BUF];

bool read(){
  if(!(cin >> nPpl)) return false;
  for(int i=0;i<nPpl;i++){
    string name;
    cin >> name;
    string dummy;
    int m, s, ms;
    cin >> dummy >> m >> dummy >> s >> dummy >> ms >> dummy;
    buf[i] = make_pair(name,m*1000*60+s*1000+ms);
  }
  return true;
}

bool mycmp(pair<string,int> a, pair<string,int> b){
  if(a.second!=b.second) return a.second<b.second;
  for(int i=0;i<a.first.size();i++)  a.first[i] = toupper(a.first[i]);
  for(int i=0;i<b.first.size();i++)  b.first[i] = toupper(b.first[i]);
  return a.first<b.first;
}

void work(){
  sort(buf,buf+nPpl,mycmp);

  for(int i=0;i<nPpl;i++){
    if(i%2==0) cout << "Row " << i/2+1 << endl;
    cout << buf[i].first << endl;
  }
  cout << endl;
}

int main(){
  while(read()) work();
  return 0;
}
