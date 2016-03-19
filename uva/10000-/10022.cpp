#include<iostream>


long long upper,lower;
int upper_row,lower_row;

class Solver{
 public:

  void read(){
    
    long a,b;

    cin >> a >> b;

    if(a>=b){
      upper = b;
      lower = a;
    }
    else{
      upper = a;
      lower = b;
    }

  }

  void work(){
    
    for(long long i=1;;i++)
      if(i*i-2*i+2<=upper && upper<=i*i){ 
	upper_row = i;
	break;
      }
    
    for(long long i=1;;i++)
      if(i*i-2*i+2<=lower && lower<=i*i){ 
	lower_row = i;
	break;
      }    

    long long left_limit = upper;
    long long right_limit = upper;
    long long curr_row = upper_row;
    bool inside;

    for(;;left_limit+=curr_row*2-1,right_limit+=curr_row*2+1,curr_row++){
      if(left_limit<= lower && lower <= right_limit){
	inside = true;
	break;
      } 
      else if(curr_row*curr_row-curr_row*2+2 <= lower && lower < left_limit){
	inside = false;
	break;
      }
      else if(right_limit < lower && lower <= curr_row*curr_row){
	inside = false;
	break;
      }  
    }

    /*
    if(inside==true) cout << "inside" << endl;
    else cout << "outside" << endl;
    */

   

    if(inside==true){
      if( (upper_row%2==0 && upper%2==0) || (upper_row%2==1 && upper%2==1) ){
	if( (lower_row%2==0 && lower%2==0) || (lower_row%2==1 && lower%2==1) ){
	  cout << (lower_row-upper_row)*2 << endl;
	  return;
	}
	else {
	  cout << (lower_row-upper_row)*2-1 << endl;
	  return;
	}
      }
      else {
	if( (lower_row%2==0 && lower%2==0) || (lower_row%2==1 && lower%2==1) ){
	  cout << (lower_row-upper_row)*2+1 << endl;
	  return;
	}
	else {
	  cout << (lower_row-upper_row)*2 << endl;
	  return;
	}	
      }
    }
    else{
      left_limit = upper;
      right_limit = upper;
      curr_row = upper_row;
      bool left;
      int counter=0;
  
      //cout << upper << " <= " <<  lower << " <= " << curr_row*2 << endl;

      for(;;left_limit+=curr_row*2-1,right_limit+=curr_row*2+1,curr_row++){
	if(curr_row*curr_row-curr_row*2+2 <= lower && lower < left_limit){
	  left = true;
	  break;
	}
	else if(right_limit < lower && lower <= curr_row*curr_row){
	  left = false;
	  break;
	}     
	
      }     

      if(upper_row!=lower_row)
	if( (upper_row%2==0 && upper%2==0) || (upper_row%2==1 && upper%2==1) ){
	  if(left==true)
	    if( (curr_row%2==0 && left_limit%2==0) || (curr_row%2==1 && left_limit%2==1) ){
	      counter += (lower_row-upper_row)*2;
	    }
	    else {
	      counter += (lower_row-upper_row)*2-1;
	    }
	  else if(left==false)
	    if( (curr_row%2==0 && right_limit%2==0) || (curr_row%2==1 && right_limit%2==1) ){
	      counter += (lower_row-upper_row)*2;
	    }
	    else {
	      counter += (lower_row-upper_row)*2-1;
	    }	  
	}
	else {
	  if(left==true)
	    if( (curr_row%2==0 && left_limit%2==0) || (curr_row%2==1 && left_limit%2==1) ){
	      counter += (lower_row-upper_row)*2+1;
	      
	    }
	    else {
	      counter += (lower_row-upper_row)*2;
	    }	
	  else if(left==false)
	    if( (curr_row%2==0 && right_limit%2==0) || (curr_row%2==1 && right_limit%2==1) ){
	      counter += (lower_row-upper_row)*2+1;
	      
	    }
	    else {
	      counter += (lower_row-upper_row)*2;
	    }
	}    
      
      //cout << "left_limit = " << left_limit << "  right_limit = " << right_limit << endl;
      //if(left==true) cout << "left" << endl;
      //else cout <<"right" << endl;

      if(left==true){
	for(;left_limit!=lower;left_limit--){
	  counter++;
	}
	cout << counter << endl;
	return;
      }
      else {
	for(;right_limit!=lower;right_limit++){
	  counter++;
	}
	cout << counter << endl;
	return;
      }

    }

  }

};

main(){

  int cases;
  Solver solver;

  cin >> cases;
  
  for(int i=0;i<cases;i++){
    if(i!=0) cout << endl;
    solver.read();
    solver.work();
  }

}
