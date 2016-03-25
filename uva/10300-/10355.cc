#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
const int SPHERE = 15, NONE = 1<<30;

string name;
double xb, yb, zb, xe, ye, ze;
int nSphere;
double xs[SPHERE], ys[SPHERE], zs[SPHERE], r[SPHERE];

bool read(){
  if(!(cin >> name)) return false;
  cin >> xb >> yb >> zb >> xe >> ye >> ze;
  cin >> nSphere;
  for(int i=0;i<nSphere;i++)
    cin >> xs[i] >> ys[i] >> zs[i] >> r[i];
  return true;
}

double sq(double v){
  return v*v;
}

pair<double,double> calcQuad(double a, double b, double c){
  if(b*b-4*a*c<0) return make_pair(NONE,NONE);
  return make_pair((-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a));
}

pair<double,double> calc(double xp, double yp, double zp, 
                         double xv, double yv, double zv,
                         double xs, double ys, double zs, double r){
  double a = sq(xv)+sq(yv)+sq(zv);
  double b = -2*xs*xv+2*xp*xv-2*ys*yv+2*yp*yv-2*zs*zv+2*zp*zv;
  double c = sq(xs)+sq(xp)-2*xs*xp+sq(ys)+sq(yp)-2*ys*yp+sq(zs)+sq(zp)-2*zs*zp-sq(r);
  return calcQuad(a,b,c);
}

void work(){
  double len = sqrt(sq(xb-xe)+sq(yb-ye)+sq(zb-ze));
  double xv = (xe-xb)/len;
  double yv = (ye-yb)/len;
  double zv = (ze-zb)/len;
  vector< pair<double,double> > ranges;
  for(int i=0;i<nSphere;i++){
    pair<double,double> ret = calc(xb,yb,zb,xv,yv,zv,xs[i],ys[i],zs[i],r[i]);
    if(ret==pair<double,double>(NONE,NONE)) continue;
    if(ret.first>ret.second) swap(ret.first,ret.second);
    ret.first = max(ret.first/len,0.0);
    ret.second = min(ret.second/len,1.0);
    if(1.0<=ret.first || ret.second<=0.0) continue;
    ranges.push_back(ret);
  }
  
  sort(ranges.begin(),ranges.end());

  double sum = 0;
  for(int i=0;i<ranges.size();i++)
    sum += ranges[i].second-ranges[i].first;
  printf("%s\n%.2lf\n",name.c_str(),sum*100);
}

int main(){
  while(read()) work();
  return 0;
}
