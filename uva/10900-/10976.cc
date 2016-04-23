#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int num;

bool read(){
  return (cin >> num);
}

void work(){
  vector< pair<int,int> > ans;

  for(int y=num+1;y<=num*2;y++)
    if((num*y)%(y-num)==0)
      ans.push_back(make_pair(num*y/(y-num),y)); 
  
  sort(ans.rbegin(),ans.rend());
  
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++)
    cout << "1/" << num << " = 1/" << ans[i].first << " + 1/" << ans[i].second << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
