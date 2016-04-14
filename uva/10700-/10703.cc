#include<iostream>
using namespace std;
const int BUF = 100;

int main(){
  while(1){
    int row, col, nRect;
    cin >> row >> col >> nRect;
    if(!(row|col|nRect)) break;
    pair<int,int> lowL[BUF], upR[BUF];
    for(int i=0;i<nRect;i++){
      cin >> lowL[i].first >> lowL[i].second 
          >> upR[i].first >> upR[i].second;
      if(lowL[i].first>upR[i].first) swap(lowL[i].first,upR[i].first);
      if(lowL[i].second>upR[i].second) swap(lowL[i].second,upR[i].second);
    }
    int cnt = 0;
    for(int i=1;i<=row;i++)
      for(int j=1;j<=col;j++)
        for(int k=0;k<nRect;k++)
          if(lowL[k].first<=i && i<=upR[k].first &&
             lowL[k].second<=j && j<=upR[k].second){
            cnt++;
            break;
          }

    if(row*col-cnt==0) 
      cout << "There is no empty spots." << endl;
    else if(row*col-cnt==1)
      cout << "There is one empty spot." << endl;
    else
      cout << "There are " << row*col-cnt << " empty spots." << endl;
  }
  return 0;
}
