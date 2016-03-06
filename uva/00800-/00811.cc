#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cmath>
#include<cstdio>

#define SIZE 20
#define INF 100000000
#define EPS (1.0e-9)
#define EQ(x,y) (abs(x-y)<EPS)

using namespace std;

typedef complex<double> Point;

class Data{
public:
  int id, val, leng;
  Point p;
  
  Data(){}
  Data(int i, int v, int l, Point p): id(i), val(v), leng(l), p(p){}

  bool operator< (const Data &d) const {
    if(EQ(p.real(),d.p.real())) return p.imag()<d.p.imag();
    return p.real()<d.p.real();
  }
};

int nPoint;
Data data[SIZE];

bool read(){
  cin >> nPoint;
  if(nPoint==0) return false;
  
  for(int i=0;i<nPoint;i++){
    int x, y, id = i+1, val, leng;
    
    cin >> x >> y >> val >> leng;
    data[i] = Data(id,val,leng,Point(x,y));
  }

  return true;
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);

  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

void pushPt(vector<int> &ret, vector<int> &remain, bool low){
  int bgn = (low ? 0 : remain.size()-1);
  int end = (low ? (int)remain.size() : -1);
  int d = (low ? 1 : -1);
  
  ret.push_back(remain[bgn]);
  int m = ret.size();
  
  for(int i=bgn+d;i!=end;i+=d){
    for(int k;(k=ret.size())>m && 
	  ccw(data[ret[k-2]].p,data[ret[k-1]].p,data[remain[i]].p)<0;)
      ret.pop_back();
    ret.push_back(remain[i]);
  }
  ret.pop_back();
}

vector<int> calcConvex(vector<int> &remain){
  vector<int> ret;
  if(remain.size()<=3) return remain;
  pushPt(ret,remain,true);
  pushPt(ret,remain,false);
  return ret;
}

bool great(vector<int> &chose, vector<int> &ans){
  int v[]={0,0};
  
  for(int i=0;i<chose.size();i++)
    v[0] += data[chose[i]].val;

  for(int i=0;i<ans.size();i++)
    v[1] += data[ans[i]].val;

  if(v[0]==v[1]) return chose.size()<ans.size();
  return v[0]<v[1];
}

void calc(int curr, vector<int> &chose, double &extra, vector<int> &ans){
  if(curr==nPoint){
    vector<int> remain;
    for(int i=0;i<nPoint;i++)
      if(find(chose.begin(),chose.end(),i)==chose.end())
	remain.push_back(i);
    
    vector<int> ret = calcConvex(remain);

    if(ans.size()==0 || great(chose,ans)){
      double sum = 0;
      for(int i=0;i<ret.size();i++){
	int curr = ret[i], next = ret[(i+1)%ret.size()];
	sum -= abs(data[curr].p-data[next].p);
      }

      for(int i=0;i<chose.size();i++)
	sum += data[chose[i]].leng;

      if(sum>=0){
	extra = sum;
	ans = chose;
      }
    }
    
    return;
  }

  chose.push_back(curr);

  calc(curr+1,chose,extra,ans);

  chose.pop_back();
  
  calc(curr+1,chose,extra,ans);
}

void work(int cases){
  double extra;
  vector<int> chose, ans;

  sort(data,data+nPoint);

  calc(0,chose,extra,ans);

  vector<int> sorted;
  for(int i=0;i<ans.size();i++)
    sorted.push_back(data[ans[i]].id);
  sort(sorted.begin(),sorted.end());
  
  cout << "Forest " << cases << endl;
  cout << "Cut these trees:";
  for(int i=0;i<sorted.size();i++)
    cout << ' ' << sorted[i];
  cout << endl;

  printf("Extra wood: %.2lf\n",fabs(extra)+EPS);
}

int main(){
  for(int i=0;read();i++){
    if(i) cout << endl;
    work(i+1);
  }
  
  return 0;
}
