#include<iostream>
#include<vector>
using namespace std;

vector<vector<string> > sList;

bool read(){
  sList.clear();
  while(1){
    vector<string> toPush;
    for(int i=0;i<5;i++){
      string s;
      cin >> s;
      if(s=="-") goto _finish;
      toPush.push_back(s);
    }
    sList.push_back(toPush);
  }
 _finish:;
  return sList.size();
}

void work(){
  int g2c[5]={9,4,4,4,7};
  double fatCalorie = 0, otherCalorie = 0;

  for(int i=0;i<sList.size();i++){
    int sumPercent = 0, sumCalorie = 0;
    for(int j=0;j<5;j++){
      string &s = sList[i][j];
      switch(s[s.size()-1]){
      case 'g':
        sumCalorie += atoi(s.substr(0,s.size()-1).c_str())*g2c[j];
        break;
      case 'C':
        sumCalorie += atoi(s.substr(0,s.size()-1).c_str());
        break;
      case '%':
        sumPercent += atoi(s.substr(0,s.size()-1).c_str());
        break;
      }
    }
    double per2cal = sumCalorie/(100.0-sumPercent);
    for(int j=0;j<5;j++){
      double cal;
      string &s = sList[i][j];
      switch(s[s.size()-1]){
      case 'g':
        cal = atoi(s.substr(0,s.size()-1).c_str())*g2c[j];
        break;
      case 'C':
        cal = atoi(s.substr(0,s.size()-1).c_str());
        break;
      case '%':
        cal = atoi(s.substr(0,s.size()-1).c_str())*per2cal;
        break;
      }
      (j==0 ? fatCalorie : otherCalorie) += cal;
    }
  }

  cout << (int)(fatCalorie/(fatCalorie+otherCalorie)*100+0.5) << '%' << endl;
}

int main(){
  while(read()) work();
  return 0;
}
