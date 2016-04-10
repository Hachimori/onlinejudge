#include<iostream>
using namespace std;

void makeTable(bool c2b[128][11]){
  for(int i=2;i<=4;i++) c2b['c'][i] = true;
  for(int i=7;i<=10;i++) c2b['c'][i] = true;
  for(int i=2;i<=4;i++) c2b['d'][i] = true;
  for(int i=7;i<=9;i++) c2b['d'][i] = true;
  for(int i=2;i<=4;i++) c2b['e'][i] = true;
  for(int i=7;i<=8;i++) c2b['e'][i] = true;
  for(int i=2;i<=4;i++) c2b['f'][i] = true;
  c2b['f'][7] = true;
  for(int i=2;i<=4;i++) c2b['g'][i] = true;
  for(int i=2;i<=3;i++) c2b['a'][i] = true;
  c2b['b'][2] = true;
  c2b['C'][3] = true;
  for(int i=1;i<=4;i++) c2b['D'][i] = true;
  for(int i=7;i<=9;i++) c2b['D'][i] = true;
  for(int i=1;i<=4;i++) c2b['E'][i] = true;
  for(int i=7;i<=8;i++) c2b['E'][i] = true;
  for(int i=1;i<=4;i++) c2b['F'][i] = true;
  c2b['F'][7] = true;
  for(int i=1;i<=4;i++) c2b['G'][i] = true;
  for(int i=1;i<=3;i++) c2b['A'][i] = true;
  for(int i=1;i<=2;i++) c2b['B'][i] = true;
}

int main(){
  bool c2b[128][11]={0};
  makeTable(c2b);

  int cases;
  cin >> cases;
  string dummy;
  getline(cin,dummy);
  for(int k=0;k<cases;k++){
    string s;
    getline(cin,s);
    int cnt[11]={0};
    s = ' '+s;
    for(int i=0;i+1<s.size();i++)
      for(int j=1;j<=10;j++)
        if(!c2b[s[i]][j] && c2b[s[i+1]][j])
          cnt[j]++;
    for(int i=1;i<=10;i++){
      if(i!=1) cout << ' ';
      cout << cnt[i];
    }
    cout << endl;
  }

  return 0;
}
