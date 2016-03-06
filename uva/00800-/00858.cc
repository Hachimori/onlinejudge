#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int BUF = 10005;

int nPt, x[BUF], y[BUF], atLeast, flyPos;

void read(){
  cin >> nPt;
  for(int i=0;i<nPt;i++)
    cin >> x[i] >> y[i];
  cin >> atLeast >> flyPos;
}

void work(){
  vector<double> crossPos;
  for(int i=0;i<nPt;i++){
    double x1 = x[i], y1 = y[i], x2 = x[(i+1)%nPt], y2 = y[(i+1)%nPt];
    if(!(min(x1,x2)<flyPos && flyPos<max(x1,x2))) continue;
    crossPos.push_back(y1+(y2-y1)*(flyPos-x1)/(x2-x1));
  }
  sort(crossPos.begin(),crossPos.end());
  double sum = 0;
  for(int i=0;i<crossPos.size();i+=2)
    sum += crossPos[i+1]-crossPos[i];
  cout << (sum>=atLeast ? "YES" : "NO") << endl;
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
