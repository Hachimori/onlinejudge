#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI = acos(-1.0), EPS = 1e-8;

double clean(double v){
  if(fabs(v)<0.0005) return 0.0;
  char sval[20];
  sprintf(sval,"%.3lf",v);
  return atof(sval);
}

bool mycmp(pair<double,double> a, pair<double,double> b){
  if(fabs(a.first-b.first)<EPS) return a.second>b.second>EPS;
  return a.first>b.first+EPS;
}

int main(){
  for(int cases=1;;cases++){
    int a,b,n;
    if(scanf("%d%di%d",&a,&b,&n)==EOF) break;

    vector< pair<double,double> > ans;
    for(int i=0;i<n;i++){
      double r = pow(sqrt(a*a+b*b),1.0/n);
      double arg = (atan2(b,a)+i*PI*2)/n;  
      ans.push_back(make_pair(r*cos(arg),r*sin(arg)));
    }
    
    sort(ans.begin(),ans.end(),mycmp);
    cout << "Case " << cases << ":" << endl;
    for(int i=0;i<n;i++){
      printf("%.3lf",clean(ans[i].first));
      printf(clean(ans[i].second)<0?"%.3lfi\n":"+%.3lfi\n",clean(ans[i].second));
    }
    cout << endl;
  }
  return 0;
}
