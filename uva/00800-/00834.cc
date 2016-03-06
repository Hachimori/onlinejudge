#include<iostream>
#include<vector>
using namespace std;

int main(){
  int nume, deno;
  while(cin >> nume >> deno){
    vector<int> ans;
    while(nume!=1){
      ans.push_back(nume/deno);
      nume %= deno;
      swap(nume,deno);
    }

    if(ans.empty()){
      cout << "[0;" << deno << "]" << endl;
    }
    else{
      cout << '[' << ans[0];
      for(int i=1;i<ans.size();i++)
        cout << (i==1 ? ';' : ',') << ans[i];
      cout << ']' << endl;
    }
  }
  return 0;
}
