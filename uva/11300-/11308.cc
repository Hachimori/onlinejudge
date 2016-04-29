#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int kk=0;kk<cases;kk++){
    string dummy; getline(cin,dummy);
    
    string title;
    getline(cin,title);

    int nItem, nRecipe, limit;
    cin >> nItem >> nRecipe >> limit;

    map<string,int> item2cost;
    for(int i=0;i<nItem;i++){
      string name;
      int cost;
      cin >> name >> cost;
      item2cost[name] = cost;
    }
    
    
    vector< pair<int,string> > ans;
    for(int i=0;i<nRecipe;i++){
      getline(cin,dummy);
      string recipeName;
      int nKind;
      getline(cin,recipeName);
      cin >> nKind;
      int sum = 0;
      for(int j=0;j<nKind;j++){
        string needItem;
        int nNeed;
        cin >> needItem >> nNeed;
        sum += item2cost[needItem]*nNeed;
      }
      if(sum<=limit) ans.push_back(make_pair(sum,recipeName));
    }
    sort(ans.begin(),ans.end());

    for(int i=0;i<title.size();i++)
      cout << (char)toupper(title[i]);
    cout << endl;
    if(ans.empty())
      cout << "Too expensive!" << endl;
    for(int i=0;i<ans.size();i++)
      cout << ans[i].second << endl;
    cout << endl;
  }
  return 0;
}
