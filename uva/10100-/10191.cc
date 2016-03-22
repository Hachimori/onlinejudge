#include<iostream>
#include<cstdio>
using namespace std;
const int DATA = 1005;

int nData;
pair<int,int> data[DATA];


int cnv(string t){
  int hh, mm;
  sscanf(t.c_str(),"%d:%d",&hh,&mm);
  return hh*60+mm;
}


bool read(){
  if(!(cin >> nData)) return false;
  for(int i=0;i<nData;i++){
    string bgn, end, dummy;
    cin >> bgn >> end;
    getline(cin,dummy);
    data[i] = make_pair(cnv(bgn),cnv(end));
  }
  data[nData++] = make_pair(cnv("10:00"),cnv("10:00"));
  data[nData++] = make_pair(cnv("18:00"),cnv("18:00"));
  return true;
}


void work(int cases){
  sort(data,data+nData);

  int maxV = 0, maxPos;
  for(int i=0;i+1<nData;i++){
    if(maxV<data[i+1].first-data[i].second){
      maxV = data[i+1].first-data[i].second;
      maxPos = data[i].second;
    }
  }

  cout << "Day #" << cases << ": the longest nap starts at ";
  printf("%d:%02d and will last for ",maxPos/60,maxPos%60);
  if(maxV>=60) cout << maxV/60 << " hours and ";
  cout << maxV%60 << " minutes." << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
