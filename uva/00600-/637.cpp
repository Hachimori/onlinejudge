#include<iostream>

int page;

class Solver{
 public:

  bool read(){
    
    cin >> page;
    if(page==0) return false;

    return true;

  }

  void work(){
    
    int j=1,k;
    int page_counter=0;

    k=(page+3)/4;
    k*=4;

    cout << "Printing order for " << page << " pages:" << endl;

    for(int i=0;i<(page+3)/4;i++){
      

      for(int counter=0;counter<2;counter++,j++,k--){

	if(j%2==0){
	  if(k<=page){ 
	    cout << "Sheet " << i+1 << ", back : " << j << ", " << k << endl;
	    page_counter+=2;
	  }
	  else{ 
	    cout << "Sheet " << i+1 << ", back : " << j << ", Blank" << endl;
	    page_counter++;
	  }
	}
	else{
	  if(k<=page){
	    cout << "Sheet " << i+1 << ", front: " << k << ", " << j << endl;
	    page_counter+=2;
	  }	 
	  else{ 
	    cout << "Sheet " << i+1 << ", front: " << "Blank, " << j << endl;
	    page_counter++;
	  }
	}

	if(page_counter==page) return;

      }


    }

  }

};

main(){

  Solver solver;
  bool first=true;

  while(true){
   
    if(solver.read()==false) break;
    if(first!=true) cout << endl;
    solver.work();
    
    first=false;
  }

}
