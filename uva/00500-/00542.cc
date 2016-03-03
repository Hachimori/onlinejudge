#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int NAME = 16;

string name[NAME];
double win[NAME][NAME];

bool read(){
  for(int i=0;i<NAME;i++) if(!(cin >> name[i])) return false;
  for(int i=0;i<NAME;i++)
    for(int j=0;j<NAME;j++){
      cin >> win[i][j];
      win[i][j] *= 0.01;
    }
  return true;
}


void rec(double p, int id[NAME*2], double sum[NAME]){
  if(id[0]!=-1){
    sum[id[0]]+=p;
    return;
  }

  for(int i=0;i<NAME-1;i++){
    if(!(id[i]==-1 && id[i*2+1]!=-1 && id[i*2+2]!=-1)) continue;
    id[i] = id[i*2+1];
    rec(p*win[id[i*2+1]][id[i*2+2]],id,sum);
    id[i] = id[i*2+2];
    rec(p*win[id[i*2+2]][id[i*2+1]],id,sum);
    id[i] = -1;
    break;
  }
}


void work(){
  int id[NAME*2];
  memset(id,-1,sizeof(id));
  for(int i=NAME-1;i<NAME*2-1;i++) id[i] = i-NAME+1;

  double sum[NAME];
  for(int i=0;i<NAME;i++) sum[i] = 0;

  rec(1.0,id,sum);

  for(int i=0;i<NAME;i++)
    printf("%-10s p=%.2lf%%\n",name[i].c_str(),sum[i]*100);
}


int main(){
  while(read()) work();
  return 0;
}
