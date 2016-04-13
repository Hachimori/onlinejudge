#include<iostream>
#include<vector>
using namespace std;

int cnvVec2Val(vector<int> vec, int base){
  int p = 1, ret = 0;
  for(int i=0;i<vec.size();i++){
    ret += vec[i]*p;
    p *= base;
  }
  return ret;
}

vector<int> cnvVal2Vec(int v, int base){
  vector<int> ret;
  while(v){
    ret.push_back(v%base);
    v /= base;
  }
  return ret;
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    int b1, b2, L, R;
    cin >> b1 >> b2 >> L >> R;
    for(int i=R-1;i>L;i--){
      vector<int> vec = cnvVal2Vec(i,b1);
      if(cnvVec2Val(vec,b2)%cnvVec2Val(vec,b1)==0){
        cout << i << endl;
        goto _success;
      }
    }
    cout << "Non-existent." << endl;
  _success:;
  }
  return 0;
}
