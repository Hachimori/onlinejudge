#include<iostream>
#include<cmath>

using namespace std;

long long size, id;

bool read(){
  
  cin >> size >> id;
  if(size==0 && id==0) return false;
  
  return true;

}

void print(long long r, long long c){
  cout << "Line = " << r << ", column = " << c << "." << endl;
}

void work(){
  
  long long currId=1, currR=(size+1)/2, currC=(size+1)/2;
  
  if(id==1) {
    print(currR,currC);
    return;
  }
 
  
  long long i = floor( (3+sqrt(4*id-3))/4 );
  i--;
  
  // cout << i << endl;
 //cout << ret1 << endl;
 currR-=i;
 currC+=i;
 //cout << currR << ' ' << currC << endl;
 currId = 4*(i+1)*(i+1)-6*(i+1)+3;
 
 if(currId<=id && id<=currId+(1+i*2)*2){
    
    if(currId<=id && id<=currId+(1+i*2)){
      currR+=id-currId;
      print(currR,currC);
      return;
    }
    
    currR+=(1+i*2);
    currId+=(1+i*2);
      
    currC-=id-currId;
    print(currR,currC);
    return;
      
  }
 
  currId += (1+i*2)*2;
  currR+=(1+i*2);
  currC-=(1+i*2);
  //cout << currR << ' ' << currC << endl;
  if( currId<=id && id<=currId+(i+1)*2*2 ){
      
    if(currId<=id && id<=currId+(i+1)*2){
      currR-=id-currId;
      print(currR,currC);
      return;
    }
      
    currR-=(i+1)*2;
    currId+=(i+1)*2;

    currC+=id-currId;
    print(currR,currC);
    return;
	
  }
    
  currId += (1+i)*2*2;
  currR-=2;
  currC+=2;
  
}

int main(){
  
  while(read())
    work();
  
  return 0;
}
