#include<iostream>
#include<set>
#include<cfloat>
#include<algorithm>
#include<cassert>

#define MAX_SIZE 220
#define EPS (FLT_EPSILON/100)

#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)-(y)<-EPS)
#define GT(x,y) ((x)-(y)>EPS)

using namespace std;

double coeff[MAX_SIZE][MAX_SIZE], val[MAX_SIZE], objCoeff[MAX_SIZE], objVal;
set<int> nonBasic, basic;

bool read(){
  
  nonBasic.clear();
  basic.clear();
  for(int i=0;i<MAX_SIZE;i++){
    for(int j=0;j<MAX_SIZE;j++)
      coeff[i][j] = 0;
    val[i] = 0;
    objCoeff[i] = 0;
  }
  objVal = 0;

  
  int nConst;
  cin >> nConst;
  
  if(nConst==0) return false;

  for(int i=0;i<nConst;i++){
    double x,y,z;
    cin >> x >> y >> z;
    
    coeff[0][i+6] = x;
    coeff[1][i+6] = y;
    coeff[2][i+6] = z;
    coeff[3][i+6] = -x;
    coeff[4][i+6] = -y;
    coeff[5][i+6] = -z;
  }
  
 
  double A,B,C;
  cin >> A >> B >> C;
  
  val[0] = -A;
  val[1] = -B;
  val[2] = -C;
  val[3] = A;
  val[4] = B;
  val[5] = C;
  
  for(int i=0;i<6;i++)
    basic.insert(i);
  for(int i=0;i<nConst;i++)
    nonBasic.insert(i+6);
  return true;

}

bool positiveExist(double a[MAX_SIZE]){
  for(set<int>::iterator i=nonBasic.begin();i!=nonBasic.end();i++)
    if(GT(a[*i],0.0)) return true;
  return false;
}

void pivot(set<int> &NB, set<int> &B, double OC[MAX_SIZE],
	   double C[MAX_SIZE][MAX_SIZE], double &OV, double V[MAX_SIZE],
	   int l, int e){
  
  V[e] = V[l]/(-C[l][e]);
  for(set<int>::iterator i=NB.begin();i!=NB.end();i++){
    if(*i==e) continue;
    C[e][*i] = C[l][*i]/(-C[l][e]);
  }
  C[e][l] = 1.0/C[l][e];
  
  for(set<int>::iterator i=B.begin();i!=B.end();i++){
    if(*i==l) continue;
    
    V[*i] += C[*i][e]*V[e];
    for(set<int>::iterator j=NB.begin();j!=NB.end();j++){
      if(*j==e) continue;
      C[*i][*j] += C[*i][e]*C[e][*j];

    }
    C[*i][l] = C[*i][e]*C[e][l];
    C[*i][e] = 0.0;
    
  }
  
  OV += OC[e]*V[e];
  for(set<int>::iterator i=NB.begin();i!=NB.end();i++){
    if(*i==e) continue;
    OC[*i] += OC[e]*C[e][*i];

  }
  OC[l] = OC[e]*C[e][l];
  OC[e] = 0.0;
  
  
  fill(C[l],C[l]+B.size()+NB.size(),0.0);
  V[l] = 0.0;
  
  NB.erase(e);
  NB.insert(l);
  B.erase(l);
  B.insert(e);
}

void print(double OC[MAX_SIZE], double C[MAX_SIZE][MAX_SIZE],
	   double OV, double V[MAX_SIZE]){

  for(set<int>::iterator i=basic.begin();i!=basic.end();i++){
    cout << "i: " << *i << "  ";
    for(int j=0;j<basic.size()+nonBasic.size();j++){
      cout << C[*i][j] << " ";
    }
    cout << V[*i] << endl;
  }
  cout << endl;
  for(int j=0;j<basic.size()+nonBasic.size();j++){
    cout << OC[j] << " ";
  }
  cout << OV << endl << endl << endl;
    
}

