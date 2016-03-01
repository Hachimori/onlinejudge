#include<iostream>
using namespace std;
const int LINE = 10000, BUF = 10;

int nLine;
string ope[LINE];

bool read(){
  cin >> nLine;
  if(nLine==0) return false;
  string dummy; getline(cin,dummy);
  for(int i=0;i<nLine;i++) getline(cin,ope[i]);
  return true;
}


void output(int &r, int &c, bool override, char ch, string b[BUF]){
  if(override)
    b[r][c] = ch;
  else{
    b[r] = b[r].substr(0,c)+ch+b[r].substr(c);
    b[r].erase(b[r].begin()+b[r].size()-1);
  }
  c = min(BUF-1,c+1);
}

void work(int cases){
  string b[BUF];
  for(int i=0;i<BUF;i++) b[i] = string(BUF,' ');

  bool override = true;
  int r = 0, c = 0;
  for(int i=0;i<nLine;i++)
    for(int j=0;j<ope[i].size();j++){
      if(ope[i][j]=='^'){
        switch(ope[i][j+1]){
        case 'b': c = 0; break;
        case 'c': 
          for(int k=0;k<BUF;k++) b[k] = string(BUF,' ');
          break;
        case 'd': r = min(BUF-1,r+1); break;
        case 'e': b[r] = b[r].substr(0,c)+string(BUF-c,' '); break;
        case 'h': r = c = 0; break;
        case 'i': override = false; break;
        case 'l': c = max(0,c-1); break;
        case 'o': override = true; break;
        case 'r': c = min(BUF-1,c+1); break;
        case 'u': r = max(0,r-1); break;
        case '^': output(r,c,override,'^',b); break;
        default:
          r = ope[i][j+1]-'0';
          c = ope[i][j+2]-'0';
          j++;
          break;
        }
        j++;
      }
      else
        output(r,c,override,ope[i][j],b);
    }

  cout << "Case " << cases << endl;
  cout << "+----------+" << endl;
  for(int i=0;i<BUF;i++)
    cout << '|'+b[i]+'|' << endl;
  cout << "+----------+" << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
