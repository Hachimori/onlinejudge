#include<iostream>

char operation[3]={'+','-','*'};
int a[5];
int b[5];

bool Search_rec(int sum, int arg){
  
  if(arg==5){
    if(sum==23) return true;
    else return false;
  }

  
  for(int i=0;i<3;i++){
      if(operation[i]=='+' && Search_rec(sum+b[arg],arg+1)==true ) return true;
      else if(operation[i]=='-' && Search_rec(sum-b[arg],arg+1)==true) return true;
      else if(operation[i]=='*' && Search_rec(sum*b[arg],arg+1)==true) return true;
  }

  return false;

}

class Solver{
 public:

  bool read(){
    
    for(int i=0;i<5;i++) 
      cin >> a[i];

    if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0) 
      return false;

    return true;

  }
  
  void work(){

    for(int v=0;v<5;v++){

      for(int w=0;w<5;w++){
	if(w==v) continue;
	
	for(int x=0;x<5;x++){
	  if(x==v||x==w) continue;
	  
	  for(int y=0;y<5;y++){
	    if(y==v||y==w||y==x) continue;

	    for(int z=0;z<5;z++){
	      if(z==v||z==w||z==x||z==y) continue;
	      
	      b[0] = a[v];
	      b[1] = a[w];
	      b[2] = a[x];
	      b[3] = a[y];
	      b[4] = a[z];
	      
	      for(int i=0;i<3;i++){ 
		if(operation[i]=='+' && Search_rec(b[0]+b[1],2)==true ){
		  cout << "Possible" << endl;
		  return;
		}
		else if(operation[i]=='-' && Search_rec(b[0]-b[1],2)==true){
		  cout << "Possible" << endl;
		  return;	
		}
		else if(operation[i]=='*' && Search_rec(b[0]*b[1],2)==true){
		  cout << "Possible" << endl;
		  return;	
		}	
	      }
	      
	      
	    }
	  }
	}
      }
    }
    
    
    cout << "Impossible" << endl;

    return;

  }

};

main(){

  Solver solver;

  while(true){

    if(solver.read()==false) break;
    solver.work();

  }


}
