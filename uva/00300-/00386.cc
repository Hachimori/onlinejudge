#include<iostream>
#include<cfloat>
#include<cmath>
#include<set>

#define LIMIT 201

using namespace std;

class FourDigit{
public:
  int a,b,c,cube;

  FourDigit(){}
  FourDigit(int a, int b, int c, int cube): a(a), b(b), c(c), cube(cube){}

  bool operator<(const FourDigit &fd) const{
 
   if(cube<fd.cube) return true;
    if(cube==fd.cube){
      if(a<fd.a) return true;
      if(a==fd.a){
	if(b<fd.b) return true;
	if(b==fd.b){
	  if(c<fd.c) return true;

	}
      }      
    }

    return false;
  }

};

void work(){
  
  set<FourDigit> fourList;
  /*
  for(int a=0;a*a*a<LIMIT*LIMIT*LIMIT;a++){
    for(int b=a;b*b*b+a*a*a<LIMIT*LIMIT*LIMIT;b++){
      
      int c = LIMIT*LIMIT*LIMIT-a*a*a-b*b*b;
      double cubeRootC = pow(c,0.33333333333333);
      int cubeRootCInt = (int)(cubeRootC+0.5);
      
      if(fabs(cubeRootC-cubeRootCInt)<FLT_EPSILON){
	
	int cube = cubeRootCInt*cubeRootCInt*cubeRootCInt + a*a*a + b*b*b;
	double cubeRootCube = pow(cube,0.33333333333333);
	int cubeRootCubeInt = (int)(cubeRootCube+0.5);	
	
	if(fabs(cubeRootCube-cubeRootCubeInt)<FLT_EPSILON){
	  FourDigit toInsert;
	  if(c<=a)
	    toInsert = FourDigit(c,a,b,cubeRootCubeInt);
	  if(a<c && c<=b)
	    toInsert = FourDigit(a,c,b,cubeRootCubeInt);
	  if(b<c)
	    toInsert = FourDigit(a,b,c,cubeRootCubeInt);

	  fourList.insert(toInsert);
	}
      }

    }
  }

  
  set<FourDigit>::iterator i,begin=fourList.begin(),end=fourList.end();
  for(i=begin;i!=end;i++)
    cout << "Cube = " << i->cube << ", Triple = (" << i->a << ',' << i->b << ',' << i->c << ')' << endl;
  */
  

  for(int cube=2;cube*cube*cube<LIMIT*LIMIT*LIMIT;cube++){
    for(int a=2;a*a*a<cube*cube*cube;a++){
      for(int b=a+1;b*b*b+a*a*a<cube*cube*cube;b++){

	int c = cube*cube*cube-(b*b*b+a*a*a);
	double cRoot = pow(c,1.0/3);
	int cRootInt = (int)(cRoot+0.5);

	if( cRootInt>=2 && cRootInt*cRootInt*cRootInt+b*b*b+a*a*a==cube*cube*cube){
	  if(cRootInt<=a)
	    fourList.insert(FourDigit(cRootInt,a,b,cube));
	  else if(a<cRootInt && cRootInt<=b)
	    fourList.insert(FourDigit(a,cRootInt,b,cube));
	  else if(b<cRootInt)
	    fourList.insert(FourDigit(a,b,cRootInt,cube));
	}

      }
    }
  }

  set<FourDigit>::iterator i,begin=fourList.begin(),end=fourList.end();
  for(i=begin;i!=end;i++)
    cout << "Cube = " << i->cube << ", Triple = (" << i->a << ',' << i->b << ',' << i->c << ')' << endl;
  //cout << "Cube = " << cube << ", Triple = (" << a << ',' << b << ',' << cRootInt << ')' << endl;
}

int main(){
  
  work();

  return 0;
}
