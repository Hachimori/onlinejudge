#include<iostream>
#include<vector>
#include<cmath>
#define EPS 1e-7
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LE(x,y) (x<=y+EPS)
using namespace std;
const int SIGNAL = 1000;

struct Data{
  double pos;
  int G, Y, R;
};

int nData;
Data data[SIGNAL];

bool read(){
  cin >> nData;
  if(nData==-1) return false;
  for(int i=0;i<nData;i++)
    cin >> data[i].pos >> data[i].G >> data[i].Y >> data[i].R;
  return true;
}


bool can(int mph){
  for(int i=0;i<nData;i++){
    double sec = data[i].pos/mph*60*60;
    double remainder = fmod(sec,data[i].G+data[i].Y+data[i].R);
    if(!(LE(remainder,data[i].G+data[i].Y) || EQ(remainder,data[i].G+data[i].Y+data[i].R))) return false;
  }
  return true;
}


void work(int cases){
  vector<int> ans;
  for(int i=30;i<=60;i++)
    if(can(i))
      ans.push_back(i);

  cout << "Case " << cases << ": ";
  if(ans.empty()){
    cout << "No acceptable speeds." << endl;
    return;
  }

  for(int i=0;i<ans.size();i++){
    int nexI = i;
    while(nexI+1<ans.size() && ans[nexI]+1==ans[nexI+1]) nexI++;
    if(nexI==i)
      cout << ans[i];
    else
      cout << ans[i] << "-" << ans[nexI];
    if(nexI+1!=ans.size()) cout << ", ";
    i = nexI;
  }
  cout << endl;
}


int main(){
  for(int i=0;read();i++) work(i+1);
  return 0;
}
