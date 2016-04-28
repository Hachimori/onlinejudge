#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<int,string> i2s;
map<string,int> s2i;

void makeTbl(){
  i2s[0] = "DONG";
  i2s[1] = "NAN";
  i2s[2] = "XI";
  i2s[3] = "BEI";
  i2s[4] = "ZHONG";
  i2s[5] = "FA";
  i2s[6] = "BAI";

  for(int i=0;i<=6;i++)
    s2i[i2s[i]] = i;
}

int nTile[4][9];

bool read(){
  for(int i=0;i<4;i++)
    for(int j=0;j<9;j++)
      nTile[i][j] = 0;

  for(int i=0;i<13;i++){
    string s;
    cin >> s;
    if(s=="0") return false;
    
    if(s[1]=='T') nTile[0][s[0]-'1']++;
    else if(s[1]=='S') nTile[1][s[0]-'1']++;
    else if(s[1]=='W') nTile[2][s[0]-'1']++;
    else               nTile[3][s2i[s]]++;
  }

  return true;
}

bool isOk(int r, int c){
  if(r==4) return true;
  if(c==9) return isOk(r+1,0);
  if(nTile[r][c]==0) return isOk(r,c+1);
  
  for(int che=0;che<=4;che++){
    if(che>0 && (c>=7 || r==3)) continue;
    bool ok = true;
    for(int i=c;i<min(c+3,9);i++)
      if(nTile[r][i]<che){
        ok = false;
        break;
      }
    if(!ok) continue;

    for(int i=c;i<min(c+3,9);i++)
      nTile[r][i] -= che;
    
    for(int pon=0;pon<=1;pon++){
      if(nTile[r][c]==3*pon){
        nTile[r][c] -= 3*pon;
        if(isOk(r,c+1)){
          nTile[r][c] += 3*pon;
          for(int i=c;i<min(c+3,9);i++)
            nTile[r][i] += che;
          return true;
        }
        nTile[r][c] += 3*pon;
      }
    }

    for(int i=c;i<min(c+3,9);i++)
      nTile[r][i] += che;
  }

  return false;
}

void work(int cases){
  bool ok[4][9];
  for(int i=0;i<4;i++)
    for(int j=0;j<9;j++)
      ok[i][j] = false;
  
  for(int i=0;i<4;i++)
    for(int j=0;j<9;j++){
      if(nTile[i][j]>=4) continue;
      
      nTile[i][j]++;

      for(int k=0;k<4;k++)
        for(int l=0;l<9;l++){
          if(nTile[k][l]<2) continue;
          nTile[k][l] -= 2;
          if(isOk(0,0)) ok[i][j] = true;
          nTile[k][l] += 2;
        }
      nTile[i][j]--;
    }

  cout << "Case " << cases << ":";

  int cnt = 0;
  for(int i=0;i<4;i++)
    for(int j=0;j<9;j++)
      if(ok[i][j]){
        cnt++;
        switch(i){
        case 0:
          cout << ' ' << j+1 << 'T';
          break;
        case 1:
          cout << ' ' << j+1 << 'S';
          break;
        case 2:
          cout << ' ' << j+1 << 'W';
          break;
        case 3:
          cout << ' ' << i2s[j];
          break;
        }
      }
  
  if(cnt==0)
    cout << " Not ready";
  cout << endl;
}

int main(){
  makeTbl();

  for(int i=0;read();i++)
    work(i+1);

  return 0;
}