bool init(set<int> &NB, set<int> &B, double OC[MAX_SIZE],
	  double C[MAX_SIZE][MAX_SIZE], double &OV, double V[MAX_SIZE]){
  int e,l,nVariable=NB.size()+B.size();
  double minV=INT_MAX;
  
  for(set<int>::iterator i=B.begin();i!=B.end();i++)
    if(GT(minV,V[*i])){
      l = *i;
      minV = V[*i];
    }
  
  if(GT(minV,0.0) || EQ(minV,0.0) ) return true;
  
  static double tmpObjC[MAX_SIZE], tmpObjV;
  
  fill(tmpObjC,tmpObjC+nVariable+1,0.0);
  fill(C[nVariable],C[nVariable]+nVariable+1,0.0);
  
  for(int i=0;i<nVariable+1;i++)
    C[i][nVariable] = 0.0;
  for(set<int>::iterator i=B.begin();i!=B.end();i++)
    C[*i][nVariable] = 1.0;
  V[nVariable] = 0;
  OC[nVariable] = 0;
  tmpObjC[nVariable] = -1;
  tmpObjV = 0;
  
  nVariable++;
  
  NB.insert(nVariable-1);
  
  pivot(NB,B,tmpObjC,C,tmpObjV,V,l,nVariable-1); 

  //print(tmpObjC,C,tmpObjV,V);
  
  while(positiveExist(tmpObjC)){
    minV = INT_MAX;
    e = -1; l =-1;
    
    for(set<int>::iterator i=NB.begin();i!=NB.end();i++)
      if(GT(tmpObjC[*i],0)){
	e = *i;
	break;
      }
        
    for(set<int>::iterator i=B.begin();i!=B.end();i++)
      if(LT(C[*i][e],0.0) && GT(minV,V[*i]/(-C[*i][e])) ){
	minV = V[*i]/(-C[*i][e]);
	l = *i;
      }

    pivot(NB,B,tmpObjC,C,tmpObjV,V,l,e);
  }
  
  //print(tmpObjC,C,tmpObjV,V);
  
  if(B.find(nVariable-1)!=B.end() && EQ(V[nVariable-1],0.0) ){
    e = -1;
    
    for(set<int>::iterator j=NB.begin();j!=NB.end();j++)
      if(!EQ(coeff[nVariable-1][*j],0.0)){
	e = *j;
	break;
      }
    
    if(e!=-1)
      pivot(NB,B,tmpObjC,C,tmpObjV,V,nVariable-1,e);
  }
  else if(B.find(nVariable-1)!=B.end() && !EQ(V[nVariable-1],0.0) )
    return false; // infeasible
  

  if(!EQ(tmpObjV,0.0)) return false; // infeasible

  
  for(set<int>::iterator i=B.begin();i!=B.end();i++){
    if(EQ(OC[*i],0.0)) continue;
    
    OV += OC[*i]*V[*i];
    for(set<int>::iterator j=NB.begin();j!=NB.end();j++){
      
      OC[*j] += OC[*i]*C[*i][*j];
    }
    OC[*i] = 0.0;
  }
  
  nVariable--;

  NB.erase(nVariable);
  B.erase(nVariable);

  return true;

}

bool simplex(set<int> &NB, set<int> &B, double OC[MAX_SIZE],
	     double C[MAX_SIZE][MAX_SIZE], double OV, double V[MAX_SIZE]){
  
  // init(NB,B,OC,C,OV,V);
  return init(NB,B,OC,C,OV,V);
  
  while(positiveExist(OC)){
    int e,l;
    double minV=INT_MAX;
    
    for(set<int>::iterator i=NB.begin();i!=NB.end();i++)
      if(GT(OC[*i],0)){
	e = *i;
	break;
      }
    
    
    for(set<int>::iterator i=B.begin();i!=B.end();i++)
      if(LT(C[*i][e],0.0) && GT(minV,V[*i]/(-C[*i][e])) ){
	minV = V[*i]/(-C[*i][e]);
	l = *i;
      }
    
    assert(!EQ(minV,INT_MAX)); // unbounded
    
    pivot(NB,B,OC,C,OV,V,l,e);
  }

}

void work(int cases){
  
  cout << "Mixture " << cases << endl;
  
  if(simplex(nonBasic,basic,objCoeff,coeff,objVal,val))
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  
}

int main(){
  
  for(int i=0;read();i++){
    if(i!=0) cout << endl;
    work(i+1);
  }
  
  return 0;
}
