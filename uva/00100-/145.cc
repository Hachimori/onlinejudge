#include<iostream>
#include<cstdio>
using namespace std;

string name;
int area, bgn, end;

bool read(){
  char ch;
  int bh, bm, eh, em;

  cin >> ch >> name >> bh >> bm >> eh >> em;
  if(ch=='#') return false;

  area = ch-'A';
  bgn = bh*60+bm;
  end = eh*60+em;
  
  return true;
}

void work(){
  double tbl[][3]={{0.10,0.06,0.02},
                   {0.25,0.15,0.05},
                   {0.53,0.33,0.13},
                   {0.87,0.47,0.17},
                   {1.44,0.80,0.30}};
  int cnt[3]={0};
  
  for(int curr=bgn;curr!=end;curr=(curr+1)%(24*60))
    if(8*60<=curr && curr<18*60)
      cnt[0]++;
    else if(18*60<=curr && curr<22*60)
      cnt[1]++;
    else
      cnt[2]++;
  
  if(bgn==end){
    cnt[0] = 10*60;
    cnt[1] = 4*60;
    cnt[2] = 10*60;
  }

  double sum = tbl[area][0]*cnt[0]+tbl[area][1]*cnt[1]+tbl[area][2]*cnt[2];
  printf("%10s%6d%6d%6d%3c%8.2f\n",name.c_str(),cnt[0],cnt[1],cnt[2],area+'A',sum+1e-7);
}

int main(){
  while(read())
    work();
  return 0;
}