#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cassert>
#define EPS 1e-5
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define known(x) (!EQ(x,NONE))
using namespace std;
const double NONE = -(1<<20), PI = acos(-1.0);;

vector<double> _len, _arg;

void read(){
  _len = _arg = vector<double>(3);

  for(int i=0;i<3;i++){
    cin >> _len[i] >> _arg[i];
    if(EQ(_len[i],-1)) _len[i] = NONE;
    if(EQ(_arg[i],-1)) _arg[i] = NONE;
  }
}

bool rule1(double &ar, double &br, double &cr){
  if(!known(ar) && known(br) && known(cr)){
    ar = PI-br-cr;
    return true;
  }
  return false;
}

bool rule2_1(double &a, double &ar, double &b, double &br){
  if(!known(a) && known(ar) && known(b) && known(br)){
    a = b*sin(ar)/sin(br);
    return true;
  }
  return false;
}

vector<double> rule2_2(double &a, double &ar, double &b, double &br){
  if(known(a) && !known(ar) && known(b) && known(br)){
    vector<double> ret;
    ret.push_back(   asin(a*sin(br)/b));
    ret.push_back(PI-asin(a*sin(br)/b));
    return ret;
  }
  return vector<double>();
}

bool rule3_1(double &a, double &b, double &c, double &ar){
  if(!known(a) && known(b) && known(c) && known(ar)){
    a = sqrt(b*b+c*c-2*b*c*cos(ar));
    return true;
  }
  return false; 
}

bool rule3_2(double &a, double &b, double &c, double &ar){
  if(known(a) && known(b) && known(c) && !known(ar)){
    ar = acos((a*a-b*b-c*c)/(-2*b*c));
    return true;
  }
  return false;
}

bool rule4(double &a, double &b, double &c, double &br, double &cr){
  if(!known(a) && known(b) && known(c) && known(br) && known(cr)){
    a = b*cos(cr)+c*cos(br);
    return true;
  }
  return false;
}

bool invalid(vector<double> len, vector<double> arg){
  for(int i=0;i<3;i++){
    double a = len[i], ar = arg[i];
    for(int j=0;j<3;j++){
      if(i==j) continue;
      double b = len[j], br = arg[j];
      // rule 2
      if(known(a) && known(b) && known(ar) && known(br) && !EQ(a/sin(ar),b/sin(br)))
        return true;

      for(int k=0;k<3;k++){
        if(i==k || j==k) continue;
        double c = len[k], cr = arg[k];
        // rule 3
        if(known(a) && known(b) && known(c) && known(br) && known(cr) &&
           !EQ(a,b*cos(cr)+c*cos(br)))
          return true;

        // rule 4
        if(known(a) && known(b) && known(c) && known(ar) &&
           !EQ(a*a,b*b+c*c-2*b*c*cos(ar)))
          return true;
      }
    }
  }

  if(known(len[0]) && known(len[1]) && known(len[2]) &&
     len[0]+len[1]+len[2]<=max(len[0],max(len[1],len[2]))*2) return true;

  return false;
}

bool allKnown(vector<double> len, vector<double> arg){
  for(int i=0;i<3;i++)
    if(!known(len[i]) || !known(arg[i]))
      return false;
  return true;
}

void rec(vector<double> len, vector<double> arg, 
         vector<double> &lenAns, vector<double> &argAns, bool &twoSol){
  
  if(invalid(len,arg)) return;
  if(allKnown(len,arg)){
    if(EQ(lenAns[0],NONE)){
      lenAns = len;
      argAns = arg;
    }
    else{
      for(int i=0;i<3;i++)
        if(!EQ(len[i],lenAns[i]) || !EQ(arg[i],argAns[i]))
          twoSol = true;
    }
    return;
  }
  
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      if(i==j) continue;
      if(rule2_1(len[i],arg[i],len[j],arg[j])){
        rec(len,arg,lenAns,argAns,twoSol);
        len[i] = NONE;
      }
      vector<double> ret = rule2_2(len[i],arg[i],len[j],arg[j]);
      if(!ret.empty()){
        for(int k=0;k<2;k++){
          arg[i] = ret[k];
          rec(len,arg,lenAns,argAns,twoSol);
          arg[i] = NONE;
        }
      }
      for(int k=0;k<3;k++){
        if(i==k || j==k) continue;
        if(rule3_1(len[i],len[j],len[k],arg[i])){ 
          rec(len,arg,lenAns,argAns,twoSol);
          len[i] = NONE;
        }
        if(rule3_2(len[i],len[j],len[k],arg[i])){ 
          rec(len,arg,lenAns,argAns,twoSol);
          arg[i] = NONE;
        }
        if(rule1(arg[i],arg[j],arg[k])){
          rec(len,arg,lenAns,argAns,twoSol);
          arg[i] = NONE;
        }
      }
    }
}

void work(){
  bool twoSol = false;
  vector<double> lenAns(3,NONE), argAns(3,NONE);
  
  for(int i=0;i<3;i++){
    lenAns[i] = NONE;
    argAns[i] = NONE;
  }
  
  rec(_len,_arg,lenAns,argAns,twoSol);

  if(twoSol)
    cout << "More than one solution." << endl;
  else if(EQ(lenAns[0],NONE))
    cout << "Invalid input." << endl;
  else{
    for(int i=0;i<3;i++){
      if(i) cout << ' ';
      printf("%.6f %.6f",lenAns[i],argAns[i]);
    }cout << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work();
  }
  return 0;
}
