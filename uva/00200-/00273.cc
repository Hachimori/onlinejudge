#include<iostream>
#include<complex>
#include<algorithm>

#define SEG 20
#define OPE 100000

using namespace std;

typedef complex<int> Point;

class Segment{
public:
  Point bgn, end;
  
  Segment(){}
  Segment(Point b, Point e): bgn(b), end(e){}
};

class Dset{
public:
  
  int nSet;
  int adj[SEG], rank[SEG];
  
  Dset(){ nSet = 0; }
  
  void makeSet(int n){
    adj[n] = n;
    rank[n] = 0;
    nSet++;
  }
  
  void merge(int a, int b){
    if(find(a)!=find(b))
      link(find(a),find(b));
  }

  int find(int n){
    if(adj[n]!=n)
      adj[n] = find(adj[n]);

    return adj[n];
  }

  void link(int a, int b){
    nSet--;
    
    if(rank[a]>rank[b])
      swap(a,b);
    
    adj[a] = b;
    if(rank[a]==rank[b])
      rank[b]++;
  }
};

int nSeg, nOpe, ope[OPE][2];
Segment seg[SEG];

void read(){
  cin >> nSeg;

  for(int i=0;i<nSeg;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    seg[i] = Segment(Point(x1,y1),Point(x2,y2));
  }

  nOpe = 0;
  while(true){
    cin >> ope[nOpe][0] >> ope[nOpe][1];
    if(ope[nOpe][0]==0 && ope[nOpe][1]==0) break;
    
    ope[nOpe][0]--, ope[nOpe][1]--;
    nOpe++;
  }
}

int cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point a, Point b, Point c){
  int ret = cross(b-a,c-a);

  if(ret==0) return 0;
  return (ret>0 ? 1:-1);
}

bool isIntersect(Segment a, Segment b){
  Point a1, a2, b1, b2;

  a1 = a.bgn, a2 = a.end;
  b1 = b.bgn, b2 = b.end;

  if(min(a1.real(),a2.real())>max(b1.real(),b2.real())) return false;
  if(min(a1.imag(),a2.imag())>max(b1.imag(),b2.imag())) return false;
  if(min(b1.real(),b2.real())>max(a1.real(),a2.real())) return false;
  if(min(b1.imag(),b2.imag())>max(a1.imag(),a2.imag())) return false;

  return (0>=ccw(a1,a2,b1)*ccw(a1,a2,b2) && 0>=ccw(b1,b2,a1)*ccw(b1,b2,a2));
}

void work(){
  Dset sets = Dset();
  
  for(int i=0;i<nSeg;i++)
    sets.makeSet(i);
  
  for(int i=0;i<nSeg;i++)
    for(int j=i+1;j<nSeg;j++)
      if(isIntersect(seg[i],seg[j]))
	sets.merge(i,j);
      
  for(int i=0;i<nOpe;i++){
    if(sets.find(ope[i][0])==sets.find(ope[i][1])) cout << "CONNECTED" << endl;
    else cout << "NOT CONNECTED" << endl;
  }
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
