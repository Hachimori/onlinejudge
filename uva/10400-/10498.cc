#include<iostream>
#include<cfloat>
#include<cassert>
#include<algorithm>
#include<cmath>

#define MAX_SIZE 50
#define EPS FLT_EPSILON

#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)-(y)<-EPS)
#define GT(x,y) ((x)-(y)>EPS)

using namespace std;

int nObj, nConst, nVariable;
double objCoeff[MAX_SIZE], coeff[MAX_SIZE][MAX_SIZE], objVal, val[MAX_SIZE];

bool read(){
  
  if(!(cin >> nObj >> nConst)) return false;
  
  nVariable = nObj+nConst;
  objVal=0.0;
  for(int i=0;i<nVariable;i++)
    for(int j=0;j<nVariable;j++){
      coeff[i][j] = 0;
      objCoeff[j] = 0;
      val[j] = 0;
    }


  for(int i=0;i<nObj;i++)
    cin >> objCoeff[i];
  
  for(int i=0;i<nConst;i++){
    for(int j=0;j<nObj;j++){
      cin >> coeff[i+nObj][j];
      coeff[i+nObj][j]*=(-1);
    }
    
    cin >> val[i+nObj];
  }
  
  return true;

}

bool positiveExist(double a[MAX_SIZE]){
  for(int i=0;i<nVariable;i++)
    if(GT(a[i],0.0))
      return true;

  return false;
}

void pivot(double objCoeff[MAX_SIZE], double coeff[MAX_SIZE][MAX_SIZE],
	   double &objVal, double val[MAX_SIZE], int e, int l){
  
  val[e] = val[l]/(-coeff[l][e]);
  for(int i=0;i<nVariable;i++){
    if(i==e) continue;
    coeff[e][i] = coeff[l][i]/(-coeff[l][e]);
  }
  coeff[e][l] = 1.0/coeff[l][e];
  

  for(int i=0;i<nVariable;i++){
    if(i==l || i==e) continue;
    
    val[i] += coeff[i][e]*val[e];
    for(int j=0;j<nVariable;j++){
      if(j==e) continue;
      coeff[i][j] += coeff[i][e]*coeff[e][j];
    }

    coeff[i][l] = coeff[i][e]*coeff[e][l];
    coeff[i][e] = 0;
  }
  
  objVal += objCoeff[e]*val[e];
  
  for(int i=0;i<nVariable;i++){
    if(i==e) continue;
    objCoeff[i]+=objCoeff[e]*coeff[e][i];
  }
  objCoeff[l] = objCoeff[e]*coeff[e][l];
  objCoeff[e] = 0;
  
  fill(coeff[l],coeff[l]+nVariable,0.0);
  val[l] = 0.0;
  
}

double simplex(double objCoeff[MAX_SIZE], double coeff[MAX_SIZE][MAX_SIZE],
	       double objVal, double val[MAX_SIZE]){
  
  while(positiveExist(objCoeff)){
    int e,l;
    double minVal = INT_MAX;
    
    for(int i=0;i<nVariable;i++)
      if(GT(objCoeff[i],0.0)){
	e = i;
	break;
      }
    
    for(int i=0;i<nVariable;i++)
      if(LT(coeff[i][e],0.0) && GT(minVal,val[i]/(-coeff[i][e])) ){
	l = i;
	minVal = val[i]/(-coeff[i][e]);
      }
    
    assert(!EQ(minVal,INT_MAX)); // unbound
    
    pivot(objCoeff,coeff,objVal,val,e,l);
  }
  
  return objVal;
}

void work(){
  
  int ans = ceil(nConst*simplex(objCoeff,coeff,objVal,val));
  
  cout << "Nasa can spend " << ans << " taka." << endl;
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
