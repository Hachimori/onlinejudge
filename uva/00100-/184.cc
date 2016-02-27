#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;
typedef complex<double> Point;
const int BUF = 305;

namespace std{
  bool operator< (Point a, Point b){
    if(a.real()==b.real()) return a.imag()<b.imag();
    return a.real()<b.real();
  }
};

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

vector<Point> pt;

bool read(){
  pt.clear();
  while(1){
    int x, y;
    cin >> x >> y;
    if(x==0 && y==0) break;
    pt.push_back(Point(x,y));
  }
  return !pt.empty();
}

void work(){
  sort(pt.begin(),pt.end());

  bool found = false;
  bool used[BUF][BUF] = {0};
  
  for(int i=0;i<pt.size();i++)
    for(int j=i+1;j<pt.size();j++)
      if(!used[i][j]){
        vector<int> onLine;
        onLine.push_back(i);
        onLine.push_back(j);
        for(int k=j+1;k<pt.size();k++)
          if(cross(pt[j]-pt[i],pt[k]-pt[i])==0)
            onLine.push_back(k);
        
        if(onLine.size()>2){
          if(!found){
            cout << "The following lines were found:" << endl;
            found = true;
          }
          for(int k=0;k<onLine.size();k++)
            printf("(%4d,%4d)",(int)pt[onLine[k]].real(),(int)pt[onLine[k]].imag());
          cout << endl;
          for(int k=0;k<onLine.size();k++)
            for(int l=0;l<onLine.size();l++)
              used[onLine[k]][onLine[l]] = true;
        }
      }
  if(!found)
    cout << "No lines were found" << endl;
}

int main(){
  while(read())
    work();
  return 0;
}
