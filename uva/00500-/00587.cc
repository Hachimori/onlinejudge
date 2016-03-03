#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
const double sq2 = 1/sqrt(2.0);

string str;

bool read(){
  getline(cin,str);
  for(int i=0;i<str.size();i++) 
    if(str[i]==',' || str[i]=='.')
      str[i] = ' ';
  return str!="END";
}

void work(int cases){
  string idx2dir[8] = {"N","NE","E","SE","S","SW","W","NW"};
  double dx[8] = {0,sq2,1,sq2,0,-sq2,-1,-sq2};
  double dy[8] = {1,sq2,0,-sq2,-1,-sq2,0,sq2};

  double x = 0, y = 0;
  int num;
  string dir;
  stringstream in(str);
  while(in >> num >> dir){
    int idx = find(idx2dir,idx2dir+8,dir)-idx2dir;
    x += dx[idx]*num;
    y += dy[idx]*num;
  }

  cout << "Map #" << cases << endl;
  printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
  printf("The distance to the treasure is %.3lf.\n",sqrt(x*x+y*y));
}

int main(){
  for(int i=0;read();i++){
    work(i+1);
    cout << endl;
  }
  return 0;
}
