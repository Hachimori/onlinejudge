#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int BUF = 105;

int n, win[BUF][BUF], draw[BUF][BUF];

bool read(){
  if(!(cin >> n)) return false;
  int mat[BUF][BUF];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> mat[i][j];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      win[i][j] = mat[i][j] && !mat[j][i];
      draw[i][j] = !mat[i][j] && !mat[j][i];
    }
  return true;
}

void work(){
  set< vector<int> > S;
  vector< vector<int> > ans;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        if(((i<j && j<k) || (i>j && j>k)) && 
           ( (win[i][j] && win[j][k] && win[k][i]) ||
             (draw[i][j] && draw[j][k] && draw[k][i]))){
          vector<int> toPush, backup;
          toPush.push_back(i);
          toPush.push_back(j);
          toPush.push_back(k);
          backup = toPush;
          sort(toPush.begin(),toPush.end());
          if(!S.count(toPush))
            ans.push_back(backup);
          S.insert(toPush);
        }
  
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++)
    cout << ans[i][0]+1 << ' ' << ans[i][1]+1 << ' ' << ans[i][2]+1 << endl;
}

int main(){
  while(read()) work();
  return 0;
}
