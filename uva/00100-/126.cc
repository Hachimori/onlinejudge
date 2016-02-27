#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<cmath>
#define BUF 210
using namespace std;

string s[2];

bool read(){
  cin >> s[0];
  if(s[0]=="#") return false;
  cin >> s[1];
  return true;
}

void getCoeff(string &str, int coeff[BUF][BUF]){
  int cur = 0;
  while(cur<str.size()){
    bool minus = str[cur]=='-';
    if(str[cur]=='-' || str[cur]=='+') cur++;
    
    string mul = "";
    while(cur<str.size() && isdigit(str[cur])) mul += str[cur++];
    
    int expX = 0, expY = 0;
    while(cur<str.size() && (str[cur]=='x' || str[cur]=='y')){
      bool isX = str[cur++]=='x';
      string exp = "";
      while(cur<str.size() && isdigit(str[cur])) exp += str[cur++];
      (isX ? expX : expY ) = (exp.empty() ? 1 : atoi(exp.c_str()));
    }

    coeff[expX][expY] += (mul.empty() ? 1 :atoi(mul.c_str())) * (minus ? -1 : 1);
  }
}

string itoa(int n){
  stringstream out;
  out << n;
  return out.str();
}

int getDigit(int n){
  return (1+log10(abs(n)));
}

void work(){
  int coeff[2][BUF][BUF];

  for(int i=0;i<2;i++)
    for(int j=0;j<BUF;j++)
      for(int k=0;k<BUF;k++)
        coeff[i][j][k] = 0;

  for(int i=0;i<2;i++)
    getCoeff(s[i],coeff[i]);


  int ans[BUF][BUF];
  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++)
      ans[i][j] = 0;

  for(int i=0;i<BUF;i++)
    for(int j=0;j<BUF;j++){
      if(coeff[0][i][j]==0) continue;
      
      for(int k=0;k<BUF;k++)
        for(int l=0;l<BUF;l++)
          if(coeff[1][k][l]!=0)
            ans[i+k][j+l] += coeff[0][i][j]*coeff[1][k][l];
    }
  
  string line1, line2;
  bool first = true;
  for(int x=BUF-1;x>=0;x--)
    for(int y=0;y<BUF;y++){
      if(ans[x][y]!=0){
        if(ans[x][y]<0){
          if(first) line1 += " ", first = false;
          else line1 += "   ";
        }
        else {
          if(first) first = false;
          else line1 += "   ";
        }

        if(abs(ans[x][y])!=1)
          line1 += string(getDigit(ans[x][y]),' ');
        
        if(x>=1) line1 += ' ';
        if(x>1)  line1 += itoa(x);
        if(y>=1) line1 += ' ';
        if(y>1)  line1 += itoa(y);
      }
    }
  
  first = true;
  for(int x=BUF-1;x>=0;x--)
    for(int y=0;y<BUF;y++)
      if(ans[x][y]!=0){
        int num = ans[x][y];
        
        if(num<0){
          if(first) line2 += "-", first = false;
          else line2 += " - ";
        }
        else{
          if(first) first = false;
          else line2 += " + ";
        }

        if(abs(num)>1 || (x==0 && y==0))
          line2 += itoa(abs(num));

        if(x!=0){
          line2 += 'x';
          if(x!=1) line2 += string(getDigit(x),' ');
        }
        if(y!=0){
          line2 += 'y';
          if(y!=1) line2 += string(getDigit(y),' ');
        }
      }
  
  
  if(first){
    cout << ' ' << endl;
    cout << 0 << endl;
    return;
  }
  
  cout << line1;
  for(int i=line1.size();i<line2.size();i++) cout << ' ';
  cout << endl;
  cout << line2;
  for(int i=line2.size();i<line1.size();i++) cout << ' ';
  cout << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
