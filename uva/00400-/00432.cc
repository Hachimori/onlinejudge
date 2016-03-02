#include<iostream>
#include<cmath>

using namespace std;

int nLeft, nRight;



void work(){
  
  int width, height;
  cin >> nLeft >> nRight >> width >> height;

  cout << "(" << width << "," << height << ")(" 
              << 0 << "," << 0 << ")" << endl;
  
  if(nLeft==0 && nRight==0){
    cout << "(" << 0 << "," << 0 << ")("
	        << width*2 << "," << 0 << ")" << endl;
    
    cout << "(" << width*2 << "," << 0 << ")(" 
     	        << width << "," << height << ")" << endl;
    
    return;
  }

  
  cout << "(" << 0 << "," << 0 << ")(" 
              << width*2/(int)pow(2.0,(double)nLeft) << "," << 0 << ")" << endl;


  for(int currX=width*2/(int)pow(2.0,(double)nLeft),currLeft=0,currHeight=height/(int)pow(2.0,(double)nLeft);
      currLeft<nLeft;
      currLeft++,currX*=2,currHeight*=2){
    

    cout << "(" << currX << "," << 0 << ")("
	        << currX/2 << "," << currHeight << ")" << endl;

    cout << "(" << currX/2 << "," << currHeight << ")(" 
            	<< currX+currX/2 << "," << currHeight << ")" << endl;
    
    cout << "(" << currX+currX/2 << "," << currHeight << ")("
                << currX << "," << 0 << ")" << endl;

    if(currLeft!=nLeft-1){
      cout << "(" << currX << "," << 0 << ")("
	   << currX*2 << "," << 0 << ")"  << endl;
    }

  }

   
  
  if(nRight==1){
    cout << "(" << width << "," << 0 << ")("
	        << width*2 << "," << 0 << ")"  << endl;
  }
  else
  for(int currHeight=height,currX=width,currRight=0;
      currRight<nRight-1;
      currRight++,currX+=(width*2-currX)/2,currHeight/=2){
    
    if(currRight==0){
      cout << "(" << currX << "," << 0 << ")("
	          << currX+(width*2-currX)/2 << "," << 0 << ")"  << endl;
    }

    cout << "(" << currX+(width*2-currX)/2 << "," << 0 << ")("
         	<< currX+(width*2-currX)/2/2 << "," << currHeight/2/2 << ")" << endl;

    cout << "(" << currX+(width*2-currX)/2/2 << "," << currHeight/2/2 << ")("
	        << currX+(width*2-currX)/2+(width*2-currX)/2/2 << "," << currHeight/2/2 << ")" << endl;
    
    cout << "(" << currX+(width*2-currX)/2+(width*2-currX)/2/2 << "," << currHeight/2/2 << ")("
	        << currX+(width*2-currX)/2 << "," << 0 << ")" << endl;
    
    if(currRight==nRight-2)
      cout << "(" << currX+(width*2-currX)/2 << "," << 0 << ")(" 
	          << width*2 << "," << 0 << ")" << endl;
    else
      cout << "(" << currX+(width*2-currX)/2 << "," << 0 << ")(" 
	          << currX+(width*2-currX)/2+(width*2-currX)/2/2 << "," << 0 << ")" << endl;
  }
  
  
  cout << "(" << width*2 << "," << 0 << ")(" 
              << width << "," << height << ")" << endl;

}

int main(){

  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    work();
    cout << endl;
  }

  return 0;
}
