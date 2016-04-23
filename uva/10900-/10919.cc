#include<iostream>
#include<vector>
#include<set>

#define BUF 105

using namespace std;

class Course{
public:
  int nSub, nNeed, sub[BUF];
};

int nTook, nCourse;
set<int> took;
Course c[BUF];

bool read(){
  cin >> nTook >> nCourse;
  if(nTook==0) return false;
  
  took.clear();
  for(int i=0;i<nTook;i++){
    int n;
    cin >> n;
    took.insert(n);
  }

  for(int i=0;i<nCourse;i++){
    cin >> c[i].nSub >> c[i].nNeed;
    for(int j=0;j<c[i].nSub;j++)
      cin >> c[i].sub[j];
  }
  
  return true;
}

void work(){
  for(int i=0;i<nCourse;i++){
    int cnt = 0;
    for(int j=0;j<c[i].nSub;j++)
      if(took.count(c[i].sub[j])) cnt++;
    if(cnt<c[i].nNeed){
      cout << "no" << endl;
      return;
    }
  }
  cout << "yes" << endl;
}

int main(){
  while(read())
    work();
  
  return 0;
}
