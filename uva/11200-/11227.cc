#include<iostream>
#include<complex>
#include<algorithm>
#define BUF 105
#define EPS (1.0e-9)
#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;
typedef complex<double> Point;

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int nPt;
Point pt[BUF];

void read(){
  nPt = 0;

  int n; cin >> n;
  for(int i=0;i<n;i++){
    double x, y; cin >> x >> y;

    bool ok = true;
    for(int j=0;j<nPt;j++)
      if(norm(Point(x,y)-pt[j])<EPS){
        ok = false;
        break;
      }
    
    if(ok) pt[nPt++] = Point(x,y);
  }
}

void work(int cases){
  cout << "Data set #" << cases << " contains ";
  
  if(nPt==1){
    cout << "a single gnu." << endl;
    return;
  }
  
  int maxV = 0;
  for(int i=0;i<nPt;i++)
    for(int j=i+1;j<nPt;j++){
      Point a = pt[i], b = pt[j];

      int cnt = 0;
      for(int k=0;k<nPt;k++)
        if(EQ(cross(b-a,pt[k]-a),0)) 
          cnt++;

      maxV = max(maxV,cnt);
    }
  
  cout << nPt << " gnus, out of which a maximum of " 
       << maxV << " are aligned." << endl;
}

int main(){
  int cases;
  cin >> cases;
  
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
