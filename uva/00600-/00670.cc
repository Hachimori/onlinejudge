#include<iostream>
#include<complex>
#define BUF 105
#define EPS (1.0e-9)
#define LE(x,y) ((x)<=(y)+EPS)
using namespace std;
typedef complex<double> Point;

int nMeet, nToVisit;
Point meet[BUF], toVisit[BUF];

void read(){
  cin >> nMeet >> nToVisit;

  for(int i=0;i<nMeet;i++){
    double x, y;  cin >> x >> y;
    meet[i] = Point(x,y);
  }

  for(int i=0;i<nToVisit;i++){
    double x, y;  cin >> x >> y;
    toVisit[i] = Point(x,y);
  }
}

bool aug(int curr, bool visited[BUF], int nLeft, int nRight, bool adj[BUF][BUF], 
         int L2R[BUF], int R2L[BUF]){
  
  if(curr<0) return true;

  visited[curr] = true;
  
  for(int i=0;i<nRight;i++){
    if(!adj[curr][i] || (R2L[i]!=-1 && visited[R2L[i]])) continue;
    
    if(aug(R2L[i],visited,nLeft,nRight,adj,L2R,R2L)){
      L2R[curr] = i;
      R2L[i] = curr;
      return true;
    }
  }

  return false;
}

int maxMatch(int nLeft, int nRight, bool adj[BUF][BUF], int L2R[BUF]){
  int cnt = 0, R2L[BUF];

  for(int i=0;i<nLeft;i++)  L2R[i] = -1;
  for(int i=0;i<nRight;i++) R2L[i] = -1;

  for(int i=0;i<nLeft;i++){
    bool visited[BUF];
    for(int j=0;j<nLeft;j++) visited[j] = false;
    cnt += aug(i,visited,nLeft,nRight,adj,L2R,R2L);
  }
  return cnt;
}

void work(){
  int nLeft = nMeet-1, nRight = nToVisit, L2R[BUF];
  bool adj[BUF][BUF];

  for(int i=0;i<nLeft;i++)
    for(int j=0;j<nRight;j++){
      Point m1 = meet[i], m2 = meet[i+1], p = toVisit[j];
      adj[i][j] = LE(abs(m1-p)+abs(p-m2),abs(m1-m2)*2);
    }

  cout << maxMatch(nLeft,nRight,adj,L2R)+nMeet << endl;

  for(int i=0;i<nMeet;i++){
    if(i) cout << ' ';
    cout << meet[i].real() << ' ' << meet[i].imag();
    if(i<nLeft && L2R[i]!=-1){
      int id = L2R[i];
      cout << ' ' << toVisit[id].real() << ' ' << toVisit[id].imag();
    }
  }
  cout << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    if(i) cout << endl;
    read();
    work();
  }
  
  return 0;
}
